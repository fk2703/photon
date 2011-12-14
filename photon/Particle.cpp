#include "Particle.h"
#include <math.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_ieee_utils.h>

#define DEPTH 0.5

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
		//if ((y < size)&&(z < size)&&(y > 0)&&(z > 0))
		{
			return PARTICLE_LENS_COLLISION;
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
			x += vx; y += vy; z += vz; 
			
			long double Focus = 1/opWorld_a.lLens.Focus;
			long double LenCenter = opWorld_a.lLens.y*Focus;
			long double tempy, tempz;

			tempy = vy/vx + LenCenter;
			tempz = vz/vx + LenCenter;
			
			double vvx, vvy, vvz;

			vx = (vx>=0?1:-1);
			vy = tempy - y*Focus;
			vz = tempz - z*Focus;
			/**/

			NormalizeSpeed();
			
			break;
		} break;
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