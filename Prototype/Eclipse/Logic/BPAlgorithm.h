/*
 * BPAlgorithm.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef BPALGORITHM_H_
#define BPALGORITHM_H_

#include "Arduino.h"

namespace Logic {

class BPAlgorithm {

public:
	unsigned short calculateMAP(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
			unsigned short *totalNumberOfPeaks); //calculated the MAP from given data
	unsigned short calculateSYS(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
			unsigned short *totalNumberOfPeaks, unsigned short MAP); //calculate SYS from MAP and data
	unsigned short calculateDIA(unsigned short peaks[], unsigned short cuffPressure[],unsigned short peakArrayLength,
			unsigned short *totalNumberOfPeaks, unsigned short MAP); //calculate DIA from MAP and data
};

} /* namespace Logic */

#endif /* BPALGORITHM_H_ */
