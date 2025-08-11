#define GPIO_BASE 0xFE200000 //The start of all the adresses for GPIO
// All these are set volatile, because they are pointers to some hardware adress. That means that there is a change that something outside this software changes the value
// That is why we don't want c to optimise the read and writes away.
#define GPIO_SEL4 (volatile unsigned int*) (GPIO_BASE + 0x10) //the start address where the function of some GPIO pins is decided
#define GPIO_SET1 (volatile unsigned int*) (GPIO_BASE + 0x20) //The start address where some GPIO pins can be set high
#define GPIO_CLR1 (volatile unsigned int*) (GPIO_BASE + 0x2c) //The start address where some GPIO pins can be set low
#define GPIO_42 42 // GPIO pin connected to the ACT light of the raspberry pi 4B 
#define GPIO_SEL4_BIT 6 //The bit that has to be set high, seen from the adress of GPIO_SEL4

void main(void) {
    unsigned int selector = *GPIO_SEL4; //GPIO_SEL4 is used to get the pin 42 config register
    selector &= ~(0b111 << GPIO_SEL4_BIT); // set the 10th,11th and 12th bit to 0 and leave the other bits unchanged 
    selector |= 1 << GPIO_SEL4_BIT; // set the 10th bit to 1 and leave the other bits unchanged, making pin 42 an output pin
    *GPIO_SEL4 = selector; //set GPIO_SEL4 to the new value
    

    while(1){
        *GPIO_CLR1 = 1 << (GPIO_42-32); //set pin 42 low
        for(volatile int i = 0; i < 2000000; i++){ //Wait some time
                __asm__ volatile("nop"); // makes sure that the empty while will not be optimized away.
        }
        *GPIO_SET1 = 1 << (GPIO_42-32); //set pin 42 high
        for(volatile int i = 0; i < 2000000; i++){ //Wait some time
                __asm__ volatile("nop"); // makes sure that the empty while will not be optimized away.
        }

    }


}

