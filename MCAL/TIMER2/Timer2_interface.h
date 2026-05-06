#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void TMR2_Init(u16 target_frequency_Hz);
void TMR2_Enable(void);
void TMR2_Disable(void);


void TMR2_EnableInterrupt(void);
void TMR2_DisableInterrupt(void);
void TMR2_SetCallback(void (*ptr)(void));
void TMR2_ISR_Handler(void);




#endif