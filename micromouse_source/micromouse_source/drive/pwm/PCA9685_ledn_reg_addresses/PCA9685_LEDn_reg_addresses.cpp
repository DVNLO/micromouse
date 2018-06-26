#include "PCA9685_LEDn_reg_addresses.h"
#include <stdexcept>

drive::pwm::PCA9685_LEDn_reg_addresses::PCA9685_LEDn_reg_addresses()
{
	LEDN_ON_L_REG_ADDRESS = PCA9685::PCA9685_REG_LED0_ON_L;
	LEDN_ON_H_REG_ADDRESS = PCA9685::PCA9685_REG_LED0_ON_H;
	LEDN_OFF_L_REG_ADDRESS = PCA9685::PCA9685_REG_LED0_OFF_L;
	LEDN_OFF_H_REG_ADDRESS = PCA9685::PCA9685_REG_LED0_OFF_H;
}

drive::pwm::PCA9685_LEDn_reg_addresses::PCA9685_LEDn_reg_addresses(const uint_fast8_t& output_channel)
{
	if (!PCA9685::isValidOutputChannel(output_channel))
	{
		throw std::out_of_range(PCA9685::DUTY_CYCLE_OUT_OF_RANGE);
	}
	uint_fast8_t channel_address_offset = static_cast<uint_fast8_t>(4 * output_channel);
	LEDN_ON_L_REG_ADDRESS = static_cast<uint_fast8_t>(PCA9685::PCA9685_REG_LED0_ON_L + channel_address_offset);
	LEDN_ON_H_REG_ADDRESS = static_cast<uint_fast8_t>(PCA9685::PCA9685_REG_LED0_ON_H + channel_address_offset);
	LEDN_OFF_L_REG_ADDRESS = static_cast<uint_fast8_t>(PCA9685::PCA9685_REG_LED0_OFF_L + channel_address_offset);
	LEDN_OFF_H_REG_ADDRESS = static_cast<uint_fast8_t>(PCA9685::PCA9685_REG_LED0_OFF_H + channel_address_offset);
}

uint_fast8_t drive::pwm::PCA9685_LEDn_reg_addresses::get_ON_L() const
{
	return LEDN_ON_L_REG_ADDRESS;
}

uint_fast8_t drive::pwm::PCA9685_LEDn_reg_addresses::get_ON_H() const
{
	return LEDN_ON_H_REG_ADDRESS;
}

uint_fast8_t drive::pwm::PCA9685_LEDn_reg_addresses::get_OFF_L() const
{
	return LEDN_OFF_L_REG_ADDRESS;
}

uint_fast8_t drive::pwm::PCA9685_LEDn_reg_addresses::get_OFF_H() const
{
	return LEDN_OFF_H_REG_ADDRESS;
}