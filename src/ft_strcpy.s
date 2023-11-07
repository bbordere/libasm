global ft_strcpy

section .text

;strcpy(dest, src)

ft_strcpy:
	xor 	rcx, rcx			;set rcx to 0

loop:
	cmp		BYTE [rsi + rcx], 0	;
	je		exit				; if (rdi[rax] == 0) go to exit 
	mov		dl, [rsi + rcx]		;copy 1 byte (1 char) to dl register
	mov		[rdi + rcx], dl		;copy char to dest
	inc		rcx					;rcx++
	jmp		loop				;go to loop

exit:
	mov 	BYTE [rdi + rcx], 0	;add final \0 to dest
	mov		rax, rdi			;set return value to dest pointer
	ret

