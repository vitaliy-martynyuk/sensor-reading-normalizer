#ifndef SESSION_H
#define SESSION_H

#include "../types/types.h"

namespace session
{
	SensorType setSensorType();
	TempRawValue setTempRawValue();
	VoltageRawValue setVoltageRawValue();
	PercentRawValue setPercentRawValue();
}

#endif