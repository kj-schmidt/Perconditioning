/*
 * Senarios.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "Senarios.h"

namespace Logic {

long Senarios::tmpTimestamp;

void Senarios::bloodPressure(unsigned short *MAP, unsigned short *SYS, unsigned short *DIA, volatile bool *btPressed)
{
	//Constant variables
	const unsigned short ArraysizePeaks = 400; //arraysize of peaks and cuffpressure
	const double alpha = 0.15; //filter value


	//Variables
	unsigned short cuffPressure[ArraysizePeaks];
	unsigned short peaks[ArraysizePeaks];
	unsigned short tmpMAP = *MAP;
	unsigned short tmpSYS = *SYS;
	unsigned short tmpDIA = *DIA;

	unsigned short rawPressure = 0;
	double pressureMmHg = 0;
	unsigned short totalNumberOfPeaks = 0;

	pc.turnValveOff();
	pc.turnMotorOn(255);
	do{ //pump cuff to 200mmHg
	rawPressure = ps.getCuffPressure();
	pressureMmHg = util.rawToMmHg(rawPressure);
	} while(pressureMmHg<200 && *btPressed);

	pc.turnMotorOff();

	ps.runningPeakDetect(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks,pc,util, &*btPressed); //detect occiliations



	df.averagingZeroGroupDelay(peaks, ArraysizePeaks, &totalNumberOfPeaks, alpha); //filter the data

	tmpMAP = bpa.calculateMAP(peaks,cuffPressure,ArraysizePeaks,&totalNumberOfPeaks); //calculate MAP

	tmpSYS = bpa.calculateSYS(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks, tmpMAP); //Calculate SYS

	tmpDIA = bpa.calculateDIA(peaks, cuffPressure, ArraysizePeaks, &totalNumberOfPeaks, tmpMAP); //Calculate DIA

	//save bloddpressure to RAM
	*MAP = tmpMAP;
	*SYS = tmpSYS;
	*DIA = tmpDIA;

	if(*btPressed){
		mem.writeToSDCard(timer.timeToString(), false, 0, util.rawToMmHg(*SYS), util.rawToMmHg(*MAP), util.rawToMmHg(*DIA), false); // Save the blood pressure onto the SD card
	}
}

unsigned short Senarios::occlusiontraining(volatile bool *start)
{
	long currentTime;
	unsigned short cuffPressure = ps.getCuffPressure(); //get cuffpressure

	if(*start){ //if startbutten pressed
		pc.turnValveOff();

		if(cuffPressure < util.mmHgToRaw(90)) //if pressure lover than 90mmHg
		{
			pc.turnMotorOn(255);
		}
		else if(ps.getCuffPressure() > util.mmHgToRaw(100)) //if pressure over 100mmHg
		{
			pc.turnMotorOff();
		}
	}
	else //if startbutton is off deflate cuff
	{
		currentTime = millis();

				if(tmpTimestamp < currentTime-2000 && cuffPressure < util.mmHgToRaw(20)) //the valve may only be opend with an interval of two sec
				{
					pc.turnValveOff();
					tmpTimestamp = currentTime;
				}
				else if(cuffPressure > util.mmHgToRaw(5))
					pc.turnValveOn();


		pc.turnMotorOff();
	}

	return util.rawToMmHg(cuffPressure); //return cuffpressure
}
unsigned short Senarios::occlude(unsigned short pressure)
{
	long currentTime;
	unsigned short cuffPressure = ps.getCuffPressure();

	if(pressure > 0){ //if defined pressure is over
		if(pressure+25 < 200)
			pressure = 175;					//Set minimum pressure to 200mmHg
		else if(pressure+25 > 300)
			pressure = 275;					//Set maximum pressure to 300mmHg

		pc.turnValveOff();

		if(cuffPressure < util.mmHgToRaw(pressure-10))
		{
			pc.turnMotorOn(255); //change from 200 to 255
		}
		else if(cuffPressure > util.mmHgToRaw(pressure+10))
		{
			pc.turnMotorOff();
		}
		}
	else
	{
		currentTime = millis();

		if(tmpTimestamp < currentTime-2000 && cuffPressure < util.mmHgToRaw(20))  //the valve may only be opend with an interval of two sec
		{
			pc.turnValveOff();
			tmpTimestamp = currentTime;
		}
		else if(cuffPressure > util.mmHgToRaw(5))
			pc.turnValveOn();


		pc.turnMotorOff();
	}

	return cuffPressure;
}

} /* namespace Logic */
