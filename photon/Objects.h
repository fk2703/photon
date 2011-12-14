#pragma once

#include "ImageSensor.h"
#include "Lens.h"

class Objects
{
public:
	Objects(void);
	~Objects(void);

	ImageSensor isSensor;
	Lens lLens;

	double ParticleEnergy;
	int TTL;
};

