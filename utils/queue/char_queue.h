#ifndef CHARQUEUE_H_INCLUDED
#define CHARQUEUE_H_INCLUDED

typedef struct char_node{
	char value; 
	void *next; 
}char_node; 


typedef struct char_queue{
	char_node *head; 
	char_node *tail;
	int size; 
}char_queue;


void char_queue_init(char_queue *q); 
void char_queue_enqueue(char_queue *q, char value); 
char char_queue_dequeue(char_queue *q); 
char char_queue_head(char_queue *q); 
int char_queue_length(char_queue *q); 
#endif 
