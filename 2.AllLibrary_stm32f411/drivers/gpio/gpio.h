#ifndef GPIO_H
#define GPIO_H
#include "../../include/device/stm32f4xx.h"

void gpio_write(uint16_t pin , bool val);
void gpio_set_mode(uint16_t pin,uint8_t mode);
/* Định nghĩa các thanh ghi cho gpio */
struct gpio
{
    /* ============================================================
     * GPIO port mode register
     * ============================================================ */
    union
    {
        volatile uint32_t MODER;

        struct
        {
            volatile uint32_t MODER0  : 2;    // GPIO pin 0 mode
            volatile uint32_t MODER1  : 2;    // GPIO pin 1 mode
            volatile uint32_t MODER2  : 2;    // GPIO pin 2 mode
            volatile uint32_t MODER3  : 2;    // GPIO pin 3 mode
            volatile uint32_t MODER4  : 2;    // GPIO pin 4 mode
            volatile uint32_t MODER5  : 2;    // GPIO pin 5 mode
            volatile uint32_t MODER6  : 2;    // GPIO pin 6 mode
            volatile uint32_t MODER7  : 2;    // GPIO pin 7 mode
            volatile uint32_t MODER8  : 2;    // GPIO pin 8 mode
            volatile uint32_t MODER9  : 2;    // GPIO pin 9 mode
            volatile uint32_t MODER10 : 2;    // GPIO pin 10 mode
            volatile uint32_t MODER11 : 2;    // GPIO pin 11 mode
            volatile uint32_t MODER12 : 2;    // GPIO pin 12 mode
            volatile uint32_t MODER13 : 2;    // GPIO pin 13 mode
            volatile uint32_t MODER14 : 2;    // GPIO pin 14 mode
            volatile uint32_t MODER15 : 2;    // GPIO pin 15 mode
        } MODER_b;

    };


    /* ============================================================
     * GPIO port output type register
     * ============================================================ */
    union
    {
        volatile uint32_t OTYPER;

        struct
        {
            volatile uint32_t OT0  : 1;       // Pin 0 output type
            volatile uint32_t OT1  : 1;       // Pin 1 output type
            volatile uint32_t OT2  : 1;       // Pin 2 output type
            volatile uint32_t OT3  : 1;       // Pin 3 output type
            volatile uint32_t OT4  : 1;       // Pin 4 output type
            volatile uint32_t OT5  : 1;       // Pin 5 output type
            volatile uint32_t OT6  : 1;       // Pin 6 output type
            volatile uint32_t OT7  : 1;       // Pin 7 output type
            volatile uint32_t OT8  : 1;       // Pin 8 output type
            volatile uint32_t OT9  : 1;       // Pin 9 output type
            volatile uint32_t OT10 : 1;       // Pin 10 output type
            volatile uint32_t OT11 : 1;       // Pin 11 output type
            volatile uint32_t OT12 : 1;       // Pin 12 output type
            volatile uint32_t OT13 : 1;       // Pin 13 output type
            volatile uint32_t OT14 : 1;       // Pin 14 output type
            volatile uint32_t OT15 : 1;       // Pin 15 output type
            volatile uint32_t      : 16;      // Reserved
        } OTYPER_b;

    };


    /* ============================================================
     * GPIO port output speed register
     * ============================================================ */
    union
    {
        volatile uint32_t OSPEEDR;

        struct
        {
            volatile uint32_t OSPEEDR0  : 2;  // Pin 0 output speed
            volatile uint32_t OSPEEDR1  : 2;  // Pin 1 output speed
            volatile uint32_t OSPEEDR2  : 2;  // Pin 2 output speed
            volatile uint32_t OSPEEDR3  : 2;  // Pin 3 output speed
            volatile uint32_t OSPEEDR4  : 2;  // Pin 4 output speed
            volatile uint32_t OSPEEDR5  : 2;  // Pin 5 output speed
            volatile uint32_t OSPEEDR6  : 2;  // Pin 6 output speed
            volatile uint32_t OSPEEDR7  : 2;  // Pin 7 output speed
            volatile uint32_t OSPEEDR8  : 2;  // Pin 8 output speed
            volatile uint32_t OSPEEDR9  : 2;  // Pin 9 output speed
            volatile uint32_t OSPEEDR10 : 2;  // Pin 10 output speed
            volatile uint32_t OSPEEDR11 : 2;  // Pin 11 output speed
            volatile uint32_t OSPEEDR12 : 2;  // Pin 12 output speed
            volatile uint32_t OSPEEDR13 : 2;  // Pin 13 output speed
            volatile uint32_t OSPEEDR14 : 2;  // Pin 14 output speed
            volatile uint32_t OSPEEDR15 : 2;  // Pin 15 output speed
        } OSPEEDR_b;

    };


    /* ============================================================
     * GPIO port pull-up/pull-down register
     * ============================================================ */
    union
    {
        volatile uint32_t PUPDR;

