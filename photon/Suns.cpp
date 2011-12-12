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
	Particle p;

	for(It; It < this->end(); It++)
	{
		p.x = It->x;
		p.y = It->y;
		p.z = It->z;
		for (int i = 0; i < 500; i++)
			pPhotons.push_front(p);
	}
}
