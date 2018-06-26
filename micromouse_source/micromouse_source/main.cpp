#include "drive/motor/Motor.h"
#include "drive/pwm/PCA9685.h"
#include "config/Config.h"
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
	drive::motor::Motor A;
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
	drive::pwm::PCA9685 board;
	board.setup(Config::PCA9685_DEVICE_ID);
	board.setFrequency(drive::pwm::PCA9685::PCA9685_FREQ_MAX);
	std::printf("%d\n", board.getFrequency());
	board.setDuty(0, 50);
}

int main(void)
{
	wiringPiSetup();
	//pwmTest();
	motorTest();
	return 0;
}