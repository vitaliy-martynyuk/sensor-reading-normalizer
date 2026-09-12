#ifndef CONSTS_H
#define CONSTS_H

#include <string_view>

namespace constants
{
	using std::string_view;

	namespace type
	{
		constexpr char tempCode{ 'T' };
		constexpr char voltageCode{ 'V' };
		constexpr char percentCode{ 'P' };

		constexpr string_view tempLabel{ "Temperature" };
		constexpr string_view voltageLabel{ "Voltage" };
		constexpr string_view percentLabel{ "Percent" };
	}
}

#endif