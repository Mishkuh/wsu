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


/******************************LOCAL PROTOTYPES *****************************/
void InitializeSystem();
void Initialize_Timer1();
void Initialize_Timer2();
void Initialize_Timer3();
void Initialize_Timer4();
void Initialize_OC();// Initialize hardware and global variables
void Initialize_IO();
void Initialize_IC();
void Forward();
void Backward();
void Stop();
void InitializeSensors();
void Stop_Hit();
void Interrupts_enable();
void Check_Min_OC();
void Follow();
void Halt();
void Search();
void Delay(int time);
void Rotate();
void Right();
void Left();

/************************ CONSTANTS/GLOBAL VARIABLES ************************/
#define L_SPEED     1400
#define R_SPEED     1400
#define TIME_90     65000
#define DELAY       100000
#define ADJUST_1    100
#define ADJUST_2    100
#define ADJUST_3    100

typedef enum {SEARCH, FOLLOW, HALT} op_mode;
typedef enum {LEFT, RIGHT, STRAIGHT} prev_dir;
unsigned int Timer3OV2 = 0;
unsigned int Timer3OV3 = 0;

prev_dir dir = RIGHT;
op_mode mode = SEARCH;

/******************************** MAIN LOOP *********************************/
int main(void)
{
    InitializeSystem();
    Interrupts_enable();
    
    while (1)
    {
        LATBbits.LATB10 = 0;
        
        while(PORTAbits.RA6 != 1){Halt();}
        
        while(PORTAbits.RA7 != 1)
        {
            if(mode == FOLLOW)
            {
                LATBbits.LATB10 = 1;
                Follow();
            }
            else if(mode == SEARCH)
            {
                Search();
            }
            else if(mode == HALT)
            {
                break;
            }
        }
    }
}

/***************************** MODE FUNCTIONS *******************************/
void Follow()
{
    if(PORTFbits.RF5 == 0 && PORTFbits.RF4 == 0)
    {
        Forward();
    }
    else if(PORTFbits.RF13 == 1 && PORTFbits.RF4 == 1 &&
            PORTFbits.RF12 == 1 && PORTFbits.RF4 == 1)
    {
        if(dir == LEFT)
        {
            Stop();
            Left();
        }
        else if(dir == RIGHT)
        {
            Stop();
            Right();
        }
    }
    else
    {
        Forward();
        
        if(PORTFbits.RF12 == 0 && PORTFbits.RF5 == 0 && 
                PORTFbits.RF13 == 1 && PORTFbits.RF4 == 0)
        {
            dir = LEFT;
        }
        else if(PORTFbits.RF4 == 0 && PORTFbits.RF13 == 1)
        {
            OC2RS = L_SPEED - ADJUST_1;
            dir = LEFT;
        }
        else if(PORTFbits.RF4 == 0 && PORTFbits.RF13 == 0)
        {
            OC2RS = L_SPEED - ADJUST_2;
            dir = LEFT;
        }
        else if(PORTFbits.RF4 == 1 && PORTFbits.RF13 == 0)
        {
            OC3RS = R_SPEED + ADJUST_3;
            OC2RS = 0;
            dir = LEFT;
        }
        else if(PORTFbits.RF12 == 1 && PORTFbits.RF5 == 0 && 
                PORTFbits.RF13 == 0 && PORTFbits.RF4 == 0)
        {
            dir = RIGHT;
        }
        else if(PORTFbits.RF12 == 1 && PORTFbits.RF5 == 0)
        {
            OC3RS = R_SPEED - ADJUST_1;
            dir = RIGHT;
        }
        else if(PORTFbits.RF12 == 0 && PORTFbits.RF5 == 0)
        {
            OC3RS = R_SPEED - ADJUST_2;
            dir = RIGHT;
        }
        else if(PORTFbits.RF12 == 0 && PORTFbits.RF5 == 1)
        {
            OC2RS = L_SPEED + ADJUST_3;
            OC3RS = 0;
            dir = RIGHT;
        }
    } 
}
void Halt()
{
    Stop();
    Delay(1000);
    if(PORTFbits.RF13 == 0 || PORTFbits.RF4 == 0
            || PORTFbits.RF4 == 0 || PORTFbits.RF12 == 0)
    {
       mode = FOLLOW;
    }
    else
    {
        mode = SEARCH;
    }
}
void Search()
{
    TMR4 = 0;
    int i;
    
    for(i = 0; i < 4; i++)
    {
        Forward();
        OC3RS = R_SPEED + 200;
        
        if(TMR4 < DELAY / 2)
        {
            LATBbits.LATB10 = 0;
        }
        else
        {
            LATBbits.LATB10 = 1;
        }
        
        if(PORTFbits.RF13 == 0 || PORTFbits.RF4 == 0
         || PORTFbits.RF4 == 0 || PORTFbits.RF12 == 0) // line found
        {
            mode = FOLLOW;
            Forward();
            break;
        }
        else if(TMR4 > DELAY)
        {
            Stop();
            Delay(DELAY);
            Backward();
            OC3RS = R_SPEED + 400;
            OC2RS = L_SPEED + 200;
            Delay(DELAY);
            Stop();
            Delay(DELAY);
            Rotate();
            Delay(DELAY);
            TMR4 = 0;
        }
    }
    
    mode = HALT;
}

