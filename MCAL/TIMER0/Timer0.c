#include "../../SERVICES/BIT_MATH.h"
#include "Timer0_interface.h"
#include "../MCU_Registers.h"


static void (*TMR0_Callback)(void) = 0;

static u32 overflows_needed = 0;
static u8 jump_value = 0;
static u32 current_overflows = 0;

void TMR0_Init(void) {
    CLR_BIT(OPTION_REG, T0CS);
    
    CLR_BIT(OPTION_REG, PSA);
    
    SET_BIT(OPTION_REG, PS2);
    SET_BIT(OPTION_REG, PS1);
    SET_BIT(OPTION_REG, PS0);
    
    CLR_BIT(INTCON, TMR0IF);
}
void TMR0_Enable(void) {
        SET_BIT(INTCON, TMR0IE);
}
void TMR0_Disable(void) {
        CLR_BIT(INTCON, TMR0IE);
}
void TMR0_Reset(void) {
     TMR0 = 0;
}
void TMR0_SetInterval_s(u8 seconds) {
    u32 total_ticks = seconds * 7812;
    u8 remainder = total_ticks % 256;
    overflows_needed = total_ticks / 256;
    jump_value = 256 - remainder;
    current_overflows = 0; 
}
void TMR0_SetCallback(void (*ptr)(void)) {
        if (ptr != 0) {
                TMR0_Callback = ptr;
        }
}
void TIMER0_ISR(void) {
        current_overflows++;
        
    if (current_overflows == overflows_needed) {
        TMR0 = jump_value;
    }
    else if (current_overflows > overflows_needed) {
        
        current_overflows = 0;
        
        if (TMR0_Callback != 0) {
            TMR0_Callback();
        }
    }

    CLR_BIT(INTCON, TMR0IF);
}