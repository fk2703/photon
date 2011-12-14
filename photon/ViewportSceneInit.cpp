#include "Viewport.h"

void Viewport::SceneInit(void)
{
	oWorld.ParticleEnergy = 0.01;
	int ttl = 50;
	int bright = 50000;

	oWorld.isSensor.ClearMode = SENSOR_NO_CLEAR;

	sSuns.push_front(Sun(15, 5, 5, bright, ttl));
}
