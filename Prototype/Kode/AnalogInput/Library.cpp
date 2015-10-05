/*
 * Library.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: simon
 */

class Scope{
public:
	static void plot(int data1) //, int data2, int data3, int data4, int data5, int data6)
{
int buffer[20]; //Buffer needed to store data packet for transmission
  int pktSize;

  buffer[0] = 0xCDAB;             //SimPlot packet header. Indicates start of data packet
  buffer[1] = sizeof(int);//6*sizeof(int);      //Size of data in bytes. Does not include the header and size fields
  buffer[2] = data1;
  /*
  buffer[3] = data2;
  buffer[4] = data3;
  buffer[5] = data4;
  buffer[6] = data5;
  buffer[7] = data6;
*/
  pktSize = 2 + 2 + (sizeof(int));//(6*sizeof(int)); //Header bytes + size field bytes + data

  //IMPORTANT: Change to serial port that is connected to PC
  Serial.write((uint8_t * )buffer, pktSize);
  //Serial.write((int *)buffer,pktSize);
}

};

