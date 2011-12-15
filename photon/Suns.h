#pragma once

#include <deque>
#include <list>
#include "Sun.h"
#include "Particles.h"



class Suns :
	public std::list<Sun>
{
public:
	Suns(void);
	~Suns(void);

	void Shine(Particles &pPhotons);
};
