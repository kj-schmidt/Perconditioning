// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _SerialMonitor_H_
#define _SerialMonitor_H_
#include "Arduino.h"
#include "Library.cpp"
//add your includes for the project SerialMonitor here


//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
void sample_Data();
void plot(int data1);//, int data2, int data3, int data4, int data5, int data6);

#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project SerialMonitor here




//Do not add code below this line
#endif /* _SerialMonitor_H_ */
