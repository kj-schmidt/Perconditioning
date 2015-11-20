/*
 * Buttons.h
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */

#ifndef GUI_BUTTONS_H_
#define GUI_BUTTONS_H_

#include "Display.h"
#include "Arduino.h"
#include "../Logic/Timer.h"
#include "../Logic/MemoryParser.h"

namespace GUI {

class Buttons {
public:
	Buttons();

	unsigned short readModeSwitch();

	//Interrupt service routines (ISR)
	unsigned short changer(volatile unsigned short state);
	unsigned short selector(volatile unsigned short state);
	bool startStopOcclusion(volatile bool startButtonPressed);
	void startStopConditiong(volatile bool *startButtonPressed);
	void btPressed(volatile bool *startButtonPressed);
};
} /* namespace GUI */

#endif /* GUI_BUTTONS_H_ */
