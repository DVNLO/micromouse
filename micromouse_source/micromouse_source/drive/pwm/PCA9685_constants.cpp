#include "PCA9685.h"

const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_MODE1 = 0x00;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_MODE2 = 0x01;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_SUBADDR1 = 0x02;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_SUBADDR2 = 0x03;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_SUBADDR3 = 0x04;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_ALLCALLADDR = 0x05;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_LED0_ON_L = 0x06;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_LED0_ON_H = 0x07;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_LED0_OFF_L = 0x08;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_LED0_OFF_H = 0x09;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_ALL_LED_ON_L = 0xFA;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_ALL_LED_ON_H = 0xFB;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_ALL_LED_OFF_L = 0xFC;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_ALL_LED_OFF_H = 0xFD;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_REG_PRESCALE = 0xFE;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_SWRST = 0x06;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_PRESCALE_MIN = 0x03;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_PRESCALE_MAX = 0xFF;
const uint_fast16_t drive::pwm::PCA9685::PCA9685_FREQ_MIN = 24;
const uint_fast16_t drive::pwm::PCA9685::PCA9685_FREQ_MAX = 1526;

const uint_fast16_t drive::pwm::PCA9685::PCA9685_COUNTER_RANGE = 4096;
const uint_fast32_t drive::pwm::PCA9685::PCA9685_DEFAULT_PERIOD = 5000000;	//Default period_ns = 1/200 Hz
const double drive::pwm::PCA9685::PCA9685_OSC_CLOCK_MHZ = 25000000;	//Internal oscillator; 25 MHz

const uint_fast8_t drive::pwm::PCA9685::PCA9685_OUTPUT_CHANNEL_MIN = 0;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_OUTPUT_CHANNEL_MAX = 15;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_NUMREGS = 0xFF;
const uint_fast8_t drive::pwm::PCA9685::PCA9685_MAXCHAN = 0x10;

const uint_fast8_t drive::pwm::PCA9685::PCA9685_LED_FULL_ON = (1 << 4);	//0000 0001 << 4 = 0001 0000 
const uint_fast8_t drive::pwm::PCA9685::PCA9685_MODE1_RESTART = (1 << 7);	//0000 0001 << 7 = 1000 0000
const uint_fast8_t drive::pwm::PCA9685::PCA9685_MODE1_SLEEP = (1 << 4);	//0000 0001 << 4 = 0001 0000
const uint_fast8_t drive::pwm::PCA9685::PCA9685_MODE2_INVERT = (1 << 4);

const std::string drive::pwm::PCA9685::FAILURE_TO_SETUP_I2C = "wiringPiI2CSetup() failed";
const std::string drive::pwm::PCA9685::FAILURE_TO_READ_REGISTER8 = "wiringPiI2CReadReg8() failed";
const std::string drive::pwm::PCA9685::FAILURE_TO_WRITE_REGISTER8 = "wiringPiWriteReg8() failed";

const std::string drive::pwm::PCA9685::INVALID_FREQUENCY = "invalid frequency";
const std::string drive::pwm::PCA9685::OUTPUT_CHANNEL_OUT_OF_RANGE = "output channel out of range";
const std::string drive::pwm::PCA9685::DUTY_CYCLE_OUT_OF_RANGE = "duty cycle out of range";