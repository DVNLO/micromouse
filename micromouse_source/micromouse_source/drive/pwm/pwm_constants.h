#ifndef MICROMOUSE_PWM_CONSTANTS_H
#define MICROMOUSE_PWM_CONSTANTS_H
#include <string>

const unsigned char Drive::PWM::PCA9685_REG_MODE1 = 0x00;
const unsigned char Drive::PWM::PCA9685_REG_MODE2 = 0x01;
const unsigned char Drive::PWM::PCA9685_REG_SUBADDR1 = 0x02;
const unsigned char Drive::PWM::PCA9685_REG_SUBADDR2 = 0x03;
const unsigned char Drive::PWM::PCA9685_REG_SUBADDR3 = 0x04;
const unsigned char Drive::PWM::PCA9685_REG_ALLCALLADDR = 0x05;

const unsigned char Drive::PWM::PCA9685_REG_LED0_ON_L = 0x06;
const unsigned char Drive::PWM::PCA9685_REG_LED0_ON_H = 0x07;
const unsigned char Drive::PWM::PCA9685_REG_LED0_OFF_L = 0x08;
const unsigned char Drive::PWM::PCA9685_REG_LED0_OFF_H = 0x09;

const unsigned char Drive::PWM::PCA9685_REG_ALL_LED_ON_L = 0xFA;
const unsigned char Drive::PWM::PCA9685_REG_ALL_LED_ON_H = 0xFB;
const unsigned char Drive::PWM::PCA9685_REG_ALL_LED_OFF_L = 0xFC;
const unsigned char Drive::PWM::PCA9685_REG_ALL_LED_OFF_H = 0xFD;
const unsigned char Drive::PWM::PCA9685_REG_PRESCALE = 0xFE;

const unsigned char Drive::PWM::PCA9685_SWRST = 0x06;

const unsigned char Drive::PWM::PCA9685_PRESCALE_MIN = 0x03;
const unsigned char Drive::PWM::PCA9685_PRESCALE_MAX = 0xFF;
const int Drive::PWM::PCA9685_FREQ_MIN = 24;
const int Drive::PWM::PCA9685_FREQ_MAX = 1526;

const int Drive::PWM::PCA9685_COUNTER_RANGE = 4096;
const int Drive::PWM::PCA9685_DEFAULT_PERIOD = 5000000;	//Default period_ns = 1/200 Hz
const double Drive::PWM::PCA9685_OSC_CLOCK_MHZ = 25000000;	//Internal oscillator; 25 MHz

const int Drive::PWM::PCA9685_OUTPUT_CHANNEL_MIN = 0;
const int Drive::PWM::PCA9685_OUTPUT_CHANNEL_MAX = 15;

const unsigned char Drive::PWM::PCA9685_NUMREGS = 0xFF;
const unsigned char Drive::PWM::PCA9685_MAXCHAN = 0x10;

const unsigned char Drive::PWM::PCA9685_LED_FULL_ON = (1 << 4);	//0000 0001 << 4 = 0001 0000 
const unsigned char Drive::PWM::PCA9685_MODE1_RESTART = (1 << 7);	//0000 0001 << 7 = 1000 0000
const unsigned char Drive::PWM::PCA9685_MODE1_SLEEP = (1 << 4);
const unsigned char Drive::PWM::PCA9685_MODE2_INVERT = (1 << 4);

const std::string Drive::PWM::FAILURE_TO_SETUP_I2C = "wiringPiI2CSetup() failed";
const std::string Drive::PWM::FAILURE_TO_READ_REGISTER8 = "wiringPiI2CReadReg8() failed";
const std::string Drive::PWM::FAILURE_TO_WRITE_REGISTER8 = "wiringPiWriteReg8() failed";

const std::string Drive::PWM::INVALID_FREQUENCY = "invalid frequency";
const std::string Drive::PWM::OUTPUT_CHANNEL_OUT_OF_RANGE = "output channel out of range";
const std::string Drive::PWM::DUTY_CYCLE_OUT_OF_RANGE = "duty cycle out of range";

#endif // MICROMOUSE_PWM_CONSTANTS_H