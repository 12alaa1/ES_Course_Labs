#include "EXT_INT_interface.h"


void EXT_INT_Init(void)
{
    /* Configure the external interrupt pin as input */
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);

    /* Configure the edge type for the external interrupt */
    EXT_INT_SetEdge(falling_edge); // Default to falling edge, can be changed later

    /* Clear the interrupt flag */
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT); // Ensure the external interrupt is disabled initially

}

void EXT_INT_Enable(void)
{
    /* Enable the external interrupt */
    SET_BIT(INTCON, INTE_BIT);
    /* Enable global interrupts */
    SET_BIT(INTCON, GIE_BIT);

    CLR_BIT(INTCON, INTF_BIT); // Clear any pending interrupt flag
}

void EXT_INT_Disable(void)
{
    /* Clear the interrupt flag */
    CLR_BIT(INTCON, INTF_BIT);
    /* Disable the external interrupt */
    CLR_BIT(INTCON, INTE_BIT);

}

void EXT_INT_SetEdge(u8 Edgetype)
{
    if (Edgetype == rising_edge)
    {
        /* Configure for rising edge */
        CLR_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 0 for rising edge
    }
    else if (Edgetype == falling_edge)
    {
        /* Configure for falling edge */
        SET_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 1 for falling edge
    }
}

void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_SetCallback(void (*ptr)(void)) {
    if (ptr != 0) {
        EXT_INT_Callback = ptr;
    }
}

void EXT_INT_ISR(void)
{

    CLR_BIT(INTCON , INTF_BIT);

    if(EXT_INT_Callback != 0)
    {
        EXT_INT_Callback();
    }

}

/*
void interrupt() {
    if (GET_BIT(INTCON, INTF_BIT)) {
        // Clear the interrupt flag
        CLR_BIT(INTCON, INTF_BIT);

        // Call the registered callback function
        if (EXT_INT_Callback != 0) {
            EXT_INT_Callback();
        }
    }
}

*/