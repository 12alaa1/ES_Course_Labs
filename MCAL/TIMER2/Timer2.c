#include "../../SERVICES/BIT_MATH.h"
#include "Timer2_interface.h"
#include "../MCU_Registers.h"


static void (*TMR2_Callback)(void) = 0;

void TMR2_Init(u16 target_frequency_Hz) {
    u32 calculated_pr2;
    
    calculated_pr2 = (F_OSC / ((u32)target_frequency_Hz * 4 * 16)) - 1;
    
    if (calculated_pr2 > 255) {
        PR2 = 255;
    } else {
        PR2 = (u8)calculated_pr2; 
    }
    
    SET_BIT(T2CON, T2CKPS1);
    SET_BIT(T2CON, T2CKPS0);
}

void TMR2_Enable(void) {
	SET_BIT(T2CON, TMR2ON);
}

void TMR2_Disable(void) {
	CLR_BIT(T2CON, TMR2ON);
}


void TMR2_EnableInterrupt(void) {
	SET_BIT(PIE1, TMR2IE);
}

void TMR2_DisableInterrupt(void) {
	CLR_BIT(PIE1, TMR2IE);
}

void TMR2_SetCallback(void (*ptr)(void)) {
	if (ptr != 0) {
		TMR2_Callback = ptr;
	}
}

void TMR2_ISR_Handler(void) {
	if (TMR2_Callback != 0) {
		TMR2_Callback();
	}
	CLR_BIT(PIR1, TMR2IF);
}