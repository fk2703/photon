#pragma once

class Sun 
{
public:
	Sun (float xc, float yc, float zc, int Br = 1, int TTLtemp = 500) {x = xc; y = yc; z = zc; Brightness = Br; TTL = TTLtemp;};
	~Sun (void);

	float x;
	float y;
	float z;

	int Brightness;
	int TTL;
};

