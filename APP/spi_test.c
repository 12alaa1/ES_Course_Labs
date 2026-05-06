#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Test: SPI master sends incrementing byte, reads response to PORTD */
void main(void)
{
    u8 txData = 0;
    u8 rxData;

    SetPortDirection(GPIO_PORTD, 0x00);  /* PORTD output for display */
    SetPinDirection(GPIO_PORTA, GPIO_PIN5, OUTPUT);  /* SS pin */

    SPI_Init();

    while(1)
    {
        /* Assert SS low */
        SetPinValue(GPIO_PORTA, GPIO_PIN5, LOW);

        rxData = SPI_Transfer(txData);

        /* Deassert SS */
        SetPinValue(GPIO_PORTA, GPIO_PIN5, HIGH);

        /* Display received data */
        SetPortValue(GPIO_PORTD, rxData);

        txData++;
        { volatile u16 d; for(d=0; d<30000; d++); }
    }
}