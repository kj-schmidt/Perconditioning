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

//Interim varible until values can be read of the SD card
//volatile unsigned short noOfCyclesVal;
volatile unsigned short noOfCyclesLeft;
volatile unsigned short timePerCycleVal;
bool isOccluding = false;

Adafruit_ILI9340 TFTscreen = Adafruit_ILI9340(cs, dc, reset);
Logic::Timer timer = Logic::Timer();
Logic::MemoryParser memory;


Display::Display() {
	// TODO Auto-generated constructor stub
}

Display::~Display() {
	// TODO Auto-generated destructor stub
}


void Display::updateTimeLeft(String value){
	if(lastStopWatchTimeUpdate != value)
		{
	TFTscreen.fillRect(180,220,80,20, ILI9340_BLACK); //Erase previous value
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(180, 220);
	TFTscreen.print(value); //Display the timer
	lastStopWatchTimeUpdate = value;
	}
}
void Display::updateNoOfCycles(unsigned short value){
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(280, 0);
	TFTscreen.print(value);
}
void Display::updateStopWatchTime(String value){
	if(lastStopWatchTimeUpdate != value)
	{
	TFTscreen.fillRect(50,220,80,20, ILI9340_BLACK);
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(50, 220);
	TFTscreen.print(value);
	lastStopWatchTimeUpdate = value;
	}
}

//** IS TO READ FROM THE DATA NAMESPACE **
void Display::updateSensorVal(unsigned short sensorVal){
	//pinMode(sensorPin, INPUT);
	//Delete the previous value
	if(millis()-lastDisplayUpdateTimestamp > 200)
	{
	TFTscreen.setTextColor(ILI9340_BLACK);  TFTscreen.setTextSize(12);
	TFTscreen.setCursor(75, 60);
	TFTscreen.print(sensorValTemp);



	//Draw new value
	TFTscreen.setTextColor(ILI9340_WHITE);  TFTscreen.setTextSize(12);
	TFTscreen.setCursor(75, 60); TFTscreen.print(sensorVal);
	sensorValTemp = sensorVal;

	lastDisplayUpdateTimestamp = millis();
	}
}

void Display::initDisplay(){
	//Setup pin to simulate modeswitch
	TFTscreen.begin();
	TFTscreen.setRotation(3); //Corner with the BL pin
	TFTscreen.fillScreen(ILI9340_BLACK);
}

void Display::clearAreaDisp(unsigned short pointX, unsigned short pointY, unsigned short width, unsigned short height){
	TFTscreen.fillRect(pointX, pointY, width, height, ILI9340_BLACK);
}

