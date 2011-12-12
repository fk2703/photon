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
	
	for(It; It < this->end(); It++)
	{
		switch(It->CheckCollision())
		{
		case PARTICLE_NO_COLLISION: It->x += It->vx; It->y += It->vy; It->z += It->vz; break;
		}
		Number++;
	}

}