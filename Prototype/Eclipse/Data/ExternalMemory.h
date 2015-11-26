/*
 * ExternalMemory.h
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#ifndef DATA_EXTERNALMEMORY_H_
#define DATA_EXTERNALMEMORY_H_

#include "SD.h"
#include "SPI.h"
#include "Arduino.h"

namespace Data {

class ExternalMemory {
public:
	ExternalMemory();
	void writeToSDCard(String textToSD);
	String generateRandomNumber();
	String checkFilesSD();
	void createFileTemplate(String filename);
	bool initializeSD();
	String getFilename();
};

} /* namespace Data */

#endif /* DATA_EXTERNALMEMORY_H_ */
