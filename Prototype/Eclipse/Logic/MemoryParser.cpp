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
	if(val == 255) // if value is larger than 255 read the next Byte on EEPROM
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
			String(sys, DEC) + "," + String(map, DEC) + "," + String(dia, DEC) + "," + String(interruptOcclusion)); //converts row data to string.

	extMem.writeToSDCard(totalString);//writes string to SD-card
}

String MemoryParser::getID(){
	String filename = extMem.getFilename(); //get filename of current .csv file
	return filename.substring(0,5); //retun patient ID
}

bool MemoryParser::startInitSD(){
	return extMem.initializeSD();
}



} /* namespace Logic */
