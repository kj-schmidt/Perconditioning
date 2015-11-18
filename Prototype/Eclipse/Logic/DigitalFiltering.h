/*
 * DigitalFiltering.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef DIGITALFILTERING_H_
#define DIGITALFILTERING_H_

#include "Arduino.h"

namespace Logic {

class DigitalFiltering {
public:

	void averagingZeroGroupDelay(unsigned short peaks[],unsigned short peakArrayLength, unsigned short *totalNumberOfPeaks, double alpha);
};

} /* namespace Logic */

#endif /* DIGITALFILTERING_H_ */
