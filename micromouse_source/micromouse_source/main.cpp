#include "drive/motor/motor.h"
#include "drive/pwm/pwm.h"
#include "config/config.h"
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>


// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
//test
#define	LED	17

void motorTest()
{
	Drive::Motor A;
	A.setPins(0, 2);
	A.forward();
	delay(1000);
	A.shortBrake();
	delay(100);
	A.stop();

	A.backward();
	delay(1000);
	A.shortBrake();
	delay(100);
	A.stop();
	
}

void pwmTest()
{
	Drive::PWM board;
	board.setup(Config::PCA9685_DEVICE_ID);
	board.setFrequency(Drive::PWM::PCA9685_FREQ_MIN);
	std::printf("%d\n", board.getFrequency());
	board.setFrequency(Drive::PWM::PCA9685_FREQ_MAX);
	std::printf("%d\n", board.getFrequency());
	board.restart();
	std::printf("%d\n", board.getFrequency());
}

int main(void)
{
	wiringPiSetup();
	pwmTest();
	motorTest();
	return 0;
}