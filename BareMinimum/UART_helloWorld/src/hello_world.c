#include "gpio.h"
#include "uart.h"


void main(void) {
  UART_println("hello world");
  while(1){ //To make the program go on for ever, such that the pie doesn't crash because there are no instructions anymore
        __asm__ volatile("nop"); // makes sure that the empty while will not be optimized away.
  }
}

