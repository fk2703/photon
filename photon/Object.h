#pragma once

class Object
{
public:
	Object() {};
	Object(float xc, float yc, float zc) {x = xc; y = yc; z = zc;};
	~Object(void);

	float x, y, z;
};

