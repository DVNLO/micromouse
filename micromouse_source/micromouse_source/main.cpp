#include <wiringPi.h>
#include <stdio.h>
#include "drive/motor/motor.h"
#include "drive/pwm/pwm.h"

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
//test
#define	LED	17

void motorTest()
{
	wiringPiSetup();
	Drive::Motor A;
	A.setPins(0, 2);
	//A.writeState(Drive::Motor::FORWARD);
	//Drive::State state = A.readState();
	//A.setPins(0, 2);
	A.forward();
	A.stop();
	//A.backward();
	//A.shortBrake();
	//A.stop();
}

void pwmTest()
{
	Drive::PWM A;
	A.setup(1);
	Drive::PWM B(1);
	std::printf("%f", A.getFrequency());
}

int main(void)
{
	//pwmTest();
	motorTest();
	
	/*
	printf("Let their be light...\n");

	wiringPiSetupSys();
	pinMode(LED, OUTPUT);

	int pin = 17;
	for (int i = 0; i < 60; i++)
	{
		printf("%i\n", digitalRead(pin));
		digitalWrite(LED, HIGH);
		printf("%i\n", digitalRead(pin));
		digitalWrite(LED, LOW);
	}
	*/


	/*
	for (int i = 0; i < 60; i++)
	{
	digitalWrite(LED, HIGH);  // On
	delay(500); // ms
	digitalWrite(LED, LOW);	  // Off
	delay(500);
	printf("again!\n");
	}

	printf("and darkness!\n");
	*/

	return 0;
}