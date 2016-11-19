#ifndef ASM_UTILS_H_INCLUDED
#define ASM_UTILS_H_INCLUDED
void pio_set_queue(void *q);
int read_lba28(int lba, void *dest);
int write_lba28(int lba); 
int read_into_mem(void *dest); 
int read_drive(); 
int write_drive(); 


#endif
