#pragma once

#include "Object.h"

class Lens :
	public Object
{
public:
	Lens(void) {Size = 5; Focus = 5;};
	~Lens(void);


	double Size;
	double Focus;
};

