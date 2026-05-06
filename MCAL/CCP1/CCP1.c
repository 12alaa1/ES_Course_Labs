#include "../../SERVICES/BIT_MATH.h"
#include "CCP1_interface.h"
#include "../MCU_Registers.h"


void CCP1_PWM_Init(void) {
        SET_BIT(CCP1CON, CCP1M3);
    SET_BIT(CCP1CON, CCP1M2);

    CCPR1L = 0;
}

void CCP1_PWM_SetDutyCycle(u8 percentage) {
        u16 mapped_value;

    if (percentage > 100) {
        percentage = 100;
    }
    
    mapped_value = ((u16)percentage * PR2) / 100;
    
    CCPR1L = (u8)mapped_value;
}