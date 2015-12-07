/*
 * PressureControl.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef PRESSURECONTROL_H_
#define PRESSURECONTROL_H_

#include "Arduino.h"

namespace Data {

class PressureControl {
public:
	void runMotor(); //starts motor at full speed while the digitalport 18 is high
	void runValve(); //opens the valve while the digitalport 19 is high

	void turnMotorOn(unsigned short speed); //start moter at the specified speed from 0-255
	void turnMotorOff(); //stop motor from running

	void turnValveOn(); //open valve
	void turnValveOff(); //close valve
};

} /* namespace Data */

#endif /* PRESSURECONTROL_H_ */
