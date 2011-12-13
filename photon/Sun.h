#pragma once

#include "Object.h"

class Sun :
	public Object
{
public:
	Sun (float xc, float yc, float zc, int Br = 1, int TTLtemp = 500) {x = xc; y = yc; z = zc; Brightness = Br; TTL = TTLtemp;};
	~Sun (void);

	int Brightness;
	int TTL;
};

