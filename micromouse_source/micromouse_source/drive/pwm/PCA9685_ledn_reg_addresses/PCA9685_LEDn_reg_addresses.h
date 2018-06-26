#ifndef MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H
#define MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H
#include "../PCA9685.h"
#include <cstdint>
#include <string>

namespace drive
{
	namespace pwm
	{
		struct PCA9685_LEDn_reg_addresses
		{
		private:
			uint_fast8_t LEDN_ON_L_REG_ADDRESS;
			uint_fast8_t LEDN_ON_H_REG_ADDRESS;
			uint_fast8_t LEDN_OFF_L_REG_ADDRESS;
			uint_fast8_t LEDN_OFF_H_REG_ADDRESS;
		public:
			PCA9685_LEDn_reg_addresses();
			PCA9685_LEDn_reg_addresses(const uint_fast8_t& output_channel);
			uint_fast8_t get_ON_L() const;
			uint_fast8_t get_ON_H() const;
			uint_fast8_t get_OFF_L() const;
			uint_fast8_t get_OFF_H() const;
		};
	}
}


#endif // MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H