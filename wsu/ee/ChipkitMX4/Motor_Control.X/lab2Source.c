#include "lab2header.h"

void delayOn(int OnTime)
{
    TMR2 = 0x0000;
    LATDbits.LATD1=1;
    while (TMR2 < OnTime){}
}

void delayOff(int OffTime)
{
    TMR2 = 0x0000;
    LATDbits.LATD1=0;
    while (TMR2 < OffTime){}
}

void forward(int seconds,int Duty_Cycle)
{
    LATDbits.LATD7=1;
    int Interval = 39000; // one second delay
    int i = 0;
    
    while (i < seconds)
    {
        i++;
        TMR1 = 0x0000; // timer1 will over flow with 16-bits resolution (65536)

        while(TMR1 < (Interval))
        {
            delayOn(Duty_Cycle);
            delayOff(10000 - Duty_Cycle);
        }
    }
}

void stop(int seconds)
{
    int Interval = 39000; // one second delay
    int i = 0;
    
    while (i < seconds)
    {
        i++;
        
        TMR1 = 0x0000; // timer1 will over flow with 16-bits resolution (65536)

        while(TMR1< (Interval)){}
    }
}

void backwards(int seconds,int Duty_Cycle)
{
    LATDbits.LATD7=0;
    int Interval = 39000; // one second delay
    int i = 0;
    
    while (i < seconds)
    {
        i++;
        
        TMR1 = 0x0000; // timer1 will over flow with 16-bits resolution (65536)

        while(TMR1< (Interval))
        {
            delayOn(Duty_Cycle);
            delayOff(10000 - Duty_Cycle);
        }
    }
}