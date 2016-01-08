#include <p32xxxx.h>
#pragma config FNOSC = PRIPLL	
#pragma config POSCMOD = EC
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLODIV = DIV_1
#pragma config FPBDIV = DIV_8
	
	.global main
	.text
   	.set noreorder

.ent main 

main:
	ori $a0, $zero, 0x0040
	jal PortAClear
	nop
	
	ori $a0, $zero, 0x0040
	jal PortAInput
	nop
	
	ori $a0, $zero, 0x3C00
	jal PortBOutput
	nop
	
	

	/* endless loop */
endless:
	la $t0, PORTA
	lw $t1, 0($t0)
	andi $t2, $t1, 0x0040
	BEQZ $t2, endless
	nop
LED1ON:	
	ori $s0, $zero, 0x0400
	la  $s1, LATBSET
	sw $s0, 0($s1)		/* Set specified bits */
	
	
Delay:
	la $t0, PR1
	ori $t1, $zero, 0xffff
	sw $t1, 0($t0)
	
	la $t0, T1CON
	ori $t1, $zero, 0x8030
	sw $t1, 0($t0)
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
	
loop:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop
	nop
	
LED1OFF:	
	ori	$s0, $zero, 0x0400
	la	$s1, LATBCLR
	sw	$s0, 0($s1)		/* Set specified bits */
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
	
loop2:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop2
	nop
	
	nop
/********** LED2 ********/
LED2ON:	
	ori		$s0, $zero, 0x0800
	la		$s1, LATBSET
	sw		$s0, 0($s1)		/* Set specified bits */
	la $t0, TMR1
	sw $zero, 0($t0)
	
loop3:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop3
	nop
	
LED2OFF:	
	ori	$s0, $zero, 0x0800
	la	$s1, LATBCLR
	sw	$s0, 0($s1)		/* Set specified bits */
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
	
loop4:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop4
	nop
	
	nop
/********** LED3 ********/
LED3ON:	
	ori		$s0, $zero, 0x1000
	la		$s1, LATBSET
	sw		$s0, 0($s1)
	la $t0, TMR1
	sw $zero, 0($t0)

loop5:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop5
	nop
	
LED3OFF:	
	ori	$s0, $zero, 0x1000
	la	$s1, LATBCLR
	sw	$s0, 0($s1)		/* Set specified bits */
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
	
loop6:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop6
	nop
	
	nop
/********** LED4 ********/
LED4ON:	
	ori	$s0, $zero, 0x2000
	la	$s1, LATBSET
	sw	$s0, 0($s1)		/* Set specified bits */
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
loop7:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop7
	nop
	
LED4OFF:	
	ori	$s0, $zero, 0x2000
	la	$s1, LATBCLR
	sw	$s0, 0($s1)		/* Set specified bits */
	
	la $t0, TMR1
	sw $zero, 0($t0)
	
	
loop8:	la $t0, TMR1
	lw $t1, 0($t0)
	ori $t2, 1000
	subu $t3, $t2, $t1
	BGEZ $t3, loop8
	nop
	j LED1ON
	nop
	
.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */


    .ent PortAClear 
PortAClear:
	la	$s0, LATACLR
	sw	$a0, 0($s0)	
	/* return to caller */
	jr		$ra
	nop
    .end PortAClear

.ent PortAInput
PortAInput:	
	la $t0, TRISASET
	sw $a0,0($t0)
	jr $ra
	nop
	jal Delay
nop
.end PortAInput

.ent PortBOutput 
PortBOutput:
	
	la	$s0, TRISBCLR
	sw	$a0, 0($s0)		/* clear specified bits (for output) */
	
	la	$t0, LATBCLR
	sw	$a0, 0($t0)
	
	/* return to caller */
	jr		$ra
	nop
.end PortBOutput