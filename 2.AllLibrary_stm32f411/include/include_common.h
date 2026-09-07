#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H
/* Thư viện được tạo ra với mục đích làm thư viện chung 
    khai báo các thư viện cần thiết để chạy các hàm trong
    folder device*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

// Quy uoc dat bit
#define BIT(x)   (1UL << (x))
#define PIN(bank,num) ((uint16_t)(((bank - 'A') << 8) | (num)))
#define PINNO(pin)    (pin & 255)   
#define PINBANK(pin)    (pin >> 8)
#define PPRE_BITS(x) \
    ((x) == 1  ? 0x0U : \
     (x) == 2  ? 0x4U : \
     (x) == 4  ? 0x5U : \
     (x) == 8  ? 0x6U : \
     (x) == 16 ? 0x7U : \
     0x0U)
     
#endif