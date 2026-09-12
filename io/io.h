#ifndef IO_H
#define IO_H

#include <cstdint>

using SensorType = char;
using TempRawValue = std::int32_t;
using VoltageRawValue = float;
using RercentRawValue = std::uint8_t;

namespace io
{
	SensorType getSensorType();
	TempRawValue getTempRawValue();
	VoltageRawValue getVoltageRawValue();
	RercentRawValue getRercentRawValue();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif