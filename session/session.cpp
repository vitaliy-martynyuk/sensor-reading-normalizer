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
				cout << "Invalid sensor type! (must be T = Temp millidegrees, V = Voltage, P = Percent byte)\n";
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
				cout << "Invalid raw value for Temperature (millidegrees) sensor (expected 0-999999)\n";
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
				cout << "Invalid raw value for Voltage sensor (expected 0.01-99.9)\n";
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
				cout << "Invalid raw value for Percent sensor (expected 0-255)\n";
				continue;
			}

			cout << '\n';

			return value;
		}
	}
}