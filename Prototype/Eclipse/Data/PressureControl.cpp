/*
 * PressureControl.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "PressureControl.h"

namespace Data {

void PressureControl::runMotor()
{
	while(digitalRead(18) == HIGH){
		digitalWrite(3, HIGH);
	  }
	digitalWrite(3, LOW);

}

void PressureControl::runValve()
{
	while(digitalRead(19) == HIGH){
		digitalWrite(11, HIGH);
	  }
	digitalWrite(11, LOW);
}


void PressureControl::turnMotorOn(unsigned short speed)
{
	analogWrite(3,speed);
}

void PressureControl::turnMotorOff()
{
	analogWrite(3,0);
}
void PressureControl::turnValveOn()
{
	digitalWrite(11, HIGH);
}
void PressureControl::turnValveOff()
{
	digitalWrite(11, LOW);
}

} /* namespace Data */
