#include <stdio.h>

/* PERIPHERAL BASE*/
#define PERIPH_BASE     (0x40000000UL)  // Thanh ghi base cua ngoai vi

// OFFSSET ADDRESS
#define AHB1_OFFSET     (0x00020000UL)  // Tiep theo la thanh ghi cho vung AHB1 thuoc ve ngoai vi
#define RCC_OFFSET      (0x00003800UL)  // Tiep theo trong AHB1 thi co RCC
#define AHB1ENR_OFFSET  (0x30UL)        // Tiep theo sau hon la nhay vao thanh ghi cua pin

#define GPIOB_OFFSET    (0x00000400UL)
#define MODER_OFFSET    (0x00UL)
#define ODR_OFFSET      (0x14UL)

/* BASE ADDRESS*/

#define AHB1_BASE       (PERIPH_BASE + AHB1_OFFSET)
#define RCC_BASE        (AHB1_BASE + RCC_OFFSET)
#define GPIOB_BASE      (AHB1_BASE + GPIOB_OFFSET)

/* REGISTERS */
#define RCC_AHB1ENR     (*(volatile unsigned int *)(RCC_BASE + AHB1ENR_OFFSET))
#define GPIOB_MODER      (*(volatile unsigned int *)(GPIOB_BASE + MODER_OFFSET))
#define GPIOB_ODR        (*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))
int main(){
    /* ENABLE CLOCK ACCESS TO GPIO PORT B*/
    // Configure PA5
    RCC_AHB1ENR |= (1U<<1);
    GPIOB_MODER |= (1U<<10);
    GPIOB_MODER &= ~(1U<<11);
    while (1)
    {
       /* SET PIN 5 AS HIGH AND LOW REPEATEDLY */
       GPIOB_ODR |= (1U<<5);
       
       /* Small note
       set pin 5 as high : GPIOB_ODR ^= (1U<<5)
       set pin 5 as low  : GPIOB_ODR &= ~(1U<<5)
       */
      /*DELAY*/
      for (int i = 0; i < 1000000; i++);
      GPIOB_ODR &= ~(1U<<5);
      for (int i = 0; i < 1000000; i++);
      
    }
    




}