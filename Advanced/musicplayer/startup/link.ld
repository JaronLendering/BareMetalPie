ENTRY(_start)
SECTIONS
{
    
    . = 0x80000;     /* Kernel load address for AArch64, enforced by start4.elf*/
    /* The named of the sections are standardized, but not fixed. So if you don't want to use .text, you can use something else. However, the compiler will use the standardized names */
    .text : {       /* Create a section named text, where all the code is in*/
        KEEP(*(.text.boot)) /* Put the boot file in the front of the code, also keeps the file if it is never referenced*/ 
        *(.text .text.* .gnu.linkonce.t*) /* Puts all other code after it, part of object files. The gnu part is from the compiler, to remove duplicates  */
    } : text
    .rodata : { /* put the read only data after. */
        *(.rodata .rodata.* .gnu.linkonce.r*) 
     } :rodata

    .data : {  /*put the data initialized, writable data here */
        *(.data .data.* .gnu.linkonce.d*) 
    } :data
    .bss (NOLOAD) : { /* Put the uninitialized variables after data, NOLOAD means that it is not included in the output file, but there is space allocated */
                      /* bss is zeroed by the boot file, because C says that an uninitialized variable must start as 0, so it is not needed to write this data to the executable, there only need to be some space free in memory, we overwrite it immediatly anyway */
        . = ALIGN(16); /* Align the current address to a 16 byte block */
        __bss_start = .; /* initialize the variable with the start address of bss */  
        *(.bss .bss.*) /* Put all bss sections here */
        *(COMMON)      /* Put all uninitialized globals here */
        __bss_end = .; /* initialize the variable with the end address of bss */
    } :data
   /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) } /* discard these sections, not needed in the final executable */
}
PHDRS
{
    text PT_LOAD FLAGS(5); /* R + X */
    rodata PT_LOAD FLAGS(4); /* R */
    data PT_LOAD FLAGS(6); /* R + W */
}