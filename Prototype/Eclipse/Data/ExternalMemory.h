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
	virtual ~ExternalMemory();
	void initializeSDCard();
	void writeToSDCard(String textToSD);
	void readFromSDCard();
	String generateRandomNumber(); //** IS TO BE MOVED TO LOGIC LAYER**
	String checkFilesSD(File dir, String val);
	void createFileTemplate(String filename);
};

} /* namespace Data */

#endif /* DATA_EXTERNALMEMORY_H_ */
