/*
 * Timer.h
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */

#ifndef LOGIC_TIMER_H_
#define LOGIC_TIMER_H_

#include "Arduino.h"
#include "DS1302.h"

namespace Logic {

class Timer {
public:
	Timer();

	void setTimestamp();
	Time getTimestamp();

	void stopWatch();
	void countdown(unsigned short totalTime);
	String displayTimer();
	bool getTimerStatus();
	void setTimerStatus(bool val);
	String timeToString();
};

} /* namespace Logic */

#endif /* LOGIC_TIMER_H_ */
