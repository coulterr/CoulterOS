[bits 16]
[extern switch_to_protected]		
[global _start]
_start:
	mov [BOOT_DRIVE], dl					;BIOS stores boot drive in DL. Store in memory for later. 

	cli														;Halt interrupts. Set up stack at 0x7B00 (free area below designated boot area) 
	mov bp, 0x7B00
	mov sp, bp												
	sti														;Restore interrupts

	mov bx, LOADING_KERNEL_MSG				
	call print_string
  
	mov bx, 0x7E00									;Load kernel instructions into memory at 0x7E00
	mov dh, 10
	mov dl, [BOOT_DRIVE]
	call load_from_disk

	mov bx, SWITCHING_MODE_MSG		;JMP to routine to switch to 32-Bit Protected mode
	call print_string
	jmp switch_to_protected					


	


print_string:						;Prints 0-terminated string pointed to by BX and moves cursor to next line
	mov si, bx
	mov ah, 0x0e					;Teletype Output parameter
	
.repeat:
	lodsb									;Loads next char in SI's string into AL
	cmp al, 0
	je .done
	int 10h								;Print interrupt
	jmp .repeat
.done:
	mov ah, 0x03					;Cursor position info parameter; stores line number in BH
	mov bh, 0							;Page number
	int 10h

	inc dh								;Increment line number and call routine to set cursor position
	mov bh, 0
	mov dl, 0
	mov ah, 0x02
	int 10h
	ret
;end print_string



load_from_disk:					;DL contains boot drive #, DH contains # of sectors to be read
	push dx								;Store DX on stack to consult later (to make sure so many sectors have been read)
	
	mov ah, 0x02					;BIOS read function argument
	mov al, dh						;# of sectors to be read
	mov ch, 0x00					;Select cylinder 0
	mov dh, 0x00					;Select head 0
	mov cl, 0x02					;Start reading from sector 2 (sector after boot sector)

	int 0x13							;BIOS interrupt
	
	jc .diskerror					;If carry flag set, JMP to diskerror routine

	pop dx								;Restore DX from stack
	
	cmp dh, al						;# of sectors successfully read stored in AL. Make sure they match DH
	jne .diskerror
	
	ret

.diskerror:
	mov bx, DISK_ERROR_MSG
	call print_string
	jmp $
;end load_from_disk

	
;DATA
SWITCHING_MODE_MSG db 'Switching to 32-Bit Protected Mode...', 0
LOADING_KERNEL_MSG db 'Loading Kernel and Rudimentary Drivers...', 0
DISK_ERROR_MSG db 'ERROR: COULD NOT READ DISK', 0
BOOT_DRIVE db 0


times 510 - ($-$$) db 0
dw 0xaa55

