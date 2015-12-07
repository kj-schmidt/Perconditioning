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

//ExternalMemory class contains all the methods dealing with the SD card.
class ExternalMemory {
public:

	ExternalMemory();
	void writeToSDCard(String textToSD); //Method writes to the SD card and closes the file afterwards
	String generateRandomNumber(); //Generate random number according to an analog port
	String checkFilesSD(); //This function checks if a .csv file exists on the SD-card
	void createFileTemplate(String filename); //Builds a .csv file with the right column names
	bool initializeSD(); //Initializes the connection to SD-card. this is only done ones.
	String getFilename(); //returns the filname of the .CSV file in the SC-card
};

} /* namespace Data */

#endif /* DATA_EXTERNALMEMORY_H_ */
