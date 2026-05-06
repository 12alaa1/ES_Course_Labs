#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch States */
#define OFF    0
#define ON     1
#define PRESSED 1

void Switch_Init(u8 Port, u8 Pin);
u8 switch_read(u8 Port, u8 Pin);

#endif