/*
 * Utilities.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#include "Utilities.h"

double Utilities::rawToMmHg(unsigned short rawPressure)
{
	double offset = 88;
	double coerficient = 0.408;

	return (rawPressure-offset)*coerficient;
};

double Utilities::mmHgToRaw(unsigned short mmHgPressure)
{
	double offset = 88;
	double coerficient = 0.408;

	return mmHgPressure/coerficient+offset;
};
