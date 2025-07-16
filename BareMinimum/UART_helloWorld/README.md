# UART_helloWorld
UART_helloworld uses the UART serial connection to send "hello world" to your development machine.

## Prerequisites
These prerequisites are needed ontop of the general prerequisites for this repository
- A TTL to USB cable (UART cable)
- A serial reader (like "Putty" or "Minicom")

## Hardware Overview
Connect to TX wire to the RX pin and the RX wire to the TX pin.
Connect the ground cable to the ground pin

###  Hardware Specifications Breakdown
The wires have to be connected in a crossed manner, because the output (TX) of the UART cable has to be connected to the 
input (RX) of the Pi, and vice versa. The power wire is only needed if you want to power the Pi using the UART cable.
The ground wire is used to reduce noice of over the RX and TX wires. 

## Installation Procedure
If you want to use <a href="https://www.gnu.org/software/make">make</a> (automation software), call "make final" in your terminal, while being in the UART_helloWorld folder.
Otherwise, the exact commands are also shown in the comments of the makefile.  
Copy the contents of "pi_files" to your sd card and plug it in the raspberry PI.
Use your serial reader software to read the UART cable. 

## References
All registers are explained in the <a href="https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf">Broadcom 2711 documentation</a>. 