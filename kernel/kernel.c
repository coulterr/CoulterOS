#include "../utils/utils.h"
#include "../utils/mem/mallocator.h"
#include "../utils/queue/char_queue.h"
#include "../drivers/vga/vga_driver.h"
#include "../drivers/ps2/ps2_driver.h"
#include "../drivers/pio/pio_driver.h"


int strcmp(char str1[10], char str2[10], int length){

	int i = 0; 

	while(i < length){
		
		if(str1[i]  != str2[i]){
			return 1;
		}

		i++; 
	}
 
	return 0; 
}


int delay(int cycles)
{
	int i, j; 
	
	for(i = 0; i < cycles; i++)
	{
		for(j = 0; j < 1000000; j++)
		{
			//do nothing
		}
	}

}


int kernel_main()
{

	init_vga(); 

	init_ps2(); 

	init_mallocator((void *)0x4000);

	char_queue *cq = (char_queue *) mallocate(sizeof(char_queue) + sizeof(char) * 20); 
	char_queue *aq = (char_queue *) mallocate(sizeof(char_queue) + sizeof(char) * 20); 

	char_queue_init(cq); 
	char_queue_init(aq); 
	
	ps2_set_vga_queue(cq);

	ps2_set_active_queue(aq); 

	vga_set_queue(cq);

	pio_set_vga_queue(cq);
	
	char_queue_enqueue(cq, ' ');
	print_char(); 

	char line[19] = "Welcome to RileyOS!"; 
	
	int i; 
	for(i = 0; i < 19; i++){
		char next = *(line + i); 
		char_queue_enqueue(cq, next); 
		print_char(); 
	}

	carriage_return();


	while(1)
	{
		print_prompt(); 
		char command[10] = {'0','0','0','0','0','0','0','0','0','0'}; 
		int length = 0; 
		
		while(1)
		{
			if(char_queue_length(aq) > 0){
				char next_char = char_queue_dequeue(aq); 
				if(next_char == '\n'){
					break;
				}else {
					command[length] = next_char;
					length++; 
				}
			}
			delay(10); 
			
			 
		}

		

		char hello[10] = {'h','e','l','l','o','0','0','0','0','0'};


		if(strcmp(command, hello, 10) == 0){
			
			char_queue_enqueue(cq, 'H'); 
			print_char(); 
			char_queue_enqueue(cq, 'e'); 
			print_char(); 
			char_queue_enqueue(cq, 'l'); 
			print_char(); 
			char_queue_enqueue(cq, 'l'); 
			print_char(); 
			char_queue_enqueue(cq, 'o'); 
			print_char(); 
			char_queue_enqueue(cq, '!'); 
			print_char(); 
			carriage_return(); 

		}else{
			char_queue_enqueue(cq, 'U');
			print_char(); 
			char_queue_enqueue(cq, 'n');
			print_char(); 
			char_queue_enqueue(cq, 'i');
			print_char(); 
			char_queue_enqueue(cq, 'd');
			print_char(); 
			char_queue_enqueue(cq, 'e');
			print_char(); 
			char_queue_enqueue(cq, 'n');
			print_char(); 
			char_queue_enqueue(cq, 't');
			print_char(); 
			char_queue_enqueue(cq, 'i');
			print_char(); 
			char_queue_enqueue(cq, 'f');
			print_char(); 
			char_queue_enqueue(cq, 'i');
			print_char(); 
			char_queue_enqueue(cq, 'e');
			print_char(); 
			char_queue_enqueue(cq, 'd');
			print_char(); 
			char_queue_enqueue(cq, ' ');
			print_char(); 
			char_queue_enqueue(cq, 'C');
			print_char(); 
			char_queue_enqueue(cq, 'o');
			print_char(); 
			char_queue_enqueue(cq, 'm');
			print_char(); 
			char_queue_enqueue(cq, 'm');
			print_char(); 
			char_queue_enqueue(cq, 'a');
			print_char(); 
			char_queue_enqueue(cq, 'n');
			print_char(); 
			char_queue_enqueue(cq, 'd');
			print_char(); 

			carriage_return(); 
		}

		
	}

	//write_lba28(0);

	//read_lba28(0); 


}

