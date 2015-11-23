/*
 * ExternalMemory.cpp
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#include "ExternalMemory.h"

namespace Data {

File fileToRead;
String filename  = "empty";

ExternalMemory::ExternalMemory() {
	// TODO Auto-generated constructor stub

}

void ExternalMemory::initializeSD(){
	if(SD.begin(4))
		filename = checkFilesSD();
	else
		Serial.println("Initializing failed...");
}

String ExternalMemory::generateRandomNumber(){
	String deviceID = "001";
	randomSeed(analogRead(A5)); //Ensure that the random number is not generated in the same order
	long randNumber = random(100000, 999999); //Generates a 6 digit random number
	String randNumberHEX = String(String(randNumber, HEX) + deviceID + ".csv"); //Convert number to HEX and adds the file type
	//Serial.print("2. The generated id: "); Serial.println(randNumberHEX);
	return randNumberHEX; //Pass the 5 digit random ID
}

String ExternalMemory::checkFilesSD(){
	String tempName, tempType, finalFile;
	String valToCheck = ".csv";
	File root = SD.open("/"); //Tell the method where to look on the SD card
		while(true){
			File entry = root.openNextFile();

			//When a file is found, check the last four characters
			tempName = entry.name();
			tempType = tempName.substring(8,12);
Serial.println(tempName);
Serial.println(tempType);
			//If a .csv is found
			if(tempType.equalsIgnoreCase(valToCheck)){
				Serial.print("*** A file was found with name: "); Serial.println(tempName);
				finalFile = tempName;
				break;
			}
			//If no file was found, creates a file
			if(!tempType.equalsIgnoreCase(valToCheck) && !entry){
				String newFileName = generateRandomNumber();
				//Create a new file with the random HEX as filename and generate a new header
				Serial.print("*** A new file was created: "); Serial.println(tempName);
				createFileTemplate(newFileName);
				finalFile = newFileName;
				break;
			}
			entry.close();
		}
	return finalFile;
}

void ExternalMemory::writeToSDCard(String textToSD){
	//Create new instance of File and get the filename
	File file;
	String nameReadFromSD = filename;

	//Convert filename to char array
	char bufName[nameReadFromSD.length()+1];
	nameReadFromSD.toCharArray(bufName, nameReadFromSD.length()+1); //

	//Open file and write data to it
	file = SD.open(bufName, FILE_WRITE);
	file.println(textToSD);
	file.close();
	Serial.print("*** Data was written to: "); Serial.println(filename);
}


void ExternalMemory::createFileTemplate(String filename){
	char buf[filename.length()+1];
	File file;
	filename.toCharArray(buf, filename.length()+1);
	file = SD.open(buf, FILE_WRITE);
	Serial.print("File name is set to: "); Serial.println(buf);
	file.println("Tidsstempel,Gennemfoert afklemning,Afklemningstryk,Systolisk blodtryk,Middeltryk(MAP),Diastolisk blodtryk,Afklemning afbrudt");
	file.close();
}

String ExternalMemory::getFilename(){
	return filename;
}

} /* namespace Data */
