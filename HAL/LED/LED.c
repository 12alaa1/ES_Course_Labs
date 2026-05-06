#include "LED_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void LED_Init(u8 Port, u8 Pin)
{
    SetPinDirection(Port, Pin, OUTPUT);
}

void LED_On(u8 Port, u8 Pin)
{
    SetPinValue(Port, Pin, HIGH);
}

void LED_Off(u8 Port, u8 Pin)
{
    SetPinValue(Port, Pin, LOW);
}

void LED_Toggle(u8 Port, u8 Pin)
{
    u8 current = GetPinValue(Port, Pin);

    if(current == HIGH)
        SetPinValue(Port, Pin, LOW);
    else
        SetPinValue(Port, Pin, HIGH);
}