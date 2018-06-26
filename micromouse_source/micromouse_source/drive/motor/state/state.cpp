#include "State.h"
#include "../../../utility/Utility.h"
#include <stdexcept>
#include <wiringPi.h>

drive::motor::State::State() 
{
	pin1_value = LOW;
	pin2_value = LOW;
}

drive::motor::State::State(const int& value1, const int& value2)
{
	if (utility::isValidDigitalPinValue(value1) && utility::isValidDigitalPinValue(value2))
	{
		pin1_value = value1;
		pin2_value = value2;
	}
	else
	{
		throw std::invalid_argument(utility::INVALID_DIGITAL_PIN_VALUE);
	}
}

bool drive::motor::operator==(const drive::motor::State& left, const drive::motor::State& right)
{
	return !(
		(left.pin1_value != right.pin1_value) ||
		(left.pin2_value != right.pin2_value)
		);
}

bool drive::motor::operator!=(const drive::motor::State& left, const drive::motor::State& right)
{
	return !(left == right);
}