#ifndef HEADER_H
#define	HEADER_H

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


enum OP_Mode{Search, Follow, Halt};

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
void Stop_Hit();
void Interrupts_enable();
void Check_Min_OC();

#endif	/* HEADER_H */