#pragma once

#include "MovingObject.h"
#include "Objects.h"

#define PARTICLE_SPEED				0.5
#define PARTICLE_IMMORTAL			-1

#define PARTICLE_NO_COLLISION		2
#define PARTICLE_TO_DELETE			4
#define PARTICLE_SENSOR_COLLISION	6
#define PARTICLE_UNKNOWN			5

class Particle :
	public MovingObject
{
public:
	Particle(float xc, float yc, float zc, float vxc, float vyc, float vzc)
	{ x = xc; y = yc; z = zc; vx = vxc; vy = vyc; vz = vzc; };
	~Particle (void);

	int TTL;

	int CheckCollision(Objects &opWorld_a);
	int Move(Objects &opWorld_a);
};

