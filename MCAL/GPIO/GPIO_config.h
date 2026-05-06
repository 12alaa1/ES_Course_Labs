#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/* Initial Directions */
<<<<<<< HEAD
#define GPIO_PORTA_DIR       0x00
#define GPIO_PORTB_DIR       0xFF
#define GPIO_PORTC_DIR       0x00
#define GPIO_PORTD_DIR       0x00
#define GPIO_PORTE_DIR       0x00
=======
#define GPIO_PORTA_DIR   0x00   // All Output
#define GPIO_PORTB_DIR   0xFF   // All Input
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6

/* Initial Values */
#define GPIO_PORTA_INIT_VAL  0x00
#define GPIO_PORTB_INIT_VAL  0x00
<<<<<<< HEAD
#define GPIO_PORTC_INIT_VAL  0x00
#define GPIO_PORTD_INIT_VAL  0x00
#define GPIO_PORTE_INIT_VAL  0x00
=======
>>>>>>> f5b011729a733c9d044c8c5c27d98ca2384f78e6

#endif