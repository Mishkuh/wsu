#include <xc.h>             /* contains Vector Name/Number Macros */
#include <sys/attribs.h>    /* contains __ISR() Macros */

/* Oscillator Settings */
#pragma config FNOSC = PRIPLL // Oscillator selection
#pragma config POSCMOD = EC // Primary oscillator mode
#pragma config FPLLIDIV = DIV_2 // PLL input divider
#pragma config FPLLMUL = MUL_20 // PLL multiplier
#pragma config FPLLODIV = DIV_1 // PLL output divider
#pragma config FPBDIV = DIV_8 // Peripheral bus clock divider

#pragma config FSOSCEN = OFF // Secondary oscillator enable
#pragma config IESO = OFF // Internal/external clock switchover
#pragma config FCKSM = CSDCMD // Clock switching (CSx)/Clock monitor(CMx)
#pragma config OSCIOFNC = OFF // Clock output on OSCO pin enable
#pragma config UPLLEN = ON // USB PLL enable
#pragma config UPLLIDIV = DIV_2 // USB PLL input divider
/* Other Peripheral Device settings */
#pragma config FWDTEN = OFF // Watchdog timer enable
#pragma config WDTPS = PS1024 // Watchdog timer post-scaler

/* Code Protection settings */
#pragma config CP = OFF // Code protection
#pragma config BWP = OFF // Boot flash write protect
#pragma config PWP = OFF // Program flash write protect

/** LOCAL PROTOTYPES ********************************************************/

void InitializeSystem();
void Initialize_Timer1();
void Initialize_Timer2();
void Initialize_Timer3();
void Initialize_OC();// Initialize hardware and global variables
void Initialize_IO();
void Initialize_IC();
void MotorForward();
void MotorBackward();
void Stop();
void InitializeSensors();
void InitializeADC();
void ReadADC();
void Stop_Hit();
void Interrupts_enable();
void Check_Min_OC();


/** main() ********************************************************************/
unsigned short Mode = 1; // 1 = forward
unsigned int Timer3OV2 = 0;
unsigned int Timer3OV3 = 0;

int main(void)
{
    InitializeSystem();
    Interrupts_enable();
    
    while(1)
    {
        //ReadADC();
    }
}

void InitializeSystem()
{
    Initialize_IO();
    InitializeADC();
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
    
    TRISBbits.TRISB1 = 0;
    LATBbits.LATB1 = 1;  // turns sonar on;
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
void InitializeADC()
{    
    AD1CON1= 0x000000;
    AD1CON1bits.FORM = 0;// unsigned integer 10 bits 0 - 1024 = 0x2208;
    AD1CON1bits.SIDL = 1; // stop operation in the idle mode
    AD1CSSL = 0x0000;
    AD1CON1bits.ASAM = 1;//auto start sampling
    AD1CON1bits.SAMP = 1;
    AD1CON1bits.SSRC = 7;
    /* Configure ADC voltage reference and buffer fill modes.VREF from AVDD and AVSS,Inputs are not scanned,Interrupt every sample */
    AD1CON2 = 0x0000;
    AD1CON2bits.VCFG = 7;  // Reference voltage to be Vdd & Vss;
    AD1CON2bits.OFFCAL = 0; // No Calibration 
    AD1CON2bits.SMPI = 1; //interrupt every other sample
    // AD1CON3 Register
    AD1CON3= 0x0000;//Sample time = 2 TAD
    AD1CON3bits.ADCS = 8;  // Sample clock is 10MHz/16
    AD1CON3bits.SAMC = 2;  
    /* Configure ADC RB00 */
    AD1PCFG = 0xFFFE; 
    /* Configure input channels,CH0+ input is AN0.CHO- input is VREFL (AVss)  */                   
    AD1CHS = 0x0000;
    AD1CSSL = 0x0000;
    AD1CSSLbits.CSSL0 = 1;   
}
void Interrupts_enable()
{
    //Interrupt for ADC
    IPC6bits.AD1IP = 5;
    IFS1bits.AD1IF = 0;
    IEC1bits.AD1IE = 1;   
    AD1CON1bits.ADON = 1;
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
void ReadADC()
{
    unsigned int ADCValue = 0;//clear value
    int count = 0;
    AD1CON1bits.ASAM = 1;//auto start sampling
    //for 31 TAD, and then go to conversion
    while (!AD1CON1bits.DONE);//conversion done?
    // AD1CON1bits.ASAM = 0;//yes, stop sample/convert
    for (count = 0; count < 8; count++)
    {
        //average the two
        ADCValue = ADCValue + ADC1BUF0;                                 
    }
    ADCValue = ADCValue >> 3;

    if (Mode == 1) // Forward Mode
    {
        if (ADCValue < 0x10)
        {
            Mode = 2; // Enter backward mode
            Stop();  // Take action (stop) move back turn
            Delay();
        }
        else
        { 
            MotorForward();
            Check_Min_OC();
        }   
    }
    else if (Mode == 2) // Backward Mode
    {
        if (ADCValue > 0x20)
        {
            Mode = 3; // Enter rotate mode
            Stop();
            Delay();
        }
        else
        {
            MotorBackward();
            Check_Min_OC();
        }
    } 
    else if (Mode == 3) // Rotate Mode
    {
        if(ADCValue > 0x60)
        {
            Mode = 1; // enter forward mode
            Stop();
            Delay();
        }
        else
        {
            Turning();
            Check_Min_OC();
        }
    }
}
void Check_Min_OC()
{
    if (OC2RS < 1800)
        OC2RS = 1800;
    if (OC3RS < 1800)
        OC3RS = 1800;   
}
// ADC interrupt controls the forward stop and turn direction
void __ISR (_ADC_VECTOR, IPL5SOFT) ADCInterrupt(void)
{
	//MotorForward();
    ReadADC();
	// Reset interrupt flag
	IFS1bits.AD1IF = 0;
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
    if (Mode == 1)
    {
        IC2CONbits.ON = 1;
        unsigned int a = IC2BUF>>16;
        unsigned int b = IC2BUF>>16; 
        unsigned int c = b-a;
        
        if (c < 2000) // the range of the desired speed 
            OC2RS = OC2RS +50; // 
        else if (c > 2000)
            OC2RS = OC2RS -50; 
    }
    
	IFS0bits.IC2IF = 0;
}
void __ISR(_INPUT_CAPTURE_3_VECTOR, IPL7SOFT) IC3Interrupt(void)
{
    if (Mode == 1)
    {
        unsigned int a = IC3BUF>>16;
        unsigned int b = IC3BUF>>16; 
        unsigned int c = b-a;

        if (c < 2000) // the range of the desired speed 
            OC3RS = OC3RS +50;
        else if (c>2000)
            OC3RS = OC3RS -50;

        IC3CONbits.ON = 1;
    }
    
    IFS0bits.IC3IF = 0;
}