        struct
        {
            volatile uint32_t PUPDR0  : 2;    // Pin 0 pull-up/pull-down
            volatile uint32_t PUPDR1  : 2;    // Pin 1 pull-up/pull-down
            volatile uint32_t PUPDR2  : 2;    // Pin 2 pull-up/pull-down
            volatile uint32_t PUPDR3  : 2;    // Pin 3 pull-up/pull-down
            volatile uint32_t PUPDR4  : 2;    // Pin 4 pull-up/pull-down
            volatile uint32_t PUPDR5  : 2;    // Pin 5 pull-up/pull-down
            volatile uint32_t PUPDR6  : 2;    // Pin 6 pull-up/pull-down
            volatile uint32_t PUPDR7  : 2;    // Pin 7 pull-up/pull-down
            volatile uint32_t PUPDR8  : 2;    // Pin 8 pull-up/pull-down
            volatile uint32_t PUPDR9  : 2;    // Pin 9 pull-up/pull-down
            volatile uint32_t PUPDR10 : 2;    // Pin 10 pull-up/pull-down
            volatile uint32_t PUPDR11 : 2;    // Pin 11 pull-up/pull-down
            volatile uint32_t PUPDR12 : 2;    // Pin 12 pull-up/pull-down
            volatile uint32_t PUPDR13 : 2;    // Pin 13 pull-up/pull-down
            volatile uint32_t PUPDR14 : 2;    // Pin 14 pull-up/pull-down
            volatile uint32_t PUPDR15 : 2;    // Pin 15 pull-up/pull-down
        } PUPDR_b;

    };


    /* ============================================================
     * GPIO port input data register
     * ============================================================ */
    union
    {
        volatile uint32_t IDR;

        struct
        {
            volatile uint32_t IDR0  : 1;       // Pin 0 input data
            volatile uint32_t IDR1  : 1;       // Pin 1 input data
            volatile uint32_t IDR2  : 1;       // Pin 2 input data
            volatile uint32_t IDR3  : 1;       // Pin 3 input data
            volatile uint32_t IDR4  : 1;       // Pin 4 input data
            volatile uint32_t IDR5  : 1;       // Pin 5 input data
            volatile uint32_t IDR6  : 1;       // Pin 6 input data
            volatile uint32_t IDR7  : 1;       // Pin 7 input data
            volatile uint32_t IDR8  : 1;       // Pin 8 input data
            volatile uint32_t IDR9  : 1;       // Pin 9 input data
            volatile uint32_t IDR10 : 1;       // Pin 10 input data
            volatile uint32_t IDR11 : 1;       // Pin 11 input data
            volatile uint32_t IDR12 : 1;       // Pin 12 input data
            volatile uint32_t IDR13 : 1;       // Pin 13 input data
            volatile uint32_t IDR14 : 1;       // Pin 14 input data
            volatile uint32_t IDR15 : 1;       // Pin 15 input data
            volatile uint32_t       : 16;      // Reserved
        } IDR_b;

    };


    /* ============================================================
     * GPIO port output data register
     * ============================================================ */
    union
    {
        volatile uint32_t ODR;

        struct
        {
            volatile uint32_t ODR0  : 1;       // Pin 0 output data
            volatile uint32_t ODR1  : 1;       // Pin 1 output data
            volatile uint32_t ODR2  : 1;       // Pin 2 output data
            volatile uint32_t ODR3  : 1;       // Pin 3 output data
            volatile uint32_t ODR4  : 1;       // Pin 4 output data
            volatile uint32_t ODR5  : 1;       // Pin 5 output data
            volatile uint32_t ODR6  : 1;       // Pin 6 output data
            volatile uint32_t ODR7  : 1;       // Pin 7 output data
            volatile uint32_t ODR8  : 1;       // Pin 8 output data
            volatile uint32_t ODR9  : 1;       // Pin 9 output data
            volatile uint32_t ODR10 : 1;       // Pin 10 output data
            volatile uint32_t ODR11 : 1;       // Pin 11 output data
            volatile uint32_t ODR12 : 1;       // Pin 12 output data
            volatile uint32_t ODR13 : 1;       // Pin 13 output data
            volatile uint32_t ODR14 : 1;       // Pin 14 output data
            volatile uint32_t ODR15 : 1;       // Pin 15 output data
            volatile uint32_t       : 16;      // Reserved
        } ODR_b;

    };


    /* ============================================================
     * GPIO port bit set/reset register
     * ============================================================ */
    union
    {
        volatile uint32_t BSRR;

        struct
        {
            volatile uint32_t BS0  : 1;        // Set pin 0
            volatile uint32_t BS1  : 1;        // Set pin 1
            volatile uint32_t BS2  : 1;        // Set pin 2
            volatile uint32_t BS3  : 1;        // Set pin 3
            volatile uint32_t BS4  : 1;        // Set pin 4
            volatile uint32_t BS5  : 1;        // Set pin 5
            volatile uint32_t BS6  : 1;        // Set pin 6
            volatile uint32_t BS7  : 1;        // Set pin 7
            volatile uint32_t BS8  : 1;        // Set pin 8
            volatile uint32_t BS9  : 1;        // Set pin 9
            volatile uint32_t BS10 : 1;        // Set pin 10
            volatile uint32_t BS11 : 1;        // Set pin 11
            volatile uint32_t BS12 : 1;        // Set pin 12
            volatile uint32_t BS13 : 1;        // Set pin 13
            volatile uint32_t BS14 : 1;        // Set pin 14
            volatile uint32_t BS15 : 1;        // Set pin 15

