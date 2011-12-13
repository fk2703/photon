#include "Particles.h"


Particles::Particles(void)
{
}


Particles::~Particles(void)
{

}

void Particles::Move(void)
{
	auto ParticleIter = this->begin();
	Number = 0;
	
	while(ParticleIter < this->end())
	{
		if (ParticleIter->Move() == PARTICLE_TO_DELETE) 
			ParticleIter = erase(ParticleIter);
		else
		{
			++ParticleIter;
			++Number;
		}
	}
}