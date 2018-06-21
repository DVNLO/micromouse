#ifndef MICROMOUSE_UTILITY_H
#define MICROMOUSE_UTILITY_H
#include <string>

namespace Utility
{
	bool isValidDigitalPinValue(const int& pin_value);
	bool isValidPinIndex(const int& pin_value);

	const extern std::string INVALID_DIGITAL_PIN_VALUE;
	const extern std::string INVALID_PIN_INDEX;
	const extern int GPIO_MIN_PIN_INDEX;
	const extern int GPIO_MAX_PIN_INDEX;
	const extern int WIRING_PI_ERROR;
}

#endif // MICROMOUSE_UTILITY_H