; Entry Point for actual Kernel 

[bits 32]
[extern ps2_ep]
[extern init_kernel]
[global _start]

_start:

	cmp eax, 0x1111
	je .kernel_init

	cmp eax, 0x2222
	je .ps2_interrupt

	ret 



	.kernel_init:
		call init_kernel
	
	.ps2_interrupt:
		call ps2_ep
		ret





