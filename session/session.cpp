#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"
#include <iostream>

namespace session
{
	using std::cout;
	using io::helpers::recoverInputStream;

	SensorType setSensorType()
	{
		while (true) {
			SensorType type{ io::getSensorType() };

			if (recoverInputStream() || !validate::isSensorTypeValid(type)) {
				io::errors::printGetSensorTypeError();
				continue;
			}
			cout << '\n';

			return type;
		}
	}

	TempRawValue setTempRawValue()
	{
		while (true) {
			TempRawValue value{ io::getTempRawValue() };

			if (recoverInputStream() || !validate::isTempRawValueValid(value)) {
				io::errors::printGetTempRawValue();
				continue;
			}
			cout << '\n';

			return value;
		}
	}

	VoltageRawValue setVoltageRawValue()
	{
		while (true) {
			VoltageRawValue value{ io::getVoltageRawValue() };

			if (recoverInputStream() || !validate::isVoltageRawValueValid(value)) {
				io::errors::printGetVoltageRawValue();
				continue;
			}
			cout << '\n';

			return value;
		}
	}

	PercentRawValue setPercentRawValue()
	{
		while (true) {
			int value{ io::getPercentRawValue() };

			if (recoverInputStream() || !validate::isPercentRawValueValid(value)) {
				io::errors::printGetPercentRawValue();
				continue;
			}
			cout << '\n';

			return static_cast<PercentRawValue>(value);
		}
	}
}