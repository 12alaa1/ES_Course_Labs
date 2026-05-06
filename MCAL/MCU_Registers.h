#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H


#define F_OSC 8000000UL

#define TRISA   (*((volatile u8*)0x85))
#define TRISB   (*((volatile u8*)0x86))
#define TRISC   (*((volatile u8*)0x87))
#define TRISD   (*((volatile u8*)0x88))
#define TRISE   (*((volatile u8*)0x89))

#define PORTA   (*((volatile u8*)0x05))
#define PORTB   (*((volatile u8*)0x06))
#define PORTC   (*((volatile u8*)0x07))
#define PORTD   (*((volatile u8*)0x08))
#define PORTE   (*((volatile u8*)0x09))

#define INTCON (*((volatile u8*)0x0B))
#define TMR0 (*((volatile u8*)0x01))
//INTCON & TMR0 Bits
#define GIE 7
#define PEIE 6
#define TMR0IE 5
#define INTE 4
#define TMR0IF 2
#define INTF 1



#define OPTION_REG (*((volatile u8*)0x81))
//OPTION_REG Bits
#define INTEDG 6
#define T0CS 5
#define T0SE 4
#define PSA 3
#define PS2 2
#define PS1 1
#define PS0 0



#define TMR2     (*(volatile u8*)0x11)
#define T2CON    (*(volatile u8*)0x12)
#define PR2     (*(volatile u8*)0x92)
//T2CON & TMR2 & PR2 Bits
#define TMR2ON   2
#define T2CKPS1  1
#define T2CKPS0  0



#define CCPR1L   (*(volatile u8*)0x15)
#define CCP1CON  (*(volatile u8*)0x17)
//CCP1CON & CCPR1l Bits
#define CCP1M3   3
#define CCP1M2   2


#define PIE1     (*(volatile u8*)0x8C)
#define PIR1     (*(volatile u8*)0x0C)
//PIE1 & PIR1 Bits
#define TMR2IE   1
#define TMR2IF   1




#define ADCON1_REG  (*(volatile unsigned char *)0x9F)




#define RISING_EDGE 1
#define FALLING_EDGE 0


#endif