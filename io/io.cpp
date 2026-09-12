#include "io.h"
#include <iostream>
#include <limits>

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

	RawSensorValue getSensorRawValue()
	{
		cout << "Enter raw sensor value: ";
		RawSensorValue input{};
		cin >> input;

		return input;
	}

	namespace helpers
	{
		bool recoverInputStream()
		{
			const bool hasUnextractedInput{ !cin.eof() && cin.peek() != '\n' };
			if (!cin || hasUnextractedInput) {
				if (cin.eof()) {
					std::exit(1);
				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				return true;
			}

			return false;
		}
	}
}