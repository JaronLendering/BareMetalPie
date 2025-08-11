# Blinky
Blinky makes the ACT light on the raspberry pi 4B blink

## pi_files
pi_files is a folder with all files that have to be put on the sd card for the raspberry pi. It consists of 5 files.
- bcm2711-rpi-4-b.dtb
    This file is the Device Tree Blob of the raspberry pi 4b. It explains to the kernel how the rapsberry pi is wired. It is not used by our kernel, but it is 
    still required by the raspberry Pi. The human readable version is in the project root. 
- config.txt
    This file has all the configuration values that are used by the starting files of the raspberry pi.
- start4.elf
    This is the main startup file of the raspberry pi. It starts all the memory and periphials, it is required by the system on a chip (SoC) of the raspberry Pi.
- fixup4.dat
    This is an addition on start4.elf that helps starting up all the periphials.
- kernel.img
    This is the file that we create, the kernel of the raspberry pi. It is the first file ran after the periphials are initialized. 


## Installation Procedure
If you want to use <a href="https://www.gnu.org/software/make">make</a> (automation software), call "make final" in your terminal, while being in the UART_helloWorld folder.
Otherwise, the exact commands are also shown in the comments of the makefile.  
Copy the contents of "pi_files" to your sd card and plug it in the raspberry PI.
Use your serial reader software to read the UART cable. 

# References
All assembly commands can be found in the <a href="https://www.cs.princeton.edu/courses/archive/spr19/cos217/reading/ArmInstructionSetOverview.pdf"> ARMv8 Instruction Set Overview </a>

