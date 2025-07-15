#include "gpio.h"
#include "uart.h"



void main(void) {
  UART_println("hello world");
  while(1){}
}

