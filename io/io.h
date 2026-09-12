#ifndef IO_H
#define IO_H

#include <cstdint>

using SensorType = char;
using TempRawValue = std::int32_t;
using VoltageRawValue = float;
using PercentRawValue = std::uint8_t;

namespace io
{
	void start();
	SensorType getSensorType();
	TempRawValue getTempRawValue();
	VoltageRawValue getVoltageRawValue();
	PercentRawValue getPercentRawValue();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif