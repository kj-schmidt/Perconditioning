/*
 * ExternalMemory.cpp
 *
 *  Created on: 03/11/2015
 *      Author: kjschmidt
 */

#include "ExternalMemory.h"

namespace Data {

#define cs_pin 4

File fileToRead;
long patientID;
ExternalMemory::ExternalMemory() {
	// TODO Auto-generated constructor stub

}

ExternalMemory::~ExternalMemory() {
	// TODO Auto-generated destructor stub
}

void ExternalMemory::initializeSDCard(){
	SD.begin(cs_pin); //cs is connected to pin 4
	/*String filename = String(String(patientID, DEC) + ".txt"); //generates random filename
	SD.open(filename, FILE_WRITE);*/
}

//** IS TO BE MOVE TO LOGIC LAYER**
String ExternalMemory::generateRandomNumber(){
	randomSeed(analogRead(A5)); //Ensure that the random number is not generated in the same order
	long randNumber = random(100000, 999999); //Generates a 6 digit random number
	String randNumberHEX = String(String(randNumber, HEX) + ".csv"); //Convert number to HEX and adds the file type
	//Serial.print("2. The generated id: "); Serial.println(randNumberHEX);
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
	  char bufName[nameReadFromSD.length()+1]; //Buffer to hold converted strings

	  if(!nameReadFromSD.equalsIgnoreCase("empty")){ //Check if there is a .csv file on the SD card
		nameReadFromSD.toCharArray(bufName, nameReadFromSD.length()+1); //Read the name of the file and convert to char array
	    file = SD.open(bufName, FILE_WRITE);
	    //Serial.print("Read from SD: "); Serial.println(file.readStringUntil('\n'));
	    file.println(textToSD);
	    file.close();
	    //Serial.println("2. No new file was created");
	  } else{ //Create new file with the random ID
		createFileTemplate(generateRandomNumber());
	    Serial.print("A new file was created with name: "); Serial.println(generateRandomNumber());
	  }
}

//** SKAL SLETTES **
void ExternalMemory::readFromSDCard(){
	File file;
	String filename = "62EA6.CSV";
	char buf[filename.length() + 1];
	filename.toCharArray(buf, filename.length()+1);
	file = SD.open(buf, FILE_READ);
	Serial.println("File contains: ");
	Serial.println(file.readString());
	file.close();
}

void ExternalMemory::createFileTemplate(String filename){
	char buf[filename.length()+1];
	File file;
	filename.toCharArray(buf, filename.length()+1);
	file = SD.open(buf, FILE_WRITE);
	Serial.print("File name is set to: "); Serial.println(buf);
	file.println("Tidsstempel,Afklemningstryk,Gennemf\x9Brt afklemning,Systolisk blodtryk,Middeltryk(MAP),Diastolisk blodtryk,Afklemning afbrudt");
	file.close();
}



} /* namespace Data */
