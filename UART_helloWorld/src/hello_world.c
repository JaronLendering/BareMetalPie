#include "gpio.h"
#include "uart.h"



void not_main(void) {
  while(1){
  UART_println("hello world");
  }
}

