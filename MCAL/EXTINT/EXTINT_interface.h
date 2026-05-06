#ifndef EXTINT_INTERFACE_H
#define EXTINT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 edge_type);
void EXT_INT_SetCallback(void (*ptr)(void));
void EXT_INT_ISR(void);

#endif