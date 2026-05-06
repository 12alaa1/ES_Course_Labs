#include "../../SERVICES/BIT_MATH.h"
#include "EXTINT_interface.h"
#include "../MCU_Registers.h"

static void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_Init(void) {
        SET_BIT(TRISB, 0);
        
        CLR_BIT(INTCON, INTF);
        
        SET_BIT(OPTION_REG, INTEDG);
}
void EXT_INT_Enable(void) {
        SET_BIT(INTCON, INTE);
}
void EXT_INT_Disable(void) {
        CLR_BIT(INTCON, INTE);
}
void EXT_INT_SetEdge(u8 type) {
        if (type == RISING_EDGE) {
                SET_BIT(OPTION_REG, INTEDG);
        } else {
                CLR_BIT(OPTION_REG, INTEDG);
        }
}
void EXT_INT_SetCallback(void (*ptr)(void)) {
        EXT_INT_Callback = ptr;
}
void EXT_INT_ISR(void) {
        if (EXT_INT_Callback != 0) {
                EXT_INT_Callback();
        }
        CLR_BIT(INTCON, INTF);
}