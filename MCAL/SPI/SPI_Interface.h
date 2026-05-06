#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/* SSPM Mode Bits (SSPCON[3:0]) */
#define SPI_MASTER_FOSC_4     0x00
#define SPI_MASTER_FOSC_16    0x01
#define SPI_MASTER_FOSC_64    0x02
#define SPI_SLAVE_SS_EN       0x04  /* Slave mode, SS enabled */
#define SPI_SLAVE_SS_DIS      0x05  /* Slave mode, SS disabled */

void SPI_Init(void);
u8   SPI_Transfer(u8 Data);
void SPI_Write(u8 Data);
u8   SPI_Read(void);

#endif
