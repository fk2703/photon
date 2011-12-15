#pragma once

#include <deque>
#include <list>
#include "Particle.h"

class Particles : 
	public std::deque<Particle>
{
public:
	Particles(void);
	~Particles(void);
	
	int Number;
	void Move(void);
	Objects *opWorld;
};

