#include "command.h"
#include "../motor.h"
#include "../../../utility/utility.h"
#include <stdexcept>

Drive::Command::Command()
{
	speed = Motor::SPEED_CONSTANT;
	duration = Motor::DURATION_INDEFINITE;	
}

Drive::Command::Command(const int& desired_speed, const int& desired_duration)
{
	if (desired_speed >= Motor::SPEED_CONSTANT && 
		(desired_duration == Motor::DURATION_INDEFINITE || desired_duration > 0))
	{
		speed = desired_speed;
		duration = desired_duration;
	}
	else
	{
		throw std::invalid_argument(INVALID_COMMAND);
	}
}

bool Drive::operator==(const Drive::Command& left, const Drive::Command& right)
{
	return !(
		left.speed != right.speed ||
		left.duration != right.duration
		);
}

bool Drive::operator!=(const Drive::Command& left, const Drive::Command& right)
{
	return !(left == right);
}

const std::string Drive::Command::INVALID_COMMAND = "invalid agruments to construct command";