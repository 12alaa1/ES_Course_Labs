#include "Interrupt_Manager_Interface.h"

void interrupt()
{
    /* Timer0 Overflow Interrupt */
    #if INT_MGR_TIMER0_EN == 1
    if(GET_BIT(INTCON, T0IE_BIT) && GET_BIT(INTCON, T0IF_BIT))
    {
        TIMER0_ISR();
    }
    #endif

    /* External Interrupt (RB0/INT) */
    #if INT_MGR_EXT_INT_EN == 1
    if(GET_BIT(INTCON, INTE_BIT) && GET_BIT(INTCON, INTF_BIT))
    {
        EXT_INT_ISR();
    }
    #endif

    /* UART Receive Interrupt */
    #if INT_MGR_UART_RX_EN == 1
    if(GET_BIT(PIR1, RCIF_BIT))
    {
        UART_ISR();
    }
    #endif
}
