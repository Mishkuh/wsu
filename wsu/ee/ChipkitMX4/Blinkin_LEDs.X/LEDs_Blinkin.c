
#include <p32xxxx.h> // this line is used to read all default names and values of the selected PIC
// Configuring the clocking frequency
#pragma config FNOSC = PRIPLL // this is to select the primary PLL for the oscillator
#pragma config POSCMOD = EC // this uses the EC option for the clock (generates 8MHz)
#pragma config FPLLIDIV = DIV_2 // This is used to divide the frequency by 2
#pragma config FPLLMUL = MUL_20 // then it is multiplied by 20 . now we have 80MHz.
#pragma config FPLLODIV = DIV_1 // now we divide by 1 so it is still at 80MHz.
#pragma config FPBDIV = DIV_8 // the frequency of the peripheral bus is divided by 8 which gives 10MHz.
// Define the delay as a constant
#define DELAY 39063 // play with this parameter
void Delay(); // function prototype

void Delay()
{
    while (TMR1 < DELAY)
    {
        // delay be waiting until the timer is equal to the Delay_Time
    }
}

int main(void)
{
TRISA = 0x0060; // PORTA 6 & 7 are inputs and the rest are output
TRISB =0x0000;
PORTB = 0x0000; // turn PORTB pins 0..7 on
T1CON = 0x8030;
PR1 = 0xFFFF; // period to timer1. resets when it is full. 

    while(1)
    {
        if (PORTAbits.RA6 ==1) 
        {
            while(1) {
            // First LED is ON
           TMR1 = 0;
            LATB=0;
            LATBbits.LATB10 = 1;
            Delay();
            // Second LED is ON
            TMR1 = 0;
            LATB=0;
            LATBbits.LATB11 = 1;
            Delay();
            // Third LED is ON
            TMR1 = 0;
            LATB=0;
            LATBbits.LATB12 = 1;
            Delay();
            // Forth LED is ON
            TMR1 = 0;
            LATB=0;
            LATBbits.LATB13 = 1;
            Delay();

            }
       }
    }
}