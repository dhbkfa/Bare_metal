    .syntax unified
    .cpu    cortex-m4
    .fpu    softvfp
    .thumb

    .global Reset_Handler
    .global g_pfnVectors
    .global Default_Handler


    .section    .text.Reset_Handler
    .weak       Reset_Handler
    .type       Reset_Handler, %function
Reset_Handler:
    ldr     sp, = _estack
    ldr     r0, = _sidata
    ldr     r1, = _sdata
    ldr     r2, = _edata
CopyDataLoop:
    cmp     r1,r2
    bcs     CopyDataDone
    ldr     r3, [r0], #4
    str     r3, [r1], #4
    b       CopyDataLoop
CopyDataDone:
    ldr     r1, = _sbss
    ldr     r2, = _ebss
    movs    r3, #0
ZeroBssLoop:
    cmp     r1,r2
    bcs     ZeroBssDone
    str     r3, [r1], #4
    b       ZeroBssLoop
ZeroBssDone:
    bl      main
InfiniteLoop:
    b       InfiniteLoop
    .size   Reset_Handler, .-Reset_Handler
    .section .text.Default_Handler, "ax" , %progbits
    .weak   Default_Handler
    .type   Default_Handler,%function
Default_Handler:
    b       Default_Handler
    .size   Default_Handler, .-Default_Handler
    .macro  def_irq_handler handler_name
    .weak   \handler_name
    .thumb_set  \handler_name, Default_Handler
    .endm
    def_irq_handler NMI_Handler
    def_irq_handler HardFault_Handler
    def_irq_handler MemManage_Handler
    def_irq_handler BusFault_Handler
    def_irq_handler UsageFault_Handler
    def_irq_handler SVC_Handler
    def_irq_handler DebugMon_Handler
    def_irq_handler PendSV_Handler
    def_irq_handler SysTick_Handler

    /* ============================================================
 * Peripheral Interrupt Handlers
 * STM32F411xC/E
 * ============================================================ */

    def_irq_handler WWDG_Handler                /* Window Watchdog interrupt */
    def_irq_handler PVD_Handler                 /* PVD through EXTI Line detection interrupt */
    def_irq_handler TAMP_STAMP_Handler          /* Tamper and TimeStamp interrupts through EXTI line */
    def_irq_handler RTC_WKUP_Handler            /* RTC Wakeup interrupt through EXTI line */
    def_irq_handler FLASH_Handler               /* FLASH global interrupt */
    def_irq_handler RCC_Handler                 /* RCC global interrupt */

    def_irq_handler EXTI0_Handler               /* EXTI Line 0 interrupt */
    def_irq_handler EXTI1_Handler               /* EXTI Line 1 interrupt */
    def_irq_handler EXTI2_Handler               /* EXTI Line 2 interrupt */
    def_irq_handler EXTI3_Handler               /* EXTI Line 3 interrupt */
    def_irq_handler EXTI4_Handler               /* EXTI Line 4 interrupt */

    def_irq_handler DMA1_Stream0_Handler        /* DMA1 Stream 0 global interrupt */
    def_irq_handler DMA1_Stream1_Handler        /* DMA1 Stream 1 global interrupt */
    def_irq_handler DMA1_Stream2_Handler        /* DMA1 Stream 2 global interrupt */
    def_irq_handler DMA1_Stream3_Handler        /* DMA1 Stream 3 global interrupt */
    def_irq_handler DMA1_Stream4_Handler        /* DMA1 Stream 4 global interrupt */
    def_irq_handler DMA1_Stream5_Handler        /* DMA1 Stream 5 global interrupt */
    def_irq_handler DMA1_Stream6_Handler        /* DMA1 Stream 6 global interrupt */

    def_irq_handler ADC_Handler                 /* ADC1 global interrupt */

    /* Reserved IRQ vectors */

    def_irq_handler EXTI9_5_Handler             /* EXTI Line[9:5] interrupts */

    def_irq_handler TIM1_BRK_TIM9_Handler       /* TIM1 Break interrupt and TIM9 global interrupt */
    def_irq_handler TIM1_UP_TIM10_Handler       /* TIM1 Update interrupt and TIM10 global interrupt */
    def_irq_handler TIM1_TRG_COM_TIM11_Handler  /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    def_irq_handler TIM1_CC_Handler             /* TIM1 Capture Compare interrupt */

    def_irq_handler TIM2_Handler                /* TIM2 global interrupt */
    def_irq_handler TIM3_Handler                /* TIM3 global interrupt */
    def_irq_handler TIM4_Handler                /* TIM4 global interrupt */

    def_irq_handler I2C1_EV_Handler             /* I2C1 event interrupt */
    def_irq_handler I2C1_ER_Handler             /* I2C1 error interrupt */

    def_irq_handler I2C2_EV_Handler             /* I2C2 event interrupt */
    def_irq_handler I2C2_ER_Handler             /* I2C2 error interrupt */

    def_irq_handler SPI1_Handler                /* SPI1 global interrupt */
    def_irq_handler SPI2_Handler                /* SPI2 global interrupt */

    def_irq_handler USART1_Handler              /* USART1 global interrupt */
    def_irq_handler USART2_Handler              /* USART2 global interrupt */

    def_irq_handler EXTI15_10_Handler           /* EXTI Line[15:10] interrupts */
    def_irq_handler RTC_Alarm_Handler           /* EXTI Line 17 / RTC Alarms (A and B) through EXTI line */
    def_irq_handler OTG_FS_WKUP_Handler         /* EXTI Line 18 / USB OTG FS Wakeup through EXTI line */

    /* Reserved IRQ vectors */

    def_irq_handler DMA1_Stream7_Handler        /* DMA1 Stream 7 global interrupt */

    /* Reserved IRQ vector */

    def_irq_handler SDIO_Handler                /* SDIO global interrupt */
    def_irq_handler TIM5_Handler                /* TIM5 global interrupt */
    def_irq_handler SPI3_Handler                /* SPI3 global interrupt */

    /* Reserved IRQ vectors */

    def_irq_handler DMA2_Stream0_Handler        /* DMA2 Stream 0 global interrupt */
    def_irq_handler DMA2_Stream1_Handler        /* DMA2 Stream 1 global interrupt */
    def_irq_handler DMA2_Stream2_Handler        /* DMA2 Stream 2 global interrupt */
    def_irq_handler DMA2_Stream3_Handler        /* DMA2 Stream 3 global interrupt */
    def_irq_handler DMA2_Stream4_Handler        /* DMA2 Stream 4 global interrupt */

    /* Reserved IRQ vectors */

    def_irq_handler OTG_FS_Handler              /* USB OTG FS global interrupt */

    def_irq_handler DMA2_Stream5_Handler        /* DMA2 Stream 5 global interrupt */
    def_irq_handler DMA2_Stream6_Handler        /* DMA2 Stream 6 global interrupt */
    def_irq_handler DMA2_Stream7_Handler        /* DMA2 Stream 7 global interrupt */

    def_irq_handler USART6_Handler              /* USART6 global interrupt */

    def_irq_handler I2C3_EV_Handler             /* I2C3 event interrupt */
    def_irq_handler I2C3_ER_Handler             /* I2C3 error interrupt */

    /* Reserved IRQ vectors */

    def_irq_handler FPU_Handler                 /* FPU global interrupt */

    /* Reserved IRQ vectors */

    def_irq_handler SPI4_Handler                /* SPI4 global interrupt */
    def_irq_handler SPI5_Handler                /* SPI5 global interrupt */
    .section .isr_vector, "a",%progbits
    .type           g_pfnVectors, %object
