SRC_DIR := src
BUILD_DIR := build
TARGET := OrthOS

CC := gcc
CFLAGS := -Wall -Wextra -pedantic -ggdb -std=c99 -m64 -ffreestanding -masm=intel 

.PHONY: all

all: clean build

build:
	mkdir -p $(BUILD_DIR)
	nasm -f bin $(SRC_DIR)/bootloader/boot.asm -o $(BUILD_DIR)/boot.bin
	nasm -f elf64 $(SRC_DIR)/bootloader/loader.asm -o $(BUILD_DIR)/loader.o

	$(CC) $(CFLAGS) -c $(SRC_DIR)/kernel/main.c -o $(BUILD_DIR)/kernel.o
	ld  -Ttext 0x100000 -o $(BUILD_DIR)/kernel.elf $(BUILD_DIR)/loader.o $(BUILD_DIR)/kernel.o 
	objcopy -R .note -R .comment -S -O binary $(BUILD_DIR)/kernel.elf $(BUILD_DIR)/kernel.bin

	dd if=/dev/zero of=$(BUILD_DIR)/$(TARGET).bin bs=512 count=2880
	dd if=$(BUILD_DIR)/boot.bin of=$(BUILD_DIR)/$(TARGET).bin conv=notrunc
	dd if=$(BUILD_DIR)/kernel.bin of=$(BUILD_DIR)/$(TARGET).bin conv=notrunc bs=512 seek=1

clean:
	sudo rm -r $(BUILD_DIR)

run:
	qemu-system-x86_64 $(BUILD_DIR)/$(TARGET).bin

