#include "Arduino.h"
#include "testLib.h"

//using namespace testspace;


void Library::plot(unsigned short data1) //, int data2, int data3, int data4, int data5, int data6)
{
	unsigned short buffer[20]; //Buffer needed to store data packet for transmission
	unsigned short pktSize;

  buffer[0] = 0xCDAB;             //SimPlot packet header. Indicates start of data packet
  buffer[1] = sizeof(unsigned short);//6*sizeof(int);      //Size of data in bytes. Does not include the header and size fields
  buffer[2] = data1;


 // buffer[3] = data2;
 // buffer[4] = data3;
 // buffer[5] = data4;
 // buffer[6] = data5;
 // buffer[7] = data6;

  pktSize = 2 + 2 + (sizeof(unsigned short));//(6*sizeof(int)); //Header bytes + size field bytes + data

  //IMPORTANT: Change to serial port that is connected to PC
Serial.write((uint8_t * )buffer, pktSize);

};

void Library::printHaloo(char x[])
{
	Serial.println(x);
};

