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

	//mean of 10 samples
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
	unsigned short tNOPeaks = *totalNumberOfPeaks; //total number of detected peaks
	unsigned short i;
	unsigned short currentPressure = getCuffPressure(); //current cuffpressure
	unsigned short startCuffPressure = currentPressure; //cuffpressuare at the begining of this method
	unsigned long timestamp = millis(); //current timestamp
	unsigned short valveOpenTime = 7; //how long the valve is supposed to be open

	//the 13 temp values containing the sampled oscilloations
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

delay(1000);

	while(currentPressure > util.mmHgToRaw(40) && *btPressed)
	{

		if(n<600)
		{
				if(timestamp<millis()-400 && n6>thresshold && (n12+n11+n10+n9+n8+n7)/6 < n6 && (n+n1+n2+n3+n4+n5)/6 < n6) //if more than 0.4 sec. has passed since last peak and a minimum height of the peak is acheaved.
				{
					peaks[tNOPeaks] = n6; //save peak height
					cuffPressure[tNOPeaks] = getCuffPressure(); //save current cuffpressure
					tNOPeaks++; //add one to total number of peaks

					pc.turnValveOn(); //open valve
					delay(valveOpenTime); //wait some time
					pc.turnValveOff(); // close valve

					timestamp = millis(); //get new timestamp

					valveOpenTime = (startCuffPressure-currentPressure)/10; //change vale open time according to cuffpresure
					if(valveOpenTime>50) //error handling
						valveOpenTime = 3;

					}
		}
		else // if no peak is detected
		{
			delay(1000); //wait
				n12 = n11 = n10 = n9 = n8 = n7 = n6 = n5 = n4 = n3 = n2 = n1 = n = (unsigned short)analogRead(A4); //get new sampled value to prevent peak detected
		}

		// move detected values to make room for a new sample at n
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

		currentPressure = getCuffPressure(); //get current cuffpressure


		if(timestamp<millis()-2000) //if no peaks has been detected for two sec
		{
			pc.turnValveOn(); //open valve
			delay(30);
			pc.turnValveOff(); //close valve
			timestamp = millis(); //get new timestamp
		}
	}

	for(i = tNOPeaks; i < peakArrayLength; i++) //insert NULL into the remaining non-used places in arrays
	{
		peaks[i] = NULL;
		cuffPressure[i] = NULL;
	}

	if(tNOPeaks == 0) //if no peaks were detected
	{
		for (i = 0; i<tNOPeaks; i++)
		{
			peaks[i] = NULL;
			cuffPressure[i] = NULL;
		}
	}

	while(getCuffPressure() > util.mmHgToRaw(10)) //deflate the cuff when done detecting peaks
	{
		pc.turnValveOn();
	}
	pc.turnValveOff();


*totalNumberOfPeaks = tNOPeaks; //save total number of peaks detected
}



} /* namespace Data */
