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
	unsigned long int rndMax = 0x2ffff;
	auto SunIter = this->begin();
	long int vx, vy, vz;
	float len, scale;
	while(SunIter < this->end())
	{
		for (int i = 0; i < SunIter->Brightness; i++)
		{
			do 
			{
				do{
					vx = gsl_rng_uniform_int(randNumGen, rndMax) - rndMax/2;
					vy = gsl_rng_uniform_int(randNumGen, rndMax) - rndMax/2;
					vz = gsl_rng_uniform_int(randNumGen, rndMax) - rndMax/2;
					//vx = rand() - RAND_MAX/2;
					//vy = rand() - RAND_MAX/2;
					//vz = rand() - RAND_MAX/2;
				}while ((vx == 0)&&(vy == 0)&&(vz == 0));

				len = vx*vx + vy*vy + vz*vz;

			} while ((len > ((rndMax*rndMax/4.0)))||(len < 100));
			len = pow(len, (float) 0.5);

			if (len == 0) scale = 0; 
			else scale = PARTICLE_SPEED/len;

			pPhotons.push_back(
				Particle(SunIter->x, SunIter->y, SunIter->z, (float) vx*scale, (float) vy*scale, (float) vz*scale)
			);
			auto enD = pPhotons.end();
			enD--;
			enD->TTL = SunIter->TTL;
		}
		++SunIter;
	}
}
