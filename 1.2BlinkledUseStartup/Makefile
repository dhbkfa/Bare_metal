TARGET	= blink
CC		= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
SIZE	= arm-none-eabi-size
MCU_FLAGS	= -mcpu=cortex-m4 -mthumb -mfloat-abi=soft
CFLAGS		= ${MCU_FLAGS} -Wall -Wextra -O0 -g3 -ffreestanding -fdata-sections -ffunction-sections
LDFLAGS		= ${MCU_FLAGS} -T linker/stm32f411.ld -nostdlib -Wl,--gc-sections -Wl,-Map=${TARGET}.map
SRCS		= src/main.c src/startup.s
all: ${TARGET}.elf ${TARGET}.bin ${TARGET}.hex

# Tạo điều kiện và tìm các file cần thiết để chạy 
${TARGET}.elf: $(SRCS) linker/stm32f411.ld
	${CC} ${CFLAGS} ${LDFLAGS} ${SRCS} -o $@
	${SIZE} $@

${TARGET}.bin: ${TARGET}.elf
	${OBJCOPY} -O binary $< $@
${TARGET}.hex: ${TARGET}.elf
	${OBJCOPY} -O ihex $< $@

flash: ${TARGET}.bin
	st-flash write ${TARGET}.bin 0x8000000

clean:
	rm -rf ${TARGET}.elf ${TARGET}.bin ${TARGET}.hex ${TARGET}.map

.PHONY: all flash clean
