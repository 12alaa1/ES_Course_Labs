#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Test: I2C master writes a byte to slave at address 0x50 (e.g., EEPROM)
   then reads it back and displays on PORTD */
void I2C_Test(void)
{
    u8 readData;

    SetPortDirection(GPIO_PORTD, 0x00);  /* PORTD output */

    I2C_Master_Init();

    while(1)
    {
        /* Write 0xAA to EEPROM address 0x00 */
        I2C_Master_Start();
        I2C_Master_Write(0xA0);     /* EEPROM control byte (write) */
        I2C_Master_Write(0x00);     /* Memory address */
        I2C_Master_Write(0xAA);     /* Data */
        I2C_Master_Stop();

        /* Small write-cycle delay */
        { volatile u16 d; for(d=0; d<30000; d++); }

        /* Read back from address 0x00 */
        I2C_Master_Start();
        I2C_Master_Write(0xA0);     /* Control byte (write for address) */
        I2C_Master_Write(0x00);     /* Memory address */
        I2C_Master_RepeatedStart();
        I2C_Master_Write(0xA1);     /* Control byte (read) */
        readData = I2C_Master_ReadNack();
        I2C_Master_Stop();

        /* Display on PORTD */
        SetPortValue(GPIO_PORTD, readData);

        { volatile u16 d; for(d=0; d<60000; d++); }
    }
}