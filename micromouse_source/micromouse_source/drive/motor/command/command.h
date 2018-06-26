#ifndef MICROMOUSE_MOTOR_COMMAND_H
#define MICROMOUSE_MOTOR_COMMAND_H
#include "../state/State.h"
#include <string>

namespace drive
{
	namespace motor
	{
		struct Command
		{
			int speed;
			int duration;

			Command();
			Command(const int& desired_speed, const int& desired_duration);

			friend bool operator==(const Command& left, const Command& right);
			friend bool operator!=(const Command& left, const Command& right);

			const static std::string INVALID_COMMAND;
		};
		bool operator==(const Command& left, const Command& right);
		bool operator!=(const Command& left, const Command& right);
	}
}

#endif // MICROMOUSE_MOTOR_COMMAND_H
