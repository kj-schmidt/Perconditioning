/*
 * Display.cpp
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */

#include "Display.h"

namespace GUI {
//Pins for the display
#define cs 	34
#define dc 	32
#define reset	30

unsigned short sensorPin = A0;
unsigned short sensorValTemp = 0;
long lastDisplayUpdateTimestamp = 0;
String lastStopWatchTimeUpdate = "0";
unsigned short lastNoOfCycleVal = 0;

volatile unsigned short noOfCyclesLeft;
volatile unsigned short timePerCycleVal;
bool isOccluding = false;

Adafruit_ILI9340 TFTscreen = Adafruit_ILI9340(cs, dc, reset);
Logic::Timer timer = Logic::Timer();
Logic::MemoryParser memory;


Display::Display() {
	// TODO Auto-generated constructor stub
}
void Display::updateTimeLeft(String value){
	//Only update value if seconds has decremented
	if(lastStopWatchTimeUpdate != value){
		TFTscreen.fillRect(180,220,80,20, ILI9340_BLACK); //Erase previous value
		TFTscreen.setTextColor(ILI9340_WHITE);
		TFTscreen.setTextSize(2);
		TFTscreen.setCursor(180, 220);
		TFTscreen.print(value);

		//Set new value to detect changes
		lastStopWatchTimeUpdate = value;
	}
}
void Display::updateNoOfCycles(unsigned short value){
	//Only update value if the value has changed
	if(lastNoOfCycleVal !=value){
		unsigned short valToDisplay = value;
		if(value%2)
			valToDisplay = (valToDisplay+1)/2;
		else
			valToDisplay = valToDisplay/2;

		clearAreaDisp(280, 0, 10, 10 );
		TFTscreen.setTextColor(ILI9340_WHITE);
		TFTscreen.setTextSize(2);
		TFTscreen.setCursor(280, 0);
		TFTscreen.print(valToDisplay);

		lastNoOfCycleVal = value;
	}

}
void Display::updateStopWatchTime(String value){
	//Only update value if seconds has incremented
	if(lastStopWatchTimeUpdate != value){
		TFTscreen.fillRect(50,220,80,20, ILI9340_BLACK); //Erase previous value
		TFTscreen.setTextColor(ILI9340_WHITE);
		TFTscreen.setTextSize(2);
		TFTscreen.setCursor(50, 220);
		TFTscreen.print(value);

		//Set new value to detect changes
		lastStopWatchTimeUpdate = value;
	}
}
void Display::updateSensorVal(unsigned short sensorVal){
	//Only update value if 200ms has passed since last update
	if(millis()-lastDisplayUpdateTimestamp > 200){
		//Delete the previous value
		TFTscreen.setTextColor(ILI9340_BLACK);  TFTscreen.setTextSize(12);
		TFTscreen.setCursor(75, 60);
		TFTscreen.print(sensorValTemp);

		//Draw new value
		TFTscreen.setTextColor(ILI9340_WHITE);  TFTscreen.setTextSize(12);
		TFTscreen.setCursor(75, 60); TFTscreen.print(sensorVal);
		sensorValTemp = sensorVal;

		//Set new timeUntilUpdate
		lastDisplayUpdateTimestamp = millis();
	}
}

void Display::updateBloodPressure(unsigned short sys, unsigned short dia, unsigned short map){
	String bloodPressure = String(String((short)util.rawToMmHg(sys), DEC) + "/" + String((short)util.rawToMmHg(dia),DEC) + "(" + String((short)util.rawToMmHg(map), DEC) + ")");

	//Clear "Arbejder..."
	clearAreaDisp(75,160, 220, 30);

	//Write the blood pressure on the screen, formal "SYS/DIA(MAP)"
	TFTscreen.setCursor(75, 160);
	TFTscreen.setTextSize(3);
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.println(bloodPressure);
}

void Display::initDisplay(){
	//Setup pin to simulate modeswitch
	TFTscreen.begin();
	TFTscreen.setRotation(3); //Corner with the BL pin
	TFTscreen.fillScreen(ILI9340_BLACK);
}

void Display::clearAreaDisp(unsigned short pointX, unsigned short pointY, unsigned short width, unsigned short height){
	//Erase area on display
	TFTscreen.fillRect(pointX, pointY, width, height, ILI9340_BLACK);
}

void Display::initConditioning(){
	//Begin communication with SD card
	memory.startInitSD();
	Serial.println("** THIS METHOD IS RUN **");

	//Writes statics parameters onto the screen
	unsigned short noOfCyclesVal = memory.getNoOfCycles();
	noOfCyclesLeft = memory.getNoOfCycles()*2;				//times two to imitate occlude and relaxed cuff

	TFTscreen.setTextColor(ILI9340_WHITE);  TFTscreen.setTextSize(2);
	TFTscreen.setCursor(0, 0);
	TFTscreen.println("ID: ");
	TFTscreen.setCursor(150, 0);
	TFTscreen.println("Cyklusser: ");
	TFTscreen.setCursor(290, 0);
	TFTscreen.print("/"); TFTscreen.print(noOfCyclesVal);

	TFTscreen.setTextSize(1);
	TFTscreen.setCursor(0, 60);
	TFTscreen.println("Tryk: ");
	TFTscreen.setCursor(0, 80);
	TFTscreen.println("[mmHg]");

	TFTscreen.setTextSize(1);
	TFTscreen.setCursor(0, 160);
	TFTscreen.println("Blodtryk: ");
	TFTscreen.setCursor(0, 180);
	TFTscreen.println("[mmHg]");

	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(0, 220);
	TFTscreen.println("Resterende tid: ");
}
void Display::initOcclusion(){
	//Writes statics parameters onto the screen
	TFTscreen.setTextSize(1);
	TFTscreen.setCursor(0, 60);
	TFTscreen.println("Tryk: ");
	TFTscreen.setCursor(0, 80);
	TFTscreen.println("[mmHg]");

	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(0, 220);
	TFTscreen.println("Tid: ");
}
void Display::initSetup(){
	//Writes statics parameters onto the screen
	TFTscreen.setTextColor(ILI9340_WHITE);  TFTscreen.setTextSize(1);
	TFTscreen.setCursor(10,60);
	TFTscreen.println("Tid pr cyklus");

	TFTscreen.setCursor(170,60);
	TFTscreen.println("Antal cyklusser");

	TFTscreen.setTextSize(5);
	TFTscreen.setCursor(10,70);
	TFTscreen.println(memory.getTimePerCycle());
	TFTscreen.setCursor(100,70);
	TFTscreen.println("s");
	TFTscreen.setCursor(170,70);
	TFTscreen.println(memory.getNoOfCycles());
	TFTscreen.setCursor(205,70);
	TFTscreen.println("stk");
}

void Display::moveSqaure(unsigned short startX, unsigned short startY, unsigned short endX, unsigned short endY, unsigned short width, unsigned short height){
	noInterrupts();
	TFTscreen.drawRect(startX,startY, width, height, ILI9340_BLACK); //Erase square
	TFTscreen.drawRect(endX,endY, width, height, ILI9340_WHITE); //Draw square
	interrupts();
}

void Display::updateConditioning(volatile bool *buttonPressed, volatile bool *btPressed){
// *** TEMP VALUES ***
unsigned short MAP = 100;
unsigned short SYS = 300;
unsigned short DIA = 100;
unsigned short cuffPressure = 0;
bool donedeflateingOrInflating = false;

	//*** When "Mål blodtryk" is pressed ***
	if(*btPressed && !*buttonPressed)
	{
		//Clear previous BP
		clearAreaDisp(75,160, 220, 30);
		TFTscreen.setTextColor(ILI9340_WHITE);
		TFTscreen.setTextSize(3);
		TFTscreen.setCursor(75, 160);
		TFTscreen.println("Arbejder...");
		s.bloodPressure(&MAP, &SYS, &DIA, &*btPressed);

		updateBloodPressure(SYS, DIA, MAP);


		*btPressed = false;
	}

	//*** When "Start/Stop" is pressed, and blood pressure is to be measured ***
	if(!*btPressed && *buttonPressed && getNoCycleLeft() != 0){

		//Print the ID on the display
		TFTscreen.setTextColor(ILI9340_WHITE);  TFTscreen.setTextSize(2);
		TFTscreen.setCursor(40, 0);
		TFTscreen.println(memory.getID());

		//*btPressed = false;
		//Clear previous BP
		clearAreaDisp(75,160, 220, 30);
		TFTscreen.setTextColor(ILI9340_WHITE);
		TFTscreen.setTextSize(3);
		TFTscreen.setCursor(75, 160);
		TFTscreen.println("Arbejder...");

		//Measure the blood pressure
		//s.bloodPressure(&MAP, &SYS, &DIA, &*buttonPressed);

		//Display the blood pressure
		updateBloodPressure(SYS, DIA, MAP);

		Serial.println("SYS: ");
		Serial.println(util.rawToMmHg(SYS));

		if(util.rawToMmHg(SYS)<175)
			SYS = util.mmHgToRaw(175);
		else if(util.rawToMmHg(SYS)>275)
			SYS = util.mmHgToRaw(275);
		memory.writeToSDCard(timer.timeToString(), false, 0, util.rawToMmHg(SYS), util.rawToMmHg(MAP), util.rawToMmHg(DIA), false); //Temp save
	}

	//*** Running the conditioning ***
	while(*buttonPressed && getNoCycleLeft() != 0){
		//If noOfCycles is uneven, meaning that it has reach reperfusion
		if(noOfCyclesLeft%2)
		{
			cuffPressure =  s.occlude(0);
			if(cuffPressure < util.mmHgToRaw(50) && donedeflateingOrInflating == false)
			{
				donedeflateingOrInflating = true;
				timer.setTimestamp();
				timer.setTimerStatus(false);
				memory.writeToSDCard(timer.timeToString(), true, util.rawToMmHg(SYS)+25, 0, 0, 0, false);
			}
			else if (cuffPressure > util.mmHgToRaw(50))
				donedeflateingOrInflating = false;
		}
		//If noOfCycles is even, meaning that it has reach occlusion
		else
		{
			cuffPressure =  s.occlude(util.rawToMmHg(SYS)+25);
			if(cuffPressure > SYS  && donedeflateingOrInflating == false)
			{
				donedeflateingOrInflating = true;
				timer.setTimestamp();
				timer.setTimerStatus(false);
				memory.writeToSDCard(timer.timeToString(), false, util.rawToMmHg(SYS)+25, 0, 0, 0, false);
			}
			else  if (cuffPressure < SYS)
				donedeflateingOrInflating = false;
		}
		if(!timer.getTimerStatus()){ //If timer is running
			if(donedeflateingOrInflating)
				timer.countdown(10);//memory.getTimePerCycle());
			String countDownTime = timer.displayTimer();

			updateSensorVal(util.rawToMmHg(cuffPressure)); //Update the sensor value
			updateNoOfCycles(getNoCycleLeft()); //** IS TO READ OF FROM THE SD CARD **
			updateTimeLeft(countDownTime); //Update the timer

		} else{ //If the timer has ended
			clearAreaDisp(280, 0, 10, 20);
			if(getNoCycleLeft() == 0){ //If all cycles have been run
				timer.setTimerStatus(true);
			}
			else{ //If more cycles are left
				timer.setTimestamp();
				timer.setTimerStatus(false); //Reset the timer
				setNoCycleLeft(getNoCycleLeft() - 1); //** IS TO READ OF FROM THE SD CARD **
			}
		}
	}

	//*** When no buttons is pressed
	if(!*btPressed && !*buttonPressed){
		s.occlude(0);
		updateTimeLeft(timer.displayTimer());
		clearAreaDisp(70, 55,220, 100); //Clear the sensor value
	}
	updateNoOfCycles(noOfCyclesLeft); //Reset noOfCycleLeft

	//Handles if the
	if(memory.getNoOfCycles() == 0)
		*buttonPressed = false;
}

void Display::updateOcclusion(volatile bool *buttonPressed){

	//Run occlusion trail
	while(*buttonPressed){
		timer.stopWatch(); //Start the stopWatch
		updateStopWatchTime(timer.displayTimer()); //Display the time
		updateSensorVal(s.occlusiontraining(&*buttonPressed)); //Update sensorvalue
	}

	//This is only executed after the while loop and if the state of "startButtonPressed" is changed, the timer is reset
	if(!*buttonPressed)
		timer.setTimerStatus(true);

	//Display the sensorvalue
	updateSensorVal(s.occlusiontraining(&*buttonPressed));
}

void Display::updateSetup(volatile unsigned short *state){
	switch (*state){
		case 0: //Move cursor
			moveSqaure(165, 55,5,55,140,60);
			break;
		case 1: //Move cursor
			moveSqaure(5,55,165,55,140,60);
			break;
		case 2: //Change time per cycle
			noInterrupts();
			TFTscreen.setTextSize(5); TFTscreen.setTextColor(ILI9340_WHITE);
			TFTscreen.setCursor(10,70);
			TFTscreen.println(memory.getTimePerCycle());
			interrupts();
			break;
		case 3: // Change number of cycles
			noInterrupts();
			TFTscreen.setTextSize(5); TFTscreen.setTextColor(ILI9340_WHITE);
			TFTscreen.setCursor(170,70);
			TFTscreen.println(memory.getNoOfCycles());
			interrupts();
			break;
		}
}

unsigned short Display::getNoCycleLeft(){
	return noOfCyclesLeft;
}
void Display::setNoCycleLeft(unsigned short val){
	noOfCyclesLeft = val;
}

} /* namespace GUI */


