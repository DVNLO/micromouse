#ifndef MICROMOUSE_PCA9685_H
#define MICROMOUSE_PCA9685_H
#include <cstdint>
#include <string>

namespace drive
{
	namespace pwm
	{
		class PCA9685
		{
		public:
			PCA9685();
			PCA9685(const uint_fast8_t& device_id);
			void setup(const uint_fast8_t& device_id);
			void setFrequency(const uint_fast16_t& frequency) const;
			uint_fast16_t getFrequency() const;
			void setDuty(const uint_fast8_t& output_channel, const uint_fast8_t& duty_cycle) const;
			uint_fast8_t getDuty(const uint_fast8_t& output_channel) const;
			bool isAsleep() const;
			void sleep() const;
			void wake() const;
			void restart() const;
			static bool isValidOutputChannel(const uint_fast8_t& output_channel);
			static bool isValidDutyCycle(const uint_fast8_t& duty_cycle);

		private:
			int_fast16_t file_descriptor_;

			void setPreScale(const uint_fast16_t& frequency) const;
			uint_fast8_t getPreScale() const;

			uint_fast8_t readRegister8(const uint_fast8_t& register_address) const;
			void writeRegister8(const uint_fast8_t& register_address, const uint_fast8_t& data) const;

		public:
			const static uint_fast8_t REG_MODE1;
			const static uint_fast8_t REG_MODE2;
			const static uint_fast8_t REG_SUBADDR1;
			const static uint_fast8_t REG_SUBADDR2;
			const static uint_fast8_t REG_SUBADDR3;
			const static uint_fast8_t REG_ALLCALLADDR;

			const static uint_fast8_t REG_LED0_ON_L;
			const static uint_fast8_t REG_LED0_ON_H;
			const static uint_fast8_t REG_LED0_OFF_L;
			const static uint_fast8_t REG_LED0_OFF_H;

			const static uint_fast8_t REG_ALL_LED_ON_L;
			const static uint_fast8_t REG_ALL_LED_ON_H;
			const static uint_fast8_t REG_ALL_LED_OFF_L;
			const static uint_fast8_t REG_ALL_LED_OFF_H;
			const static uint_fast8_t REG_PRESCALE;

			const static uint_fast8_t SWRST;

			const static uint_fast8_t PRESCALE_MIN;
			const static uint_fast8_t PRESCALE_MAX;
			const static uint_fast16_t FREQ_MIN;
			const static uint_fast16_t FREQ_MAX;

			const static uint_fast16_t COUNTER_RANGE;
			const static uint_fast32_t DEFAULT_PERIOD;
			const static double OSC_CLOCK_MHZ;

			const static uint_fast8_t OUTPUT_CHANNEL_MIN;
			const static uint_fast8_t OUTPUT_CHANNEL_MAX;

			const static uint_fast8_t NUMREGS;
			const static uint_fast8_t MAXCHAN;

			const static uint_fast8_t LED_FULL_ON;
			const static uint_fast8_t MODE1_RESTART;
			const static uint_fast8_t MODE1_SLEEP;
			const static uint_fast8_t MODE2_INVERT;

			const static std::string INVALID_FREQUENCY;
			const static std::string OUTPUT_CHANNEL_OUT_OF_RANGE;
			const static std::string DUTY_CYCLE_OUT_OF_RANGE;
		};
	}
}

#endif // MICROMOUSE_PWM_H