#include "Particles.h"


Particles::Particles(void)
{
}


Particles::~Particles(void)
{

}

void Particles::Move(void)
{
	auto It = this->begin();
	Number = 0;
	
	while(It < this->end())
	{
		if (It->Move() == PARTICLE_TO_DELETE) 
			It = erase(It);
		else
		{
			++It;
			++Number;
		}
	}
}