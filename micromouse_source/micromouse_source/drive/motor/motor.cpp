#include "motor.h"
#include "motor_constants.h"
#include "../../utility/utility.h"
#include <stdexcept>
#include <wiringPi.h>

/*
Default constructs a motor object. Initializes class
data members pin1_ and pin2_ to DEFAULT_PIN.
*/
Drive::Motor::Motor() 
{
	pin1_ = DEFAULT_PIN;
	pin2_ = DEFAULT_PIN;
}

/*
Constructs a motor object using pin1 and pin2 arguments.
*/
Drive::Motor::Motor(const int& pin1, const int& pin2)
{
	setPins(pin1, pin2);
}

/*
Calls setPin() to assign pins to pin1 and pin2.
*/
void Drive::Motor::setPins(const int& pin1, const int& pin2)
{
	setPin(PIN_ONE_ID, pin1);
	setPin(PIN_TWO_ID, pin2);
}

/*
Assigns class data member pin1_ or pin2_ to pin. Utilizes
pin_id to determine which data member to assign pin too. 
Throws invalid_argument exception when an invalid pin
or an invalid pin_id is found.
*/
void Drive::Motor::setPin(const int& pin_id, const int& pin)
{
	if (!Utility::isValidPin(pin))
		throw std::invalid_argument(Utility::INVALID_PIN);
	if (pin_id == PIN_ONE_ID)
		pin1_ = pin;
	else if (pin_id == PIN_TWO_ID)
		pin2_ = pin;
	else
		throw std::invalid_argument(INVALID_MOTOR_PIN_ID);
}

/*
Returns true when both pins have a value between 0 and 40, inclusive.
*/
bool Drive::Motor::isInitialized() const
{
	return !(pin1_ < Utility::GPIO_MIN_PIN_INDEX || pin1_ > Utility::GPIO_MAX_PIN_INDEX ||
		pin2_ < Utility::GPIO_MIN_PIN_INDEX || pin2_ > Utility::GPIO_MAX_PIN_INDEX);
}

/*
Validates motor initialization by calliing isInitialized().
Throws runtime_error if motor is not initialized. 
*/
void Drive::Motor::validateInitialization() const
{
	if (!isInitialized())
		throw std::runtime_error(INVALID_STATE_PIN_NOT_SET);
}

/*
Returns true when the motor's current state is equal to desired_state.
Throws a runtime_error exception when states are not equal.
*/
bool Drive::Motor::isCurrentState(const Drive::State& desired_state) const
{
	if (readState() == desired_state)
		return true;
	else
		throw std::runtime_error(INVALID_STATE_DIFFERENCE);
}

/*
Returns State read on pins.
*/
Drive::State Drive::Motor::readState() const
{
	validateInitialization();
	State read_state;
	try
	{
		read_state.pin1_value = digitalRead(pin1_);
		read_state.pin2_value = digitalRead(pin2_);
	}
	catch (...)
	{
		throw std::runtime_error(FAILURE_TO_READ_STATE);
	}
	return read_state;
}

/*
Writes State on digital_pins. 
*/
void Drive::Motor::writeState(const State& desired_state) const
{
	validateInitialization();
	pinMode(pin1_, OUTPUT);
	pinMode(pin2_, OUTPUT);
	digitalWrite(pin1_, desired_state.pin1_value);
	digitalWrite(pin2_, desired_state.pin2_value);
	if (!isCurrentState(desired_state))
	{
		throw std::runtime_error(FAILURE_TO_WRITE_STATE);
	}
}

/*
Rotates motor forward.
*/
void Drive::Motor::forward() const
{
	rotate(FORWARD);
}

/*
Rotates motor backward.
*/
void Drive::Motor::backward() const
{
	rotate(BACKWARD);
}

/*
Short brakes motor.
*/
void Drive::Motor::shortBrake()
{
	rotate(SHORT_BRAKE);
}

/*
Stops motor.
*/
void Drive::Motor::stop() const
{
	rotate(STOP);
}

/*
Writes a desired_state to the motor.
*/
void Drive::Motor::rotate(const Drive::State& desired_state) const
{
	writeState(desired_state);
}