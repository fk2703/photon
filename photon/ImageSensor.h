#pragma once

#include <vector>

#define SENSOR_NO_CLEAR			1
#define SENSOR_AUTO_CLEAR		2
#define SENSOR_ONE_CLEAR		3

class ImageSensor : 
	public std::vector<double>
{
public:
	ImageSensor(void) {ClearMode = SENSOR_AUTO_CLEAR;};
	~ImageSensor(void);

	void Clear();

	int ClearMode;
	int Resolution;
	double Size;
};

