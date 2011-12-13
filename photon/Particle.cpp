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
	int i = 0;
	if (i == 1 )
		return PARTICLE_TO_DELETE;

	return PARTICLE_NO_COLLISION;
}

int Particle::Move(void)
{
	int iCollision = CheckCollision();
	switch(iCollision)
	{
	case PARTICLE_NO_COLLISION: x += vx; y += vy; z += vz; break;
	case PARTICLE_TO_DELETE: break;
	}
	return iCollision;
}