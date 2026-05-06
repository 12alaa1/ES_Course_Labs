#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXTINT/EXTINT_interface.h"
#include "../MCAL/TIMER0/Timer0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/BIT_MATH.h"

static u8 led2_seconds = 0;

void scheduler(void) {
     LED_Toggle(GPIO_PORTB, GPIO_PIN1);
     led2_seconds++;
     if (led2_seconds == 2) {
         LED_Toggle(GPIO_PORTB, GPIO_PIN2);
         led2_seconds = 0;
     }
}


int main() {
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    
    SET_BIT(INTCON, GIE);
    TMR0_Init();
    TMR0_SetInterval_s(1);
    TMR0_SetCallback(scheduler);
    TMR0_Enable();

    while(1) {
    
    }


    return 0;
}