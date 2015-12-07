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
	/* This method determinate what program the code should run. The method read the value of two analog pins. The value
	 * of the analog pins varies from 0 to 1024. Depending on the status of pin an init method is called, initializing
	 * conditioning, occlusion or setup program.
	 */

	//Interrupt service routines (ISR)
	unsigned short changer(volatile unsigned short *state);
	/* This method change the value of state, if state is 0 or 1 the value is inverted. If state is 2 the timePerCycles
	 * is incremented with 30s. If the value is greater than 480 timePerCycle is change to 180s. If state is 3, noOfCycles
	 * is incremented. Finally the method return the value of state
	 */
	unsigned short selector(volatile unsigned short *state);
	/* Handles the value of state. If state = 0, state is change to 2. If state = 1, state is change to 3. If state = 2, state
	 * is change to 0. Lastly if state is 3, the value is change to 1
	 */
	bool startStopOcclusion(volatile bool *startButtonPressed);
	/* This ISR invert the value of *startButtonPressed. If this value is false the display is cleared and a time stamp is
	 * created
	 */
	void startStopConditiong(volatile bool *startButtonPressed);
	/* This ISR invert the value of *startButtonPressed. If this value is false the display is cleared, the noOfCylces is reset
	 * and information is saved on the SD card, about the interruption of the conditioning trial.
	 */
	void btPressed(volatile bool *startButtonPressed);
	/* /* This ISR invert the value of *startButtonPressed
	 */
};
} /* namespace GUI */

#endif /* GUI_BUTTONS_H_ */
