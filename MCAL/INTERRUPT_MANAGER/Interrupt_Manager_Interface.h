#ifndef INTERRUPT_MANAGER_INTERFACE_H
#define INTERRUPT_MANAGER_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "Interrupt_Manager_Private.h"
#include "Interrupt_Manager_Config.h"

/*
 * No public API — the interrupt() function is called automatically
 * by the hardware. Individual ISR handlers are defined in each
 * driver module and declared as extern here.
 */

extern void EXT_INT_ISR(void);
extern void TIMER0_ISR(void);
extern void UART_ISR(void);

#endif
