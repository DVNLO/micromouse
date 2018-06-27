#include "PCA9685.h"
#include "PCA9685_ledn_reg_addresses/PCA9685_LEDn_reg_addresses.h"
#include "../../utility/Utility.h"
#include <cmath>
#include <stdexcept>
#include <wiringPi.h>
#include <wiringPiI2C.h>

/*
Default initializes file descriptor handle to an erronous state.
*/
drive::pwm::PCA9685::PCA9685()
{
	file_descriptor_= utility::WIRING_PI_ERROR;
}

/*
Sets file_descriptor_ for default initialized objects.
*/
void drive::pwm::PCA9685::setup(const uint_fast8_t& device_id)
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
drive::pwm::PCA9685::PCA9685(const uint_fast8_t& device_id)
{
	file_descriptor_ = wiringPiI2CSetup(device_id);
	if (file_descriptor_ == utility::WIRING_PI_ERROR)
	{
		throw std::runtime_error(utility::FAILURE_TO_SETUP_I2C);
	}
}

/*
Sets operating frequency.
*/
void drive::pwm::PCA9685::setFrequency(const uint_fast16_t& frequency) const
{
	setPreScale(frequency);
}

/*
Gets the operating frequency.
*/
uint_fast16_t drive::pwm::PCA9685::getFrequency() const
{
	return static_cast<uint_fast16_t>(round(OSC_CLOCK_MHZ / (4096 * (getPreScale() + 1))));
}

/*
Sets the Pre Scale register to the operating frequency.
*/
void drive::pwm::PCA9685::setPreScale(const uint_fast16_t& frequency) const
{
	if (frequency < FREQ_MIN || frequency > FREQ_MAX)
	{
		throw std::invalid_argument(INVALID_FREQUENCY);
	}
	sleep();
	delayMicroseconds(500);	//datasheet spec (section 7.3.1.1)
	writeRegister8(REG_PRESCALE, 
		static_cast<uint_fast8_t>(lround(OSC_CLOCK_MHZ / (4096 * frequency)) - 1));
	wake();
}

/*
Returns a value read from the prescale register.
*/
uint_fast8_t drive::pwm::PCA9685::getPreScale() const
{
	return readRegister8(REG_PRESCALE);
}

/*
Sets duty_cycle(%) on output_channel. Assumes no delay.
*/
void drive::pwm::PCA9685::setDuty(const uint_fast8_t& output_channel, const uint_fast8_t& duty_cycle) const
{
	if (!isValidOutputChannel(output_channel))
	{
		throw std::out_of_range(OUTPUT_CHANNEL_OUT_OF_RANGE);
	}
	else if (!isValidDutyCycle(duty_cycle))
	{
		throw std::out_of_range(DUTY_CYCLE_OUT_OF_RANGE);
	}
	uint_fast16_t on_count = static_cast<uint_fast16_t>(
		lround((static_cast<double>(duty_cycle) / 100) * COUNTER_RANGE));
	
	drive::pwm::PCA9685_LEDn_reg_addresses address_packet(output_channel);
	
	//on
	writeRegister8(address_packet.get_ON_L(), 0x00);
	uint_fast8_t register_data = readRegister8(address_packet.get_ON_H());
	writeRegister8(address_packet.get_ON_H(), register_data & 0xE0);	//write 0's on [0:3] for MSB and [4] for full on
	
	//off
	writeRegister8(address_packet.get_OFF_L(), on_count & 0xFF);	//LSBs
	register_data = readRegister8(address_packet.get_OFF_H()) & 0xE0;
	uint_fast8_t on_count_msb = (on_count >> 8) & 0x0F;
	writeRegister8(address_packet.get_OFF_H(), register_data | on_count_msb);
}

uint_fast8_t drive::pwm::PCA9685::getDuty(const uint_fast8_t& output_channel) const
{
	drive::pwm::PCA9685_LEDn_reg_addresses address_packet(output_channel);
	uint_fast16_t ON = readRegister8(address_packet.get_ON_H()) << 8;
	ON += readRegister8(address_packet.get_ON_L());
	uint_fast16_t OFF = readRegister8(address_packet.get_OFF_H()) << 8;
	OFF += readRegister8(address_packet.get_OFF_L());
	return static_cast<uint_fast8_t>(
		lround((100 * (static_cast<double>(OFF - ON))) / COUNTER_RANGE));
}

/*
Restarts PCA9685 PWM cycle. Preserves all PWM register contents. 
*/
void drive::pwm::PCA9685::restart() const
{
	uint_fast8_t mode1_reg_data = readRegister8(REG_MODE1);
	if (mode1_reg_data & MODE1_RESTART)
	{
		mode1_reg_data = static_cast<uint_fast8_t>(mode1_reg_data & (!MODE1_SLEEP));
		delayMicroseconds(500);	//datasheet spec (section 7.3.1.1)
		writeRegister8(REG_MODE1, mode1_reg_data);
	}
}


/*
Puts PCA9685 to sleep, via writing a logical 1 to mode 1 register bit 4.
*/
void drive::pwm::PCA9685::sleep() const
{
	uint_fast8_t mode1_reg_data = readRegister8(REG_MODE1);
	mode1_reg_data = static_cast<uint_fast8_t>(mode1_reg_data | MODE1_SLEEP);
	writeRegister8(REG_MODE1, mode1_reg_data);
}

/*
Wakes PCA9685, via writing a logical 0 to mode 1 register bit 4.
*/
void drive::pwm::PCA9685::wake() const
{
	uint_fast8_t mode1_reg_data = readRegister8(REG_MODE1);
	mode1_reg_data = static_cast<uint_fast8_t>(mode1_reg_data & !MODE1_SLEEP);
	writeRegister8(REG_MODE1, mode1_reg_data);
}

/*
Returns true when PCA9685 is asleep.
*/
bool drive::pwm::PCA9685::isAsleep() const
{
	return readRegister8(REG_MODE1) & MODE1_SLEEP;
}

/*
Returns true when output_channel is between PCA9685_OUTPUT_CHANNEL_MIN and PCA9685_OUTPUT_CHANNEL_MAX. 
*/
bool drive::pwm::PCA9685::isValidOutputChannel(const uint_fast8_t& output_channel)
{
	return !(output_channel < OUTPUT_CHANNEL_MIN || output_channel > OUTPUT_CHANNEL_MAX);
}

/*
Returns true when duty_cycle is between 0 and 100.
*/
bool drive::pwm::PCA9685::isValidDutyCycle(const uint_fast8_t& duty_cycle)
{
	return !(duty_cycle < 0 || duty_cycle > 100);
}

/*
Reads an 8 bit register. 
*/
uint_fast8_t drive::pwm::PCA9685::readRegister8(const uint_fast8_t& register_address) const
{
	uint_fast8_t reg_data = static_cast<uint_fast8_t>(wiringPiI2CReadReg8(file_descriptor_, register_address));
	if (reg_data == utility::WIRING_PI_ERROR)
		throw std::runtime_error(utility::FAILURE_TO_READ_REGISTER8);
	return reg_data;
}

/*
Writes 8 bits to a register.
*/
void drive::pwm::PCA9685::writeRegister8(const uint_fast8_t& register_address, const uint_fast8_t& data) const
{
	if (wiringPiI2CWriteReg8(file_descriptor_, register_address, data) == utility::WIRING_PI_ERROR)
	{
		throw std::runtime_error(utility::FAILURE_TO_WRITE_REGISTER8);
	}
}
