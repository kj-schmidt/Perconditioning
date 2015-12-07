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

	unsigned short getNoOfCycles(); //reads number of cycles saved on EEPROM
	void setNoOfCycles(unsigned short val); //sets number of cycles onto EEPROM

	unsigned short getTimePerCycle(); //reads time per cycle saved on EEPROM
	void setTimePerCycle(unsigned short val); //save time per cycle onto EEPROM

	String getID(); //get filneme of current .csf file
	bool startInitSD(); //iniatialize SD-card

	void writeToSDCard(String timeStamp, boolean occlusionComplete, unsigned short occlusionPressure, unsigned short sys, unsigned short map, unsigned short dia, boolean interruptOcclusion); //write row of data to SD-card
};

} /* namespace Logic */

#endif /* LOGIC_MEMORYPARSER_H_ */
