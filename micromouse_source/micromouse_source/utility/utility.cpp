#include "Utility.h"
#include <wiringPi.h>

const std::string utility::INVALID_DIGITAL_PIN_VALUE = "invalid digital pin value";
const std::string utility::INVALID_PIN = "invalid pin";
const uint_fast8_t utility::GPIO_MIN_PIN_INDEX = 0;
const uint_fast8_t utility::GPIO_MAX_PIN_INDEX = 40;
const int_fast16_t utility::WIRING_PI_ERROR = -1;

bool utility::isValidDigitalPinValue(const uint_fast8_t& pin_value)
{
	return ((pin_value == HIGH) || (pin_value == LOW));
}

bool utility::isValidPin(const int_fast8_t& pin)
{
	return (pin >= GPIO_MIN_PIN_INDEX && pin <= GPIO_MAX_PIN_INDEX);
}