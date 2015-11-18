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
	void runMotor();
	void runValve();

	void turnMotorOn(unsigned short speed);
	void turnMotorOff();

	void turnValveOn();
	void turnValveOff();
};

} /* namespace Data */

#endif /* PRESSURECONTROL_H_ */
