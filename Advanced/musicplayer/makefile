CC = aarch64-none-elf-gcc 
COBJ = aarch64-none-elf-objcopy 
CLD = aarch64-none-elf-ld
HEADER_DIR = include 
CFLAGS = -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -I$(HEADER_DIR)
SRCS = $(wildcard src/*.c utils/*.c startup/*.S) 
STDFILES = $(wildcard standard_files/*) startup/config.txt 
OBJS = $(SRCS:startup/%.S=build/%.o) 
OBJS := $(OBJS:src/%.c=build/%.o) 
OBJS := $(OBJS:utils/%.c=build/%.o) 
ELF = build/kernel.elf 
IMG = build/kernel.img 
LINKER = startup/link.ld
DEST = pi_files/ 
VPATH := src:utils:startup

.PHONY: all clean final prepare

all:$(IMG) 

prepare: 
	mkdir -p build

build/%.o: %.c | prepare
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: %.S | prepare
	$(CC) $(CFLAGS) -c $< -o $@ 
	
-include $(OBJECTS:.o=.d) #The .d file has the names of all dependencies of the other files. This way the dependecies are loaded in so if you change them, the make rules will be called again.

$(ELF): $(OBJS) #link the .c and the .s files in 1 file, the .elf file
	$(CLD) -nostdlib $^ -T $(LINKER) -o $@ 

$(IMG): $(ELF) # create a binary file form the .elf file
	$(COBJ) $^ -O binary $(IMG)

clean: # remove the unnecessary files from the build folder
	rm -f build/*.o build/*.elf

final: $(STDFILES) $(IMG) # add the necessary files to the pi_files folder
	mkdir -p pi_files
	cp $^ $(DEST)


# Compiling commands executed by calling "make final"

# aarch64-none-elf-gcc -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/boot.S -o build/boot.o
# aarch64-none-elf-gcc -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/uart_setup.c -o build/uart_setup.o
# aarch64-none-elf-gcc -ffreestanding -nostdinc -nostdlib -nostartfiles -mstrict-align -MMD -MP -c src/hello_world.c -o build/hello_world.c
# aarch64-none-elf-ld  -nostdlib build/boot.o build/uart_setup.o build/hello_world.o -T link.ld -o build/kernel.elf
# aarch64-none-elf-objcopy build/kernel.elf -O binary build/kernel.img
# mkdir -p pi_files
# cp standard_files/bcm2711-rpi-4-b.dtb standard_files/fixup4.dat standard_files/start4.elf src/config.txt build/kernel.img pi_files/

# The first 3 lines are for compiling the necessary files, the 4th line is for linking the boot and the c files. 
# The 5th line is for making a binary file that the pi can read. The last 2 lines are for copying the necessary files to pi_files


#CFLAGS explanations:
#-ffreestanding - To let the compiler make no assumptions about keywords (like main) or the pressance of standard functions
#-nostdinc - Do not search standard system directories for header files
#-nostdlib - Do not use standard system startup files or libraries when linking
#-nostartfiles - Do not use any standard startup files.
#-mstrict-align - Avoid unaligned memory access (to make sure peripherals are accessed properly)
#-MMD - create files defining the user-defined headers
#-MP - creates phony rules for every header, such that make doesn't complain when you delete a header (because .d files are checked before compilation)
