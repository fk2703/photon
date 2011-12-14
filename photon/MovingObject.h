#pragma once
#include "Object.h"

class MovingObject :
	public Object
{
public:
	MovingObject() {};
	MovingObject(double xc, double yc, double zc) {x = xc; y = yc; z = zc;};
	MovingObject(double xc, double yc, double zc, double vxc, double vyc, double vzc) {x = xc; y = yc; z = zc; vx = vxc; vy = vyc; vz = vzc;};
	~MovingObject(void);

	double vx, vy, vz;
};

