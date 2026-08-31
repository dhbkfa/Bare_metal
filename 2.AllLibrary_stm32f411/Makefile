TARGET	= blink
CC		= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
SIZE	= arm-none-eabi-size
MCU_FLAGS	= -mcpu=cortex-m4 -mthumb -mfloat-abi=hard
CFLAGS		= ${MCU_FLAGS} -Wall -Wextra -O0 -g3 -ffreestanding -fdata-sections -ffunction-sections
LDFLAGS		= ${MCU_FLAGS} -T linker/linker.ld -nostdlib -Wl,--gc-sections -Wl,-Map=${TARGET}.map
SRCS		= src/main.c \
			  startup/startup.s \
			  $(wildcard drivers/*/*.c) \
			  lib/blinkled/blinkled.c 
all: ${TARGET}.elf ${TARGET}.bin ${TARGET}.hex

# Tạo điều kiện và tìm các file cần thiết để chạy 
${TARGET}.elf: $(SRCS) linker/linker.ld
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
