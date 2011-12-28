#include "Viewport.h"

void Viewport::SceneInit(void)
{
	oWorld.ParticleEnergy = 0.01;
	int ttl = 250;
	int bright = 10000;

	oWorld.isSensor.ClearMode = SENSOR_NO_CLEAR;
	//oWorld.isSensor.ClearMode = SENSOR_AUTO_CLEAR;
	oWorld.isSensor.Size = 10;

	oWorld.lLens.Focus = 5.0;
	oWorld.lLens.Size = 5;
	oWorld.lLens.x = 2.942;
	oWorld.lLens.y = 5;
	oWorld.lLens.z = 5;

	oWorld.wWall.Size = 1.5;
	oWorld.wWall.x = 10;
	oWorld.wWall.y = 10;
	oWorld.wWall.z = 5;

	sSuns.push_front(Sun(10, 7, 5, bright, ttl));
}
