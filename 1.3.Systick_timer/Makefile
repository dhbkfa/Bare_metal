Target	= blink
CC		= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
SIZE	= arm-none-eabi-size
MCU_FLAGS	= -mcpu=cortex-m4 -mthumb -mfloat-abi=soft
CFLAGS		= ${MCU_FLAGS} -Wall -Wextra -O0 -g3 -ffreestanding -fdata-sections -ffunction-sections  
LDFLAGS		= ${MCU_FLAGS} -T linker/linker.ld -nostdlib -nostartfiles -Wl,--gc-sections -Wl,-Map=${Target}.map
SRCS		= src/main.c src/gpio.c
all: ${Target}.elf ${Target}.bin ${Target}.hex

${Target}.elf: ${SRCS} linker/linker.ld 
	${CC} ${CFLAGS} ${LDFLAGS} ${SRCS} -o $@
	${SIZE} $@

${Target}.bin: ${Target}.elf
	${OBJCOPY} -O binary $< $@
${Target}.hex: ${Target}.elf
	${OBJCOPY} -O ihex $< $@

flash: ${Target}.bin
	st-flash --reset write $< 0x8000000
clean:
	rm -rf ${Target}.elf ${Target}.bin ${Target}.hex ${Target}.map
.PHONY:	all flash clean
