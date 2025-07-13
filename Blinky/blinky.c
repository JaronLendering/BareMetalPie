#define GPIO_BASE 0x7E200000
#define GPIO_SEL2 (unsigned int*) (GPIO_BASE + 0x08) 
#define GPIO_SET0 (unsigned int*) (GPIO_BASE + 0x1c)
#define GPIO_CLR0 (unsigned int*) (GPIO_BASE + 0x28)
#define GPIO_23 23
#define GPIO_SEL2_BIT 10



void not_main(void) {
//clear and set input for pin 23
unsigned int selector = *GPIO_SEL2;
selector &= ~(1 << GPIO_SEL2_BIT);
selector |= 1 << GPIO_SEL2_BIT;
*GPIO_SEL2 = selector;

*GPIO_SET0 |= 1 < GPIO_23;
//set pin 23
while(1){

}




}

