#include "Command.h"
#include "../Motor.h"
#include "../../../utility/Utility.h"
#include <stdexcept>

drive::motor::Command::Command()
{
	speed = Motor::SPEED_CONSTANT;
	duration = Motor::DURATION_INDEFINITE;	
}

drive::motor::Command::Command(const int& desired_speed, const int& desired_duration)
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

bool drive::motor::operator==(const drive::motor::Command& left, const drive::motor::Command& right)
{
	return !(
		left.speed != right.speed ||
		left.duration != right.duration
		);
}

bool drive::motor::operator!=(const drive::motor::Command& left, const drive::motor::Command& right)
{
	return !(left == right);
}

const std::string drive::motor::Command::INVALID_COMMAND = "invalid agruments to construct command";