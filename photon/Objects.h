#pragma once

#include "ImageSensor.h"
#include "Lens.h"
#include "Wall.h"

class Objects
{
public:
	Objects(void);
	~Objects(void);

	ImageSensor isSensor;
	Lens lLens;
	Wall wWall;

	double ParticleEnergy;
	int TTL;
};