/************************ INITIALIZATION FUNCTIONS **************************/
void InitializeSystem()
{
    Initialize_IO();
    Initialize_OC();
    Initialize_Timer1();
    Initialize_Timer2();
    Initialize_Timer3();
    Initialize_Timer4();
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

    // H bridge
    TRISDbits.TRISD1 = 0;
    LATDbits.LATD1 = 0;
    TRISDbits.TRISD2 =0;
    LATDbits.LATD2 =0;
    
    // LS1
    TRISFbits.TRISF13 = 1;
    TRISFbits.TRISF4 = 1;
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF12 = 1;
    
    // Buttons
    TRISAbits.TRISA6 = 1;
    TRISAbits.TRISA7 = 1;
    
    // LED
    TRISBbits.TRISB10 = 0;
    LATBbits.LATB10 = 0;
}
void Initialize_OC()
{
    //OC2 is for LEFT motor
    OC2CONbits.OCM = 6;
    OC2R = 0;
    OC2RS = 0;
    OC2CONbits.ON = 1;
    
    //OC3 is for RIGHT motor
    OC3CONbits.OCM = 6;
    OC3R = 0;
    OC3RS = 0;
    OC3CONbits.ON = 1;
    /* Set Interrupt Controller for multi-vector mode */ 
}

/************************ INITIALIZATION OF TIMERS **************************/
void Initialize_Timer1()
{
    T1CON = 0x8030;
    PR1 = 0x3609;
    TMR1 = 0;
}
void Initialize_Timer2()
{ 
    T2CON = 0x0030;
    PR2 = 10000;
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
void Initialize_Timer4()
{
    T4CON = 0x0; // Stop any 16/32-bit Timer4 operation
    T5CON = 0x0; // Stop any 16-bit Timer5 operation
    T4CON = 0x8078; // Start Timer4/5
   // internal peripheral clock source
    TMR4 = 0x00000000; // Clear contents of the TMR4 and TMR5
    PR4 = 0xFFFFFFFF; // every five seconds
}

/********************************* DELAY ************************************/
void Delay(int time)
{
    TMR4 = 0;
    while(TMR4 < time)
    {
        if(PORTAbits.RA7 == 1)
        {
            Halt();
            mode = HALT;
        }
        
        if(TMR4 > time / 2)
        {
            LATBbits.LATB10 = 1;
        }
        else
        {
            LATBbits.LATB10 = 0;
        }
    }
}

/**************************** MOVEMENT FUNCTIONS ****************************/
void Forward()
{
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 1;
    
    OC2RS = L_SPEED;
    OC3RS = R_SPEED;
}
void Backward()
{
    LATDbits.LATD6 = 1;
    LATDbits.LATD7 = 0;
    
    OC2RS = L_SPEED;
    OC3RS = R_SPEED;
}
void Rotate()
{
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 0;
    
    OC2RS = L_SPEED;
    OC3RS = R_SPEED;
    Delay(TIME_90);
    OC2RS = 0;
    OC3RS = 0;
}
void Left()
{
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 0;
    
    OC2RS = L_SPEED;
    OC3RS = R_SPEED;
}
void Right()
{
    LATDbits.LATD6 = 1;
    LATDbits.LATD7 = 1;
    
    OC2RS = L_SPEED;
    OC3RS = R_SPEED;
}
void Stop()
{
    OC2RS = 0;
    OC3RS = 0;
}

/****************************** INTERRUPT INFO ******************************/
void Interrupts_enable()
{
    // Interrupt for IC2
    IFS0bits.IC2IF = 0;
    IPC2bits.IC2IP = 7;
    IEC0bits.IC2IE = 1;
    // turn ON IC2 & IC3
    IC2CONbits.ON = 1;

    INTCONbits.MVEC = 1;
    __builtin_enable_interrupts();
}
// IC2 Interrupt to control the duty cycle
void __ISR(_INPUT_CAPTURE_2_VECTOR, IPL7SOFT) IC2Interrupt(void)
{
    if (mode == SEARCH)
    {
        IC2CONbits.ON = 1;
        unsigned int a = IC2BUF>>16;
        unsigned int b = IC2BUF>>16; 
        unsigned int c = b-a;
        
        if (c < L_SPEED - 100) // the range of the desired speed 
            OC2RS = OC2RS + 100; // 
        else if (c > L_SPEED + 100)
            OC2RS = OC2RS - 100; 
    }
    
	IFS0bits.IC2IF = 0;
}
void __ISR(_INPUT_CAPTURE_3_VECTOR, IPL7SOFT) IC3Interrupt(void)
{
    if (mode == SEARCH)
    {
        unsigned int a = IC3BUF>>16;
        unsigned int b = IC3BUF>>16; 
        unsigned int c = b-a;

        if (c < R_SPEED - 100) // the range of the desired speed 
            OC3RS = OC3RS + 100;
        else if (c > R_SPEED + 100)
            OC3RS = OC3RS - 100;

        IC3CONbits.ON = 1;
    }
    
    IFS0bits.IC3IF = 0;
}