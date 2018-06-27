#ifndef MICROMOUSE_UTILITY_H
#define MICROMOUSE_UTILITY_H
#include <cstdint>
#include <string>

namespace utility
{
	bool isValidDigitalPinValue(const uint_fast8_t& pin_value);
	bool isValidPin(const int_fast8_t& pin);

	const extern std::string INVALID_DIGITAL_PIN_VALUE;
	const extern std::string INVALID_PIN;
	const extern std::string FAILURE_TO_SETUP_I2C;
	const extern std::string FAILURE_TO_READ_REGISTER8;
	const extern std::string FAILURE_TO_WRITE_REGISTER8;

	const extern uint_fast8_t GPIO_MIN_PIN_INDEX;
	const extern uint_fast8_t GPIO_MAX_PIN_INDEX;
	const extern int_fast16_t WIRING_PI_ERROR;
}

#endif // MICROMOUSE_UTILITY_H
