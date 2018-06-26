#include "pwm.h"
#include "pwm_constants.h"
#include "../../utility/utility.h"
#include <cmath>
#include <stdexcept>
#include <wiringPi.h>
#include <wiringPiI2C.h>

/*
Default initializes file descriptor handle to an erronous state.
*/
Drive::PWM::PWM()
{
	file_descriptor_= Utility::WIRING_PI_ERROR;
}

/*
Sets file_descriptor_ for default initialized objects.
*/
void Drive::PWM::setup(const int& device_id)
{
	if (file_descriptor_ == Utility::WIRING_PI_ERROR)
	{
		file_descriptor_ = wiringPiI2CSetup(device_id);
	}
}

/*
Initializes file descriptor via wiringPiI2CSetup() from a supplied device id.
wiringPiI2CSetup() returns a linux default file descriptor handle.
*/
Drive::PWM::PWM(const int& device_id)
{
	file_descriptor_ = wiringPiI2CSetup(device_id);
	if (file_descriptor_ == Utility::WIRING_PI_ERROR)
	{
		throw std::runtime_error(FAILURE_TO_SETUP_I2C);
	}
}

/*
Sets operating frequency.
*/
void Drive::PWM::setFrequency(const int& frequency) const
{
	setPreScale(frequency);
}

/*
Gets the operating frequency.
*/
int Drive::PWM::getFrequency() const
{
	return static_cast<int>(round(PCA9685_OSC_CLOCK_MHZ / (4096 * (getPreScale() + 1))));
}

/*
Sets the Pre Scale register to the operating frequency.
*/
void Drive::PWM::setPreScale(const int& frequency) const
{
	if (frequency < PCA9685_FREQ_MIN || frequency > PCA9685_FREQ_MAX)
	{
		throw std::invalid_argument(INVALID_FREQUENCY);
	}
	sleep();
	int prescale_value = static_cast<int>(lround(PCA9685_OSC_CLOCK_MHZ / (4096 * frequency)) - 1);
	writeRegister8(PCA9685_REG_PRESCALE, prescale_value);
	restart();
}

/*
Returns a value read from the prescale register.
*/
int Drive::PWM::getPreScale() const
{
	return readRegister8(PCA9685_REG_PRESCALE);
}

/*

*/
void Drive::PWM::setDuty(const unsigned char& output_channel, const unsigned char& duty_cycle) const
{
	if (output_channel < PCA9685_OUTPUT_CHANNEL_MIN || output_channel > PCA9685_OUTPUT_CHANNEL_MAX)
	{
		throw std::out_of_range(OUTPUT_CHANNEL_OUT_OF_RANGE);
	}
	if (duty_cycle < 0 || duty_cycle > 100)
	{
		throw std::out_of_range(DUTY_CYCLE_OUT_OF_RANGE);
	}
	unsigned int on_count = lround((static_cast<double>(duty_cycle) / 100) * PCA9685_COUNTER_RANGE);
	unsigned int channel_address_offset = 4 * output_channel;
	unsigned char LEDN_ON_H_REG_ADDRESS = static_cast<unsigned char>(PCA9685_REG_LED0_ON_H + channel_address_offset);
	unsigned char LEDN_ON_L_REG_ADDRESS = static_cast<unsigned char>(PCA9685_REG_LED0_ON_L + channel_address_offset);
	unsigned char LEDN_OFF_H_REG_ADDRESS = static_cast<unsigned char>(PCA9685_REG_LED0_OFF_H + channel_address_offset);
	unsigned char LEDN_OFF_L_REG_ADDRESS = static_cast<unsigned char>(PCA9685_REG_LED0_OFF_L + channel_address_offset);
		
	writeRegister8(LEDN_ON_L_REG_ADDRESS, 0x00);	//ie: https://www.miniwebtool.com/bitwise-calculator/?data_type=2&number1=10110110&number2=11110000&operator=AND
	writeRegister8(LEDN_ON_H_REG_ADDRESS, 0x0);	//write 0's on [0:3] for MSB

	writeRegister8(LEDN_OFF_L_REG_ADDRESS, on_count & 0xFF);
	writeRegister8(LEDN_OFF_H_REG_ADDRESS, on_count >> 8);	//write on_count_msb on [0:3]
}

/*
Restarts PCA9685 PWM cycle. Preserves all PWM register contents. 
*/
void Drive::PWM::restart() const
{
	unsigned char mode1_reg_data = readRegister8(PCA9685_REG_MODE1);
	if (mode1_reg_data >> 7)
	{
		mode1_reg_data &= 0xEF;
	}
	delayMicroseconds(500);	//datasheet spec (section 7.3.1.1)
	writeRegister8(PCA9685_REG_MODE1, mode1_reg_data);
}


/*
Puts PCA9685 to sleep, via writing a logical 1 to mode 1 register bit 4.
*/
void Drive::PWM::sleep() const
{
	writeRegister8(PCA9685_REG_MODE1, readRegister8(PCA9685_REG_MODE1) | PCA9685_MODE1_SLEEP);
}

/*
Returns true when PCA9685 is asleep.
*/
bool Drive::PWM::isAsleep() const
{
	return readRegister8(PCA9685_REG_MODE1) & PCA9685_MODE1_SLEEP;
}

/*
Reads an 8 bit register. 
*/
unsigned char Drive::PWM::readRegister8(const unsigned char& register_address) const
{
	unsigned char reg_data = static_cast<unsigned char>(wiringPiI2CReadReg8(file_descriptor_, register_address));
	if (reg_data == Utility::WIRING_PI_ERROR)
		throw std::runtime_error(FAILURE_TO_READ_REGISTER8);
	return reg_data;
}

/*
Writes 8 bits to a register.
*/
void Drive::PWM::writeRegister8(const unsigned char& register_address, const unsigned char& data) const
{
	if (wiringPiI2CWriteReg8(file_descriptor_, register_address, data) == Utility::WIRING_PI_ERROR)
	{
		throw std::runtime_error(FAILURE_TO_WRITE_REGISTER8);
	}
}
