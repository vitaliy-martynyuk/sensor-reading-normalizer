#include "session/session.h"
#include "consts/consts.h"
#include <iostream>
#include <cassert>

int main()
{
	io::start();

	const SensorType type{ session::setSensorType() };
	PercentRawValue percentValue{};
	TempRawValue tempValue{};
	VoltageRawValue voltageValue{};

	switch (type) {
	case constants::type::percentCode:
		percentValue = session::setPercentRawValue();
		std::cout << type << ' ' << percentValue << '\n';
		break;
	case constants::type::tempCode:
		tempValue = session::setTempRawValue();
		std::cout << type << ' ' << tempValue << '\n';
		break;
	case constants::type::voltageCode:
		voltageValue = session::setVoltageRawValue();
		std::cout << type << ' ' << voltageValue << '\n';
		break;
	default:
		assert(false && "Invalid sensor type");
	}

	return 0;
}