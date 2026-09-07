TARGET	= build
CC		= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
SIZE	= arm-none-eabi-size
ROOTDIR		:= $(CURDIR)
LIBDIR		= $(ROOTDIR)/drivers
MCU_FLAGS	= -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS		= ${MCU_FLAGS} -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
				-Og -g3 -ffreestanding -fdata-sections -ffunction-sections \
				-Wformat-truncation -fno-common -Wconversion -fno-strict-aliasing \
				-MMD -MP -I. -I$(LIBDIR)
LDFLAGS		= ${MCU_FLAGS} -T linker/linker.ld -nostdlib -Wl,--gc-sections -Wl,-Map=${TARGET}.map


SRCS		= src/main.c \
			  startup/startup.s \
			  $(wildcard $(LIBDIR)/*/*.c) \
			  lib/blinkled/blinkled.c 
all: ${TARGET}.elf ${TARGET}.bin ${TARGET}.hex
# Transform source paths to object paths in the build directory
IOBJS = $(addprefix $(TARGET)/, $(notdir $(SRCS:.c=.0)))
# Transform object paths to dependency paths
DEPS = $(OBJS:.o=.d)

# Search paths for source files (so make can find them)
vpath %.c . $(LIBDIR)
# Tạo điều kiện và tìm các file cần thiết để chạy 
${TARGET}.elf: $(SRCS) linker/linker.ld
	${CC} ${CFLAGS} ${LDFLAGS} ${SRCS} -o $@
	@echo "\n---build Sumary---"
	${SIZE} $@
	


${TARGET}.bin: ${TARGET}.elf
	${OBJCOPY} -O binary $< $@
${TARGET}.hex: ${TARGET}.elf
	${OBJCOPY} -O ihex $< $@

flash: ${TARGET}.bin
	st-flash --reset write ${TARGET}.bin 0x8000000

clean:
	rm -rf ${TARGET}.elf ${TARGET}.bin ${TARGET}.hex ${TARGET}.map

.PHONY: all flash clean
