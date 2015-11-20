/*
 * MemoryParser.cpp
 *
 *  Created on: 09/11/2015
 *      Author: kjschmidt
 */

#include "MemoryParser.h"

namespace Logic {

Data::InternalMemory intMem;
Data::ExternalMemory extMem;

MemoryParser::MemoryParser() {
	// TODO Auto-generated constructor stub

}

MemoryParser::~MemoryParser() {
	// TODO Auto-generated destructor stub
}

unsigned short MemoryParser::getNoOfCycles(){
	return intMem.readFromEEPROM(200);
}
void MemoryParser::setNoOfCycles(unsigned short val){
	intMem.writeToEEPROM(200, val);
}

unsigned short MemoryParser::getTimePerCycle(){
	//Handle overload
	unsigned short val = intMem.readFromEEPROM(205);
	unsigned overloadVal = 0;
	if(val == 255)
		return overloadVal = val + intMem.readFromEEPROM(206);
	else
		return val;
}
void MemoryParser::setTimePerCycle(unsigned short val){
	//Handle overload
	if(val > 255){
			unsigned short rest = val % 255;
			unsigned short valtoFit = val - rest;
			intMem.writeToEEPROM(205, valtoFit);
			intMem.writeToEEPROM(206, rest);
		}
		else
			intMem.writeToEEPROM(205, val);
}


void MemoryParser::writeToSDCard(String timeStamp, boolean occlusionComplete,
		unsigned short occlusionPressure, unsigned short sys, unsigned short map, unsigned short dia, boolean interruptOcclusion){
	String totalString = String(timeStamp + "," + String(occlusionComplete) + "," + String(occlusionPressure, DEC) + "," +
			String(sys, DEC) + "," + String(map, DEC) + "," + String(dia, DEC) + "," + String(interruptOcclusion));

	extMem.writeToSDCard(totalString);
}

String MemoryParser::getID(){
	String filename = extMem.getFilename();
	return filename.substring(0,5);
}

void MemoryParser::startInitSD(){
	extMem.initializeSD();
}



} /* namespace Logic */