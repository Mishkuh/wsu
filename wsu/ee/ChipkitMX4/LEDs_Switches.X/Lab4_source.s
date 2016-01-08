#include <p32xxxx.h>
    
.global main
.text
.set noreorder

.ent main 
    
main:
    ori $a0, $zero, 0x000F
    jal PortE0_3Clear
    nop
    
    ori $a0, $zero, 0x000F
    jal PortE0_3Input
    nop

    ori $a0, $zero, 0x3C00
    jal PortBOutput
    nop
    
    la $t0, PR1
    ori $t1, $zero, 0x03D0
    sw $t1, 0($t0)

    la $t0, T1CON
    ori $t1, $zero, 0x8030
    sw $t1, 0($t0)
     
    la $t0, TMR1
    sw $zero, 0($t0)
    
    move $s2, $zero
    
LOOP:
    lw $t5, TMR1
    
    BEQZ $t5, CHECK_LOOP
    nop
    
    B LOOP
    nop
    
CHECK_LOOP:
    sw $zero, 0($t0)
    addi $s2, $s2, 0x0001
    lw $t1, PORTE
    
SW1_CHECK:
    andi $s3, $s2, 0x0001
    andi $t2, $t1, 0x0001
    and $t2, $t2, $s2
    BNEZ $t2, LED1_ON
    nop
    B LED1_OFF
    nop
SW2_CHECK:
    andi $s3, $s2, 0x0002
    andi $t2, $t1, 0x0002
    and $t2, $t2, $s3
    BNEZ $t2, LED2_ON
    nop
    B LED2_OFF
    nop
SW3_CHECK:
    andi $s3, $s2, 0x0004
    andi $t2, $t1, 0x0004
    and $t2, $t2, $s3
    BNEZ $t2, LED3_ON
    nop
    B LED3_OFF
    nop
SW4_CHECK:
    andi $s3, $s2, 0x0008
    andi $t2, $t1, 0x0008
    and $t2, $t2, $s3
    BNEZ $t2, LED4_ON
    nop
    B LED4_OFF
    nop
    
LED1_ON:
    ori	$s0, $zero, 0x0400
    la	$s1, LATBSET
    sw	$s0, 0($s1)
    
    B SW2_CHECK
    
LED1_OFF:
    ori	$s0, $zero, 0x0400
    la	$s1, LATBCLR
    sw	$s0, 0($s1)
    
    B SW2_CHECK
    
LED2_ON:
    ori	$s0, $zero, 0x0800
    la	$s1, LATBSET
    sw	$s0, 0($s1)
    
    B SW3_CHECK
    
LED2_OFF:
    ori	$s0, $zero, 0x0800
    la	$s1, LATBCLR
    sw	$s0, 0($s1)
    
    B SW3_CHECK
    
LED3_ON:
    ori	$s0, $zero, 0x1000
    la	$s1, LATBSET
    sw	$s0, 0($s1)
    
    B SW4_CHECK
    
LED3_OFF:
    ori	$s0, $zero, 0x1000
    la	$s1, LATBCLR
    sw	$s0, 0($s1)
    
    B SW4_CHECK
    
LED4_ON:
    ori	$s0, $zero, 0x2000
    la	$s1, LATBSET
    sw	$s0, 0($s1)
    
    B LOOP
    
LED4_OFF:
    ori	$s0, $zero, 0x2000
    la	$s1, LATBCLR
    sw	$s0, 0($s1)
    
    B LOOP
    
.end main
    
    
/* clear ports in E */
.ent PortE0_3Clear 
PortE0_3Clear:
    la $s0, LATECLR
    sw $a0, 0($s0)

    jr $ra
    nop
.end PortE0_3Clear

/* set ports in E to inputs */
.ent PortE0_3Input
PortE0_3Input:	
    la $t0, TRISESET
    sw $a0,0($t0)
    jr $ra
    nop
    
.end PortE0_3Input

/* set ports in A to output */
.ent PortBOutput 
PortBOutput:
	
    la	$s0, TRISBCLR
    sw	$a0, 0($s0)

    la	$t0, LATBCLR
    sw	$a0, 0($t0)

    jr	$ra
    nop
.end PortBOutput