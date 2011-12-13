#pragma once

#include <vector>

class ImageSensor : 
	public std::vector<float>
{
public:
	~ImageSensor(void);

	int Resolution;
	float Size;
};