void Display::initConditioning(){
	unsigned short noOfCyclesVal = memory.getNoOfCycles();
	noOfCyclesLeft = memory.getNoOfCycles()*2;				//times two to imitate occlude and relaxed cuff

	//Setup pin to read from sensor
	pinMode(sensorPin, INPUT);
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

	TFTscreen.setTextSize(2);
	TFTscreen.setCursor(0, 220);
	TFTscreen.println("Resterende tid: ");
}
void Display::initOcclusion(){
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
unsigned short MAP = 100;
unsigned short SYS = 300;
unsigned short DIA = 100;
unsigned short cuffPressure = 0;
bool donedeflateingOrInflating = false;



if(*btPressed && !*buttonPressed)
{
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setTextSize(3);
	TFTscreen.setCursor(75, 60);
	TFTscreen.println("Arbejder...");


//	s.bloodPressure(&MAP, &SYS, &DIA);

	TFTscreen.setTextColor(ILI9340_BLACK);
	TFTscreen.setCursor(75, 60);
	TFTscreen.println("Arbejder...");

	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setCursor(75, 60);
	TFTscreen.print(util.rawToMmHg(SYS));
	TFTscreen.print("/");
	TFTscreen.print(util.rawToMmHg(DIA));
	TFTscreen.print(" (");
	TFTscreen.print(util.rawToMmHg(MAP));
	TFTscreen.print(")");

	*btPressed = false;

}

if(!*btPressed && *buttonPressed && getNoCycleLeft() != 0){
	TFTscreen.setTextColor(ILI9340_WHITE);
	TFTscreen.setTextSize(3);
	TFTscreen.setCursor(75, 60);
	TFTscreen.println("Arbejder...");


	//s.bloodPressure(&MAP, &SYS, &DIA);

	TFTscreen.setTextColor(ILI9340_BLACK);
	TFTscreen.setTextSize(3);
	TFTscreen.setCursor(75, 60);
	TFTscreen.println("Arbejder...");
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! indsæt metode til at skrive blodtrykket på skærmen

Serial.println("SYS: ");
Serial.println(util.rawToMmHg(SYS));

if(util.rawToMmHg(SYS)<175)
	SYS = util.mmHgToRaw(175);
}
	while(*buttonPressed && getNoCycleLeft() != 0){
		if(noOfCyclesLeft%2)							//uneaven numbers
		{
			cuffPressure =  s.occlude(0);
			if(cuffPressure < util.mmHgToRaw(10) && donedeflateingOrInflating == false)
			{
				donedeflateingOrInflating = true;
				timer.setTimestamp();
				timer.setTimerStatus(false);
				Serial.println("The if was entered");
			}
			else if (cuffPressure > util.mmHgToRaw(10))
				donedeflateingOrInflating = false;
		}
		else
		{
			cuffPressure =  s.occlude(util.rawToMmHg(SYS)+25);
			if(cuffPressure > SYS  && donedeflateingOrInflating == false)
			{
				donedeflateingOrInflating = true;
				timer.setTimestamp();
				timer.setTimerStatus(false);
			}
			else  if (cuffPressure < SYS)
				donedeflateingOrInflating = false;
		}



				if(!timer.getTimerStatus()){ //If timer is running
					if(donedeflateingOrInflating)
						timer.countdown(10); //memory.getTimePerCycle());
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

	if(!*buttonPressed){
		s.occlude(0);
		updateTimeLeft(timer.displayTimer());
		clearAreaDisp(70, 55,220, 150); //Clear the sensor value
	}
	updateNoOfCycles(noOfCyclesLeft); //Reset noOfCycleLeft

	if(memory.getNoOfCycles() == 0)
		*buttonPressed = false;
}
void Display::updateOcclusion(volatile bool *buttonPressed){
	while(*buttonPressed){
		timer.stopWatch();
		updateStopWatchTime(timer.displayTimer());

		updateSensorVal(s.occlusiontraining(&*buttonPressed));

	}
	//This is only executed after the while loop and if the state of "startButtonPressed" is changed
	if(!*buttonPressed)
		timer.setTimerStatus(true);
	//clearAreaDisp(70, 55,220, 150); //Clear the sensor value

	updateSensorVal(s.occlusiontraining(&*buttonPressed));
}
void Display::updateSetup(volatile unsigned short *state){
	switch (*state){
		case 0:
			moveSqaure(165, 55,5,55,140,60);
			break;
		case 1:
			moveSqaure(5,55,165,55,140,60);
			break;
		case 2:
			noInterrupts();
			TFTscreen.setTextSize(5); TFTscreen.setTextColor(ILI9340_WHITE);
			TFTscreen.setCursor(10,70);
			TFTscreen.println(memory.getTimePerCycle());
			interrupts();
			break;
		case 3:
			noInterrupts();
			TFTscreen.setTextSize(5); TFTscreen.setTextColor(ILI9340_WHITE);
			TFTscreen.setCursor(170,70);
			TFTscreen.println(memory.getNoOfCycles());
			interrupts();
			break;
		}
}


//** TO BE MOVE TO DATA NAMESPACE
/*
unsigned short Display::getTimePerCycle(){
	return timePerCycleVal;
}
void Display::setTimePerCycle(unsigned short val){
	timePerCycleVal = val;
}
unsigned short Display::getNoCycle(){
	return noOfCyclesVal;
}
void Display::setNoCycle(unsigned short val){
	noOfCyclesVal = val;
}*/

unsigned short Display::getNoCycleLeft(){
	return noOfCyclesLeft;
}
void Display::setNoCycleLeft(unsigned short val){
	noOfCyclesLeft = val;
}




} /* namespace GUI */


