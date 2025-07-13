CC = arm-none-eabi-gcc
COBJ = arm-none-eabi-objcopy
CFLAGS = -nostdlib -ffreestanding
SRCS = $(wildcard src/*.c) $(wildcard src/*.S)
STDFILES = $(wildcard standard_files/*) src/config.txt
OBJS = $(SRCS:src/%.S=build/%.o)
OBJS := $(OBJS:src/%.c=build/%.o)
TARGET = build/kernel.elf
BIN = build/kernel.img
LINKER = src/link.ld
DEST = pi_files

.PHONY: all clean final

all:$(BIN) 

build/%.o: src/%.c
	mkdir -p build
	$(CC) -c $< -o $@

build/%.o: src/%.s
	mkdir -p build
	$(CC) -c $< -o $@ 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -T $(LINKER) -o $@ $^

$(BIN): $(TARGET)
	$(COBJ) $^ -O binary $(BIN)
clean:
	rm -f build/*.o build/*.elf

final: $(STDFILES) $(BIN)
	mkdir -p pi_files
	cp $^ $(DEST)/

