#pragma once

#define PARTICLE_NO_COLLISION		2

class Particle
{
public:
	Particle () {x = 0; y = 0; z = 0; vx = 0; vy = 0; vz = 0;};
	Particle (float xc, float yc, float zc) {x = xc; y = yc; z = zc;};
	Particle(float xc, float yc, float zc, float vxc, float vyc, float vzc);
	~Particle (void);

	float x;
	float y;
	float z;

	float vx;
	float vy;
	float vz;

	int CheckCollision(void);
};

