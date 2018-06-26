#ifndef MICROMOUSE_PCA9685_H
#define MICROMOUSE_PCA9685_H
#include <string>

namespace drive
{
	namespace pwm
	{
		class PCA9685
		{
		public:
			PCA9685();
			PCA9685(const int& device_id);
			void setup(const int& device_id);
			void setFrequency(const int& frequency) const;
			int getFrequency() const;
			void setDuty(const unsigned char& output_channel, const unsigned char& duty_cycle) const;
			unsigned char getDuty(const unsigned char& output_channel) const;
			void sleep() const;
			void restart() const;
			bool isAsleep() const;

		private:
			int file_descriptor_;

			void setPreScale(const int& frequency) const;
			int getPreScale() const;

			unsigned char readRegister8(const unsigned char& register_address) const;
			void writeRegister8(const unsigned char& register_address, const unsigned char& data) const;

		public:

			const static unsigned char PCA9685_REG_MODE1;
			const static unsigned char PCA9685_REG_MODE2;
			const static unsigned char PCA9685_REG_SUBADDR1;
			const static unsigned char PCA9685_REG_SUBADDR2;
			const static unsigned char PCA9685_REG_SUBADDR3;
			const static unsigned char PCA9685_REG_ALLCALLADDR;

			const static unsigned char PCA9685_REG_LED0_ON_L;
			const static unsigned char PCA9685_REG_LED0_ON_H;
			const static unsigned char PCA9685_REG_LED0_OFF_L;
			const static unsigned char PCA9685_REG_LED0_OFF_H;

			const static unsigned char PCA9685_REG_ALL_LED_ON_L;
			const static unsigned char PCA9685_REG_ALL_LED_ON_H;
			const static unsigned char PCA9685_REG_ALL_LED_OFF_L;
			const static unsigned char PCA9685_REG_ALL_LED_OFF_H;
			const static unsigned char PCA9685_REG_PRESCALE;

			const static unsigned char PCA9685_SWRST;

			const static unsigned char PCA9685_PRESCALE_MIN;
			const static unsigned char PCA9685_PRESCALE_MAX;
			const static int PCA9685_FREQ_MIN;
			const static int PCA9685_FREQ_MAX;

			const static int PCA9685_COUNTER_RANGE;
			const static int PCA9685_DEFAULT_PERIOD;
			const static double PCA9685_OSC_CLOCK_MHZ;

			const static int PCA9685_OUTPUT_CHANNEL_MIN;
			const static int PCA9685_OUTPUT_CHANNEL_MAX;

			const static unsigned char PCA9685_NUMREGS;
			const static unsigned char PCA9685_MAXCHAN;

			const static unsigned char PCA9685_LED_FULL_ON;
			const static unsigned char PCA9685_MODE1_RESTART;
			const static unsigned char PCA9685_MODE1_SLEEP;
			const static unsigned char PCA9685_MODE2_INVERT;

			const static std::string FAILURE_TO_SETUP_I2C;
			const static std::string FAILURE_TO_READ_REGISTER8;
			const static std::string FAILURE_TO_WRITE_REGISTER8;

			const static std::string INVALID_FREQUENCY;
			const static std::string OUTPUT_CHANNEL_OUT_OF_RANGE;
			const static std::string DUTY_CYCLE_OUT_OF_RANGE;
		};
	}
}

#endif // MICROMOUSE_PWM_H