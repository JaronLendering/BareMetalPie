//Defines all the UART related registers of the SoC

#define UART_BASE 0xFE215000
#define AUX_ENABLES       ((volatile unsigned int*)(UART_BASE + 0x04))
#define AUX_MU_IO_REG     ((volatile unsigned int*)(UART_BASE + 0x40))
#define AUX_MU_IER_REG    ((volatile unsigned int*)(UART_BASE + 0x44))
#define AUX_MU_IIR_REG    ((volatile unsigned int*)(UART_BASE + 0x48))
#define AUX_MU_LCR_REG    ((volatile unsigned int*)(UART_BASE + 0x4C))
#define AUX_MU_MCR_REG    ((volatile unsigned int*)(UART_BASE + 0x50))
#define AUX_MU_LSR_REG    ((volatile unsigned int*)(UART_BASE + 0x54))
#define AUX_MU_MSR_REG    ((volatile unsigned int*)(UART_BASE + 0x58))
#define AUX_MU_SCRATCH    ((volatile unsigned int*)(UART_BASE + 0x5C))
#define AUX_MU_CNTL_REG   ((volatile unsigned int*)(UART_BASE + 0x60))
#define AUX_MU_STAT_REG   ((volatile unsigned int*)(UART_BASE + 0x64))
#define AUX_MU_BAUD_REG   ((volatile unsigned int*)(UART_BASE + 0x68))



void UART_init();
char UART_receive();
void UART_send(unsigned int c);
void UART_println(char* s);




