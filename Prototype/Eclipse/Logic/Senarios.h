/*
 * Senarios.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef SENARIOS_H_
#define SENARIOS_H_

#include "Arduino.h"
#include "BPAlgorithm.h"
#include "DigitalFiltering.h"
#include "../Data/PressureControl.h"
#include "../Data/PressureSampling.h"
#include "MemoryParser.h"
#include "../Utilities.h"
#include "../Logic/Timer.h"




namespace Logic {

class Senarios {

	Utilities util;
	Logic::BPAlgorithm bpa;
	Logic::DigitalFiltering df;
	Data::PressureControl pc;
	Data::PressureSampling ps;
	Logic::MemoryParser mem;
	Logic::Timer timer;
public:

	void bloodPressure(unsigned short *MAP, unsigned short *SYS, unsigned short *DIA); //, Logic::BPAlgorithm bpa, Data::PressureControl pc, Data::PressureSampling ps, Logic::DigitalFiltering df,  Utilities util);
	unsigned short occlusiontraining(volatile bool *start);
	unsigned short occlude(unsigned short pressure);
};

} /* namespace Logic */

#endif /* SENARIOS_H_ */
