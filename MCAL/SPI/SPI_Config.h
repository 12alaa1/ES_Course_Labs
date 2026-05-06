#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* SPI Mode: SPI_MASTER_FOSC_4, SPI_MASTER_FOSC_16,
             SPI_MASTER_FOSC_64, SPI_SLAVE_SS_EN, SPI_SLAVE_SS_DIS */
#define SPI_MODE    SPI_MASTER_FOSC_4

/* Clock Polarity: 0 = Idle Low, 1 = Idle High */
#define SPI_CKP     0

/* Clock Edge: 0 = Transmit on idle-to-active, 1 = Transmit on active-to-idle */
#define SPI_CKE     1

/* Sample Bit: 0 = Middle, 1 = End (Master only, must be 0 for Slave) */
#define SPI_SMP     0

#endif