            volatile uint32_t BR0  : 1;         // Reset pin 0
            volatile uint32_t BR1  : 1;         // Reset pin 1
            volatile uint32_t BR2  : 1;         // Reset pin 2
            volatile uint32_t BR3  : 1;         // Reset pin 3
            volatile uint32_t BR4  : 1;         // Reset pin 4
            volatile uint32_t BR5  : 1;         // Reset pin 5
            volatile uint32_t BR6  : 1;         // Reset pin 6
            volatile uint32_t BR7  : 1;         // Reset pin 7
            volatile uint32_t BR8  : 1;         // Reset pin 8
            volatile uint32_t BR9  : 1;         // Reset pin 9
            volatile uint32_t BR10 : 1;         // Reset pin 10
            volatile uint32_t BR11 : 1;         // Reset pin 11
            volatile uint32_t BR12 : 1;         // Reset pin 12
            volatile uint32_t BR13 : 1;         // Reset pin 13
            volatile uint32_t BR14 : 1;         // Reset pin 14
            volatile uint32_t BR15 : 1;         // Reset pin 15
        } BSRR_b;

    };


    /* ============================================================
     * GPIO port configuration lock register
     * ============================================================ */
    union
    {
        volatile uint32_t LCKR;

        struct
        {
            volatile uint32_t LCK0  : 1;       // Lock pin 0 configuration
            volatile uint32_t LCK1  : 1;       // Lock pin 1 configuration
            volatile uint32_t LCK2  : 1;       // Lock pin 2 configuration
            volatile uint32_t LCK3  : 1;       // Lock pin 3 configuration
            volatile uint32_t LCK4  : 1;       // Lock pin 4 configuration
            volatile uint32_t LCK5  : 1;       // Lock pin 5 configuration
            volatile uint32_t LCK6  : 1;       // Lock pin 6 configuration
            volatile uint32_t LCK7  : 1;       // Lock pin 7 configuration
            volatile uint32_t LCK8  : 1;       // Lock pin 8 configuration
            volatile uint32_t LCK9  : 1;       // Lock pin 9 configuration
            volatile uint32_t LCK10 : 1;       // Lock pin 10 configuration
            volatile uint32_t LCK11 : 1;       // Lock pin 11 configuration
            volatile uint32_t LCK12 : 1;       // Lock pin 12 configuration
            volatile uint32_t LCK13 : 1;       // Lock pin 13 configuration
            volatile uint32_t LCK14 : 1;       // Lock pin 14 configuration
            volatile uint32_t LCK15 : 1;       // Lock pin 15 configuration
            volatile uint32_t LCKK  : 1;       // Lock key
            volatile uint32_t       : 15;      // Reserved
        } LCKR_b;

    };


    /* ============================================================
     * GPIO alternate function low register
     * Pins 0 - 7
     * ============================================================ */
    union
    {
        volatile uint32_t AFRL;

        struct
        {
            volatile uint32_t AFRL0 : 4;       // Alternate function for pin 0
            volatile uint32_t AFRL1 : 4;       // Alternate function for pin 1
            volatile uint32_t AFRL2 : 4;       // Alternate function for pin 2
            volatile uint32_t AFRL3 : 4;       // Alternate function for pin 3
            volatile uint32_t AFRL4 : 4;       // Alternate function for pin 4
            volatile uint32_t AFRL5 : 4;       // Alternate function for pin 5
            volatile uint32_t AFRL6 : 4;       // Alternate function for pin 6
            volatile uint32_t AFRL7 : 4;       // Alternate function for pin 7
        } AFRL_b;

    };


    /* ============================================================
     * GPIO alternate function high register
     * Pins 8 - 15
     * ============================================================ */
    union
    {
        volatile uint32_t AFRH;

        struct
        {
            volatile uint32_t AFRH8  : 4;      // Alternate function for pin 8
            volatile uint32_t AFRH9  : 4;      // Alternate function for pin 9
            volatile uint32_t AFRH10 : 4;      // Alternate function for pin 10
            volatile uint32_t AFRH11 : 4;      // Alternate function for pin 11
            volatile uint32_t AFRH12 : 4;      // Alternate function for pin 12
            volatile uint32_t AFRH13 : 4;      // Alternate function for pin 13
            volatile uint32_t AFRH14 : 4;      // Alternate function for pin 14
            volatile uint32_t AFRH15 : 4;      // Alternate function for pin 15
        } AFRH_b;

    };
};
// Enum values are per datasheet : 0 , 1 , 2 , 3
enum{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
};
/* Define GPIO*/
#define GPIO(bank)  ((struct gpio*)((GPIO_BASE + (0x400*bank)))) // Cho phep lay dia chi cua cac GPIO: A,B,C

#endif  