#include "Viewport.h"

void Viewport::SceneInit(void)
{
	oWorld.ParticleEnergy = 0.1;
	int ttl = 100;
	int bright = 10000;

	oWorld.isSensor.ClearMode = SENSOR_NO_CLEAR;
	oWorld.isSensor.ClearMode = SENSOR_AUTO_CLEAR;
	oWorld.isSensor.Size = 10;

	oWorld.lLens.Focus = 5;
	oWorld.lLens.Size = 15;
	oWorld.lLens.x = 5;
	oWorld.lLens.y = 5;
	oWorld.lLens.z = 5;

	sSuns.push_front(Sun(15, 9, 10, bright, ttl));
}
