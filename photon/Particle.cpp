#include "Particle.h"
#include <math.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_ieee_utils.h>
#include "gsl/gsl_randist.h"

#define DEPTH 0.5
extern gsl_rng *randNumGen;

Particle::~Particle(void)
{

}

inline int Particle::CheckCollision(Objects &opWorld_a)
{
	if (TTL == 0)
		return PARTICLE_TO_DELETE;
	
	double MaxDistance = 100;
	if ((abs(x) > MaxDistance)||(abs(y) > MaxDistance)||(abs(z) > MaxDistance))
		return PARTICLE_TO_DELETE;
	
	double size = opWorld_a.isSensor.Size;
	if ((y < size)&&(z < size)&&(y > 0)&&(z > 0))
	{
		//if ((abs(x) < DEPTH)||(abs(x + vx) < DEPTH))
		if ((x >= 0)&&(x + vx <= 0))
		{
			return PARTICLE_SENSOR_COLLISION;
		}
	}

	size = opWorld_a.lLens.Size;
	if ((x >= opWorld_a.lLens.x)&&((x + vx) < opWorld_a.lLens.x))
	{
		if (gsl_hypot((y - opWorld_a.lLens.y), (z - opWorld_a.lLens.z)) <= size)
		{
			return PARTICLE_LENS_COLLISION;
		}
	}

	size = opWorld_a.wWall.Size;
	if ((y <= opWorld_a.wWall.y)&&((y + vy) > opWorld_a.wWall.y)||(y >= opWorld_a.wWall.y)&&((y + vy) < opWorld_a.wWall.y))
	{
		if (gsl_hypot((x - opWorld_a.wWall.x), (z - opWorld_a.wWall.z)) <= size)
		//if ((x  - opWorld_a.wWall.x < size)&&(z - opWorld_a.wWall.z < size)&&(x - opWorld_a.wWall.x > 0)&&(z - opWorld_a.wWall.z > 0))
		{
			return PARTICLE_WALL_COLLISION;
		}
	}

	return PARTICLE_NO_COLLISION;
}

void Particle::NormalizeSpeed(void)
{
	//long double scale = (long double) PARTICLE_SPEED/pow((long double)vx*vx + vy*vy + vz*vz, (long double) 0.5);
	long double scale = (long double) PARTICLE_SPEED/gsl_hypot3(vx, vy, vz);
	
	vx *= scale;
	vy *= scale;
	vz *= scale;
}

int Particle::Move(Objects &opWorld_a)
{
	if((TTL != PARTICLE_IMMORTAL)||(TTL != 0)) TTL--;

	int iCollision = CheckCollision(opWorld_a);
	switch(iCollision)
	{
	case PARTICLE_NO_COLLISION: x += vx; y += vy; z += vz; break;
	case PARTICLE_SENSOR_COLLISION:
		{
			double persy, persz;
			persy = y;// + vx/(vy*x);
			persz = z;// + vx/(vz*x);

			double size = opWorld_a.isSensor.Size;
			double res = ((double)opWorld_a.isSensor.Resolution)/size;
			if ((persy < size)&&(persy > 0))
			{
				if ((persz < size)&&(persz > 0))
				{
					opWorld_a.isSensor[((int)(persy*res))*opWorld_a.isSensor.Resolution + (int)(persz*res)] += opWorld_a.ParticleEnergy;
				}
			}
			x += vx; y += vy; z += vz; break;
			return PARTICLE_TO_DELETE;
		} break;
	case PARTICLE_LENS_COLLISION:
		{
			//фотон двигается до линзы
			long double time = (long double)abs(opWorld_a.lLens.x - x)/(long double)vx;
			y += (long double)time*(long double)vy;
			z += (long double)time*(long double)vz;
			
			long double Focus = 1/(long double)opWorld_a.lLens.Focus;
			long double LenCenterY = (long double)opWorld_a.lLens.y*Focus;
			long double LenCenterZ = (long double)opWorld_a.lLens.z*Focus;
			long double tempy, tempz;

			tempy = (long double)vy/(long double)vx + LenCenterY;
			tempz = (long double)vz/(long double)vx + LenCenterZ;
			
			vx = (vx>=0?1:-1);
			vy = tempy - (long double)y*Focus;
			vz = tempz - (long double)z*Focus;
			/**/

			NormalizeSpeed();
			
			//фотон двигается с новым вектором после линзы
			x = (long double)opWorld_a.lLens.x + (1-time)*(long double)vx;
			y += (1-time)*(long double)vy;
			z += (1-time)*(long double)vz;
			
			
			//salt
			double SaltScale = 0.2*PARTICLE_SPEED;
			y += (long double)((long double)rand()/(long double)RAND_MAX - 0.5)*SaltScale;
			z += (long double)((long double)rand()/(long double)RAND_MAX - 0.5)*SaltScale;
			/**/

			break;
		} break;
	case PARTICLE_WALL_COLLISION: 
		{
			//фотон двигается до стены
			long double time = (long double)abs(opWorld_a.wWall.y - y)/(long double)vy;
			x += (long double)time*(long double)vx;
			z += (long double)time*(long double)vz;

			//глянец
			//vy = -vy;
			
			//матовая
			double temp = (vy>=0?-1:1);
			gsl_ran_dir_3d(randNumGen, &vx, &vy, &vz);
			vy = temp*abs(vy);
			vx *= PARTICLE_SPEED;
			vy *= PARTICLE_SPEED;
			vz *= PARTICLE_SPEED;
			/**/

			//фотон двигается с новым вектором после стены
			y = (long double)opWorld_a.wWall.y + (1-time)*(long double)vy;
			x += (1-time)*(long double)vx;
			z += (1-time)*(long double)vz;

		}break;
	case PARTICLE_TO_DELETE: break;
	}
	return iCollision;
}
/*
float persy, persz;
float size = 9;
float res = RESOLUTION/size;

if ((iter->y < size + CSPEED)&&(iter->x < size + CSPEED)&&(iter->y > -CSPEED)&&(iter->x > -CSPEED))
	if ((abs(iter->x) < DEPTH)||(abs(iter->x + iter->x1) < DEPTH))
	{
		persy = iter->y + iter->x1/(iter->y1*iter->x);
		persz = iter->z + iter->x1/(iter->z1*iter->x);

		if ((persy < size)&&(persy > 0))
			if ((persz < size)&&(persz > 0))
			{
				MATRIX[(int) ((persy*res))*RESOLUTION + (int)(persz*res)] += iter->bright;
			}
	}
	
*/