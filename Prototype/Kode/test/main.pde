#include "Arduino.h"
#include "testLib.h"
//#include <avr/pgmspace.h>
//using namespace testspace;

//instances

	Library lib;


	//Constant variables
	const short Arraysize = 50;
	const short ArraysizeCuffPress = 200;
	const short ArraysizeOcyliationPeaks = 200;
	//String startupMeassage = String("Halloo world!!");


	//Variables
	short i;
	short tmpValue;
	short tmpPeakValue;
	unsigned short currentPressure;
	short count = 0;
	unsigned short volt[Arraysize];
	unsigned short cuffPressure[ArraysizeCuffPress];
	unsigned short OcyliationPeaks[ArraysizeOcyliationPeaks];


	//Pin setup
	const short PressurePin = A2;
	const short OcyliationPin = A3;

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	  Serial.begin(9600);

	  while (!Serial) {
	    ; // wait for serial port to connect. Needed for native USB port only
	  }

	//  Serial.println(F("Halloo world!!"));



}

// The loop function is called in an endless loop
void loop()
{

	//char x[] = "test is on the way";
	//lib.printHaloo(x);


	//sample_Data();
	tmpValue = 0;
	tmpPeakValue = 0;
		for (i = 0 ; i < Arraysize ; i++)
		  {
			tmpValue = analogRead(OcyliationPin);
			volt[i] =tmpValue;
			if(tmpValue > tmpPeakValue)
				tmpPeakValue = tmpValue;
			delay(1);
		  }
		currentPressure = (unsigned short)analogRead(PressurePin);
		cuffPressure[count] = currentPressure;
		OcyliationPeaks[count] = tmpPeakValue;
		count++;
		/*
		for (i = 0; i < Arraysize; i++) {
		  //Serial.println(volt[i]);
		  lib.plot2(volt[i],currentPressure);
		}
		*/

		if(count == ArraysizeOcyliationPeaks)
		{
			for (i = 0; i < ArraysizeOcyliationPeaks; i++) {
				//Serial.println(volt[i]);
				lib.plot2(OcyliationPeaks[i],cuffPressure[i]);
			}
			count = 0;
		}


		//lib.plot2(currentPressure);
	//	Serial.println(volt[1]);
		//lib.plot(volt);

//	lib.plot(analogRead(AnalogIn));


	//delay(2000);
//Add your repeated code here
	
}

/*
int main(void)
{
     init();
     setup();
     for (;;)
           loop();
     return 0;
}
*/
