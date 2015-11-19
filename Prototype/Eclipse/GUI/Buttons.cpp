/*
 * Buttons.cpp
 *
 *  Created on: 30/10/2015
 *      Author: kjschmidt
 */

#include "Buttons.h"

namespace GUI {

//values handle by interrupts

volatile unsigned short state = 0; //volatile enable the value to change during an interrupt
//volatile bool startButtonPressed= false;
//volatile bool btPressed = false;

//pin values for modeswitch
unsigned short conditioningPin = 26;
unsigned short occlusionPin = 24;
unsigned short setupPin = 22;
unsigned short modeSwitch = 0; //values to ensure mode only can be change after reset

//Create an object of the display class
GUI::Display disp;
Logic::Timer timerButtons = Logic::Timer();
Logic::MemoryParser memoryBT;

Buttons::Buttons() {
	// TODO Auto-generated constructor stub
}

Buttons::~Buttons() {
	// TODO Auto-generated destructor stub
}

unsigned short Buttons::readModeSwitch(){
	//Setup pin to simulate modeswitch
	pinMode(conditioningPin, INPUT);
	pinMode(occlusionPin, INPUT);
	pinMode(setupPin, INPUT);

	if(digitalRead(conditioningPin)){
		disp.initConditioning();
		modeSwitch = 1;
	} else if(digitalRead(occlusionPin)){
		disp.initOcclusion();
		modeSwitch = 2;
	} else if(digitalRead(setupPin)){
		disp.initSetup();
		modeSwitch = 3;
	} else
		modeSwitch = 0;
	return modeSwitch;
}

unsigned short Buttons::changer(volatile unsigned short state){
	if(state == 0)
		state = 1;
	else if(state == 1)
		state = 0;
	else if(state == 2)
		if(memoryBT.getTimePerCycle() <= 450){
			disp.clearAreaDisp(10, 70, 90, 40); //Erase old value
			memoryBT.setTimePerCycle(memoryBT.getTimePerCycle()+30);
		}else{
			disp.clearAreaDisp(10, 70, 90, 40);
			memoryBT.setTimePerCycle(180);
		}
	else if(state == 3){
		if(memoryBT.getNoOfCycles() <=4){
			disp.clearAreaDisp(170, 70, 35, 40);
			memoryBT.setNoOfCycles(memoryBT.getNoOfCycles()+1);

		}else{
			disp.clearAreaDisp(170, 70, 35, 40);
			memoryBT.setNoOfCycles(1);
		}
	}
	return state;
}

unsigned short Buttons::selector(volatile unsigned short state){
	if(state == 0)
		state = 2;
	else if(state ==1)
		state = 3;
	else if(state ==2)
		state = 0;
	else if(state ==3)
		state = 1;
	return state;
}

bool Buttons::startStopOcclusion(volatile bool startButtonPressed){
	if(!startButtonPressed){
		disp.clearAreaDisp(50, 20, 80, 30);
		timerButtons.setTimestamp();

	}
	startButtonPressed = !startButtonPressed; //Invert the value of state
	return startButtonPressed;
}

void Buttons::startStopConditiong(volatile bool *startButtonPressed){
	//Clear the timer to set disp for new conditioning threatment
	*startButtonPressed = !*startButtonPressed; //Invert the value of state

	if(!*startButtonPressed){
		disp.clearAreaDisp(180, 220, 80, 30);
		disp.clearAreaDisp(2890, 0, 10, 20);
		disp.setNoCycleLeft(memoryBT.getNoOfCycles()*2); //Reset the no of cycles
		// X2 to handle both occlusion and perfusion

		//Save info, that the conditioning was interrupted
		memoryBT.writeToSDCard(timerButtons.timeToString(), false, 0, 0, 0, 0, true);
	} else
		timerButtons.setTimestamp();//Set the starting point for the timer


}
void Buttons::btPressed(volatile bool *btPressed){
	//Only handles interrupt if conditioning is not ongoing
	*btPressed = !*btPressed;
	if(!*btPressed){
		//initialyze blood pressure reading
	}

}

} /* namespace GUI */
