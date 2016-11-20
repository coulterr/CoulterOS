#include "../utils/utils.h"
#include "../utils/queue/char_queue.h"
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

	init_mallocator((void *) 0x4000); 
	char_queue *queue = (char_queue *) mallocate(sizeof(char_queue) + sizeof(char) * 20); 

	char_queue_init(queue); 
	
	pio_set_queue(queue);

	read_lba28(0, (void *) 0x3B9ACA00); 
	
	asm("mov $0x1111, %eax \t\n\
				jmp 0x3B9ACA00");

	while(1)
	{
	}

	//write_lba28(0);

	//read_lba28(0); 


}

