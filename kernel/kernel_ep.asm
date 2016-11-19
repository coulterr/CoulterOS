; Entry Point for actual Kernel 

[bits 32] 
[global _start]

_start:
	
	mov eax, 0xabcde

	.infi_loop:
		jmp .infi_loop





