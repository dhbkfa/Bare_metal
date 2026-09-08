#include "usart.h"

void usart_init(struct usart* usart,unsigned long baud)
{
    uint8_t af = 7; // Default AF7 for USART1-3 , will be overridden for USART
    uint16_t rx = 0,tx = 0;
    uint32_t pclk = 0;
    // Enable USART clock , detemine AF and pins based on usart instance
    if (usart == USART1)
    {
        RCC->APB2ENR_b.USART1EN = 1;    // Enable USART1 clock
        af = 7;                         // AF7 for USART1
        rx = PIN('A',10);               // USART1_RX : Pin A10
        tx = PIN('A',9);                // USART1_TX : Pin A9
        pclk = APB2_FREQUENCY;         
    }
    else if (usart == USART2)
    {
        RCC->APB1ENR_b.USART2EN = 1;    // Enable USART2 clock
        af = 7;                         // AF7 for USART2
        rx = PIN('A',3);                // USART2_RX : Pin A3
        tx = PIN('A',2);                // USART2_TX : Pin A2
        pclk = APB1_FREQUENCY;
    }
    else if (usart == USART6)
    {
        RCC->APB2ENR_b.USART6EN = 1;    // Enable USART6 clock
        af = 8;                         // AF7 for USART6
        rx = PIN('A',12);                // USART6_RX : Pin A12
        tx = PIN('A',11);                // USART6_TX : Pin A11
        pclk = APB2_FREQUENCY;         
    }

    gpio_set_mode(tx, GPIO_MODE_AF); 
    gpio_set_mode(rx, GPIO_MODE_AF);

    gpio_set_af(tx,af);
    gpio_set_af(rx,af);

    // Diable USART before configuration

    usart->CR1 = 0;     // Clear CR1 to diable USART and reset settings
    // Better Baud Rate calculation for 16x oversampling
    // This handles the 4-bit fraction correctly
    uint32_t div = (pclk + (baud/2)) / baud;
    usart->BRR = div;

    // Enable USART,receiver and transmitter 
    // This part is interesting because in order to avoid RMW issues with the UE bit
    // The fields MUST be set to volatile
    usart->CR1_b.RE = 1; // Enable receiver
    usart->CR1_b.TE = 1; // Enable Transmitter
    usart->CR1_b.UE = 1; // Enble USART

}
int usart_read_ready(struct usart* usart)
{
    return usart->SR_b.RXNE; // If RXNE bit is set , data is ready
}
uint8_t usart_read_byte(struct usart* usart)
{
    return (uint8_t)(usart->DR & 255);

}
void usart_write_byte(struct usart* usart,char ch)
{
    while (!usart->SR_b.TXE)
    {
        (void)0;    // Wait until TXE bit is set , indicating data register is empty
    }
    usart->DR = (uint32_t)ch;
}
void usart_write_buf(struct usart* usart,char *buf,size_t len)
{
    while (len-- >0)
    {
        usart_write_byte(usart,*(uint8_t*)buf++);
    }
    
}
