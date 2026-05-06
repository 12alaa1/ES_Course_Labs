#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)
{
<<<<<<< HEAD
    SetPinDirection(Port, Pin, OUTPUT);
=======
    GPIO_SetPinDirection(Port, Pin, GPIO_OUTPUT);
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}

void LED_On(u8 Port, u8 Pin)
{
<<<<<<< HEAD
    SetPinValue(Port, Pin, HIGH);
=======
    GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}

void LED_Off(u8 Port, u8 Pin)
{
<<<<<<< HEAD
    SetPinValue(Port, Pin, LOW);
=======
    GPIO_SetPinValue(Port, Pin, GPIO_LOW);
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}

void LED_Toggle(u8 Port, u8 Pin)
{
<<<<<<< HEAD
    u8 current = GetPinValue(Port, Pin);

    if(current == HIGH)
        SetPinValue(Port, Pin, LOW);
    else
        SetPinValue(Port, Pin, HIGH);
=======
    u8 current = GPIO_GetPinValue(Port, Pin);

    if(current == GPIO_HIGH)
        GPIO_SetPinValue(Port, Pin, GPIO_LOW);
    else
        GPIO_SetPinValue(Port, Pin, GPIO_HIGH);
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}