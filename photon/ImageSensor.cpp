#include "ImageSensor.h"


ImageSensor::~ImageSensor(void)
{
}

void ImageSensor::Clear(void)
{
	if ((ClearMode == SENSOR_AUTO_CLEAR)||(ClearMode == SENSOR_ONE_CLEAR))
	{	
		auto MatIter = this->begin();

		while(MatIter < this->end())
		{
			*MatIter = 0;
			MatIter++;
		}
	}
	if (ClearMode == SENSOR_ONE_CLEAR)
		ClearMode = SENSOR_NO_CLEAR;
}