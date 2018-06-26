#ifndef MICROMOUSE_MOTOR_H
#define MICROMOUSE_MOTOR_H
#include "state/State.h"
#include <cstdint>
#include <string>

namespace drive
{
	namespace motor
	{
		class Motor
		{
		public:
			Motor();
			Motor(const int_fast8_t& pin1, const int_fast8_t& pin2);
			void setPins(const int_fast8_t& pin1, const int_fast8_t& pin2);
			void setPin(const int_fast8_t& pin_id, const int_fast8_t& pin);

			void forward() const;
			void backward() const;
			void shortBrake();
			void stop() const;

		private:
			int_fast8_t pin1_;
			int_fast8_t pin2_;

			bool isInitialized() const;
			void validateInitialization() const;
			bool isCurrentState(const drive::motor::State& desired_state) const;

			State readState() const;
			void writeState(const drive::motor::State& new_state) const;

			void rotate(const drive::motor::State& desired_state) const;

		public:
			const static int_fast8_t PIN_ONE_ID;
			const static int_fast8_t PIN_TWO_ID;

			const static int_fast8_t DEFAULT_PIN;
			const static int_fast8_t SPEED_CONSTANT;
			const static int_fast8_t DURATION_INDEFINITE;

			const static std::string INVALID_STATE_PIN_NOT_SET;
			const static std::string INVALID_STATE_DIFFERENCE;
			const static std::string INVALID_ROTATION_DIRECTION;
			const static std::string INVALID_MOTOR_PIN_ID;
			const static std::string INVALID_COMMAND_PACKET_OPERATION;

			const static std::string FAILURE_TO_READ_STATE;
			const static std::string FAILURE_TO_WRITE_STATE;
			const static std::string FAILURE_TO_SET_PIN;

			const static drive::motor::State FORWARD;
			const static drive::motor::State BACKWARD;
			const static drive::motor::State SHORT_BRAKE;
			const static drive::motor::State STOP;
		};
	}
}

#endif // MICROMOUSE_MOTOR_H