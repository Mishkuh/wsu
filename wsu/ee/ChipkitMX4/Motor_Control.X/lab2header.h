#include <p32xxxx.h> 
#include <stdio.h>

#ifndef LAB2HEADER_H
#define	LAB2HEADER_H

void forward(int seconds,int Duty_Cycle);
void stop(int seconds);
void backwards(int seconds,int Duty_Cycle);
void delayOn(int OnTime);
void delayOff(int OffTime);

#endif	/* LAB2HEADER_H */

