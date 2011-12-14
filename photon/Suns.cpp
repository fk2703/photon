#include "Suns.h"

Suns::Suns(void)
{
	randNumGen = gsl_rng_alloc(gsl_rng_mt19937);
}


Suns::~Suns(void)
{
}

void Suns::Shine(Particles &pPhotons)
{
	unsigned long int rndMax = 0x7fff;
	auto SunIter = this->begin();
	double vx, vy, vz;
	
	while(SunIter < this->end())
	{
		for (int i = 0; i < SunIter->Brightness; i++)
		{
			gsl_ran_dir_3d(randNumGen, &vx, &vy, &vz);
			vx *= PARTICLE_SPEED;
			vy *= PARTICLE_SPEED;
			vz *= PARTICLE_SPEED;

			pPhotons.push_back(
				Particle(SunIter->x, SunIter->y, SunIter->z, vx, vy, vz)
			);
			auto enD = pPhotons.end();
			enD--;
			enD->TTL = SunIter->TTL;
		}
		++SunIter;
	}
}
