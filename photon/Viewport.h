#pragma once

#include "Suns.h"
#include "Particles.h"
#include "Objects.h"

class Viewport
{
public:
	Viewport(int iResolution, unsigned int iMaxPhotons);
	~Viewport(void);

	int Resolution;
	int MaxPhotons;

	void OneStep(void);
	void SceneInit(void);

	Suns sSuns;
	Particles pPhotons;
	Objects oWorld;
};
/*

#define CSPEED 0.5
#define STEPS_PER_FRAME 100
#define SHINE_PER_STEP 100
#define RESOLUTION 100
#define MAX_DIST 10
#define DEPTH 1.8
#define BRIGHT 0.01

*/

