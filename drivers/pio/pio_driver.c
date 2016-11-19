#include "../../utils/utils.h"
#include "../../utils/queue/char_queue.h"
#include "pio_driver.h"
#include "../vga/vga_driver.h"

char_queue *queue; 


void pio_set_queue(void *q)
{
	queue = (char_queue *) q; 
}


int read_lba28(int lba)
{
	unsigned char drive = 0x00; 

	out_byte(0x1F1, 0x00); 
	out_byte(0x1F2, 0x01); 
	
	out_byte(0x1F3, (unsigned char) lba);
	out_byte(0x1F4, (unsigned char) (lba >> 8)); 
	out_byte(0x1F5, (unsigned char) (lba >> 16)); 
	out_byte(0x1F6, 0xE0 | ( drive << 4) | ((lba >> 24) & 0x0F)); 

	out_byte(0x1F7, 0x20); 

	while(!(in_byte(0x1F7) & 0x08)){}; 
	read_drive();  
}


int write_lba28(int lba)
{
	unsigned char drive = 0x00; 

	out_byte(0x1F1, 0x00); 
	out_byte(0x1F2, 0x01); 
	
	out_byte(0x1F3, (unsigned char) lba);
	out_byte(0x1F4, (unsigned char) (lba >> 8)); 
	out_byte(0x1F5, (unsigned char) (lba >> 16)); 
	out_byte(0x1F6, 0xE0 | ( drive << 4) | ((lba >> 24) & 0x0F)); 

	out_byte(0x1F7, 0x30);

	while(!(in_byte(0x1F7) & 0x08)){};
	write_drive(); 
}

int read_drive()
{
	int idx; 
	for(idx = 0; idx < 256; idx++)
	{
		unsigned short tmpword = in_word(0x1F0); 
		char_queue_enqueue(queue, (char) tmpword); 
		char_queue_enqueue(queue, (char) (tmpword >> 8));
	}

	while(in_byte(0x1F7) & 0x08){};
}


int write_drive()
{
	out_word(0x1F0, 0x4820); 
	out_word(0x1F0, 0x4C45);
	out_word(0x1F0, 0x4F4C); 
	out_word(0x1F0, 0x0021); 
	
	int idx; 
	
	for(idx = 0; idx < 252; idx++)
	{
		out_word(0x1F0, 0x0000); 
	}
	
	out_byte(0x1F7, 0xE7); 

	while(in_byte(0x1F7) & 0x08){}; 
}
