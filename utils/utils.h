#ifndef ASM_UTILS_H_INCLUDED
#define ASM_UTILS_H_INCLUDED

unsigned char in_byte ( unsigned short port ); 
void out_byte ( unsigned short port, unsigned char data ); 
unsigned short in_word ( unsigned short port ); 
void out_word ( unsigned short port, unsigned short data ); 

#endif //ASM_UTILS_INCLUDED
