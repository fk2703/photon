#include "Suns.h"


Suns::Suns(void)
{
}


Suns::~Suns(void)
{
}

void Suns::Shine(Particles &pPhotons)
{
	auto It = this->begin();
	int vx, vy, vz;
	float len, scale;
	while(It < this->end())
	{
		for (int i = 0; i < It->iBrightness; i++)
		{
			do 
			{
				do{
					vx = rand() - RAND_MAX/2;
					vy = rand() - RAND_MAX/2;
					vz = rand() - RAND_MAX/2;
				}while ((vx == 0)&&(vy == 0)&&(vz == 0));

				len = vx*vx + vy*vy + vz*vz;

			} while ((len > (RAND_MAX*RAND_MAX/4))||(len < 10000));
			len = pow(len, (float) 0.5);

			if (len == 0) scale = 0; else scale = PARTICLE_SPEED/len;

			pPhotons.push_front(
				Particle(It->x, It->y, It->z, (float) vx*scale, (float) vy*scale, (float) vz*scale)
			);

		}
		++It;
	}
}
