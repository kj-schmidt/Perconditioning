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

		unsigned short i;
		unsigned short loc = 0; //location MAP i arrays
		unsigned short maxValue1 = 0; //max peak hieght
		unsigned short tNOPeaks = *totalNumberOfPeaks; //total number of peaks

		for( i=0; i<tNOPeaks; i++)
		{
			if(peaks[i]>maxValue1) //if the new peak height is higher than the last value
			{
				maxValue1 = peaks[i]; //save peak value
				loc = i; //save peak location
			}
		}


		return cuffPressure[loc]; //returns MAP value
	};


unsigned short BPAlgorithm::calculateSYS(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
		unsigned short *totalNumberOfPeaks, unsigned short MAP)
{
	unsigned short i;
	double fixedRatio = 0.38; //the fixed-ratio of where the SYS can be found i data
	unsigned short loc = 0; //location of MAP
	unsigned short maxValue1 = 0; //max peak hieght
	unsigned short SYS = 0; //SYS value
	int currentClosestPeakhight; //the closest peak hight to SYS
	int tmpValue = 1000;
	unsigned short tNOPeaks = *totalNumberOfPeaks; //total number of peaks


	for( i=0; i<tNOPeaks; i++) //find MAP
			{
				if(peaks[i]>maxValue1)
				{
					maxValue1 = peaks[i];
					loc = i;
				}
			}
	int peakHightSys = peaks[loc]*fixedRatio; //calculate the estimated peakhight of SYS

	for(i=0;i<tNOPeaks;i++) //find SYS array
	{
		if(cuffPressure[i] == MAP) //calculate the estimated peakhight of SYS
		{
			break;
		}
		currentClosestPeakhight = peaks[i]-peakHightSys;
		currentClosestPeakhight = abs(currentClosestPeakhight); //The distance between current value and the estimated SYS value
		if (currentClosestPeakhight<tmpValue) //if value is closer than the last save value. save the new one
		{

			SYS = cuffPressure[i]; //save cuffpressure
			tmpValue = currentClosestPeakhight; //save peak height
		}
	}
	return SYS;
}

unsigned short BPAlgorithm::calculateDIA(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
		unsigned short *totalNumberOfPeaks, unsigned short MAP)
{
	unsigned short i;
	double fixedRatio = 0.48; //the fixed-ratio of where the SYS can be found i data
	unsigned short loc = 0; //location of MAP
	unsigned short maxValue1 = 0; //max peak hieght
	unsigned short DIA = 0; //DIA value
	int currentClosestPeakhight;  //the closest peak height to DIA
	int tmpValue = 1000;
	unsigned short tNOPeaks = *totalNumberOfPeaks; //total number of peaks


	for( i=0; i<tNOPeaks; i++) //find MAP
			{
				if(peaks[i]>maxValue1)
				{
					maxValue1 = peaks[i];
					loc = i;
				}
			}
	int peakHightDia = peaks[loc]*fixedRatio; //calculate the estimated peakhight of DIA


	for(i=loc;i<tNOPeaks;i++) //calculate the estimated peakhight of SYS
	{
		currentClosestPeakhight = peaks[i]-peakHightDia; //The distance between current value and the estimated SYS value
		currentClosestPeakhight = abs(currentClosestPeakhight); //if value is closer than the last save value. save the new one
		if (currentClosestPeakhight<tmpValue)
		{
			DIA = cuffPressure[i]; //save cuffpressure
			tmpValue = currentClosestPeakhight; //save peak height
		}
	}
	return DIA;
}

} /* namespace Logic */
