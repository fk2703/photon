#pragma once

#include <vector>

class ImageSensor : 
	public std::vector<double>
{
public:
	~ImageSensor(void);

	int Resolution;
	double Size;
};

