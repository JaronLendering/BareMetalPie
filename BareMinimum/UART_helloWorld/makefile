CC = aarch64-none-elf-gcc
COBJ = aarch64-none-elf-objcopy
CLD = aarch64-none-elf-ld
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP
SRCS = $(wildcard src/*.c) $(wildcard src/*.S)
STDFILES = $(wildcard standard_files/*) src/config.txt
OBJS = $(SRCS:src/%.S=build/%.o)
OBJS := $(OBJS:src/%.c=build/%.o)
ELF = build/kernel.elf
IMG = build/kernel.img
LINKER = src/link.ld
DEST = pi_files



.PHONY: all clean final

all:$(IMG) 

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.s
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@ 
	
-include $(OBJECTS:.o=.d)

$(ELF): $(OBJS)
	$(CLD) -nostdlib $^ -T $(LINKER) -o $@ 

$(IMG): $(ELF)
	$(COBJ) $^ -O binary $(IMG)

clean:
	rm -f build/*.o build/*.elf

final: $(STDFILES) $(IMG)
	mkdir -p pi_files
	cp $^ $(DEST)/


# Compiling commands executed by calling "make final"
# aarch64-none-elf-gcc -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/boot.S -o build/boot.o
# aarch64-none-elf-gcc -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/uart_setup.c -o build/uart_setup.o
# aarch64-none-elf-gcc -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/hello_world.c -o build/hello_world.c
# aarch64-none-elf-ld  -nostdlib build/boot.o build/uart_setup.o build/hello_world.o -T link.ld -o build/kernel.elf
# aarch64-none-elf-objcopy build/kernel.elf -O binary build/kernel.img
# mkdir -p pi_files
# cp standard_files/bcm2711-rpi-4-b.dtb standard_files/fixup4.dat standard_files/start4.elf src/config.txt build/kernel.img pi_files/


