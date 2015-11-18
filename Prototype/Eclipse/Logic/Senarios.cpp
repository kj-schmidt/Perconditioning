/*
 * Senarios.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "Senarios.h"

namespace Logic {


void Senarios::bloodPressure(unsigned short *MAP, unsigned short *SYS, unsigned short *DIA) //BPAlgorithm bpa, Data::PressureControl pc, Data::PressureSampling ps, Logic::DigitalFiltering df, Utilities util)
{
	//Constant variables
	const unsigned short ArraysizePeaks = 400;
	const double alpha = 0.15;


	//Variables
	unsigned short cuffPressure[ArraysizePeaks];
	unsigned short peaks[ArraysizePeaks];
	unsigned short tmpMAP = *MAP;
	unsigned short tmpSYS = *SYS;
	unsigned short tmpDIA = *DIA;

	unsigned short rawPressure = 0;
	double pressureMmHg = 0;
	unsigned short totalNumberOfPeaks = 0;

	pc.turnMotorOn(255);
	do{
	rawPressure = ps.getCuffPressure();
	pressureMmHg = util.rawToMmHg(rawPressure);
	} while(pressureMmHg<200);

	pc.turnMotorOff();

	ps.runningPeakDetect(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks,pc,util);

Serial.print("\n");
for (int i = 0; i < ArraysizePeaks; i++) {
	  Serial.print(peaks[i]);
	  Serial.print(",");
	}
Serial.print("\n");

	df.averagingZeroGroupDelay(peaks, ArraysizePeaks, &totalNumberOfPeaks, alpha);

	tmpMAP = bpa.calculateMAP(peaks,cuffPressure,ArraysizePeaks,&totalNumberOfPeaks);

	tmpSYS = bpa.calculateSYS(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks, tmpMAP);

	tmpDIA = bpa.calculateDIA(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks, tmpMAP);;

	*MAP = tmpMAP;
	*SYS = tmpSYS;
	*DIA = tmpDIA;

Serial.print("\n");
for (int i = 0; i < ArraysizePeaks; i++) {
	  Serial.print(peaks[i]);
	  Serial.print(",");
	}
Serial.print("\n");
for (int i = 0; i < ArraysizePeaks; i++) {
	  Serial.print(cuffPressure[i]);
	  Serial.print(",");
	}
Serial.print("\n");
<<<<<<< HEAD
	mem.writeToSDCard(timer.timeToString(), false, 0, util.rawToMmHg(*SYS), util.rawToMmHg(*MAP), util.rawToMmHg(*DIA), false); // Save the blood pressure onto the SD card
=======


<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
}

unsigned short Senarios::occlusiontraining(volatile bool *start)
{

	if(*start){
		pc.turnValveOff();

		if(ps.getCuffPressure() < util.mmHgToRaw(90))
		{
			pc.turnMotorOn(200);
			/*
			while(ps.getCuffPressure() < util.mmHgToRaw(100))
			{
				Serial.print("\nCuffpressure: ");
				Serial.print(util.rawToMmHg(ps.getCuffPressure()));
			}
			pc.turnMotorOff();
			*/
		}
		else if(ps.getCuffPressure() > util.mmHgToRaw(100))
		{
			pc.turnMotorOff();
		}
	}
	else
	{
		pc.turnValveOn();
		pc.turnMotorOff();
	}

	return util.rawToMmHg(ps.getCuffPressure());
}
unsigned short Senarios::occlude(unsigned short pressure)
{
	unsigned short cuffPressure = ps.getCuffPressure();

	if(pressure > 0){
		if(pressure+25 < 200)
			pressure = 175;					//Set minimum pressure to 200mmHg
		else if(pressure+25 > 300)
			pressure = 275;					//Set maximum pressure to 300mmHg

		pc.turnValveOff();

		if(cuffPressure < util.mmHgToRaw(pressure-10))
		{
			pc.turnMotorOn(200);
			/*
			while(ps.getCuffPressure() < util.mmHgToRaw(100))
			{
				Serial.print("\nCuffpressure: ");
				Serial.print(util.rawToMmHg(ps.getCuffPressure()));
			}
			pc.turnMotorOff();
			*/
		}
		else if(cuffPressure > util.mmHgToRaw(pressure+10))
		{
			pc.turnMotorOff();
		}
		}
	else
	{
		if(cuffPressure < util.mmHgToRaw(10))
			pc.turnValveOff();
		else if(cuffPressure > util.mmHgToRaw(2))
			pc.turnValveOn();


		pc.turnMotorOff();
	}

	return cuffPressure;
}

} /* namespace Logic */
