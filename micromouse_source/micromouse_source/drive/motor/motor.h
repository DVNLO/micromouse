#ifndef MICROMOUSE_MOTOR_H
#define MICROMOUSE_MOTOR_H
#include "command/command.h"
#include "state/state.h"
#include <string>



namespace Drive
{
	class Motor
	{
	public:
		Motor();
		Motor(const int& pin1, const int& pin2);
		void setPins(const int& pin1, const int& pin2);
		void setPin(const int& pin_id, const int& pin);

		void forward() const;	
		void backward() const;
		void shortBrake();
		void stop() const;

	private:
		int pin1_;
		int pin2_;

		bool isInitialized() const;
		void validateInitialization() const;
		bool isCurrentState(const Drive::State& desired_state) const;

		State readState() const;
		void writeState(const Drive::State& new_state) const;

		void rotate(const Drive::State& desired_state) const;
	
	public:
		const static int PIN_ONE_ID;
		const static int PIN_TWO_ID;

		const static int DEFAULT_PIN;
		const static int ROTATE_FORWARD_CCW;
		const static int ROTATE_BACKWARD_CW;
		const static int SPEED_CONSTANT;
		const static int DURATION_INDEFINITE;

		const static std::string INVALID_STATE_PIN_NOT_SET;
		const static std::string INVALID_STATE_DIFFERENCE;
		const static std::string INVALID_ROTATION_DIRECTION;
		const static std::string INVALID_MOTOR_PIN_ID;
		const static std::string INVALID_COMMAND_PACKET_OPERATION;
		
		const static std::string FAILURE_TO_READ_STATE;
		const static std::string FAILURE_TO_WRITE_STATE;
		const static std::string FAILURE_TO_SET_PIN;

		const static Drive::State FORWARD;
		const static Drive::State BACKWARD;
		const static Drive::State SHORT_BRAKE;
		const static Drive::State STOP;
	};
}

#endif // MICROMOUSE_MOTOR_H