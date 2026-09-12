#include "session/session.h"
#include "consts/consts.h"
#include <iostream>
#include <cassert>

int main()
{
	io::start();

	const SensorType type{ session::setSensorType() };
	NormalizedValue value{};

	switch (type) {
	case constants::type::percentCode:
		value = static_cast<NormalizedValue>(session::setPercentRawValue());
		break;
	case constants::type::tempCode:
		value = static_cast<NormalizedValue>(session::setTempRawValue());
		break;
	case constants::type::voltageCode:
		value = static_cast<NormalizedValue>(session::setVoltageRawValue());
		break;
	default:
		assert(false && "Invalid sensor type");
	}

	io::printSensorConversion(value, type);

	return 0;
}