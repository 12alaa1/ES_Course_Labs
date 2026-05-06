#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* I2C Mode: I2C_MASTER or I2C_SLAVE */
#define I2C_MODE    I2C_MASTER

/* I2C Speed (Master): typically 100kHz or 400kHz
   SSPADD = (Fosc / (4 * Fscl)) - 1
   For 4MHz Fosc, 100kHz -> SSPADD = 9 */
#define I2C_SPEED_KHZ   100
#define I2C_SSPADD_VAL  9

/* Slave Address (7-bit, used only in slave mode) */
#define I2C_SLAVE_ADDR  0x30

#endif
