#pragma once

class Object
{
public:
	Object() {x = 0; y = 0; z = 0;};
	Object(double xc, double yc, double zc) {x = xc; y = yc; z = zc;};
	~Object(void);

	double x, y, z;
};

