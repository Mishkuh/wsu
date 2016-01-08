#include "lab2header.h"

#pragma config FNOSC = PRIPLL // this is to select the primary PLL for the oscillator
#pragma config POSCMOD = EC // this uses the EC option for the clock (generates 8MHz)
#pragma config FPLLIDIV = DIV_2 // This is used to divide the frequency by 2
#pragma config FPLLMUL = MUL_20 // then it is multiplied by 20 . now we have 80MHz.
#pragma config FPLLODIV = DIV_1 // now we divide by 1 so it is still at 80MHz.
#pragma config FPBDIV = DIV_8 // the frequency of the peripheral bus is divided by 8 which gives 10MHz. 

int main(void)
{
    TRISA = 0x0060; // PORTA 6 & 7 are inputs and the rest are output
    TRISB = 0x0000;
    TRISD = 0x000;
    PORTB = 0x0000; //
    PORTD = 0x0000;
    T2CON = 0x8040; //
    PR2= 0xFFFF;
    T1CON = 0x8030;
    PR1 = 0xFFFF; // period to timer1. resets when it is full. 
    
    while(1)
    {
        if (PORTAbits.RA6 ==1)
        {
            forward(4, 9000);
            stop(1);
            backwards(3, 6000);
            stop(2);
            forward(3, 4000);
            stop(1);
            forward(5, 2000);
        }
    }
    
    return 0;
}
