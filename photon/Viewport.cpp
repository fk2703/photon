#include "Viewport.h"

Viewport::Viewport(int iResolution, unsigned int iMaxPhotons)
{
	Resolution = iResolution;
	MaxPhotons = iMaxPhotons;

	oWorld.isSensor.resize(Resolution*Resolution);
	oWorld.isSensor.Resolution = Resolution;
	oWorld.isSensor.Size = 10;
	for(int i = 0; i < Resolution; i++) oWorld.isSensor[i] = 0;

	pPhotons.opWorld = &oWorld;
}

Viewport::~Viewport(void)
{
}

void Viewport::OneStep(void)
{
	Particles &pPhotons_a = pPhotons;
	sSuns.Shine(pPhotons_a);
	pPhotons.Move();
}

