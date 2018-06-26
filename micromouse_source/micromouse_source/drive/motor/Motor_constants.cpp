#include "Motor.h"
#include <string>
#include <wiringPi.h>

const int drive::motor::Motor::PIN_ONE_ID = 1;
const int drive::motor::Motor::PIN_TWO_ID = 2;

const int drive::motor::Motor::DEFAULT_PIN = -1;
const int drive::motor::Motor::SPEED_CONSTANT = -1;
const int drive::motor::Motor::DURATION_INDEFINITE = -1;

const std::string drive::motor::Motor::INVALID_STATE_PIN_NOT_SET = "invalid state pin not set";
const std::string drive::motor::Motor::INVALID_STATE_DIFFERENCE = "invalid state (current and desired states differ)";
const std::string drive::motor::Motor::INVALID_ROTATION_DIRECTION = "invalid rotation direction";
const std::string drive::motor::Motor::INVALID_MOTOR_PIN_ID = "invalid motor pin id";
const std::string drive::motor::Motor::INVALID_COMMAND_PACKET_OPERATION = "invalid command packet operation";

const std::string drive::motor::Motor::FAILURE_TO_READ_STATE = "digitalRead() failed to read state";
const std::string drive::motor::Motor::FAILURE_TO_WRITE_STATE = "digitalWrite() failed to write state";
const std::string drive::motor::Motor::FAILURE_TO_SET_PIN = "failed to set pin";

/*****************************************************************************
forward is a Motor::State specified on the toshiba TB6612FNG datasheet.
A forward event will occur in a single motor state:
1: IN1: L | IN2: H
*****************************************************************************/
const drive::motor::State drive::motor::Motor::FORWARD{ LOW, HIGH };

/*****************************************************************************
backward is a Motor::State specified on the toshiba TB6612FNG datasheet.
A backward event will occur in a single motor state:
1: IN1: H | IN2: L
*****************************************************************************/
const drive::motor::State drive::motor::Motor::BACKWARD{ HIGH, LOW };

/*****************************************************************************
Short brake is a motor state specified on the toshiba TB6612FNG datasheet.
A sort brake event will occur in 3 possible motor states:
1: IN1: H | IN2: H
2: IN1: L | IN2: H	//forward "coasting"
3: IN1: H | IN2: L	//backward "coasting"
Note: states 2-3 occur during operation when the pwm signal is low. We
consider a short brake event equivalent to "coasting"; a state in which
braking occurs passively, as the motor decelerates.
https://electronics.stackexchange.com/questions/267863/what-does-short-brake-mean
*****************************************************************************/
const drive::motor::State drive::motor::Motor::SHORT_BRAKE{ HIGH, HIGH };

/*****************************************************************************
Stop is a motor state specified on the toshiba TB6612FNG datasheet.
A stop event will occur in a single motor state (H: High, L: LOW):
1: IN1: L | IN2: L | PWM: H | STBY: H
*****************************************************************************/
const drive::motor::State drive::motor::Motor::STOP{ LOW, LOW };