/*
 * DigitalFiltering.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "DigitalFiltering.h"

namespace Logic {

void DigitalFiltering::averagingZeroGroupDelay(unsigned short peaks[],unsigned short peakArrayLength, unsigned short *totalNumberOfPeaks, double alpha)
{
	unsigned short i;
	unsigned short totalNOPeaks = *totalNumberOfPeaks;
	unsigned short startValue = 25; //start value at the ends of the dataset filtering

	if(totalNOPeaks > 0)
	{
		peaks[0] = startValue;
		peaks[totalNOPeaks] = startValue;
		for(i = 1;i<totalNOPeaks; i++) //filter from left to right
		{
			peaks[i] = alpha*peaks[i]+(1-alpha)*peaks[i-1];
		}

		for(i = totalNOPeaks-1;i>0; i--) //filter from right to left
		{
			peaks[i] = alpha*peaks[i]+(1-alpha)*peaks[i+1];
		}
	}
}

} /* namespace Logic */
