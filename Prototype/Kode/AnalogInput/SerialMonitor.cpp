// Do not remove the include below
#include "SerialMonitor.h"
#include <EEPROM.h>
#include "Library.cpp"

//Constant variables
const int AnalogIn = 0;     // the number of the pushbutton pin
const unsigned short Arraysize = 600;

//Variables
unsigned short i;
unsigned short time[Arraysize];
unsigned short volt[Arraysize];



//The setup function is called once at startup of the sketch
void setup()
{
/*
	//Clear memory
	  for (int i = 0 ; i < 1000 ; i++) {
	    EEPROM.write(i, 0);
	  }
*/

// Add your initialization code here
//	  pinMode(AnalogIn, INPUT);

	  Serial.begin(9600);
	  //Serial.println("Hello world!");
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
    //Serial.println("Starts sampling on analog pin:0");

    //sample_Data();
	for (i = 0 ; i < Arraysize ; i++)
	  {
	  time[i]=millis();
	  volt[i]=analogRead(AnalogIn);
	  delay(1);
	  }

	  for (i=0;i<Arraysize;i++) {
	    //Serial.print(time[i]);
	    //Serial.print(" , ");
	    //Serial.println(volt[i]);
	    //plot(volt[i]);
	  }

	  delay(500);

}

void sample_Data(){
	  for (int i = 0 ; i < 100 ; i++)
	  {
		  volt[i] = i;
		  Serial.println(volt[i]);
		  delay(5);
	  }
}









