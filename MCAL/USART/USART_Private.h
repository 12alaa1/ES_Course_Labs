#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* ================= Registers Addresses ================= */

#define TXSTA   (*(volatile unsigned char*)0x98)
#define RCSTA   (*(volatile unsigned char*)0x18)
#define SPBRG   (*(volatile unsigned char*)0x99)
#define TXREG   (*(volatile unsigned char*)0x19)
#define RCREG   (*(volatile unsigned char*)0x1A)

/* ================= TXSTA Bits ================= */

#define TXEN   5
#define BRGH   2
#define SYNC   4
#define TRMT   1

/* ================= RCSTA Bits ================= */

#define SPEN   7
#define CREN   4

/* ================= PIR1 Bits ================= */

#define RCIF   5

/* ================= PIE1 Bits ================= */

#define RCIE   5


#endif