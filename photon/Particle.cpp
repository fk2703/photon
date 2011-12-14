#include "Particle.h"

#define DEPTH 1.8

Particle::~Particle(void)
{

}

inline int Particle::CheckCollision(Objects &opWorld_a)
{
	if (TTL == 0)
		return PARTICLE_TO_DELETE;

	float size = opWorld_a.isSensor.Size;
	if ((y < size + PARTICLE_SPEED)&&(x < size + PARTICLE_SPEED)&&(y > -PARTICLE_SPEED)&&(x > -PARTICLE_SPEED))
	{
		if ((abs(x) < DEPTH)||(abs(x + vx) < DEPTH))
		{
			return PARTICLE_SENSOR_COLLISION;
		}
	}

	return PARTICLE_NO_COLLISION;
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
			float persy, persz;
			persy = y + vx/(vy*x);
			persz = z + vx/(vz*x);

			float size = opWorld_a.isSensor.Size;
			float res = (float)opWorld_a.isSensor.Resolution/size;
			if ((persy < size)&&(persy > 0))
			{
				if ((persz < size)&&(persz > 0))
				{
					opWorld_a.isSensor[(int) ((persy*res))*opWorld_a.isSensor.Resolution + (int)(persz*res)] += opWorld_a.ParticleEnergy;
				}
			}
			x += vx; y += vy; z += vz; break;
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