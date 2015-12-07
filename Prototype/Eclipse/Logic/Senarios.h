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

private:
static long tmpTimestamp;

//create instances of used classes
	Utilities util;
	Logic::BPAlgorithm bpa;
	Logic::DigitalFiltering df;
	Data::PressureControl pc;
	Data::PressureSampling ps;
	Logic::MemoryParser mem;
	Logic::Timer timer;
public:

	void bloodPressure(unsigned short *MAP, unsigned short *SYS, unsigned short *DIA, volatile bool *btPressed); //contains senario that runs a bloodpressure senario.
	unsigned short occlusiontraining(volatile bool *start); //contains senario that runs a occlutiontraining senario.
	unsigned short occlude(unsigned short pressure); //contains senario that runs a occlude senario.
};

} /* namespace Logic */

#endif /* SENARIOS_H_ */
