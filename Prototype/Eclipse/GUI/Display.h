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
	/* To use the TFT screen, the method .begin(), has to be executed first. This is done in this method, together with
	 * defining the rotation of the display, and the background color.
	 */
	void clearAreaDisp(unsigned short pointX, unsigned short pointY, unsigned short width, unsigned short height);
	/* Since the background of the display is always black, this method is used to delete objects on the display by
	 * drawing the area, define by the four parameters, black
	 */
	void initConditioning();
	/* This method check if the SD card is connected correctly, if not, an error message is writing on the display. If
	 * true, the display is writing with the static parameters define by the layout of a conditiong trial. Aside from
	 * creating the static parameters on the screen, the method also loads the numbers of cycles to two variable with data
	 * from the logic layer.
	 */
	void initOcclusion();
	/* Drawing the static parameters on the display for a occlusion trial.
	 */
	void initSetup();
	/* Drawing the static parameters on the display for a setup trial.
	 */
	void moveSqaure(unsigned short startX, unsigned short startY, unsigned short endX, unsigned short endY, unsigned short width, unsigned short height);
	/* This method is used to control the cursor during setup. The method uses six parameter, the starting x and y
	 * coordinate, the ending x and y and the height and weight of the square. When the method is called, the square is
	 * move from startX and startY to endX and endY. While this method is running, interrupts is disable.
	 */
	void updateConditioning(volatile bool *buttonPressed, volatile bool *btPressed);
	/* This method handle the action during a conditioning trial. Here several parameters determinate which state the
	 * method is excuting.
	 *
	 * If (*btPressed && !*buttonPressed):
	 * The method runs a blood pressure measurement. The patient ID is writing on the screen and the last measured value
	 * is delete on the screen. bloodPressure() is called to measure the blood pressure and the updateBloodPressure()
	 * display the measurement on the screen. Lastly the value of *btPressed is reset to false.
	 *
	 * If (!*btPressed && *buttonPressed && getNoCycleLeft() != 0)
	 * The state the method runs a conditioning trial. The patient ID is displayed on the screen, the last measured value
	 * is cleared and the new value is measureed with bloodPressure() and displayed with updateBloodPressure(). When the
	 * blood pressure is known, the conditioning begins. This is done in a while loop with the following critrias:
	 * (*buttonPressed && getNoCycleLeft() != 0). Next, if the noOfCycleLeft is a even number, the conditioning is in a
	 * occlusion phase. Here the cuff pressure is raised to 25mmHg higher than the measured systolic pressure. When this
	 * pressure is reached, a time stamp is set and the count down timer begins. Data is also save to the SD card a this
	 * point, the data contain a time stamp and the occlusion pressure.
	 * If noOfCycles is uneven the conditioning is in a reperfusion phase. This means the cuff is deflated. When the pressure
	 * reach under 50mmHg the count down timer start and data is save to the SD card that a occlusion phase has finished.
	 * Next is check is the count down timer is running. If that is the case the sensorValue, noOfCycles and the timer is
	 * updated.
	 * IF the timer has ended the display is cleared and noOfCylces is decremented one. If noOfCycles is greater than 1, the
	 * timer is reset. Else the conditioning ends.
	 *
	 * The last scenario is when (!*btPressed && !*buttonPressed). Here occlude() ensure that the cuff is empty and the display
	 * is cleared.
	 */
	void updateOcclusion(volatile bool *buttonPressed);
	/* The method controls the occlusion trial. A while loop is execute if the value of *buttenPressed is true. Here the stop
	 * watch is started, and the cuff pressure is change to 100mmHg. Lastly the sensorValue is updated.
	 * If the *buttonPressed is false the timer is disabled.
	 */
	void updateSetup(volatile unsigned short *state);
	/* This method contains a case switch structure, with 4 cases. The case state is determinate by the value of *state. State
	 * 0 and 1 moves the cursor to the opposite value with use of moveSquare()
	 *
	 * Case 2 takes the value from getTimePerCycle() and display it on the display. The same goes for case 3, but the value is
	 * here noOfCycles()
	 */
	unsigned short getNoCycleLeft();
	/* Return the current number of cycles left
	 */
	void setNoCycleLeft(unsigned short val);
	/* Set the number of cycles left
	 */

	//Is to be move to DATA namespace
	void updateSensorVal(unsigned short sensorVal);
	/* Writes the value of the sensor on the display, the value is only updated if the value has changed
	 */


private:
	void updateTimeLeft(String value);
	/* Writes the value of the timer on the display, the value is only updated if the value has changed
	 */
	void updateNoOfCycles(unsigned short value);
	/* Writes the value of the noOfCyclesLeft() on the display, the value is only updated if the value has changed
	 */
	void updateStopWatchTime(String value);
	/* Writes the value of the timer on the display, the value is only updated if the value has changed
	 */
	void updateBloodPressure(unsigned short sys, unsigned short dia, unsigned short map);
	/* Writes the value of the lastest blood pressure measurement on the display, the value is only updated if the value has changed
	 */
};

} /* namespace GUI */

#endif /* GUI_DISPLAY_H_ */
