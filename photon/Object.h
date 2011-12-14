#pragma once

class Object
{
public:
	Object() {};
	Object(double xc, double yc, double zc) {x = xc; y = yc; z = zc;};
	~Object(void);

	double x, y, z;
};

