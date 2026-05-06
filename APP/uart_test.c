#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Callback: echo received byte back */
void UART_RX_Callback(u8 st)
{
    UART_Write_ISR(st);
}

/* Test: UART echo — send back whatever is received */
void main(void)
{
    UART_TX_Init();
    UART_RX_Init();
    UART_SetCallback(UART_RX_Callback);

    /* Send a greeting */
    UART_WriteString("UART Ready\r\n");

    while(1)
    {
        /* RX handled by interrupt */
    }
}