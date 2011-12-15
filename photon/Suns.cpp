#include "Suns.h"
#include <gsl/gsl_math.h>
#include "gsl/gsl_randist.h"

extern gsl_rng *randNumGen;

Suns::Suns(void)
{

}


Suns::~Suns(void)
{
}

void Suns::Shine(Particles &pPhotons)
{
	auto SunIter = this->begin();
	double vx, vy, vz;
	
	while(SunIter != this->end())
	{
		for (int i = 0; i < SunIter->Brightness; i++)
		{
			
			//точка
			gsl_ran_dir_3d(randNumGen, &vx, &vy, &vz);
			
			vx *= PARTICLE_SPEED;
			vy *= PARTICLE_SPEED;
			vz *= PARTICLE_SPEED;
			
			pPhotons.push_back(
				Particle(SunIter->x, SunIter->y, SunIter->z, vx, vy, vz)
				);
			/**/
			/*
			//конус
			double maxvx = 0.9;
			do 
			{
				gsl_ran_dir_3d(randNumGen, &vx, &vy, &vz);
			} while(abs(vx) < maxvx);

			vx = -abs(vx);
			vx *= PARTICLE_SPEED;
			vy *= PARTICLE_SPEED;
			vz *= PARTICLE_SPEED;

			pPhotons.push_back(
				Particle(SunIter->x, SunIter->y, SunIter->z, vx, vy, vz)
				);
			/**/

			/*
			//кольцо
			gsl_ran_dir_2d(randNumGen, &vy, &vz); 

			double rad = 5.0;
			pPhotons.push_back(
				Particle( SunIter->x, rad*vy + SunIter->y, rad*vz + SunIter->z, -PARTICLE_SPEED, 0, 0)
				);
			/**/

			/*
			//проектор
			double rad = 5.0;
			double maxi = 0x7fffffff;//дискретизация
			do 
			{
				vy = (double)gsl_rng_uniform_int(randNumGen, maxi)/maxi - 0.5;
				vz = (double)gsl_rng_uniform_int(randNumGen, maxi)/maxi - 0.5;
			} while (gsl_hypot(vy, vz) >= 0.5);

			pPhotons.push_back(
				Particle( SunIter->x, rad*vy + SunIter->y, rad*vz + SunIter->z, -PARTICLE_SPEED, 0, 0)
				);
			/**/

			auto enD = pPhotons.end();
			enD--;
			enD->TTL = SunIter->TTL;
			enD->NormalizeSpeed();
		}
		++SunIter;
	}
}
