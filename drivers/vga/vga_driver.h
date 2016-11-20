#ifndef VGA_DRIVER_H_INCLUDED
#define VGA_DRIVER_H_INCLUDED

int init_vga(); 
int clear_vga_screen(); 
int carriage_return(); 
int print_char(); 
int print_prompt(); 
void vga_set_queue(void *q); 
#endif
