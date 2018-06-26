#ifndef MICROMOUSE_MOTOR_STATE_H
#define MICROMOUSE_MOTOR_STATE_H
#include <cstdint>

namespace drive
{
	namespace motor
	{
		struct State
		{
		public:
			State();
			State(const uint_fast8_t& in1, const uint_fast8_t& in2);
			
			void setPin1(const uint_fast8_t& pin1_value_in);
			void setPin2(const uint_fast8_t& pin2_value_in);
			
			uint_fast8_t getPin1() const;
			uint_fast8_t getPin2() const;
			
			friend bool operator==(const State& left, const State& right);
			friend bool operator!=(const State& left, const State& right);

		private:
			uint_fast8_t pin1_value;
			uint_fast8_t pin2_value;
			void setPin(const uint_fast8_t& id, const uint_fast8_t& value);

		};
		bool operator==(const State& left, const State& right);
		bool operator!=(const State& left, const State& right);
	}
}

#endif // MICROMOUSE_MOTOR_STATE_H
