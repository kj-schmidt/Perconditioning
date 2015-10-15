  //Pin setup
  int pin10 = 10; int pin10Val = 0;
  int pin7 = 7;   int pin7Val = 0;
  int pin5 = 5;   int pin5Val = 0;
  int pin2 = 2; int pin2Val = 2; 
  

  //Sensor values
  int sensorValRaw = 0;
  float sensorValVolt = 0;
  float sensorValPres = 0; 
  int sensorPin = A1;

void setup() {
  pinMode(pin10, INPUT);
  pinMode(pin7, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin2, INPUT);

  //Setup motor
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT); 

  //Setup sensor
  pinMode(sensorPin, INPUT); 
  
  Serial.begin(9600); 
}

void loop() {
  //Start pump (Channel A)
  if(digitalRead(pin7) == HIGH){
    digitalWrite(12, HIGH); 
    digitalWrite(9, LOW);
    analogWrite(3,255); 
  } else { //Stop pump
    digitalWrite(9,HIGH); 
  }

  //Open valve
  if(digitalRead(pin5) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(8, LOW);
    analogWrite(11,255); 
  } else{ //Close valve
    digitalWrite(8, HIGH);
    analogWrite(11,0); 
  }

  if(digitalRead(pin2) == HIGH){
    sensorValRaw = analogRead(sensorPin);
    sensorValVolt = sensorValRaw * 4,8;
    sensorValPres = sensorValVolt / 6;

    //Display counts
    Serial.print(sensorValRaw); 
    Serial.print(F(" counts"));
    Serial.print("\t");

    //Display value in millivonltage 
    Serial.print(sensorValVolt); 
    Serial.print(F(" mV"));
    Serial.print("\t\t");

    //Display value in mmHg
    Serial.print(sensorValPres);
    Serial.print(F(" mmHg"));
    Serial.print("\n");
    delay(100);
  }
}
