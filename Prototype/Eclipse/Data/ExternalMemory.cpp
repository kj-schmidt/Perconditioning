/*
 * ExternalMemory.cpp
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#include "ExternalMemory.h"

namespace Data {

File fileToRead;
long patientID;
ExternalMemory::ExternalMemory() {
	// TODO Auto-generated constructor stub

}

ExternalMemory::~ExternalMemory() {
	// TODO Auto-generated destructor stub
}

void ExternalMemory::initializeSDCard(){
	SD.begin(4); //cs is connected to pin 4
	/*String filename = String(String(patientID, DEC) + ".txt"); //generates random filename
	SD.open(filename, FILE_WRITE);*/
}

//** IS TO BE MOVE TO LOGIC LAYER**
String ExternalMemory::generateRandomNumber(){
	randomSeed(analogRead(A5)); //Ensure that the random number is not generated in the same order
	long randNumber = random(100000, 999999); //Generates a 6 digit random number
	String randNumberHEX = String(String(randNumber, HEX) + ".csv"); //Convert number to HEX and adds the file type
	Serial.print("2. The generated id: "); Serial.println(randNumberHEX);
	return randNumberHEX; //Pass the 5 digit random ID
}

String ExternalMemory::checkFilesSD(File dir, String val){
	while(true){
		String fileExists = "empty";
		File entry = dir.openNextFile();
		String filename, filetype;
		if(!entry){
			//Serial.println("** NO MORE FILES **");
			break;
		}
		filename = entry.name();
		filetype = filename.substring(5,9);

		if(filetype.equalsIgnoreCase(val)){
			fileExists = filename;
			Serial.print("1. A .csv file was found with name: "); Serial.println(filename);
			return fileExists;
			break;
		}else
			return fileExists;
	}
}

void ExternalMemory::writeToSDCard(String textToSD){
	  File file;
	  File root = SD.open("/"); //Tell the method where to look on the SD card
	  String nameReadFromSD = checkFilesSD(root, ".csv");
	  String randomNumb = generateRandomNumber();
	  char bufName[nameReadFromSD.length()+1]; //Buffer to hold converted strings
	  char bufTextRecieved[textToSD.length()+1];

	  if(!nameReadFromSD.equalsIgnoreCase("empty")){ //Check if there is a .csv file on the SD card
		nameReadFromSD.toCharArray(bufName, nameReadFromSD.length()+1);
	    file = SD.open(bufName, FILE_WRITE);
	    textToSD.toCharArray(bufTextRecieved, textToSD.length()+1);
	    file.write(bufTextRecieved);
	    file.close();
	    Serial.println("2. No new file was created");
	  } else{ //Create new file with the random ID
		createFileTemplate(generateRandomNumber());
	    Serial.print("3. A new file was created with name: "); Serial.println(generateRandomNumber());
	  }
}

void ExternalMemory::readFromSDCard(){

}

void ExternalMemory::createFileTemplate(String filename){
	char buf[filename.length()+1];
	File file;
	filename.toCharArray(buf, filename.length()+1);
	file = SD.open(buf, FILE_WRITE);
	Serial.print("File name is set to: "); Serial.println(buf);
	file.write("Tidsstempel,\nAfklemningstryk,\nGennemf\x9Brt afklemning,\nSystolisk blodtryk,\nMiddeltryk(MAP),\nDiastolisk blodtryk,\n");
	file.close();
}



} /* namespace Data */
