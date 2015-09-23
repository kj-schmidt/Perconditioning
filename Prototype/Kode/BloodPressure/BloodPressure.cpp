// Do not remove the include below
#include "BloodPressure.h"
#include <EEPROM.h>


/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int LEDPin =  13; 		// the number of the LED pin
const int DIRA =  12;
const int PWMA =  3;
const int PWMB =  11;
const int buttonPin2 = 4;     // the number of the pushbutton pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int wasHigh = 0;

int sensorValue = 0;
int i = 0;

void setup() {

	//Clear memory
	  for (int i = 0 ; i < 1000 ; i++) {
	    EEPROM.write(i, 0);
	  }

  // initialize the motershield pin as an output:
  pinMode(DIRA, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  //analogWrite(PWMA, 20);
  Serial.begin(9600);


}
void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);


  if(buttonState2 == HIGH)
  {
	  if(wasHigh == 0)
	  {
	  wasHigh = 1;
	  }
	  else if(wasHigh == 1)
	  {
		  wasHigh = 2;
	  }
	  else if(wasHigh == 4)
	  {
		  wasHigh = 5;
	  }
	  else if(wasHigh == 5)
	  {
		  wasHigh = 6;
	  }
  }
  else
  {
	  if(wasHigh == 2)
	  {
	  wasHigh = 3;
	  }
	  else if(wasHigh == 3)
	  {
		  wasHigh = 4;
	  }
	  else if(wasHigh == 6)
	  {
		  wasHigh = 7;
	  }
	  else if(wasHigh == 7)
	  {
		  wasHigh = 0;
	  }
  }




  if (buttonState1 == HIGH)
  {
    // turn LED on:
    digitalWrite(DIRA, HIGH);
    digitalWrite(LEDPin, HIGH);

    analogWrite(PWMB, 255);
    //analogWrite(PWMA, 128);
  }
  else if(wasHigh==4)
  {
	  analogWrite(PWMA, 255);
	  //digitalWrite(DIRA, HIGH);
	  digitalWrite(LEDPin, HIGH);
  }
  else if (wasHigh==0)
  {
	  analogWrite(PWMA, 0);
	  //digitalWrite(DIRA, LOW);
	  digitalWrite(LEDPin, LOW);

  }
  //delay(500)

  // read the input on analog pin 0:
    sensorValue = analogRead(A1);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    //print out the value you read:
    Serial.println(voltage);

}

