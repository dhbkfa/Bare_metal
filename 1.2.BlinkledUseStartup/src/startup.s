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

    .rept   91
    .word   Default_Handler
    .endr
    .size   g_pfnVectors, .-g_pfnVectors