/*
 * InternalMemory.cpp
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#include "InternalMemory.h"

namespace Data {

InternalMemory::InternalMemory() {
	// TODO Auto-generated constructor stub

}

InternalMemory::~InternalMemory() {
	// TODO Auto-generated destructor stub
}
void InternalMemory::writeToEEPROM(int adr, unsigned short value){
	EEPROM.write(adr, value);
}


unsigned short InternalMemory::readFromEEPROM(int adr){
	return EEPROM.read(adr);
}

} /* namespace Data */
