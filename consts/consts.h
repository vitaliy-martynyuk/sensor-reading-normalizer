#ifndef CONSTS_H
#define CONSTS_H

#include <string_view>

namespace constants
{
	using std::string_view;

	namespace type
	{
		constexpr auto tempCode{ 'T' };
		constexpr auto voltageCode{ 'V' };
		constexpr auto percentCode{ 'P' };

		constexpr string_view tempLabel{ "Temperature (millidegrees)" };
		constexpr string_view voltageLabel{ "Voltage" };
		constexpr string_view percentLabel{ "Percent" };
	}
}

#endif