#include "Particle.h"


Particle::Particle(float xc, float yc, float zc,
	float vxc, float vyc, float vzc)
{
	x = xc; y = yc; z = zc;
	vx = vxc; vy = vyc; vz = vzc;
}

Particle::~Particle(void)
{

}

int Particle::CheckCollision(void)
{
	if (TTL == 0)
		return PARTICLE_TO_DELETE;

	return PARTICLE_NO_COLLISION;
}

int Particle::Move(void)
{
	if((TTL != PARTICLE_IMMORTAL)||(TTL != 0)) TTL--;

	int iCollision = CheckCollision();
	switch(iCollision)
	{
	case PARTICLE_NO_COLLISION: x += vx; y += vy; z += vz; break;
	case PARTICLE_TO_DELETE: break;
	}
	return iCollision;
}