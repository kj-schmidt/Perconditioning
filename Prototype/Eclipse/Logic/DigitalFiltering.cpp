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
	unsigned short startValue = 25;

	if(totalNOPeaks > 0)
	{
		peaks[0] = startValue;
		peaks[totalNOPeaks] = startValue;
		for(i = 1;i<totalNOPeaks; i++)
		{
			peaks[i] = alpha*peaks[i]+(1-alpha)*peaks[i-1];
		}

		for(i = totalNOPeaks-1;i>0; i--)
		{
			peaks[i] = alpha*peaks[i]+(1-alpha)*peaks[i+1];
		}
	}
}

} /* namespace Logic */
