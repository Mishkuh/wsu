#include <xc.h>
#include <stdio.h>
#pragma config FNOSC = PRIPLL // this is to select the primary PLL for the oscillator
#pragma config POSCMOD = EC // this uses the EC option for the clock (generates 8MHz)
#pragma config FPLLIDIV = DIV_2 // This is used to divide the frequency by 2
#pragma config FPLLMUL = MUL_20 // then it is multiplied by 20 . now we have 80MHz.
#pragma config FPLLODIV = DIV_1 // now we divide by 1 so it is still at 80MHz.
#pragma config FPBDIV = DIV_8 // the frequency of the peripheral bus is divided by 8 which gives 10MHz.
// function Prototypes
void setup_IOs();
void Setup_timer1();
void setup_timer4();
void Tone(unsigned short);
void Pause(unsigned short);

void main(){
    
    setup_IOs();
    setup_timer1();
    setup_timer4();
    
    while(1)
    {
        if (PORTGbits.RG0 == 1){
            TMR4 = 0;
            Loop0();
        }
        else if (PORTGbits.RG1 == 1){
            TMR4 = 0;
            Loop1();
        }
        else if (PORTFbits.RF0 == 1){
            TMR4 = 0;
            Loop2();
        }
        else if (PORTFbits.RF1 == 1){
            TMR4 = 0;
            Loop3();
        }    
        else
            LATEbits.LATE0 = 0;  
    }
}
void setup_IOs(){
 // Port E is output
    TRISE = 0x0000;
    LATE = 0x0000; 
    LATEbits.LATE1= 0;
    LATEbits.LATE3 = 1; // turned on SHUTDOWN bit

    // Port G pins 0 and 1 Port F pins 0 and 1 are inputs for the switches.
    TRISGbits.TRISG0 = 1;
    TRISGbits.TRISG1 = 1;
    TRISFbits.TRISF0 = 1;
    TRISFbits.TRISF1 = 1;

    // Btn1 & Btn2 are Inputs
    TRISAbits.TRISA6 =1;
    TRISAbits.TRISA7 =1;

 }
void setup_timer1(){
    T1CON= 0x8030;
    PR1 = 0xFFF;
    TMR1 = 0;
}
void setup_timer4(){
    T4CON = 0x0; // Stop any 16/32-bit Timer4 operation
    T5CON = 0x0; // Stop any 16-bit Timer5 operation
    T4CON = 0x8078; // Start Timer4/5
   // internal peripheral clock source
    TMR4 = 0x00000000; // Clear contents of the TMR4 and TMR5
    PR4 = 0xffffffff; // every five seconds
}



