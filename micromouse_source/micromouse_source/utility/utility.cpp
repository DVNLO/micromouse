#include "utility.h"
#include <wiringPi.h>
#include <string>

const std::string Utility::INVALID_DIGITAL_PIN_VALUE = "invalid digital pin value";
const std::string Utility::INVALID_PIN = "invalid pin";
const int Utility::GPIO_MIN_PIN_INDEX = 0;
const int Utility::GPIO_MAX_PIN_INDEX = 40;
const int Utility::WIRING_PI_ERROR = -1;

bool Utility::isValidDigitalPinValue(const int& pin_value)
{
	return ((pin_value == HIGH) || (pin_value == LOW));
}

bool Utility::isValidPin(const int& pin)
{
	return (pin >= GPIO_MIN_PIN_INDEX && pin <= GPIO_MAX_PIN_INDEX);
}