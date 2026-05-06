#include "I2C_Interface.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

static void I2C_WaitIdle(void)
{
    /* Wait for SSPIF (operation complete) */
    while(!GET_BIT(PIR1, SSPIF_BIT));
    CLR_BIT(PIR1, SSPIF_BIT);
}

/* ======== Master Mode ======== */

void I2C_Master_Init(void)
{
    /* Set SDA and SCL as inputs (open-drain driven by MSSP) */
    SET_BIT(TRISC, SCL_PIN);
    SET_BIT(TRISC, SDA_PIN);

    /* SSPM = 1000 -> I2C Master mode, clock = Fosc/(4*(SSPADD+1)) */
    SSPCON = 0x00;
    SSPCON |= 0x08;

    /* Set baud rate */
    SSPADD = I2C_SSPADD_VAL;

    /* Slew rate control disabled for 100kHz */
    SET_BIT(SSPSTAT, SMP_BIT);

    /* Enable MSSP module */
    SET_BIT(SSPCON, SSPEN_BIT);

    /* Clear flags */
    CLR_BIT(PIR1, SSPIF_BIT);
    CLR_BIT(SSPCON, WCOL_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
}

void I2C_Master_Start(void)
{
    SET_BIT(SSPCON2, SEN_BIT);
    I2C_WaitIdle();
}

void I2C_Master_RepeatedStart(void)
{
    SET_BIT(SSPCON2, RSEN_BIT);
    I2C_WaitIdle();
}

void I2C_Master_Stop(void)
{
    SET_BIT(SSPCON2, PEN_BIT);
    I2C_WaitIdle();
}

u8 I2C_Master_Write(u8 Data)
{
    SSPBUF = Data;
    I2C_WaitIdle();
    /* Return ACK status: 0 = ACK received, 1 = NACK */
    return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

u8 I2C_Master_ReadAck(void)
{
    u8 data;
    /* Enable receive */
    SET_BIT(SSPCON2, RCEN_BIT);
    I2C_WaitIdle();

    data = SSPBUF;

    /* Send ACK */
    CLR_BIT(SSPCON2, ACKDT_BIT);
    SET_BIT(SSPCON2, ACKEN_BIT);
    I2C_WaitIdle();

    return data;
}

u8 I2C_Master_ReadNack(void)
{
    u8 data;
    SET_BIT(SSPCON2, RCEN_BIT);
    I2C_WaitIdle();

    data = SSPBUF;

    /* Send NACK */
    SET_BIT(SSPCON2, ACKDT_BIT);
    SET_BIT(SSPCON2, ACKEN_BIT);
    I2C_WaitIdle();

    return data;
}

/* ======== Slave Mode ======== */

void I2C_Slave_Init(u8 Address)
{
    SET_BIT(TRISC, SCL_PIN);
    SET_BIT(TRISC, SDA_PIN);

    /* SSPM = 0110 -> I2C Slave, 7-bit address */
    SSPCON = 0x00;
    SSPCON |= 0x06;

    /* Set slave address */
    SSPADD = (Address << 1);

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN_BIT);

    /* Release clock (slave holds SCL low when data ready) */
    SET_BIT(SSPCON, CKP_BIT);

    CLR_BIT(SSPCON, WCOL_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
    CLR_BIT(PIR1, SSPIF_BIT);
}

u8 I2C_Slave_Read(void)
{
    u8 data;
    /* Wait for data */
    while(!GET_BIT(SSPSTAT, BF_BIT));

    data = SSPBUF;

    /* Release clock */
    SET_BIT(SSPCON, CKP_BIT);
    return data;
}

void I2C_Slave_Write(u8 Data)
{
    CLR_BIT(SSPCON, WCOL_BIT);
    SSPBUF = Data;

    /* Release clock for master to read */
    SET_BIT(SSPCON, CKP_BIT);

    /* Wait for transfer */
    while(!GET_BIT(PIR1, SSPIF_BIT));
    CLR_BIT(PIR1, SSPIF_BIT);
}

/* ======== Common Init ======== */
void I2C_Init(void)
{
    #if I2C_MODE == I2C_MASTER
        I2C_Master_Init();
    #else
        I2C_Slave_Init(I2C_SLAVE_ADDR);
    #endif
}