#include "DataProces.h"

//Pin setup
  int pin10 = 10; int pin10Val = 0;
  int pin7 = 7;   int pin7Val = 0;
  int pin5 = 5;   int pin5Val = 0;
  int pin2 = 2; int pin2Val = 2; 
  

  //Sensor values
  int sensorValRaw = 0;
  float sensorValVolt = 0;
  float sensorValPres = 0; 
  int sensorPin = A2;


  //Constant variables
  short currentScale = 3;   //(3.3/5*1024)/2000*3; //converts 10bit input to 3mA
void setup() {
  pinMode(pin10, INPUT);
  pinMode(pin7, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin2, INPUT);

  //Setup motor
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(3, OUTPUT); 		//PWMA
  pinMode(11, OUTPUT);		//PWMB

  //Setup sensor
  pinMode(sensorPin, INPUT); 
  
  Serial.begin(9600); 

  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  //Start pump (Channel A)
  if(digitalRead(pin7) == HIGH){
	digitalWrite(3, HIGH);
  }
  else if(digitalRead(pin2) == HIGH)
  {
	    analogWrite(3,140);
  }
  else
	  digitalWrite(3, LOW);

  //Open valve
  if(digitalRead(pin5) == HIGH){
    digitalWrite(11, HIGH);

  } else{ //Close valve

	digitalWrite(11, LOW);
  }



sensorValRaw = analogRead(sensorPin)-45;
Serial.print(sensorValRaw/1.21);
Serial.print("mmHg\t");
Serial.print(sensorValRaw);
Serial.print("Raw\tMoterCurrent: ");
Serial.print(analogRead(A0)*currentScale);
Serial.print("mA\n");
delay(100);
}















