/*
 * Timer.cpp
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */

#include "Timer.h"

//Pin definition for the RTC module
const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock

//Initialize values for timer
bool timerHasEnded = false;
unsigned short seconds = 0, minutes = 0; //Values to hold the current value of either stopWatch() or countdown()

//Initialize instances
DS1302 rtc(kCePin, kIoPin, kSclkPin);
Time timestamp = rtc.time();

namespace Logic {

Timer::Timer() {
	// TODO Auto-generated constructor stub
}

void Timer::setTimestamp(){
	timestamp = rtc.time(); // get the current time on the RTC module
}

Time Timer::getTimestamp(){
	return timestamp;
}

void Timer::stopWatch(){
	Time elapsedTime = rtc.time();
	unsigned short hoursToSec = (elapsedTime.hr-timestamp.hr) * 60 * 60; //Convert hours into seconds
	unsigned short minutesToSec = (elapsedTime.min- timestamp.min) * 60; //Convert minutes in seconds
	unsigned short elapsedTotalSeconds = hoursToSec + minutesToSec + (elapsedTime.sec - timestamp.sec); //Calculate total elapsed seconds

	//Update the timer value
	seconds = elapsedTotalSeconds % 60;
	minutes = (elapsedTotalSeconds - seconds)/60;

}

void Timer::countdown(unsigned short totalTime){
	timerHasEnded = false;
	Time elapsedTime = rtc.time(); //Get the current time from the RTC module
	String elapsedTimeString;
	unsigned short hoursToSec = (elapsedTime.hr-timestamp.hr) * 60 * 60; //Convert hours into seconds
	unsigned short minutesToSec = (elapsedTime.min- timestamp.min) * 60; //Convert minutes in seconds
	unsigned short elapsedTotalSeconds = hoursToSec + minutesToSec + (elapsedTime.sec - timestamp.sec); //Calculate total elapsed seconds

	//Update the timer value
	seconds = (totalTime - elapsedTotalSeconds) % 60;
	minutes = (totalTime - elapsedTotalSeconds - seconds)/60;

	//Stops the timer if the countdown is finished
	if(minutes == 0 && seconds == 0)
		timerHasEnded = true;
}

String Timer::displayTimer(){
	String minString = String(minutes, DEC);
	String secString = String(seconds, DEC);
	String timeString;

	//Ensure currect format, if minString is "1", then a extra zero is added, so the string is "01"
	if(0 <=minutes && minutes < 10)
		minString = String("0" + minString);
	else
		minString = String(minutes, DEC);

	if(0 <=seconds && seconds < 10)
		secString = String("0" + secString);
	else
		secString = String(seconds, DEC);
	return timeString = String(minString + ":" + secString);

}

bool Timer::getTimerStatus(){
	return timerHasEnded;
}

void Timer::setTimerStatus(bool val){
	timerHasEnded = val;
}

String Timer::timeToString(){
	Time timeFormat = getTimestamp();
	String hourString, minString, secString;

	if(0 <= timeFormat.hr && timeFormat.hr < 10)
		hourString = String("0" + String(timeFormat.hr, DEC));
	else
		hourString = String(timeFormat.hr, DEC);

	if(0 <= timeFormat.min && timeFormat.min < 10)
		minString = String("0" + String(timeFormat.min, DEC));
	else
		minString = String(timeFormat.min, DEC);

	if(0 <= timeFormat.sec && timeFormat.sec < 10)
		secString = String("0" + String(timeFormat.sec, DEC));
	else
		secString = String(timeFormat.sec, DEC);

	String dayString = String(timeFormat.date, DEC);
	String monthString = String(timeFormat.mon, DEC);
	String yearString = String(timeFormat.yr, DEC);
	String timestampString = String(hourString + ":" + minString + ":" + secString + " " + dayString + "-" + monthString + "-" + yearString);
	return timestampString;
}

} /* namespace Logic */
