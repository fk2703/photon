#pragma once

#include "Object.h"

class Wall :
	public Object
{
public:
	Wall(void) {Size = 5;};
	~Wall(void);

	double Size;
};

