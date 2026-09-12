# Sensor Reading Normalizer

A small C++ console utility that reads a raw sensor reading — in whatever
native format that sensor reports (integer millidegrees, a float voltage,
or a raw byte percentage) — validates it, and converts it into a single
normalized reading with a clear, printed account of the conversion path
it took.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 10: implicit vs. explicit conversions, narrowing conversions,
type aliases, and `auto`. Earlier fundamentals (multi-file structure,
validation, stream-failure recovery, retry loops) are used as supporting
scaffolding, not the focus.

## What it does

- Prompts for a sensor type (`T` = Temperature, `V` = Voltage, `P` =
  Percent) and, based on that, a raw value in that sensor's native format
- Recovers from invalid or malformed console input and reprompts, rather
  than crashing or hanging
- Reads and validates each sensor's raw value in its natural type —
  `std::int32_t` for temperature, `float` for voltage, a validated `int`
  narrowed down to `std::uint8_t` for percent — before converting any of
  them into a shared normalized `double` reading
- Applies the correct scaling for each sensor (divide millidegrees by
  1000, divide a percent byte by 255, or no scaling at all for voltage,
  which is already in target units) and prints the conversion path taken

## Project structure

```
main.cpp                    // program entry point, orchestrates the flow
io/
  io.h / io.cpp             // reading raw input, printing errors/results,
                            //   and stream-failure recovery
validate/
  validate.h / .cpp         // isXValid() checks for each sensor's raw value
session/
  session.h / .cpp          // read+validate+retry loops per sensor type
consts/
  consts.h                  // sensor type codes and display labels
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp validate/validate.cpp session/session.cpp
```

Or open `Sensor Reading Normalizer.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
=== Sensor Reading Normalizer ===
Select sensor type (T = Temp millidegrees, V = Voltage, P = Percent byte): T
Enter raw sensor value: 21500

Conversion: 21500 millidegrees -> 21.5 degrees
Normalized reading: 21.5
```

## Notes

`TempRawValue`, `VoltageRawValue`, `PercentRawValue`, and `NormalizedValue`
are named type aliases used throughout function signatures to keep each
sensor's native representation visible at the point of use. The percent
sensor's raw value is read as a plain `int` and validated against its
real 0–255 range *before* being narrowed down to `PercentRawValue`
(`std::uint8_t`) — a deliberate, justified narrowing conversion, chosen
specifically because reading directly into a `uint8_t` causes `std::cin`
to treat it as a character rather than a number. Widening conversions
into the shared `NormalizedValue` (`double`) are always safe and lossless
regardless of the sensor's native type.