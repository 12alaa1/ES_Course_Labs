#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/EXTINT/EXTINT_interface.h"
#include "../MCAL/TIMER2/Timer2_interface.h"
#include "../MCAL/CCP1/CCP1_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/BIT_MATH.h"


u8 current_duty_cycle = 25;

void button_ISR(void) {
     current_duty_cycle += 25;

    if (current_duty_cycle > 100) {
        current_duty_cycle = 25;
    }
    
    CCP1_PWM_SetDutyCycle(current_duty_cycle);
}

int main() {
    SetPinDirection(GPIO_PORTB, GPIO_PIN0, INPUT);
    SetPinDirection(GPIO_PORTC, GPIO_PIN2, OUTPUT);


    TMR2_Init(500);
    CCP1_PWM_Init();

    CCPR1L = (25 * PR2) / 100;

    EXT_INT_Init();
    EXT_INT_SetCallback(button_ISR);
    EXT_INT_Enable();

    TMR2_Enable();
    SET_BIT(INTCON, GIE);



   return 0;
}