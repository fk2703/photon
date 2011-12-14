#include "Viewport.h"

void Viewport::SceneInit(void)
{
	oWorld.ParticleEnergy = 0.1;
	int ttl = 150;
	int bright = 1000;

	oWorld.isSensor.ClearMode = SENSOR_NO_CLEAR;
	oWorld.isSensor.ClearMode = SENSOR_AUTO_CLEAR;
	oWorld.isSensor.Size = 10;

	oWorld.lLens.Focus = 4;
	oWorld.lLens.Size = 10;
	oWorld.lLens.x = 8;
	oWorld.lLens.y = 5;
	oWorld.lLens.z = 5;

	sSuns.push_front(Sun(16, 5, 5, bright, ttl));
}
