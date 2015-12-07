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
	void writeToSDCard(String textToSD);
	/* This methods writes textToSD to a new line on the .csv file on the SD card. To be able to write to the SD card,
	 * the filename has to be converted to a char array first. After writing to the SD card, the file is close, to ensure
	 * correct handling of the SD card.
	 */
	String generateRandomNumber();
	/* When this method is ran, a random number is generate. First a random integer is create in the interval 100k to
	 * 999999. Next this number is converted to hex, converted to a string and combined with the device ID. An example
	 * of the string that is returned is "1ABC2001.CSV".
	 */
	String checkFilesSD();
	/* This method check all the files on the SD card. When iterating through all the file, each file is check for the
	 * substring ".csv". If a file is found with ".csv" the iteration and the file checks stops and the methods returns
	 * the name of the file. If no file is found with the correct substring, the method generateRandomNumber() is executed.
	 * The createFileTemplate is also call in this scenario.
	 */
	void createFileTemplate(String filename); //Builds a .csv file with the right column names
	/* This method is use to write the header to the .csv file on the SD card. This method should always be called just
	 * after generateRandomNumber(), so the first line wrote to the file is the header.
	 */
	bool initializeSD();
	/* This method is run to ensure that the SD card i connected correctly. If the status of the SD card is true, the
	 * method checkFilesSD() is executed, and statusSD is change to true. Other wise statusSD is false. At last the statusSD
	 * is returned.
	 */

	String getFilename(); //returns the filname of the .CSV file in the SC-card
	/* Returns the filename found on the SD card
	 */
};

} /* namespace Data */

#endif /* DATA_EXTERNALMEMORY_H_ */
