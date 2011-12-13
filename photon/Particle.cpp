#include "Particle.h"

Particle::~Particle(void)
{

}

int Particle::CheckCollision(Objects &opWorld_a)
{
	if (TTL == 0)
		return PARTICLE_TO_DELETE;

	return PARTICLE_NO_COLLISION;
}

int Particle::Move(Objects &opWorld_a)
{
	if((TTL != PARTICLE_IMMORTAL)||(TTL != 0)) TTL--;

	int iCollision = CheckCollision(opWorld_a);
	switch(iCollision)
	{
	case PARTICLE_NO_COLLISION: x += vx; y += vy; z += vz; break;
	case PARTICLE_TO_DELETE: break;
	}
	return iCollision;
}