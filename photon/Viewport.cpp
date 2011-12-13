#include "Viewport.h"


Viewport::Viewport(int iResolution, unsigned int iMaxPhotons)
{
	Resolution = iResolution;
	MaxPhotons = iMaxPhotons;

	oWorld.isSensor.resize(Resolution*Resolution);
	for(int i = 0; i < Resolution; i++) oWorld.isSensor[i] = 0;

	pPhotons.opWorld = &oWorld;
}

Viewport::~Viewport(void)
{
}

void Viewport::OneStep(void)
{
	Particles &pPhotons_ref = pPhotons;
	sSuns.Shine(pPhotons_ref);
	pPhotons.Move();
}



/*

int step(deque<photon>& photons, float *MATRIX)
{
	deque<photon>::iterator iter = photons.begin();
	
	float persy, persz;
	float size = 9;
	float res = RESOLUTION/size;

	while (iter!= photons.end())
	{

		if ((iter->y < size + CSPEED)&&(iter->x < size + CSPEED)&&(iter->y > -CSPEED)&&(iter->x > -CSPEED))
		if ((abs(iter->x) < DEPTH)||(abs(iter->x + iter->x1) < DEPTH))
		{
			persy = iter->y + iter->x1/(iter->y1*iter->x);
			persz = iter->z + iter->x1/(iter->z1*iter->x);

			if ((persy < size)&&(persy > 0))
			if ((persz < size)&&(persz > 0))
			{
				MATRIX[(int) ((persy*res))*RESOLUTION + (int)(persz*res)] += iter->bright;
			}
		}

		
		step_photon(&(*iter));
		if(brig_dist_check(&(*iter)) == PHOTON_UNFIT)
			while (brig_dist_check(&(*iter)) == PHOTON_UNFIT) {iter = photons.erase(iter);}
		else iter++;
	}

	return photons.size();
}

*/