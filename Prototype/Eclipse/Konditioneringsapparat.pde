
#include "Arduino.h"
#include "GUI/Buttons.h"
#include "GUI/Display.h"
#include "Data/ExternalMemory.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9340.h"

#define cs 	34
#define dc 	32
#define reset	30

int interruptPin0 = 18;
int interruptPin1 = 20;

volatile unsigned short state;
volatile bool startStopPressed = false;
volatile bool btPressed = false;

unsigned short programToRun = 0;

GUI::Buttons btt;
GUI::Display disp;
Logic::Timer timer;
Data::ExternalMemory ext;
Logic::MemoryParser mem;
//The setup function is called once at startup of the sketch

void intCon_ISR(){
	delay(100);
	if(digitalRead(interruptPin0))
		startStopPressed = btt.startStopConditiong(startStopPressed);
}
void intBT_ISR(){
	delay(100);
	if(digitalRead(interruptPin1))
		startStopPressed = btt.btPressed(btPressed);
}
void intOcc_ISR(){
	startStopPressed = btt.startStopOcclusion(startStopPressed);
}
void intCha_ISR(){
	delay(100);
	if(digitalRead(interruptPin0))
		state = btt.changer(state);
}
void intSel_ISR(){
	delay(100);
	if(digitalRead(interruptPin1))
		state = btt.selector(state);
}


void setup()
{
	Serial.begin(9600);
	/*ext.initializeSDCard();
	mem.writeToSDCard(timer.timeToString(), false, 130, 180, 140, 120, false);
	ext.readFromSDCard();*/
	//*****
	disp.initDisplay();

	programToRun = btt.readModeSwitch();

	//Setup for i interrupts
	pinMode(interruptPin0, INPUT);
	pinMode(interruptPin1, INPUT);

	switch(btt.readModeSwitch()){
		case 1: //Conditioning
			attachInterrupt(digitalPinToInterrupt(interruptPin0), intCon_ISR, RISING);
			attachInterrupt(digitalPinToInterrupt(interruptPin1), intBT_ISR, RISING);
			break;
		case 2: //Occlusion
			attachInterrupt(digitalPinToInterrupt(interruptPin0), intOcc_ISR, RISING);
			break;
		case 3: //Setup
			attachInterrupt(digitalPinToInterrupt(interruptPin0), intCha_ISR, RISING);
			attachInterrupt(digitalPinToInterrupt(interruptPin1), intSel_ISR, RISING);
			break;
		}
}

void loop()
{
	switch(programToRun){
	case 1: //Conditioning
		disp.updateConditioning(&startStopPressed);
		break;
	case 2: //Occlusion
		disp.updateOcclusion(&startStopPressed);
		break;
	case 3: //Setup
		disp.updateSetup(&state);
		break;
	}
}




