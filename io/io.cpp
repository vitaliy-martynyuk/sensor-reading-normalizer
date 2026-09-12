#include "io.h"
#include <iostream>
#include <limits>
#include <cstdlib>

namespace io
{
	using std::cin;
	using std::cout;
	using std::numeric_limits;
	using std::streamsize;

	SensorType getSensorType()
	{
		cout << "=== Sensor Reading Normalizer ===\n";
		cout << "Select sensor type (T = Temp millidegrees, V = Voltage, P = Percent byte): ";
		SensorType input{};
		cin >> input;

		return input;
	}

	TempRawValue getTempRawValue()
	{
		cout << "Enter raw sensor value: ";
		TempRawValue input{};
		cin >> input;

		return input;
	}

	VoltageRawValue getVoltageRawValue()
	{
		cout << "Enter raw sensor value: ";
		VoltageRawValue input{};
		cin >> input;

		return input;
	}

	RercentRawValue getRercentRawValue()
	{
		cout << "Enter raw sensor value: ";
		RercentRawValue input{};
		cin >> input;

		return input;
	}

	namespace helpers
	{
		bool recoverInputStream()
		{
			const bool hasUnextractedInput{ !cin.eof() && cin.peek() != '\n' };
			if (!cin || hasUnextractedInput) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				return true;
			}

			return false;
		}
	}
}