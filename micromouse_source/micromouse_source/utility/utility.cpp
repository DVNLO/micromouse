#include "Utility.h"
#include <wiringPi.h>
#include <string>

const std::string utility::INVALID_DIGITAL_PIN_VALUE = "invalid digital pin value";
const std::string utility::INVALID_PIN = "invalid pin";
const int utility::GPIO_MIN_PIN_INDEX = 0;
const int utility::GPIO_MAX_PIN_INDEX = 40;
const int utility::WIRING_PI_ERROR = -1;

bool utility::isValidDigitalPinValue(const int& pin_value)
{
	return ((pin_value == HIGH) || (pin_value == LOW));
}

bool utility::isValidPin(const int& pin)
{
	return (pin >= GPIO_MIN_PIN_INDEX && pin <= GPIO_MAX_PIN_INDEX);
}