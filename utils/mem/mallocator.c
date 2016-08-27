#include "mallocator.h"

void *start_free;

void init_mallocator(void *start)
{
	start_free = start; 
}

void *mallocate(int size)
{
	int i; 
	for(i = 0; i < size; i++)
	{
		*((char *) (start_free + i)) = (char) 0;
	}

	void *val = start_free; 
	start_free = start_free + size + 10; 

	return val; 
}
