#ifndef INTERRUPT_MANAGER_PRIVATE_H
#define INTERRUPT_MANAGER_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers used by the ISR dispatcher */
#define INTCON      (*((volatile u8*)0x0B))
#define PIR1        (*((volatile u8*)0x0C))

/* INTCON Flag/Enable Bits */
#define GIE_BIT     7
#define PEIE_BIT    6
#define T0IE_BIT    5
#define INTE_BIT    4
#define T0IF_BIT    2
#define INTF_BIT    1

/* PIR1 Bits */
#define RCIF_BIT    5
#define SSPIF_BIT   3

#endif
