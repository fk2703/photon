#pragma once

#include <vector>

class Viewport
{
public:
	Viewport(int iResolution, unsigned int iMaxPhotons);
	~Viewport();

	int Resolution;
	int MaxPhotons;

	std::vector<float> *Matrix;

	int DrawGLScene();  

private:
	float fMulCoeffitient;

};
/*
#include "stdio.h"
#include "conio.h"
#include "malloc.h"
#include "math.h"
#include "string.h"
#include <stdlib.h>
#include <deque>

using namespace std;

#define PHOTON_UNFIT 1
#define PHOTON_FIT 0

#define CSPEED 0.5
#define STEPS_PER_FRAME 100
#define SHINE_PER_STEP 100
#define RESOLUTION 100
#define MAX_DIST 10
#define DEPTH 1.8
#define BRIGHT 0.01

struct photon
{
	float x, y, z;
	float x1, y1, z1;
	float bright;
};

struct sun
{
	float x, y, z;
	struct sun *next;
	struct sun *prev;
};

void inline add_photon(deque<photon>& photons, float x, float y, float z, float x1, float y1, float z1, float bright);
void inline norm_photon(photon *temp);

sun *new_sun(float x, float y, float z);
sun *add_sun(sun *temp, float x, float y, float z);
sun *find_last_sun(sun *temp);
sun *find_first_sun(sun *temp);

int step(deque<photon>& photons, float *MATRIX);
void inline step_photon(photon *temp);
int inline brig_dist_check(photon *temp);

int shine(sun *suns, deque<photon>& photons);
*/

