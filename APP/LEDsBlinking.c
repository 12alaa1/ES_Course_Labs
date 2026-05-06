/*
* APPLICATION LAYER


*/

#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/MCU_Registers.h"


void Delay_ms(u8 milliseconds);


int main()
{
        ADCON1_REG = 0x06;
        LED_Init(GPIO_PORTB, GPIO_PIN0);
        LED_Init(GPIO_PORTB, GPIO_PIN1);
        Switch_Init(GPIO_PORTA, GPIO_PIN0);
        Switch_Init(GPIO_PORTA, GPIO_PIN1);
    while(1)
    {
                if ((switch_read(GPIO_PORTA, GPIO_PIN0) == LOW) && (switch_read(GPIO_PORTA, GPIO_PIN1) == LOW)) {
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                }
                else if (switch_read(GPIO_PORTA, GPIO_PIN0) == HIGH)
                {
                        LED_On(GPIO_PORTB, GPIO_PIN0);
                        LED_On(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(200);
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(200);
                }
                else if (switch_read(GPIO_PORTA, GPIO_PIN1) == HIGH)
                {
                        LED_On(GPIO_PORTB, GPIO_PIN0);
                        LED_On(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(500);
                        LED_Off(GPIO_PORTB, GPIO_PIN0);
                        LED_Off(GPIO_PORTB, GPIO_PIN1);
                        Delay_ms(500);
                }
    }
    return 0;
}