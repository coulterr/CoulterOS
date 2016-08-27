#include "../mem/mallocator.h"
#include "char_queue.h"

void char_queue_init(char_queue *q)
{
	q -> head = 0;
	q -> tail = 0; 
	q -> size = 0; 
}

char char_queue_head(char_queue *q)
{
	char val = q -> head -> value; 
	return val; 
}

int char_queue_length(char_queue *q){
	return q -> size; 
}

void char_queue_enqueue(char_queue *q, char value)
{
	char_node *new_node = mallocate(sizeof(char_node)); 
	new_node -> value = value; 
	new_node -> next = 0; 

	if(q -> size == 0){
		q -> head = new_node; 
		q -> tail = new_node; 
	}else{
		q -> tail -> next = (void *) new_node; 
		q -> tail = new_node; 
	}

	q -> size = q -> size + 1; 
}


char char_queue_dequeue(char_queue *q)
{
	if(q -> size != 0){
		char val = q -> head -> value; 
		q -> head = (char_node *) q -> head -> next; 
		q -> size = q -> size - 1; 
	
		if(q -> size == 0){
			q -> tail = 0; 
		}
	
		return val;
	}else{
		return 0; 
	}
}


