#include "VL6180X.h"
#include "../utility/Utility.h"
#include <stdexcept>
#include <wiringPi.h>
#include <wiringPiI2C.h>

/*
Default initialize to an erronous state.
*/
sense::VL6180X::VL6180X()
{
	file_descriptor_ = utility::WIRING_PI_ERROR;
}

/*
Sets file_descriptor_ for default initialized objects.
*/
void sense::VL6180X::setup(const uint_fast8_t& device_id)
{
	if (file_descriptor_ == utility::WIRING_PI_ERROR)
	{
		file_descriptor_ = wiringPiI2CSetup(device_id);
	}
}

/*
Initializes file descriptor via wiringPiI2CSetup() from a supplied device id.
wiringPiI2CSetup() returns a linux default file descriptor handle.
*/
sense::VL6180X::VL6180X(const uint_fast8_t& device_id)
{
	file_descriptor_ = wiringPiI2CSetup(device_id);
	if (file_descriptor_ == utility::WIRING_PI_ERROR)
	{
		throw std::runtime_error(utility::FAILURE_TO_SETUP_I2C);
	}
}