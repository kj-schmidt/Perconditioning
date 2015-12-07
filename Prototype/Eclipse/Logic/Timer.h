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

	void setTimestamp(); //Metod used to set a time stamp, this is for example used when stopWatch() or countdown() is used.
	Time getTimestamp(); //Returns the last set time stamp

	void stopWatch();
	/* This method is used to create a stop watch from the RTC module. When the method is called, a time stamp is set,
	 * to set the starting point for the stop watch. When the method is call the current time is read of from the RTC
	 * module. This time is then converted into a seconds and subtracted from the time stamp in seconds.
	*/
	void countdown(unsigned short totalTime);
	/* Before the method is run a time stamp has to create. This ensures a starting point for the timer. This method
	 * the parameter "totalTime". This value holds the number of second the count down has to last. Every time the method
	 * is ran, the elapsed time in seconds is subtracted from totalTime. If the countdown finishes the value "timerHasEnded"
	 * is changed to true
	 */
	String displayTimer();
	/* This method takes the value of minutes and seconds and convert the into a string on the format mm:ss. The string
	 * is the returned.
	 */
	bool getTimerStatus();
	/* Method that return the value "timerHasEnded". If this is true, the timer has ended
	 */
	void setTimerStatus(bool val);
	/* This method is created to control the timer, it changes the value of "timerHasEnded" to true
	 */
	String timeToString();
	/* Method that takes the current time stamp and converts it into a string on the following format: hh:mm:ss dd-mm-yyyy
	 * This string is the returned. This method is used when a time stamp is to be save on the SD card
	 */
};

} /* namespace Logic */

#endif /* LOGIC_TIMER_H_ */
