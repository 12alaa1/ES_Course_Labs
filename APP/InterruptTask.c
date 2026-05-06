#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/EXTINT/EXTINT_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"


void app_toggle_led(void) {
     LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}


int main() {
     LED_Init(GPIO_PORTB, GPIO_PIN1);
     Switch_Init(GPIO_PORTB, GPIO_PIN0);
     
     EXT_INT_Init();
     EXT_INT_SetEdge(RISING_EDGE);
     EXT_INT_SetCallback(app_toggle_led);
     EXT_INT_Enable();
     
     while(1) {
     }
     return 0;
}