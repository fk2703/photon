#pragma once
#include "Object.h"

class MovingObject :
	public Object
{
public:
	MovingObject() {};
	MovingObject(float xc, float yc, float zc) {x = xc; y = yc; z = zc;};
	MovingObject(float xc, float yc, float zc, float vxc, float vyc, float vzc) {x = xc; y = yc; z = zc; vx = vxc; vy = vyc; vz = vzc;};
	~MovingObject(void);

	float vx, vy, vz;
};

