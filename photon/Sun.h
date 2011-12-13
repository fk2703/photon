#pragma once

class Sun 
{
public:
	Sun (float xc, float yc, float zc, int Br = 1) {x = xc; y = yc; z = zc; iBrightness = Br;};
	~Sun (void);

	float x;
	float y;
	float z;

	int iBrightness;
};

