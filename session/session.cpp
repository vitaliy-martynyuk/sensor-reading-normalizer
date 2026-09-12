#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"
#include "../consts/consts.h"
#include <iostream>

namespace session
{
	using std::cout;

	SensorType setSensorType()
	{
		while (true) {
			SensorType type{ io::getSensorType() };

			if (io::helpers::recoverInputStream() || !validate::isSensorTypeValid(type)) {
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

			if (io::helpers::recoverInputStream() || !validate::isTempRawValueValid(value)) {
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

			if (io::helpers::recoverInputStream() || !validate::isVoltageRawValueValid(value)) {
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
			PercentRawValue value{ io::getPercentRawValue() };

			if (io::helpers::recoverInputStream() || !validate::isPercentRawValueValid(value)) {
				io::errors::printGetPercentRawValue();
				continue;
			}

			cout << '\n';

			return value;
		}
	}
}