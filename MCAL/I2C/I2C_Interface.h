#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

/* Mode Definitions */
#define I2C_MASTER  0
#define I2C_SLAVE   1

/* Master Functions */
void I2C_Master_Init(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
u8   I2C_Master_Write(u8 Data);
u8   I2C_Master_ReadAck(void);
u8   I2C_Master_ReadNack(void);

/* Slave Functions */
void I2C_Slave_Init(u8 Address);
u8   I2C_Slave_Read(void);
void I2C_Slave_Write(u8 Data);

/* Common */
void I2C_Init(void);

#endif
