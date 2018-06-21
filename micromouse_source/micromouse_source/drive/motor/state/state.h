#ifndef MICROMOUSE_MOTOR_STATE_H
#define MICROMOUSE_MOTOR_STATE_H

namespace Drive
{
	struct State
	{
		int digital_pin_in1_value;
		int digital_pin_in2_value;
		State();
		State(const int& in1, const int& in2);
		friend bool operator==(const State& left, const State& right);
		friend bool operator!=(const State& left, const State& right);
	};
	bool operator==(const State& left, const State& right);
	bool operator!=(const State& left, const State& right);
	
}

#endif // MICROMOUSE_MOTOR_STATE_H
