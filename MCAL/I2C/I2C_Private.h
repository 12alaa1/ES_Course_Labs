#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* MSSP Registers (I2C mode) */
#define SSPCON      (*((volatile u8*)0x14))
#define SSPCON2     (*((volatile u8*)0x91))
#define SSPSTAT     (*((volatile u8*)0x94))
#define SSPBUF      (*((volatile u8*)0x13))
#define SSPADD      (*((volatile u8*)0x93))

/* SSPCON Bits */
#define SSPEN_BIT   5
#define SSPM3_BIT   3
#define SSPM2_BIT   2
#define SSPM1_BIT   1
#define SSPM0_BIT   0
#define WCOL_BIT    7
#define SSPOV_BIT   6
#define CKP_BIT     4

/* SSPCON2 Bits */
#define SEN_BIT     0   /* Start Condition Enable */
#define RSEN_BIT    1   /* Repeated Start */
#define PEN_BIT     2   /* Stop Condition Enable */
#define RCEN_BIT    3   /* Receive Enable */
#define ACKEN_BIT   4   /* Acknowledge Sequence Enable */
#define ACKDT_BIT   5   /* Acknowledge Data Bit (0=ACK, 1=NACK) */
#define ACKSTAT_BIT 6   /* Acknowledge Status (0=ACK received) */
#define GCEN_BIT    7   /* General Call Enable */

/* SSPSTAT Bits */
#define SMP_BIT     7
#define CKE_BIT     6
#define BF_BIT      0
#define R_W_BIT     2
#define S_BIT       3
#define P_BIT       4
#define D_A_BIT     5

/* PIR1 */
#define PIR1        (*((volatile u8*)0x0C))
#define SSPIF_BIT   3

/* TRISC for I2C pins */
#define TRISC       (*((volatile u8*)0x87))
#define SCL_PIN     3   /* RC3/SCL */
#define SDA_PIN     4   /* RC4/SDA */

#endif
