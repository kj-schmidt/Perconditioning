/*
 * MemoryParser.h
 *
 *  Created on: 09/11/2015
 *      Author: kjschmidt
 */

#ifndef LOGIC_MEMORYPARSER_H_
#define LOGIC_MEMORYPARSER_H_

#include "../Data/ExternalMemory.h"
#include "../Data/InternalMemory.h"


namespace Logic {

class MemoryParser {
public:
	MemoryParser();
	virtual ~MemoryParser();

	unsigned short getNoOfCycles();
	void setNoOfCycles(unsigned short val);

	unsigned short getTimePerCycle();
	void setTimePerCycle(unsigned short val);

	String getID();

	void writeToSDCard(String timeStamp, boolean occlusionComplete, unsigned short occlusionPressure, unsigned short sys, unsigned short map, unsigned short dia, boolean interruptOcclusion);
};

} /* namespace Logic */

#endif /* LOGIC_MEMORYPARSER_H_ */
