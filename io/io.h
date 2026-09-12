#ifndef IO_H
#define IO_H

#include "../types/types.h"

namespace io
{
	void start();
	SensorType getSensorType();
	TempRawValue getTempRawValue();
	VoltageRawValue getVoltageRawValue();
	int getPercentRawValue();

	void printSensorConversion(NormalizedValue value, SensorType type);

	namespace errors
	{
		void printGetSensorTypeError();
		void printGetTempRawValue();
		void printGetVoltageRawValue();
		void printGetPercentRawValue();
	}

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif