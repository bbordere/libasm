global ft_atoi_base

extern ft_strlen

section .text

; r8 => sign, r9 => tmp var, r10 tmp char, r11 str pointer, r12 base length

ft_atoi_base:
	push	rbp						; save stack pointer
	mov		rbp, rsp				; set rbp to rsp
	sub		rsp, 127				; reserve 127 bytes
	mov		r11, rdi				; save string ptr
	mov		rdi, rsi				;
	cmp		rdi, 0					; check if base ptr is not null
	je		exit_failure					; exit
	call	ft_strlen				; get len of base
	cmp		rax, 0					; check if len == 0
	je		exit_failure					; exit
	cmp		rax, 1					; check if len == 1
	je		exit_failure					; exit
	mov		r12, rax				; save base length
	xor		rcx, rcx				; set rcx to 0

init_mem:
	cmp		rcx, 127
	je		restore_rcx				; if rcx == 127 go to restore_rcx
	mov		BYTE [rsp + rcx], 254	; rsp[rcx] = 254
	inc		rcx 					; rcx++
	jmp		init_mem				;

restore_rcx:
	xor		rcx, rcx				; set rcx to 0
	xor		r9, r9					; set r9 to 0

loop_base:
	cmp		BYTE [rdi + rcx], 0		; check if char is null
	je		check_str
	mov		r10b, BYTE [rdi + rcx]	; mov char in 1 byte register
	cmp		r10b, '+'					;
	je		exit_failure			; exit if char is '+'
	cmp		r10b, '-'					; 
	je		exit_failure			; exit if char is '-'
	cmp		r10b, 9					; '\t'
	je		exit_failure			;
	cmp		r10b, 10				; '\n'
	je		exit_failure			;
	cmp		r10b, 13				; '\r'
	je		exit_failure			;
	cmp		r10b, 11				; '\v'
	je		exit_failure			;
	cmp		r10b, 12				; '\f'
	je		exit_failure			;
	cmp		r10b, ' '				; ' '
	je		exit_failure			;
	cmp		BYTE [rsp + r10], 254	;
	jne		exit_failure			; exit if char is already in base
	mov		BYTE [rsp + r10], r9b	; *(rsp + r10) = r9b
	inc		rcx						; rcx++
	inc		r9b						; r9++
	jmp		loop_base				;

check_str:
	mov		rcx, -1					; set rcx to -1
	mov		rdi, r11				; restore str pointer

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
	cmp		BYTE [rdi + rcx], ' '	; ' '
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
	xor		rax, rax				; set rax to 0

parse_int:
	mov		r10b, BYTE [rdi + rcx]	; mov char in 1 byte register
	cmp		r10b, 0					;
	je		return_res				; if current char is null
	cmp		BYTE [rsp + r10], 254	;
	je		return_res				; if current char is not in base return res
	mov		r9b, BYTE [rsp + r10]	; set r9 to char value in base
	imul	rax, r12				; 
	add		rax, r9					;
	inc		rcx 					; rcx++
	jmp		parse_int

return_res:
	add		rsp, 127				; restore stack pos
	pop		rbp						; restore rdp
	imul	rax, r8					; res *= sign
	ret	

exit_failure:
	add		rsp, 127				; restore stack pos
	pop		rbp						; restore rdp
	mov		rax, 0					; 
	ret								;
