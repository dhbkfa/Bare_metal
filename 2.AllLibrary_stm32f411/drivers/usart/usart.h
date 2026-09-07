#ifndef USART_H
#define USART_H
#include "../../include/device/stm32f4xx.h"

struct usart
{
    /* 0x00 - Status register */
    union
    {
        volatile uint32_t SR;

        struct
        {
            volatile uint32_t PE      : 1;  // Parity error
            volatile uint32_t FE      : 1;  // Framing error
            volatile uint32_t NF      : 1;  // Noise detected
            volatile uint32_t ORE     : 1;  // Overrun error
            volatile uint32_t IDLE    : 1;  // IDLE line detected
            volatile uint32_t RXNE    : 1;  // Receive data not empty
            volatile uint32_t TC      : 1;  // Transmission complete
            volatile uint32_t TXE     : 1;  // Transmit data empty
            volatile uint32_t LBDF    : 1;  // LIN break detection flag
            volatile uint32_t CTS     : 1;  // CTS flag

            volatile uint32_t         : 22; // Reserved
        } SR_b;
    };

    /* 0x04 - Data register */
    union
    {
        volatile uint32_t DR;

        struct
        {
            volatile uint32_t DR      : 9;  // Receive/transmit data
            volatile uint32_t         : 23; // Reserved
        } DR_b;
    };

    /* 0x08 - Baud rate register */
    union
    {
        volatile uint32_t BRR;

        struct
        {
            volatile uint32_t DIV_Fraction : 4;  // Fraction
            volatile uint32_t DIV_Mantissa : 12; // Mantissa

            volatile uint32_t              : 16; // Reserved
        } BRR_b;
    };

    /* 0x0C - Control register 1 */
    union
    {
        volatile uint32_t CR1;

        struct
        {
            volatile uint32_t SBK     : 1;  // Send break
            volatile uint32_t RWU     : 1;  // Receiver wakeup
            volatile uint32_t RE      : 1;  // Receiver enable
            volatile uint32_t TE      : 1;  // Transmitter enable
            volatile uint32_t IDLEIE  : 1;  // IDLE interrupt enable
            volatile uint32_t RXNEIE  : 1;  // RXNE interrupt enable
            volatile uint32_t TCIE    : 1;  // TC interrupt enable
            volatile uint32_t TXEIE   : 1;  // TXE interrupt enable
            volatile uint32_t PEIE    : 1;  // Parity error interrupt
            volatile uint32_t PS      : 1;  // Parity selection
            volatile uint32_t PCE     : 1;  // Parity control enable
            volatile uint32_t WAKE    : 1;  // Wakeup method
            volatile uint32_t M       : 1;  // Word length
            volatile uint32_t UE      : 1;  // USART enable
            volatile uint32_t OVER8   : 1;  // Oversampling mode

            volatile uint32_t         : 17; // Reserved
        } CR1_b;
    };

    /* 0x10 - Control register 2 */
    union
    {
        volatile uint32_t CR2;

        struct
        {
            volatile uint32_t ADD     : 4;  // USART node address
            volatile uint32_t         : 1;  // Reserved
            volatile uint32_t LBDL    : 1;  // LIN break detection length
            volatile uint32_t LBDIE   : 1;  // LIN break interrupt enable
            volatile uint32_t         : 1;  // Reserved
            volatile uint32_t LBCL    : 1;  // Last bit clock pulse
            volatile uint32_t CPHA    : 1;  // Clock phase
            volatile uint32_t CPOL    : 1;  // Clock polarity
            volatile uint32_t CLKEN   : 1;  // Clock enable
            volatile uint32_t STOP    : 2;  // Stop bits
            volatile uint32_t LINEN   : 1;  // LIN mode enable

            volatile uint32_t         : 17; // Reserved
        } CR2_b;
    };

    /* 0x14 - Control register 3 */
    union
    {
        volatile uint32_t CR3;

        struct
        {
            volatile uint32_t EIE     : 1;  // Error interrupt enable
            volatile uint32_t IREN    : 1;  // IrDA mode enable
            volatile uint32_t IRLP    : 1;  // IrDA low-power mode
            volatile uint32_t HDSEL   : 1;  // Half-duplex selection
            volatile uint32_t NACK    : 1;  // Smartcard NACK enable
            volatile uint32_t SCEN    : 1;  // Smartcard mode enable
            volatile uint32_t DMAR    : 1;  // DMA receiver enable
            volatile uint32_t DMAT    : 1;  // DMA transmitter enable
            volatile uint32_t RTSE    : 1;  // RTS enable
            volatile uint32_t CTSE    : 1;  // CTS enable
            volatile uint32_t CTSIE   : 1;  // CTS interrupt enable
            volatile uint32_t ONEBIT  : 1;  // One-bit sampling
            volatile uint32_t OVRDIS  : 1;  // Overrun disable
            volatile uint32_t DDRE    : 1;  // DMA disable on reception error
            volatile uint32_t DEM     : 1;  // Driver enable mode
            volatile uint32_t DEP     : 1;  // Driver enable polarity

            volatile uint32_t         : 16; // Reserved
        } CR3_b;
    };

    /* 0x18 - Guard time and prescaler register */
    union
    {
        volatile uint32_t GTPR;

        struct
        {
            volatile uint32_t PSC     : 8;  // Prescaler value
            volatile uint32_t GT      : 8;  // Guard time value

            volatile uint32_t         : 16; // Reserved
        } GTPR_b;
    };
};

#define USART1 ((struct usart*)USART1_ADDRESS)
#define USART2 ((struct usart*)USART2_ADDRESS)
#define USART6 ((struct usart*)USART6_ADDRESS)

void usart_init(struct usart* usart,unsigned long baud);
int usart_read_ready(struct usart* usart);
int usart_write_ready(struct usart* usart);
void usart_write_char(struct usart* usart);
void usart_write_buf(struct usart* usart,char *buf,size_t len);

#endif