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
	return PARTICLE_NO_COLLISION;
}
