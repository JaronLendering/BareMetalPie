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