#include "Switch_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void Switch_Init(u8 Port, u8 Pin)
{
    SetPinDirection(Port, Pin, INPUT);
}

u8 switch_read(u8 Port, u8 Pin) {
        return GetPinValue(Port, Pin);
}