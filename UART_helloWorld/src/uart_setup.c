#include "uart.h"
#include "gpio.h"

void UART_init(){

  *AUX_ENABLES |= 1; //enable mini UART
  *AUX_MU_IER_REG = 0; //disable Interrupts
  *AUX_MU_IIR_REG = 0xc6; //enable and clear FIFO
  *AUX_MU_LCR_REG &= ~(3 << 6); //don't break TX line and disable DLAB
  *AUX_MU_BAUD_REG = 270; //sets the baudrate to 115200
  *AUX_MU_CNTL_REG = 0; // Turn off extra features, turn off rx and tx pins
  
  unsigned int r = *GPFSEL1;
  r &= ~(7 << 12 | 7 << 15) //set function bits of pin 14 and 15 to 0
  r |= (2 << 12 | 2 << 15); //set pin 14 to tx mode and pin 15 to rx mode
  *GPFSEL1 = r; 
  *GPIO_PUB_PDN_CNTRL_REG0 &= ~(3 << 28 | 3 << 30); //set pin 14 and 15 to no pull up/down
  
  *AUX_MU_CNTL_REG |= 3; // turn on rx and tx
}

void UART_receive(){
  while(~(*AUX_MU_LSR_REG&0X01)){
    __asm__ volatile("nop")
  }
  char r = (char)*AUX_MU_IO_REG&255
  return r=='\r'?'\n':r;
}

void UART_send(unsigned int c){
  while(~(*AUX_MU_LSR_REG&(1<<5))){
    __asm__ volatile("nop")
  }
  *AUX_MU_IO_REG |= c&255;
}

void UART_println(char* s){
  while(*s){
    UART_send(*s++)
  }
}
