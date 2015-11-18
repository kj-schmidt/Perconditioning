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
	unsigned short getCuffPressure();
	void runningPeakDetect(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
				unsigned short *totalNumberOfPeaks, PressureControl pc, Utilities util);


};

} /* namespace Data */

#endif /* PRESSURESAMPLING_H_ */
