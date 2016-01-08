#include "header.h"

void InitializeSystem()
{
    Initialize_IO();
    Initialize_OC();
    Initialize_Timer1();
    Initialize_Timer2();
    Initialize_Timer3();
    Initialize_IC();
} 
void Initialize_IC()
{
    // Initialize IC2
    TRISDbits.TRISD9 = 1;
    IC2CON= 0x0000;
    IC2CONbits.SIDL = 1; // halt in CPU Idle Mode
    IC2CONbits.C32 = 0; // 16bit timer;
    IC2CONbits.ICTMR = 0; // select Timer 3;
    IC2CONbits.ICI = 3; // interrupt every 4 events
    IC2CONbits.ICM = 5; // increment every 16 rising edge
      
    // Initialize IC3
    TRISDbits.TRISD10 = 1;
    IC3CON= 0x0000;
    IC3CONbits.SIDL = 1; // halt in CPU Idle Mode
    IC3CONbits.C32 = 0; // 16bit timer;
    IC3CONbits.ICTMR = 0; // select Timer 3;
    IC3CONbits.ICI = 3; // interrupt every fourth event
    IC3CONbits.ICM = 5; // increment every 16 rising edge
}
void Initialize_IO()
{
    // Motor Direction bits
    TRISDbits.TRISD6 = 0; 
    TRISDbits.TRISD7 = 0; 

    TRISDbits.TRISD1 = 0;
    LATDbits.LATD1 = 0;
    TRISDbits.TRISD2 =0;
    LATDbits.LATD2 =0;
    
    // LS1
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB0 = 1;
}
void Initialize_OC()
{
    // output compare
    OC2CONbits.OCM = 6;
    OC2R = 1000;
    OC2RS = 1000;
    OC2CONbits.ON=1;
      
    OC3CONbits.OCM = 6;
    OC3R = 1000;
    OC3RS = 1000;
    OC3CONbits.ON = 1;
    /* Set Interrupt Controller for multi-vector mode */ 
}
void Delay()
{
    TMR1 = 0;
    
    while(TMR1 < 39069)
    {;}
}
void Initialize_Timer1()
{
    T1CON = 0x8030;
    PR1 = 0xFFFF;
    TMR1 = 0;
}
void Initialize_Timer2()
{ 
    T2CON = 0x0030;
    PR2 = 3906;
    TMR2 = 0;   
    T2CONbits.ON = 1;
}
void Initialize_Timer3()
{
    T3CON = 0x0030;
    PR3 = 0xFFFF;
    TMR3 = 0;   
    T3CONbits.ON = 1;
}
void Interrupts_enable()
{
    // Interrupt for IC2
    IFS0bits.IC2IF =0;
    IPC2bits.IC2IP = 7;
    IEC0bits.IC2IE = 1;
    // turn ON IC2 & IC3
    IC2CONbits.ON = 1;
    // Interrupt for IC3
    //INTCONSET = _INTCON_MVEC_MASK;
    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();

}

void Check_Min_OC()
{
    if (OC2RS < 1800)
        OC2RS = 1800;
    if (OC3RS < 1800)
        OC3RS = 1800;   
}

void MotorForward()
{
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 1;
    
    OC2RS = 1800;
    OC3RS = 1800;
}
void Stop()
{
    OC2RS = 0;
    OC3RS = 0;
}

void Turning()
{
    LATDbits.LATD6 = 1; 
    LATDbits.LATD7 = 1;
    
    OC2RS = 1800;
    OC3RS = 1800;
}
void MotorBackward()
{
    LATDbits.LATD6 = 1; 
    LATDbits.LATD7 = 0;
    
    OC2RS = 1800;
    OC3RS = 1800;
}

// IC2 Interrupt to control the duty cycle
void __ISR(_INPUT_CAPTURE_2_VECTOR, IPL7SOFT) IC2Interrupt(void)
{
        IC2CONbits.ON = 1;
        unsigned int a = IC2BUF>>16;
        unsigned int b = IC2BUF>>16; 
        unsigned int c = b-a;
        
        if (c < 2000) // the range of the desired speed 
            OC2RS = OC2RS +50; // 
        else if (c > 2000)
            OC2RS = OC2RS -50; 
    
	IFS0bits.IC2IF = 0;
}
void __ISR(_INPUT_CAPTURE_3_VECTOR, IPL7SOFT) IC3Interrupt(void)
{
        unsigned int a = IC3BUF>>16;
        unsigned int b = IC3BUF>>16; 
        unsigned int c = b-a;

        if (c < 2000) // the range of the desired speed 
            OC3RS = OC3RS +50;
        else if (c>2000)
            OC3RS = OC3RS -50;

        IC3CONbits.ON = 1;
    
    IFS0bits.IC3IF = 0;
}