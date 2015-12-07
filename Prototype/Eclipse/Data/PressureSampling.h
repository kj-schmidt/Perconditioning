/*
 * PressureSampling.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef PRESSURESAMPLING_H_
#define PRESSURESAMPLING_H_

#include "Arduino.h"
#include "PressureControl.h"
#include "../Utilities.h"

namespace Data {

class PressureSampling {
public:
	unsigned short getCuffPressure(); //this method returs the current cuffpresure. 10 values are sampled and the average value is the current cuffpressure
	void runningPeakDetect(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
				unsigned short *totalNumberOfPeaks, PressureControl pc, Utilities util, volatile bool *btPressed); //This method samples pressure data and detects peaks.
	//if a peak is detected it is saved in peaks[] allongside a cuffpressure value in cuffPressure[]. when the pressure gets lower than 40mmHg the cuff is deflated to 0.



};

} /* namespace Data */

#endif /* PRESSURESAMPLING_H_ */
