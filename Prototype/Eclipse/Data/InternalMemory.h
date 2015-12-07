/*
 * InternalMemory.h
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#ifndef DATA_INTERNALMEMORY_H_
#define DATA_INTERNALMEMORY_H_

#include "EEPROM.h"
#include "Arduino.h"

namespace Data {

class InternalMemory {
public:
	InternalMemory();
	virtual ~InternalMemory();

	void writeToEEPROM(int adr, unsigned short value); // writes value to EEPROM on the specified adress
	unsigned short readFromEEPROM(int adr); // Read value from specified adress
};

} /* namespace Data */

#endif /* DATA_INTERNALMEMORY_H_ */
