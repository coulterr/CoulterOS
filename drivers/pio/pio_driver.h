#ifndef ASM_UTILS_H_INCLUDED
#define ASM_UTILS_H_INCLUDED
void pio_set_vga_queue(void *q);
int print_charr(char character);
int read_lba28(int lba);
int write_lba28(int lba); 
int read_drive(); 
int write_drive(); 


#endif
