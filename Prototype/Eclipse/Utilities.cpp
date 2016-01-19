/*
 * Utilities.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "Utilities.h"

double Utilities::rawToMmHg(unsigned short rawPressure)
{
	double offset = 85; //88 med gammel sensor
	double coerficient = 0.408;

	double conversion = (rawPressure-offset)*coerficient;

	if(conversion < 0)
		conversion = 0;

	return conversion;
};

double Utilities::mmHgToRaw(unsigned short mmHgPressure)
{
	double offset = 85;
	double coerficient = 0.408;

	return mmHgPressure/coerficient+offset;
};
