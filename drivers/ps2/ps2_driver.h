#ifndef PS2_DRIVER_H_INCLUDED
#define PS2_DRIVER_H_INCLUDED

int print_scancode(unsigned char scancode);
int play_sound(int note); 
int stop_sound(); 
int play_key(unsigned char scancode); 
int ps2_driver_entrypoint(); 
int init_caps(); 
int init_piano_mode(); 
int init_text_mode(); 
int init_ps2(); 
void ps2_set_active_queue(void *q); 
void ps2_set_vga_queue(void *q);
#endif
