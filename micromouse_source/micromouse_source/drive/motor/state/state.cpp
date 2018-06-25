#include "state.h"
#include "../../../utility/utility.h"
#include <stdexcept>
#include <wiringPi.h>

Drive::State::State() 
{
	pin1_value = LOW;
	pin2_value = LOW;
}

Drive::State::State(const int& value1, const int& value2)
{
	if (Utility::isValidDigitalPinValue(value1) && Utility::isValidDigitalPinValue(value2))
	{
		pin1_value = value1;
		pin2_value = value2;
	}
	else
	{
		throw std::invalid_argument(Utility::INVALID_DIGITAL_PIN_VALUE);
	}
}

bool Drive::operator==(const Drive::State& left, const Drive::State& right)
{
	return !(
		(left.pin1_value != right.pin1_value) ||
		(left.pin2_value != right.pin2_value)
		);
}

bool Drive::operator!=(const Drive::State& left, const Drive::State& right)
{
	return !(left == right);
}