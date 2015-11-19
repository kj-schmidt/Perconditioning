
#include "Arduino.h"
#include "GUI/Buttons.h"
#include "GUI/Display.h"
#include "Data/PressureControl.h"
#include "Data/PressureSampling.h"
#include "Data/ExternalMemory.h"
#include "Logic/DigitalFiltering.h"
#include "Logic/BPAlgorithm.h"
#include "Logic/Senarios.h"
#include "Utilities.h"

#define cs 	34
#define dc 	32
#define reset	30

//Pin setup
int interruptPin0 = 18;
int interruptPin1 = 19;
const short PressurePin = A2;
const short OcyliationPin = A3;


volatile unsigned short state;
volatile bool startStopPressed = false;
volatile bool btPressed = false;

unsigned short programToRun = 0;

//instances
GUI::Buttons btt;
GUI::Display disp;
Data::ExternalMemory ex;

//The setup function is called once at startup of the sketch
void intCon_ISR(){
	delay(100);
	if(digitalRead(interruptPin0))
		btt.startStopConditiong(&startStopPressed);
}
void intBT_ISR(){
	delay(100);
	if(digitalRead(interruptPin1))
		btt.btPressed(&btPressed);
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
	/*SD.begin(4); //Initialize SD card
	ex.checkFilesSD();*/
	Serial.begin(9600);

	disp.initDisplay();

	programToRun = btt.readModeSwitch();

	//Pin setup
	pinMode(3, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);
		//For i interrupts
		pinMode(interruptPin0, INPUT);
		pinMode(interruptPin1, INPUT);

	switch(programToRun){
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
		disp.updateConditioning(&startStopPressed, &btPressed);
		break;
	case 2: //Occlusion
		disp.updateOcclusion(&startStopPressed);
		break;
	case 3: //Setup
		disp.updateSetup(&state);
		break;
	}
}




