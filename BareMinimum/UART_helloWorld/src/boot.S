.section ".text.boot"  // Name of the section, used in the linker

.global _start  // create a symbol that can be accessed by linked files in the linker

_start: // symbol is used as a label, to represent this place in the code
    // Check processor ID is zero (executing on main core), else hang
    mrs     x1, mpidr_el1 //move system register (register with topology information about the cores) into general purpose register "x1"
    and     x1, x1, #3 // x1 = x1 AND 11 (3 in binary). This keeps only the the first 2 bits of x1, the rest is 0.
    cbz     x1, 1f // if x1 is 0, jump to label 2 forward.
    
hang: b hang // we are not in the main core, so we hang forever

1:  // We're on the main core!

    ldr     x1, =_start //load the start position in x1
    mov     sp, x1 //set the stack pointer to the start of the program

    // Clean the BSS section, stores non initialized variables at compile time. C expects it to be 0.
    ldr     x1, =__bss_start    // Start address
    ldr     x2, =__bss_end      // End address
2:  cmp     x1,x2               // Check if we have gone through every adress
    b.ge    3f                  // Jump to 3 if we have
    str     xzr, [x1]    // Store 8 bytes of zeros in x1. [] are to say that you mean the value of x1 instead of the adress of x1
    add     x1, x1, #8   // Add 8 bytes to the _bss pointer x1
    b       2b           // loop until we have gone through every adress

3:  bl      main         // Jump to our main() routine in C, if it returns jump to the next line (that happens because of the l in bl)
    b       hang         // If main returns, hang the core
