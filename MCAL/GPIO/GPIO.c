<<<<<<< HEAD
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "../../SERVICES/BIT_MATH.h"

void SetPinDirection(u8 Port, u8 Pin, u8 Direction)
=======
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "../../SERVICES/BIT_MATH.h"


void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
{
    switch(Port)
    {
        case GPIO_PORTA:
<<<<<<< HEAD
            if(Direction == OUTPUT) CLR_BIT(TRISA, Pin);
            else                        SET_BIT(TRISA, Pin);
            break;
        case GPIO_PORTB:
            if(Direction == OUTPUT) CLR_BIT(TRISB, Pin);
            else                        SET_BIT(TRISB, Pin);
            break;
        case GPIO_PORTC:
            if(Direction == OUTPUT) CLR_BIT(TRISC, Pin);
            else                        SET_BIT(TRISC, Pin);
            break;
        case GPIO_PORTD:
            if(Direction == OUTPUT) CLR_BIT(TRISD, Pin);
            else                        SET_BIT(TRISD, Pin);
            break;
        case GPIO_PORTE:
            if(Direction == OUTPUT) CLR_BIT(TRISE, Pin);
            else                        SET_BIT(TRISE, Pin);
            break;
        default: break;
    }
}

void SetPinValue(u8 Port, u8 Pin, u8 Value)
=======
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISA, Pin);
            else
                SET_BIT(TRISA, Pin);
        break;

        case GPIO_PORTB:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISB, Pin);
            else
                SET_BIT(TRISB, Pin);
        break;

        case GPIO_PORTC:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISC, Pin);
            else
                SET_BIT(TRISC, Pin);
        break;

        case GPIO_PORTD:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISD, Pin);
            else
                SET_BIT(TRISD, Pin);
        break;

        case GPIO_PORTE:
            if(Direction == GPIO_OUTPUT)
                CLR_BIT(TRISE, Pin);
            else
                SET_BIT(TRISE, Pin);
        break;

        default:
        break;
    }
}


void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
{
    switch(Port)
    {
        case GPIO_PORTA:
<<<<<<< HEAD
            if(Value == HIGH) SET_BIT(PORTA, Pin);
            else                   CLR_BIT(PORTA, Pin);
            break;
        case GPIO_PORTB:
            if(Value == HIGH) SET_BIT(PORTB, Pin);
            else                   CLR_BIT(PORTB, Pin);
            break;
        case GPIO_PORTC:
            if(Value == HIGH) SET_BIT(PORTC, Pin);
            else                   CLR_BIT(PORTC, Pin);
            break;
        case GPIO_PORTD:
            if(Value == HIGH) SET_BIT(PORTD, Pin);
            else                   CLR_BIT(PORTD, Pin);
            break;
        case GPIO_PORTE:
            if(Value == HIGH) SET_BIT(PORTE, Pin);
            else                   CLR_BIT(PORTE, Pin);
            break;
        default: break;
    }
}

u8 GetPinValue(u8 Port, u8 Pin)
{
    u8 val = 0;
    switch(Port)
    {
        case GPIO_PORTA: val = GET_BIT(PORTA, Pin); break;
        case GPIO_PORTB: val = GET_BIT(PORTB, Pin); break;
        case GPIO_PORTC: val = GET_BIT(PORTC, Pin); break;
        case GPIO_PORTD: val = GET_BIT(PORTD, Pin); break;
        case GPIO_PORTE: val = GET_BIT(PORTE, Pin); break;
        default: break;
    }
    return val;
}

void SetPortDirection(u8 Port, u8 Direction)
{
    switch(Port)
    {
        case GPIO_PORTA: TRISA = Direction; break;
        case GPIO_PORTB: TRISB = Direction; break;
        case GPIO_PORTC: TRISC = Direction; break;
        case GPIO_PORTD: TRISD = Direction; break;
        case GPIO_PORTE: TRISE = Direction; break;
        default: break;
    }
}

void SetPortValue(u8 Port, u8 Value)
{
    switch(Port)
    {
        case GPIO_PORTA: PORTA = Value; break;
        case GPIO_PORTB: PORTB = Value; break;
        case GPIO_PORTC: PORTC = Value; break;
        case GPIO_PORTD: PORTD = Value; break;
        case GPIO_PORTE: PORTE = Value; break;
        default: break;
    }
}

u8 GetPortValue(u8 Port)
{
    switch(Port)
    {
        case GPIO_PORTA: return PORTA;
        case GPIO_PORTB: return PORTB;
        case GPIO_PORTC: return PORTC;
        case GPIO_PORTD: return PORTD;
        case GPIO_PORTE: return PORTE;
        default: return 0;
    }
=======
            if(Value == GPIO_HIGH)
                SET_BIT(PORTA, Pin);
            else
                CLR_BIT(PORTA, Pin);
        break;

        case GPIO_PORTB:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTB, Pin);
            else
                CLR_BIT(PORTB, Pin);
        break;

        case GPIO_PORTC:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTC, Pin);
            else
                CLR_BIT(PORTC, Pin);
        break;

        case GPIO_PORTD:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTD, Pin);
            else
                CLR_BIT(PORTD, Pin);
        break;

        case GPIO_PORTE:
            if(Value == GPIO_HIGH)
                SET_BIT(PORTE, Pin);
            else
                CLR_BIT(PORTE, Pin);
        break;

        default:
        break;
    }
}


u8 GPIO_GetPinValue(u8 Port, u8 Pin)
{
    u8 Local_Value = 0;

    switch(Port)
    {
        case GPIO_PORTA:
            Local_Value = GET_BIT(PORTA, Pin);
        break;

        case GPIO_PORTB:
            Local_Value = GET_BIT(PORTB, Pin);
        break;

        case GPIO_PORTC:
            Local_Value = GET_BIT(PORTC, Pin);
        break;

        case GPIO_PORTD:
            Local_Value = GET_BIT(PORTD, Pin);
        break;

        case GPIO_PORTE:
            Local_Value = GET_BIT(PORTE, Pin);
        break;

        default:
        break;
    }

    return Local_Value;
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}

void GPIO_Init(void)
{
    TRISA = GPIO_PORTA_DIR;
    TRISB = GPIO_PORTB_DIR;
<<<<<<< HEAD
    TRISC = GPIO_PORTC_DIR;
    TRISD = GPIO_PORTD_DIR;
    TRISE = GPIO_PORTE_DIR;

    PORTA = GPIO_PORTA_INIT_VAL;
    PORTB = GPIO_PORTB_INIT_VAL;
    PORTC = GPIO_PORTC_INIT_VAL;
    PORTD = GPIO_PORTD_INIT_VAL;
    PORTE = GPIO_PORTE_INIT_VAL;
=======

    PORTA = GPIO_PORTA_INIT_VAL;
    PORTB = GPIO_PORTB_INIT_VAL;
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6
}