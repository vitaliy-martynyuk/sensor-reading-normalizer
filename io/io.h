#ifndef IO_H
#define IO_H

using SensorType = char;
using RawSensorValue = double;

namespace io
{
	SensorType getSensorType();
	RawSensorValue getSensorRawValue();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif