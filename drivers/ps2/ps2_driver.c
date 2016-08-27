#include "../../utils/utils.h"
#include "../../utils/queue/char_queue.h"
#include "../../utils/mem/mallocator.h"
#include "ps2_driver.h"
#include "../vga/vga_driver.h"


char_queue *vga_queue; 
char_queue *active_queue; 

int print_scancode(unsigned char scancode){
	
	char *ps2_shift = (char *) 0xF004;

	if(*ps2_shift == (char) 1){
		
		if ( scancode == 0x1e ){ 
		
			char_queue_enqueue(active_queue, 'A');
			char_queue_enqueue(vga_queue, 'A'); 
			print_char(); 
		
		}else if ( scancode == 0x30 ){
			
			char_queue_enqueue(active_queue, 'B'); 
			char_queue_enqueue(vga_queue, 'B'); 
			print_char(); 
		
		}else if( scancode == 0x2e ){
		
			char_queue_enqueue(active_queue, 'C'); 
			char_queue_enqueue(vga_queue, 'C'); 
			print_char(); 
		
		}else if ( scancode == 0x20 ){
		
			char_queue_enqueue(active_queue, 'D'); 
			char_queue_enqueue(vga_queue, 'D'); 
			print_char(); 
		
		}else if ( scancode == 0x12 ){
		
			char_queue_enqueue(active_queue, 'E'); 
			char_queue_enqueue(vga_queue, 'E'); 
			print_char(); 
		
		}else if ( scancode == 0x21 ){
		
			char_queue_enqueue(active_queue, 'F'); 
			char_queue_enqueue(vga_queue, 'F'); 
			print_char(); 
		
		}else if ( scancode == 0x22 ){
		
			char_queue_enqueue(active_queue, 'G'); 
			char_queue_enqueue(vga_queue, 'G'); 
			print_char(); 
		
		}else if ( scancode == 0x23 ){
		
			char_queue_enqueue(active_queue, 'H'); 
			char_queue_enqueue(vga_queue, 'H'); 
			print_char(); 
		
		}else if ( scancode == 0x17 ){
		
			char_queue_enqueue(active_queue, 'I'); 
			char_queue_enqueue(vga_queue, 'I'); 
			print_char(); 
		
		}else if ( scancode == 0x24 ){
		
			char_queue_enqueue(active_queue, 'J'); 
			char_queue_enqueue(vga_queue, 'J'); 
			print_char(); 
		
		}else if ( scancode == 0x25 ){
		
			char_queue_enqueue(active_queue, 'K'); 
			char_queue_enqueue(vga_queue, 'K'); 
			print_char(); 
		
		}else if ( scancode == 0x26 ){
		
			char_queue_enqueue(active_queue, 'L'); 
			char_queue_enqueue(vga_queue, 'L'); 
			print_char(); 
		
		}else if ( scancode == 0x32 ){
		
			char_queue_enqueue(active_queue, 'M'); 
			char_queue_enqueue(vga_queue, 'M'); 
			print_char(); 
		
		}else if ( scancode == 0x31 ){
		
			char_queue_enqueue(active_queue, 'N'); 
			char_queue_enqueue(vga_queue, 'N'); 
			print_char(); 
		
		}else if ( scancode == 0x18 ){
		
			char_queue_enqueue(active_queue, 'O'); 
			char_queue_enqueue(vga_queue, 'O'); 
			print_char(); 
		
		}else if ( scancode == 0x19 ){
		
			char_queue_enqueue(active_queue, 'P'); 
			char_queue_enqueue(vga_queue, 'P'); 
			print_char(); 
		
		}else if ( scancode == 0x10 ){
			
			char_queue_enqueue(active_queue, 'Q'); 
			char_queue_enqueue(vga_queue, 'Q'); 
			print_char(); 
		
		}else if ( scancode == 0x13 ){
			
			char_queue_enqueue(active_queue, 'R'); 
			char_queue_enqueue(vga_queue, 'R'); 
			print_char(); 
		
		}else if ( scancode == 0x1f ){
			
			char_queue_enqueue(active_queue, 'S'); 
			char_queue_enqueue(vga_queue, 'S'); 
			print_char(); 
		
		}else if ( scancode == 0x14 ){
			
			char_queue_enqueue(active_queue, 'T'); 
			char_queue_enqueue(vga_queue, 'T'); 
			print_char(); 
		
		}else if ( scancode == 0x16 ){
			
			char_queue_enqueue(active_queue, 'U'); 
			char_queue_enqueue(vga_queue, 'U'); 
			print_char(); 
		
		}else if ( scancode == 0x2f ){
			
			char_queue_enqueue(active_queue, 'V'); 
			char_queue_enqueue(vga_queue, 'V'); 
			print_char(); 
		
		}else if ( scancode == 0x11 ){
			
			char_queue_enqueue(active_queue, 'W'); 
			char_queue_enqueue(vga_queue, 'W'); 
			print_char(); 
		
		}else if ( scancode == 0x2d ){
			
			char_queue_enqueue(active_queue, 'X'); 
			char_queue_enqueue(vga_queue, 'X'); 
			print_char(); 
		
		}else if ( scancode == 0x15 ){
			
			char_queue_enqueue(active_queue, 'Y'); 
			char_queue_enqueue(vga_queue, 'Y'); 
			print_char(); 
		
		}else if ( scancode == 0x2c ){
			
			char_queue_enqueue(active_queue, 'Z'); 
			char_queue_enqueue(vga_queue, 'Z'); 
			print_char(); 
		
		}else if ( scancode == 0x39 ){
			
			char_queue_enqueue(active_queue, ' '); 
			char_queue_enqueue(vga_queue, ' '); 
			print_char(); 
		}
	}else if(*ps2_shift == (char) 0){
	
		if ( scancode == 0x1e ){ 
		
			char_queue_enqueue(active_queue, 'a'); 
			char_queue_enqueue(vga_queue, 'a'); 
			print_char(); 
		
		}else if ( scancode == 0x30 ){
			
			char_queue_enqueue(active_queue, 'b'); 
			char_queue_enqueue(vga_queue, 'b'); 
			print_char(); 
		
		}else if( scancode == 0x2e ){
		
			char_queue_enqueue(active_queue, 'c'); 
			char_queue_enqueue(vga_queue, 'c'); 
			print_char(); 
		
		}else if ( scancode == 0x20 ){
		
			char_queue_enqueue(active_queue, 'd'); 
			char_queue_enqueue(vga_queue, 'd'); 
			print_char(); 
		
		}else if ( scancode == 0x12 ){
		
			char_queue_enqueue(active_queue, 'e'); 
			char_queue_enqueue(vga_queue, 'e'); 
			print_char(); 
		
		}else if ( scancode == 0x21 ){
		
			char_queue_enqueue(active_queue, 'f'); 
			char_queue_enqueue(vga_queue, 'f'); 
			print_char(); 
		
		}else if ( scancode == 0x22 ){
		
			char_queue_enqueue(active_queue, 'g'); 
			char_queue_enqueue(vga_queue, 'g'); 
			print_char(); 
		
		}else if ( scancode == 0x23 ){
		
			char_queue_enqueue(active_queue, 'h'); 
			char_queue_enqueue(vga_queue, 'h'); 
			print_char(); 
		
		}else if ( scancode == 0x17 ){
		
			char_queue_enqueue(active_queue, 'i'); 
			char_queue_enqueue(vga_queue, 'i'); 
			print_char(); 
		
		}else if ( scancode == 0x24 ){
		
			char_queue_enqueue(active_queue, 'j'); 
			char_queue_enqueue(vga_queue, 'j'); 
			print_char(); 
		
		}else if ( scancode == 0x25 ){
		
			char_queue_enqueue(active_queue, 'k'); 
			char_queue_enqueue(vga_queue, 'k'); 
			print_char(); 
		
		}else if ( scancode == 0x26 ){
		
			char_queue_enqueue(active_queue, 'l'); 
			char_queue_enqueue(vga_queue, 'l'); 
			print_char(); 
		
		}else if ( scancode == 0x32 ){
		
			char_queue_enqueue(active_queue, 'm'); 
			char_queue_enqueue(vga_queue, 'm'); 
			print_char(); 
		
		}else if ( scancode == 0x31 ){
		
			char_queue_enqueue(active_queue, 'n'); 
			char_queue_enqueue(vga_queue, 'n'); 
			print_char(); 
		
		}else if ( scancode == 0x18 ){
		
			char_queue_enqueue(active_queue, 'o'); 
			char_queue_enqueue(vga_queue, 'o'); 
			print_char(); 
		
		}else if ( scancode == 0x19 ){
		
			char_queue_enqueue(active_queue, 'p'); 
			char_queue_enqueue(vga_queue, 'p'); 
			print_char(); 
		
		}else if ( scancode == 0x10 ){
			
			char_queue_enqueue(active_queue, 'q'); 
			char_queue_enqueue(vga_queue, 'q'); 
			print_char(); 
		
		}else if ( scancode == 0x13 ){
			
			char_queue_enqueue(active_queue, 'r'); 
			char_queue_enqueue(vga_queue, 'r'); 
			print_char(); 
		
		}else if ( scancode == 0x1f ){
			
			char_queue_enqueue(active_queue, 's'); 
			char_queue_enqueue(vga_queue, 's'); 
			print_char(); 
		
		}else if ( scancode == 0x14 ){
			
			char_queue_enqueue(active_queue, 't'); 
			char_queue_enqueue(vga_queue, 't'); 
			print_char(); 
		
		}else if ( scancode == 0x16 ){
			
			char_queue_enqueue(active_queue, 'u'); 
			char_queue_enqueue(vga_queue, 'u'); 
			print_char(); 
		
		}else if ( scancode == 0x2f ){
			
			char_queue_enqueue(active_queue, 'v'); 
			char_queue_enqueue(vga_queue, 'v'); 
			print_char(); 
		
		}else if ( scancode == 0x11 ){
			
			char_queue_enqueue(active_queue, 'w'); 
			char_queue_enqueue(vga_queue, 'w'); 
			print_char(); 
		
		}else if ( scancode == 0x2d ){
			
			char_queue_enqueue(active_queue, 'x'); 
			char_queue_enqueue(vga_queue, 'x'); 
			print_char(); 
		
		}else if ( scancode == 0x15 ){
			
			char_queue_enqueue(active_queue, 'y'); 
			char_queue_enqueue(vga_queue, 'y'); 
			print_char(); 
		
		}else if ( scancode == 0x2c ){
			
			char_queue_enqueue(active_queue, 'z'); 
			char_queue_enqueue(vga_queue, 'z'); 
			print_char(); 
		
		}else if ( scancode == 0x39 ){
			
			char_queue_enqueue(active_queue, ' '); 
			char_queue_enqueue(vga_queue, ' '); 
			print_char(); 
		}
	
	}

	if(scancode == 0x36 || scancode == 0x2A){
		*ps2_shift = (char) 1; 
	}else if(scancode == 0xB6 || scancode == 0xAA){
		*ps2_shift = (char) 0; 
	}

	if(scancode == 0x1C){
		char_queue_enqueue(active_queue, '\n');
		char_queue_enqueue(vga_queue, '\n'); 
		print_char(); 
	}		
}