g_pfnVectors:
    .word   _estack
    .word   Reset_Handler
    .word   NMI_Handler
    .word   HardFault_Handler
    .word   MemManage_Handler
    .word   BusFault_Handler
    .word   UsageFault_Handler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   SVC_Handler
    .word   DebugMon_Handler
    .word   0
    .word   PendSV_Handler
    .word   SysTick_Handler


    /* ============================================================
 * Peripheral Interrupt Vector Table
 * STM32F411xC/E
 * ============================================================ */

    .word   WWDG_Handler                /* Window Watchdog interrupt */
    .word   PVD_Handler                 /* PVD through EXTI Line detection */
    .word   TAMP_STAMP_Handler          /* Tamper and TimeStamps through EXTI line */
    .word   RTC_WKUP_Handler            /* RTC Wakeup through EXTI line */
    .word   FLASH_Handler               /* FLASH global interrupt */
    .word   RCC_Handler                 /* RCC global interrupt */

    .word   EXTI0_Handler               /* EXTI Line 0 interrupt */
    .word   EXTI1_Handler               /* EXTI Line 1 interrupt */
    .word   EXTI2_Handler               /* EXTI Line 2 interrupt */
    .word   EXTI3_Handler               /* EXTI Line 3 interrupt */
    .word   EXTI4_Handler               /* EXTI Line 4 interrupt */

    .word   DMA1_Stream0_Handler        /* DMA1 Stream 0 global interrupt */
    .word   DMA1_Stream1_Handler        /* DMA1 Stream 1 global interrupt */
    .word   DMA1_Stream2_Handler        /* DMA1 Stream 2 global interrupt */
    .word   DMA1_Stream3_Handler        /* DMA1 Stream 3 global interrupt */
    .word   DMA1_Stream4_Handler        /* DMA1 Stream 4 global interrupt */
    .word   DMA1_Stream5_Handler        /* DMA1 Stream 5 global interrupt */
    .word   DMA1_Stream6_Handler        /* DMA1 Stream 6 global interrupt */

    .word   ADC_Handler                 /* ADC1 global interrupt */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   EXTI9_5_Handler             /* EXTI Line[9:5] interrupts */

    .word   TIM1_BRK_TIM9_Handler       /* TIM1 Break interrupt and TIM9 global interrupt */
    .word   TIM1_UP_TIM10_Handler       /* TIM1 Update interrupt and TIM10 global interrupt */
    .word   TIM1_TRG_COM_TIM11_Handler  /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    .word   TIM1_CC_Handler             /* TIM1 Capture Compare interrupt */

    .word   TIM2_Handler                /* TIM2 global interrupt */
    .word   TIM3_Handler                /* TIM3 global interrupt */
    .word   TIM4_Handler                /* TIM4 global interrupt */

    .word   I2C1_EV_Handler             /* I2C1 event interrupt */
    .word   I2C1_ER_Handler             /* I2C1 error interrupt */

    .word   I2C2_EV_Handler             /* I2C2 event interrupt */
    .word   I2C2_ER_Handler             /* I2C2 error interrupt */

    .word   SPI1_Handler                /* SPI1 global interrupt */
    .word   SPI2_Handler                /* SPI2 global interrupt */

    .word   USART1_Handler              /* USART1 global interrupt */
    .word   USART2_Handler              /* USART2 global interrupt */

    .word   0                           /* Reserved */

    .word   EXTI15_10_Handler           /* EXTI Line[15:10] interrupts */
    .word   RTC_Alarm_Handler           /* EXTI Line 17 interrupt / RTC Alarms (A and B) through EXTI line */
    .word   OTG_FS_WKUP_Handler         /* EXTI Line 18 interrupt / USB OTG FS Wakeup through EXTI line */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   DMA1_Stream7_Handler        /* DMA1 Stream 7 global interrupt */

    .word   0                           /* Reserved */

    .word   SDIO_Handler                /* SDIO global interrupt */
    .word   TIM5_Handler                /* TIM5 global interrupt */
    .word   SPI3_Handler                /* SPI3 global interrupt */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   DMA2_Stream0_Handler        /* DMA2 Stream 0 global interrupt */
    .word   DMA2_Stream1_Handler        /* DMA2 Stream 1 global interrupt */
    .word   DMA2_Stream2_Handler        /* DMA2 Stream 2 global interrupt */
    .word   DMA2_Stream3_Handler        /* DMA2 Stream 3 global interrupt */
    .word   DMA2_Stream4_Handler        /* DMA2 Stream 4 global interrupt */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   OTG_FS_Handler              /* USB On The Go FS global interrupt */

    .word   DMA2_Stream5_Handler        /* DMA2 Stream 5 global interrupt */
    .word   DMA2_Stream6_Handler        /* DMA2 Stream 6 global interrupt */
    .word   DMA2_Stream7_Handler        /* DMA2 Stream 7 global interrupt */

    .word   USART6_Handler              /* USART6 global interrupt */

    .word   I2C3_EV_Handler             /* I2C3 event interrupt */
    .word   I2C3_ER_Handler             /* I2C3 error interrupt */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   FPU_Handler                 /* FPU global interrupt */

    .word   0                           /* Reserved */
    .word   0                           /* Reserved */

    .word   SPI4_Handler                /* SPI4 global interrupt */
    .word   SPI5_Handler                /* SPI5 global interrupt */
   
    .size   g_pfnVectors, .-g_pfnVectors

    