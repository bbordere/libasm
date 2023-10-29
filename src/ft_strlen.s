global ft_strlen

section .text

ft_strlen:
	xor 	rax, rax			; set counter to 0
	jmp		loop_count  		; go to loop

loop_count:
	cmp		BYTE [rdi + rax], 0 ;
	je		exit				; if (rdi[rax] == 0) go to exit 
	inc		rax					; rax++
	jmp		loop_count			; jump loop_count

exit:
	ret							; return rax