/*
 * Utilities.h
 *
 *  Created on: Nov 9, 2015
 *      Author: simon
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

class Utilities {
public:
	double rawToMmHg(unsigned short rawPressure);
	double mmHgToRaw(unsigned short mmHgPressure);
};

#endif /* UTILITIES_H_ */
