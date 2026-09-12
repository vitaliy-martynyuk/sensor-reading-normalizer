#ifndef VALIDATE_H
#define VALIDATE_H

#include "../types/types.h"

namespace validate
{
	bool isSensorTypeValid(SensorType type);
	bool isTempRawValueValid(TempRawValue value);
	bool isVoltageRawValueValid(VoltageRawValue value);
	bool isPercentRawValueValid(int value);
}

#endif