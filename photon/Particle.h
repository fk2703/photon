#pragma once

#define PARTICLE_SPEED				0.5
#define PARTICLE_IMMORTAL			-1


#define PARTICLE_NO_COLLISION		2
#define PARTICLE_TO_DELETE			4
#define PARTICLE_UNKNOWN			5

class Particle
{
public:
	Particle (float xc, float yc, float zc) {x = xc; y = yc; z = zc;};
	Particle(float xc, float yc, float zc, float vxc, float vyc, float vzc);
	~Particle (void);

	float x;
	float y;
	float z;

	float vx;
	float vy;
	float vz;
	int TTL;

	int CheckCollision(void);
	int Move(void);
};

