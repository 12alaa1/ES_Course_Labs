#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include "EXT_INT_Config.h"
#include "EXT_INT_Private.h"



/* External Interrupt Configuration */

#define GIE_BIT 7
#define INTE_BIT 4
#define INTF_BIT 1
/* Edge types */
#define INTEDGE_BIT 6
#define rising_edge 1
#define falling_edge 0

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);



#endif