#ifndef SESSION_H
#define SESSION_H

#include "../io/io.h"

namespace session
{
	SensorType setSensorType();
	TempRawValue setTempRawValue();
	VoltageRawValue setVoltageRawValue();
	PercentRawValue setPercentRawValue();
}

#endif