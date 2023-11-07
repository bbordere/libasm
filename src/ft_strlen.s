global ft_strlen

section .text

ft_strlen:
	xor 	rcx, rcx			; set counter to 0

loop_count:
	cmp		BYTE [rdi + rcx], 0 ;
	je		exit				; if (rdi[rcx] == 0) go to exit 
	inc		rcx					; rcx++
	jmp		loop_count			; jump loop_count

exit:
	mov		rax, rcx			; set rax to rcx
	ret							; return rax