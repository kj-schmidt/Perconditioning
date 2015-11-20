/*
 * PressureSampling.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

//#include "Arduino.h"
#include "PressureSampling.h"
//#include "Utilities.h"

namespace Data {

unsigned short PressureSampling::getCuffPressure()
{
	int tmpValue = 0;

	for(int i = 0;i<10; i++)
	{
		tmpValue = tmpValue + analogRead(A3);
	}
	return (unsigned short)(tmpValue/10);
}


void PressureSampling::runningPeakDetect(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
		unsigned short *totalNumberOfPeaks, PressureControl pc, Utilities util, volatile bool *btPressed)
{
	unsigned short thresshold = 25; //The minimum amplitude of the occiliations for an accepted peak.
	unsigned short tNOPeaks = *totalNumberOfPeaks;
	unsigned short i;
	unsigned short currentPressure = getCuffPressure();
	unsigned short startCuffPressure = currentPressure;
	unsigned long timestamp = millis();
	unsigned short valveOpenTime = 7;

	unsigned short n12 = (unsigned short)analogRead(A4);
	unsigned short n11 = n12;
	unsigned short n10 = n12;
	unsigned short n9 = n12;
	unsigned short n8 = n12;
	unsigned short n7 = n12;
	unsigned short n6 = n12;
	unsigned short n5 = n12;
	unsigned short n4 = n12;
	unsigned short n3 = n12;
	unsigned short n2 = n12;
	unsigned short n1 = n12;
	unsigned short n = n12;
//Serial.println(n6);
delay(1000);

	while(currentPressure > util.mmHgToRaw(40) && *btPressed)
	{
//Serial.print(n6);
//Serial.print(",");

		if(n<600)
		{
				if(timestamp<millis()-400 && n6>thresshold && (n12+n11+n10+n9+n8+n7)/6 < n6 && (n+n1+n2+n3+n4+n5)/6 < n6)
				{
					peaks[tNOPeaks] = n6;
					cuffPressure[tNOPeaks] = getCuffPressure();
					tNOPeaks++;

					pc.turnValveOn();
					delay(valveOpenTime);
					pc.turnValveOff();

					timestamp = millis();

					valveOpenTime = (startCuffPressure-currentPressure)/10;
					if(valveOpenTime>50)
						valveOpenTime = 3;

Serial.print("\nValveTime: ");
Serial.print(valveOpenTime);
Serial.print("\n ");
Serial.print("\nPeak: ");
Serial.print(n6);
Serial.print("		CuffPressure: ");
Serial.print(util.rawToMmHg(cuffPressure[tNOPeaks-1]));

					}
		}
		else
		{
			delay(1000);
				n12 = n11 = n10 = n9 = n8 = n7 = n6 = n5 = n4 = n3 = n2 = n1 = n = (unsigned short)analogRead(A4);
		}

		n12 = n11;
		n11 = n10;
		n10 = n9;
		n9 = n8;
		n8 = n7;
		n7 = n6;
		n6 = n5;
		n5 = n4;
		n4 = n3;
		n3 = n2;
		n2 = n1;
		n1 = n;

		n = (unsigned short)analogRead(A4);

		currentPressure = getCuffPressure();


		if(timestamp<millis()-2000)
		{
//Serial.print((int)millis);
			pc.turnValveOn();
			delay(30);
			pc.turnValveOff();
			timestamp = millis();
		}
//Serial.println(n6);
	}

	for(i = tNOPeaks; i < peakArrayLength; i++)
	{
		peaks[i] = NULL;
		cuffPressure[i] = NULL;
	}

	if(tNOPeaks == 0)
	{
		for (i = 0; i<tNOPeaks; i++)
		{
			peaks[i] = NULL;
			cuffPressure[i] = NULL;
		}
	}

	while(getCuffPressure() > util.mmHgToRaw(10))
	{
		pc.turnValveOn();
	}
	pc.turnValveOff();


*totalNumberOfPeaks = tNOPeaks;
}



} /* namespace Data */
