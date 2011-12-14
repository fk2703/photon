#pragma once

#include "ImageSensor.h"

class Objects
{
public:
	Objects(void);
	~Objects(void);

	ImageSensor isSensor;
	double ParticleEnergy;
	int TTL;
};

