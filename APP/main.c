<<<<<<< HEAD
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"


#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1  GPIO_PIN0
#define MOTOR_PIN2  GPIO_PIN2

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN1

//u8 USART_data = 0;
void Bluetooth_UART_Callback(u8 UART_data)
{
     //UART_Write(UART_data);
    if (UART_data == 'f')  // forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_HIGH);
    }
    else if (UART_data == 's') // stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_LOW);
    }
    

}

int main(void)
{
    // Initialize GPIOs
    GPIO_Init();
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    // Initialize UART
    UART_RX_Init();
    UART_TX_Init();
    //UART_Write('A');  // write  A  to the  Virtual Terminal


    // Set UART callback
    UART_SetCallback(Bluetooth_UART_Callback);

    while(1)
    {
        // main loop can be empty because interrupts handle everything
    }

    return 0;
}
=======
/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);

    while(1)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        delay();

        LED_Off(GPIO_PORTB, GPIO_PIN0);
        delay();
    }
}
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
