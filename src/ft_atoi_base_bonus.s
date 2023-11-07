global ft_atoi_base

extern ft_strlen

section .text

ft_atoi_base:
	push	rdi						;store string ptr
	mov		rdi, rsi				;
	cmp		rdi, 0					; check if base ptr is not null
	je		exit					; exit
	call	ft_strlen				; get len of base
	cmp		rax, 0					; check if len == 0
	je		exit					; exit
	cmp		rax, 1					; check if len == 1
	je		exit					; exit
	mov		r10, rax				; set r10 to rax
	xor		rcx, rcx				; set rcx to 0
	push	rbp						; save stack pointer
	mov		rbp, rsp				; set rbp to rsp
	sub		rsp, 127				; reserve 127 bytes
	jmp		loop_base				;



loop_base:
	cmp		BYTE [rdi + rcx], 0		; check if char is null
	je		check_str
	mov		dl, BYTE [rdi + rcx]	; mov char in 1 byte register
	cmp		dl, '+'					;
	je		restore_stack			; exit if char is '+'
	cmp		dl, '-'					; 
	je		restore_stack			; exit if char is '-'
	movzx	rax, dl 				; set rax to dl
	cmp		BYTE [rsp + rax], 1		;
	je		restore_stack			; exit if char is already in base
	mov		BYTE [rsp + rax], 1		; *(rsp + rax) = 1
	inc		rcx						; rcx++
	jmp		loop_base				;

check_str:
	add		rsp, 127				; restore stack pos
	pop		rbp						; restore rdp

	mov		rcx, -1					; set rcx to -1
	pop		rdi						; restore rdi to str pointer
	jmp		skip_whitespaces		;


skip_whitespaces:
	inc		rcx						; rcx++
	cmp		BYTE [rdi + rcx], 9		; '\t'
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], 10	; '\n'
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], 13	; '\r'
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], 11	; '\v'
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], 12	; '\f'
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], ' '	;
	je		skip_whitespaces		;
	dec		rcx						;
	mov		r8, 1					; set r8 to 1 (represents sign of expression)
	jmp		get_sign				;

inverse_sign:
	neg		r8						; inverse r8

get_sign:
	inc		rcx						; rcx++
	cmp		BYTE [rdi + rcx], '+'	; 
	je		get_sign				; go to get_sign if str[rcx] = '+'				
	cmp		BYTE [rdi + rcx], '-'	; 
	je		inverse_sign			; go to inverse_sign if str[rcx] = '+'
	jmp		parse_int				;
	dec		rcx						; rcx--

parse_int:
	inc		rcx						; rcx++
	cmp		BYTE [rdi + rcx], '0'	; 
	jl		exit					; exit if char is lower than '0'
	cmp		BYTE [rdi + rcx], '9'	; 
	jg		exit					; exit if char is greater than '0'
	mov		rax, r8					;
	ret		

exit:
	pop		rdi						; restore rdi
	mov		rax, -42				; 
	ret								;


restore_stack:
	add		rsp, 127				; restore stack pos
	pop		rbp						; restore rdp
	jmp		exit					;