int play_sound(int note)
{
	int counter; 

	counter = 0x1234DD / note; 
	
	out_byte(0x43, 0xB6); 
	out_byte(0x42, 0xFF && counter); 
	out_byte(0x42, counter >> 8); 

	unsigned char val = in_byte(0x61); 
	out_byte(0x61, val|3); 
}

int stop_sound()
{
	unsigned char val = in_byte(0x61); 	
	out_byte(0x61, val^3); 
}

int play_key(unsigned char scancode)
{	

	if ( scancode == 0x10 ){
		
		play_sound(65);
	
	}else if ( scancode == 0x11 ){
		
		play_sound(73); 
	
	}else if ( scancode == 0x12 ){
	
		play_sound(82); 
	
	}else if ( scancode == 0x13 ){ 
	
		play_sound(87); 
	
	}else if ( scancode == 0x14 ){
		
		play_sound(98); 
	
	}else if ( scancode == 0x15 ){
		
		play_sound(110); 
	
	}else if ( scancode == 0x16 ){
		
		play_sound(123); 
	
	}else if ( scancode == 0x17 ){
		
		play_sound(131);  
	
	}else if ( scancode == 0x18 ){
		
		play_sound(147); 
	
	}else if ( scancode == 0x19 ){
		
		play_sound(165); 
	
	}else if ( scancode == 0x1e ){
		
		play_sound(175);  
	
	}else if ( scancode == 0x1f ){
		
		play_sound(196); 
	
	}else if ( scancode == 0x20 ){
		
		play_sound(220); 
	
	}else if ( scancode == 0x21 ){
		
		play_sound(245); 
	
	}else if ( scancode == 0x22 ){
		
		play_sound(262);  
	
	}else if ( scancode == 0x23 ){
		
		play_sound(294);  
	
	}else if ( scancode == 0x24 ){
		
		play_sound(330);  
	
	}else if ( scancode == 0x25 ){
		
		play_sound(349);  
	
	}else if ( scancode == 0x26 ){
		
		play_sound(392);  
	
	}else if ( scancode == 0x2c ){
		
		play_sound(440);  
	
	}else if ( scancode == 0x2d ){
		
		play_sound(494);  
	
	}else if ( scancode == 0x2e ){
		
		play_sound(523);  
	
	}else if ( scancode == 0x2f ){
		
		play_sound(587); 
	
	}else if ( scancode == 0x30 ){
		
		play_sound(659);  
	
	}else if ( scancode == 0x31 ){
		
		play_sound(698);  	
	
	}else if ( scancode == 0x32 ){
		
		play_sound(784);

	}else{

		stop_sound();
	}
	
}

int init_caps()
{
	char *ps2_shift = (char *) 0xF004; 
	*ps2_shift = (char) 0; 
}

int init_piano_mode()
{
	char *mode = (char *) 0xF008; 
	*mode = (char) 0x11; 
}

int init_text_mode()
{
	char *mode = (char *) 0xF008; 
	*mode = (char) 0x00; 
}


int init_ps2()
{
	init_caps(); 
	init_text_mode(); 
}

void ps2_set_active_queue(void *q) 
{
	active_queue = (char_queue *) q; 
}

void ps2_set_vga_queue(void *q)
{
	vga_queue = (char_queue *) q; 
}

int ps2_driver_entrypoint()
{
	char *mode = (char *) 0xF008; 
	unsigned char result = in_byte(0x60);

	if(*mode == (char) 0x11){
		play_key(result); 
	}else if (*mode == (char) 0x00){
		print_scancode(result); 
	}
	
	return 0;
}


