[bits 32]
[global switch_to_protected]
[extern kernel_main]
[extern ps2_driver_entrypoint]
[extern drive_ready_isr]
gdt_start:

gdt_null:
	dd 0x0
	dd 0x0
	
gdt_code_0:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10011010b
	db 11001111b
	db 0x00
		
gdt_data_0:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00

gdt_code_3:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 11111010b
	db 11001111b
	db 0x00

gdt_data_3: 
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 11110010b
	db 11001111b
	db 0x00

gdt_end: 

	
gdt_descriptor: 
	dw gdt_end - gdt_start - 1
	dd gdt_start

	CODE_SEG_0 equ gdt_code_0 - gdt_start
	DATA_SEG_0 equ gdt_data_0 - gdt_start
	CODE_SEG_3 equ gdt_code_3 - gdt_start
	DATA_SEG_3 equ gdt_data_3 - gdt_start


idt_start:

dd 0x00
dd 0x00

INT_01:
dd 0x00
dd 0x00 

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

dd 0x00
dd 0x00

INT_32:;IRQ 0
	dw ps2_isr
	dw CODE_SEG_0
	dw 0x8E00
	dw 0x0000

INT_33:;IRQ 1
	
	dw ps2_isr
	dw CODE_SEG_0
	dw 0x8E00
	dw 0x0000

INT_34:;IRQ 2

dw ide_isr
dw CODE_SEG_0
dw 0x8E00
dw 0x0000

INT_35:;IRQ 3

dd 0x00
dd 0x00

INT_36:;IRQ 4

dd 0x00
dd 0x00

INT_37:;IRQ 5

dd 0x00
dd 0x00

INT_38:;IRQ 6

dd 0x00
dd 0x00

INT_39:;IRQ 7

dd 0x00
dd 0x00

INT_40:;IRQ 8

dd 0x00
dd 0x00

INT_41:;IRQ 9

dd 0x00
dd 0x00

INT_42:;IRQ 10

dd 0x00
dd 0x00

INT_43:;IRQ 11

dd 0x00
dd 0x00

INT_44:;IRQ 12

dd 0x00
dd 0x00

INT_45:;IRQ 13

dw ide_isr
dw CODE_SEG_0
dw 0x8E00
dw 0x0000

INT_46:;IRQ 14

dw ide_isr
dw CODE_SEG_0
dw 0x8E00
dw 0x0000

INT_47:;IRQ 15

dw ide_isr
dw CODE_SEG_0
dw 0x8E00
dw 0x0000

INT_48:;IRQ 16

dd 0x00
dd 0x00


idt_end:

idt_descriptor: 
	dw (idt_start - idt_end) - 1
	dd idt_start

[bits 16]
switch_to_protected:
	
	cli
	lgdt [gdt_descriptor]
	lidt [idt_descriptor]
	mov eax, cr0
	or eax, 0x01
	mov cr0, eax
	jmp CODE_SEG_0:init_pm

[bits 32] 

init_pm:
	
	;Configure PIC (IRQ Controller)
	
	mov al, 0x11 	
	out 0x20, al	;Restart PIC1
	out 0xA0, al	;Restart PIC2
	
	mov al, 0x20	
	out 0x21, al	;IRQ0 now starts at 32  
	
	mov al, 0x28
	out 0xA1, al	;IRQ8 now starts at 40
	
	mov al, 0x04
	out 0x21, al	;PIC1 is Master
	
	mov al, 0x02	
	out 0xA1, al	;PIC2 is Slave
	
	mov al, 0x01
	out 0x21, al	;PIC1 ready
	out 0xA1, al	;PIC2 ready
	
	;mov al, 0xFF	
	;out 0xA1, al	;Disable IRQ 8-15

	mov al, 11111101b	
	out 0x21, al		;Disable all except IRQ1
	mov al, 11111101b	;Disable all except IRQ14
	out 0xA1, al

	mov ax, DATA_SEG_0
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ebp, 0x90000
	mov esp, ebp

	sti
	
	jmp kernel_main
	
	ps2_isr:
		;call ps2_driver_entrypoint
		mov al, 0x20
		out 0x20, al
		out 0xA0, al
		iret
	
	ide_isr:
	;	call drive_ready_isr
		mov al, 0x20
		out 0x20, al
		out 0xA0, al
		iret


