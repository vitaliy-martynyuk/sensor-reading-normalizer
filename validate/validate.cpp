#include "validate.h"

namespace validate
{
	bool isSensorTypeValid(SensorType type)
	{
		switch (type) {
		case constants::type::tempCode:
		case constants::type::voltageCode:
		case constants::type::percentCode:
			return true;
		default:
			return false;
		}
	}

	bool isTempRawValueValid(TempRawValue value)
	{
		return (value >= 0) && (value <= 999999);
	}

	bool isVoltageRawValueValid(VoltageRawValue value)
	{
		return (value >= static_cast<VoltageRawValue>(0.01))
			&& (value <= static_cast<VoltageRawValue>(99.9));
	}

	bool isPercentRawValueValid(int value)
	{
		return (value >= 0) && (value <= 255);
	}
}