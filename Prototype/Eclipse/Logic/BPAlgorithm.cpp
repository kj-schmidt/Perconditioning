/*
 * BPAlgorithm.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "BPAlgorithm.h"

namespace Logic {

unsigned short BPAlgorithm::calculateMAP(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
			unsigned short *totalNumberOfPeaks)
	{
		//double MAP;
		unsigned short i;
		unsigned short loc = 0;
		unsigned short maxValue1 = 0;
		//unsigned short maxValue2 = 0;
		//unsigned short maxValue3 = 0;
		unsigned short tNOPeaks = *totalNumberOfPeaks;

		for( i=0; i<tNOPeaks; i++)
		{
			if(peaks[i]>maxValue1)
			{
				maxValue1 = peaks[i];
				//maxValue2 = maxValue1;
				//maxValue3 = maxValue2;
				loc = i;
			}
		}


		return cuffPressure[loc];
	};


unsigned short BPAlgorithm::calculateSYS(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
		unsigned short *totalNumberOfPeaks, unsigned short MAP)
{
	unsigned short i;
	unsigned short loc = 0;
	unsigned short maxValue1 = 0;
	unsigned short SYS = 0;
	//int peakHightSys = MAP *0.6;
	int currentClosestPeakhight;
	int tmpValue = 1000;
	unsigned short tNOPeaks = *totalNumberOfPeaks;


	for( i=0; i<tNOPeaks; i++)
			{
				if(peaks[i]>maxValue1)
				{
					maxValue1 = peaks[i];
					//maxValue2 = maxValue1;
					//maxValue3 = maxValue2;
					loc = i;
				}
			}
	int peakHightSys = peaks[loc]*0.38;


	for(i=0;i<tNOPeaks;i++)
	{
		if(cuffPressure[i] == MAP)
		{
			Serial.print("\n BREAK\n");
			break;
		}
		currentClosestPeakhight = peaks[i]-peakHightSys;
		currentClosestPeakhight = abs(currentClosestPeakhight);
		if (currentClosestPeakhight<tmpValue)
		{

			SYS = cuffPressure[i];
			tmpValue = currentClosestPeakhight;
		}
	}
	return SYS;
}

unsigned short BPAlgorithm::calculateDIA(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
		unsigned short *totalNumberOfPeaks, unsigned short MAP)
{
	unsigned short i;
	unsigned short loc = 0;
	unsigned short maxValue1 = 0;
	unsigned short DIA = 0;
	//int peakHightSys = MAP *0.6;
	int currentClosestPeakhight;
	int tmpValue = 1000;
	unsigned short tNOPeaks = *totalNumberOfPeaks;


	for( i=0; i<tNOPeaks; i++)
			{
				if(peaks[i]>maxValue1)
				{
					maxValue1 = peaks[i];
					//maxValue2 = maxValue1;
					//maxValue3 = maxValue2;
					loc = i;
				}
			}
	int peakHightDia = peaks[loc]*0.48;


	for(i=loc;i<tNOPeaks;i++)
	{
		currentClosestPeakhight = peaks[i]-peakHightDia;
		currentClosestPeakhight = abs(currentClosestPeakhight);
		if (currentClosestPeakhight<tmpValue)
		{
			DIA = cuffPressure[i];
			tmpValue = currentClosestPeakhight;
		}
	}
	return DIA;
}

} /* namespace Logic */
