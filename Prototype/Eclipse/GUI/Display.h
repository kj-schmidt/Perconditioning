/*
 * Display.h
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */



#ifndef GUI_DISPLAY_H_
#define GUI_DISPLAY_H_

#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"
#include "../Logic/Timer.h"
#include "../Logic/MemoryParser.h"
#include "../Logic/Senarios.h"
#include "../Utilities.h"

namespace GUI {

class Display {

Logic::Senarios s;
Utilities util;

public:
	Display();
	void initDisplay();
	void clearAreaDisp(unsigned short pointX, unsigned short pointY, unsigned short width, unsigned short height);
	void initConditioning();
	void initOcclusion();
	void initSetup();
	void moveSqaure(unsigned short startX, unsigned short startY, unsigned short endX, unsigned short endY, unsigned short width, unsigned short height);
	void updateConditioning(volatile bool *buttonPressed, volatile bool *btPressed);
	void updateOcclusion(volatile bool *buttonPressed);
	void updateSetup(volatile unsigned short *state);
	unsigned short getNoCycleLeft();
	void setNoCycleLeft(unsigned short val);

	//Is to be move to DATA namespace
	void updateSensorVal(unsigned short sensorVal);


private:
	void updateTimeLeft(String value);
	void updateNoOfCycles(unsigned short value);
	void updateStopWatchTime(String value);
	void updateBloodPressure(unsigned short sys, unsigned short dia, unsigned short map);
};

} /* namespace GUI */

#endif /* GUI_DISPLAY_H_ */
