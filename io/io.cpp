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

	void start()
	{
		cout << "=== Sensor Reading Normalizer ===\n";
	}

	SensorType getSensorType()
	{
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

	int getPercentRawValue()
	{
		cout << "Enter raw sensor value: ";
		int input{};
		cin >> input;

		return input;
	}

	namespace errors
	{
		void printGetSensorTypeError()
		{
			cout << "Invalid sensor type! (must be T = Temp millidegrees, V = Voltage, P = Percent byte)\n";
		}

		void printGetTempRawValue()
		{
			cout << "Invalid raw value for Temperature (millidegrees) sensor (expected 0-999999)\n";
		}

		void printGetVoltageRawValue()
		{
			cout << "Invalid raw value for Voltage sensor (expected 0.01-99.9)\n";
		}

		void printGetPercentRawValue()
		{
			cout << "Invalid raw value for Percent sensor (expected 0-255)\n";
		}
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