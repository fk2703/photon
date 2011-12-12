#pragma once

#include <deque>
#include "Sun.h"
#include "Particles.h"

class Suns :
	public std::deque<Sun>
{
public:
	Suns(void);
	~Suns(void);

	void Shine(Particles &pPhotons);
};
