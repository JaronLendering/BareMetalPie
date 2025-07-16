# BareMetalPie

## Prerequisites
This is the software and hardware used by me. Other software/hardware might or might not work.
- Raspberry Pi 4B
- <a href="https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads">aarch64-none-elf 14.3</a> (The cross compiler)
- Ubuntu (development OS)
- Micro SD card

### Prerequisites Specifications Breakdown
A cross compiler is needed, because you need to compile for the ARM CPU, while you development machine has most likely another CPU architecture.
So a normal C compiler cannot be used. 


## File Structure
### BareMinimum
In BareMinimum, I will put highly documented code of simple implementations for a UART connection and a blinking action light. This can be used as a easy to understand starting point if you do not want to follow an exact tutorial. 


## General References
All registers are explained in the <a href="https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf">Broadcom 2711 documentation</a>.   
Compiler options can be found in the <a href="https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html"> gcc documentation</a>.

### Important Addition!
The Broadcom 2711 documentation says that the GPIO memory adresses start at 0x7E200000 and that the UART memory adresses start at 0x7E215000. However, those are the memory adresses for the GPU. The CPU cannot access those so they are remapped to 0xFE200000 and 0xFE215000 respectively. Sadly, I have not been able to find a good source for this. If anyone has one, please say so!