void Loop0()
{
    TMR4 = 0;
    
    unsigned int Max = 200000; // Loop time
    while (TMR4 <Max){
        if (TMR4 < 20000)
        Tone(150);
        else if ( TMR4 < 50000)
        Tone(130);
        else if ( TMR4 < 30000)
        Tone(120);
        else if ( TMR4 < 40000)
        Tone(100);
        else if ( TMR4 < 50000)
        Tone(130);
        else if ( TMR4 < 60000)
        Tone(100);
        else if (TMR4< 80000)
        Tone(110);
        else if ( TMR4 < 95000)
        Tone(130);
        else if ( TMR4 < 110000)
        Tone(100);
        else if (TMR4< 120000)
        Tone(90);
        else if ( TMR4 < 140000)
        Tone(130);
        else if (TMR4< 150000)
        Tone(100);
        else if ( TMR4 < 170000)
        Tone(90);
        else if (TMR4< 180000)
        Tone(130);
        else if (TMR4< 195000)
        Tone(180);
        else if (TMR4< 200000)
        Pause(100);
        else
        break;
    }
}
void Loop1()
{
    TMR4 = 0;
    
    unsigned int Max = 200000; // Loop time
    while (TMR4 <Max){
        
        if (TMR4 < 8000)
        Tone(80);
        else if ( TMR4 < 16000)
        ;
        else if ( TMR4 < 24000)
        Tone(80);
        else if ( TMR4 < 32000)
        ;
        else if ( TMR4 < 40000)
        Tone(80);
        else if ( TMR4 < 48000)
        ;
        else if ( TMR4 < 80000)
        Tone(120);
        else if ( TMR4 < 90000)
        ;
        else if ( TMR4 < 100000)
        Tone(100);
        else if ( TMR4 < 110000)
        ;
        else if ( TMR4 < 120000)
        Tone(100);
        else if ( TMR4 < 130000)
        ;
        else if ( TMR4 < 140000)
        Tone(100);
        else if ( TMR4 < 150000)
        ;
        else if ( TMR4 < 180000)
        Tone(200);
        else if ( TMR4 < 200000)
        ;
        else
        break;
    }
}
void Loop2()
{
  TMR4 = 0;
    
  unsigned int Max = 200000; // Loop time
  
    while (TMR4 <Max){
        
        if (TMR4 < 8000)
        Tone(60);
        else if ( TMR4 < 16000)
        Tone(80);
        else if ( TMR4 < 24000)
        Tone(70);
        else if ( TMR4 < 32000)
        Tone(100);
        else if ( TMR4 < 40000)
        Tone(60);
        else if ( TMR4 < 48000)
        Tone(70);
        else if ( TMR4 < 80000)
        Tone(50);
        else if ( TMR4 < 90000)
        Tone(70);
        else if ( TMR4 < 100000)
        Tone(75);
        else if ( TMR4 < 110000)
        Tone(80);
        else if ( TMR4 < 120000)
        Tone(85);
        else if ( TMR4 < 130000)
        Tone(90);
        else if ( TMR4 < 140000)
        Tone(95);
        else if ( TMR4 < 150000)
        Tone(100);
        else if ( TMR4 < 180000)
        Tone(105);
        else if ( TMR4 < 200000)
        Tone(110);
        else
        break;
    }
}
void Loop3()
{
    TMR4 = 0;
    unsigned int Max = 200000; // Loop time
    while (TMR4 <Max){
        if (TMR4 < 20000)
        Tone(60);
        else if ( TMR4 < 22000)
        Tone(70);
        else if ( TMR4 < 40000)
        Tone(80);
        else if ( TMR4 < 50000)
        Tone(60);
        else if ( TMR4 < 60000)
        Tone(70);
        else if ( TMR4 < 80000)
        Tone(80);
        else if ( TMR4 < 90000)
        Tone(70);
        else if ( TMR4 < 100000)
        Tone(80);
        else if ( TMR4 < 12000)
        Tone(90);
        else if ( TMR4 < 130000)
        Tone(60);
        else if ( TMR4< 150000)
        Tone(70);
        else if ( TMR4 < 160000)
        Tone(80);
        else if ( TMR4 < 180000)
        Tone(60);
        else if ( TMR4 < 185000)
        Tone(70);
        else if ( TMR4 < 200000)
        ;
        else
        break;
    }
}

void Tone(unsigned short T )
{    
    // BTN1 pushed down. 30% Duty cycle
    if(PORTAbits.RA6 == 1)
    {
        LATEbits.LATE0 = 1;
        TMR1 = 0;
        while(TMR1< (T*2)*0.3){;}

        TMR1 = 0;
        LATEbits.LATE0 = 0;
        while(TMR1< (T*2)*0.7){;}
        
    }
    // BTN2 pushed down. 70% Duty cycle
    else if(PORTAbits.RA7 == 1)
    {
        LATEbits.LATE0 = 1;
        TMR1 = 0;
        while(TMR1< (T*2)*0.7){;}

        TMR1 = 0;
        LATEbits.LATE0 = 0;
        while(TMR1< (T*2)*0.3){;}
    }
    // No buttons pushed down. 50% Duty cycle
    else
    {
        LATEbits.LATE0 = 1;
        TMR1 = 0;
        while(TMR1<T){;}

        TMR1 = 0;
        LATEbits.LATE0 = 0;
        while(TMR1<T){;}
    } 
}

void Pause(unsigned short T )
{
    TMR1 = 0;
    LATEbits.LATE0 = 0;
    while(TMR1<T){;}
} 
