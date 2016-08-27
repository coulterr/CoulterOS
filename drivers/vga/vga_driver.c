#include "vga_driver.h"
#include "../../utils/queue/char_queue.h"

char_queue *vga_queue; 

void vga_set_queue(void *q)
{
	vga_queue = (char_queue *)q; 
}

int init_vga()
{
	clear_vga_screen(); 

	short *vga_row = (short *) 0xF000;
	short *vga_col = (short *) 0xF002; 
	*vga_row = 0x00; 
	*vga_col = 0x00; 
}


int clear_vga_screen()
{
	char *vga_mem = (char *) 0xB8000; 
	int i; 
	for(i = 0; i < 2000; i+=2)
	{
		*(vga_mem + i) = 0x00; 
	}
}

int carriage_return()
{
	short *vga_row = (short *) 0xF000;
	short *vga_col = (short *) 0xF002;
	
	short row = *vga_row;
	row ++; 
	*vga_row = row; 
	*vga_col = 0; 
	short col = 0; 
	

	short pos =  ((row * 80) + col);


 	char lower_byte = (long) pos;
	char higher_byte = (long) pos >> 8;  

	out_byte(0x3D4, 0x0F); 
	out_byte(0x3D5, lower_byte); 
	out_byte(0x3D4, 0x0E); 
	out_byte(0x3D5, higher_byte); 

	*vga_col = *vga_col + 1; 
}

int print_char()
{

	char character = char_queue_dequeue(vga_queue); 

	if(character == '\n'){
		carriage_return(); 
	}else{

		short *vga_row = (short *) 0xF000;
		short *vga_col = (short *) 0xF002;
	
		short row = *vga_row;
		short col = *vga_col; 
	
		short pos =  ((row * 80) + col);

		char *char_pos = (char *) 0xB8000;
		char_pos += 2 * pos;
		*(char_pos - 2) = character;

 		char lower_byte = (long) pos;
		char higher_byte = (long) pos >> 8;  

		out_byte(0x3D4, 0x0F); 
		out_byte(0x3D5, lower_byte); 
		out_byte(0x3D4, 0x0E); 
		out_byte(0x3D5, higher_byte); 

		*vga_col = *vga_col + 1; 
	
		if(*vga_col > 80){
			*vga_col = 0;
			*vga_row = *vga_row + 1;
		}
	}
	 
}


int print_prompt()
{

	char character = '>'; 

	short *vga_row = (short *) 0xF000;
	short *vga_col = (short *) 0xF002;
	
	short row = *vga_row;
	short col = *vga_col; 

	short pos =  ((row * 80) + col);

	char *char_pos = (char *) 0xB8000;
	char_pos += 2 * pos;
	*(char_pos - 1) = (char) 0x1703;
	*(char_pos - 2) = character;

 	char lower_byte = (long) pos;
	char higher_byte = (long) pos >> 8;  

	out_byte(0x3D4, 0x0F); 
	out_byte(0x3D5, lower_byte); 
	out_byte(0x3D4, 0x0E); 
	out_byte(0x3D5, higher_byte); 

	*vga_col = *vga_col + 1; 
	
	if(*vga_col > 80){
		*vga_col = 0;
		*vga_row = *vga_row + 1;
	}
	 
}
