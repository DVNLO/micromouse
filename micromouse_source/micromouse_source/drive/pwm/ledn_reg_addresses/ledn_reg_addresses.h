#ifndef MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H
#define MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H
#include <string>

namespace Drive
{
	struct PCA9685_LEDN_REG_ADDRESSES
	{
		unsigned char LEDN_ON_L_REG_ADDRESS;
		unsigned char LEDN_ON_H_REG_ADDRESS;

		unsigned char LEDN_OFF_L_REG_ADDRESS;
		unsigned char LEDN_OFF_H_REG_ADDRESS;
	};
}


#endif // MICROMOUSE_PWM_LEDN_REG_ADDRESSES_H