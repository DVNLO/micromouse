#include "../Motor.h"
#include "State.h"
#include "../../../utility/Utility.h"
#include <stdexcept>
#include <wiringPi.h>

drive::motor::State::State() 
{
	pin1_value = LOW;
	pin2_value = LOW;
}

drive::motor::State::State(const uint_fast8_t& pin1_value_in, const uint_fast8_t& pin2_value_in)
{
	setPin(drive::motor::Motor::PIN_ONE_ID, pin1_value_in);
	setPin(drive::motor::Motor::PIN_TWO_ID, pin2_value_in);
}

void drive::motor::State::setPin1(const uint_fast8_t& value)
{
	setPin(drive::motor::Motor::PIN_ONE_ID, value);
}

void drive::motor::State::setPin2(const uint_fast8_t& value)
{
	setPin(drive::motor::Motor::PIN_TWO_ID, value);
}

void drive::motor::State::setPin(const uint_fast8_t& id, const uint_fast8_t& value)
{
	if (!utility::isValidDigitalPinValue(value))
		throw std::invalid_argument(utility::INVALID_DIGITAL_PIN_VALUE);
	if (id == drive::motor::Motor::PIN_ONE_ID)
		pin1_value = value;
	else if (id == drive::motor::Motor::PIN_TWO_ID)
		pin2_value = value;
}

uint_fast8_t drive::motor::State::getPin1() const
{
	return pin1_value;
}

uint_fast8_t drive::motor::State::getPin2() const
{
	return pin2_value;
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