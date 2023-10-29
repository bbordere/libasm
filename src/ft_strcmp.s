global ft_strcmp
section .text

;strcmp(s1, s2)
ft_strcmp:
	xor		rax, rax				;set return value to 0
	xor		rcx, rcx				;set return value to 0
	jmp		loop					;go to loop

loop:
	cmp		BYTE [rdi + rcx], 0 	;
	je		exit					; if (rdi[rcx] == 0) go to exit
	cmp		BYTE [rsi + rcx], 0 	;
	je		exit					; if (rsi[rcx] == 0) go to exit
	mov		dl, BYTE [rdi + rcx]	; set dl to rdi[rcx]
	cmp		BYTE [rsi + rcx], dl	;
	jne		exit					;if rdi[rcx] != rsi[rcx] go to exit
	inc		rcx						;rcx++
	jmp		loop					;go to loop

exit:
	movzx	rax, BYTE [rdi + rcx]	;set rax to rdi[rcx]
	movzx	rcx, BYTE [rsi + rcx]	;set rcx to rdi[rcx]
	sub		rax, rcx				;rax = rax - rcx
	ret								; return rax
