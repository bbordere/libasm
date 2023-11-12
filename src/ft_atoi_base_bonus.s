global ft_atoi_base

extern ft_strlen

section .text

; r8 => sign, r9 => tmp var, r10 tmp char, r11 str pointer, r12 base length

ft_atoi_base:
	push	r12						; save r12
	push	rbp						; save stack pointer
	mov		rbp, rsp				; set rbp to rsp
	sub		rsp, 128				; reserve 128 bytes
	mov		r11, rdi				; save string ptr
	mov		rdi, rsi				;
	cmp		rdi, 0					; check if base ptr is not null
	je		exit_failure					; exit
	call	ft_strlen				; get len of base
	cmp		rax, 2					; 
	jl		exit_failure			; exit if base lenth < 2
	mov		r12, rax				; save base length
	xor		rcx, rcx				; set rcx to 0

init_mem:
	cmp		rcx, 128
	je		restore_rcx				; if rcx == 128 go to restore_rcx
	mov		BYTE [rsp + rcx], -1	; rsp[rcx] = -1
	inc		rcx 					; rcx++
	jmp		init_mem				;

restore_rcx:
	xor		rcx, rcx				; set rcx to 0
	xor		r9, r9					; set r9 to 0
	xor		r10, r10				; set r10 to 0

check_base:
	cmp		BYTE [rdi + rcx], 0		; check if char is null
	je		check_str
	mov		r10b, BYTE [rdi + rcx]	; mov char in 1 byte register
	cmp		r10b, 9					; check whitespaces	 '\t' '\r' '\n' '\v' '\f'
	jl		fill_mem				;
	cmp		r10b, 13				;
	jg		fill_mem				; 
	jmp		exit_failure			; if char <= 9 && >= 13

fill_mem:
	cmp		r10b, ' '				; ' '
	je		exit_failure			;
	cmp		r10b, '+'					;
	je		exit_failure			; exit if char is '+'
	cmp		r10b, '-'					; 
	je		exit_failure			; exit if char is '-'
	cmp		BYTE [rsp + r10], -1	;
	jne		exit_failure			; exit if char is already in base
	mov		BYTE [rsp + r10], r9b	; *(rsp + r10) = r9b
	inc		rcx						; rcx++
	inc		r9b						; r9++
	jmp		check_base				;

check_str:
	mov		rcx, -1					; set rcx to -1
	mov		rdi, r11				; restore str pointer

skip_whitespaces:
	inc		rcx						; rcx++
	cmp		BYTE [rdi + rcx], ' '	;
	je		skip_whitespaces		;
	cmp		BYTE [rdi + rcx], 9		;
	jl		prepare_parsing			;
	cmp		BYTE [rdi + rcx], 13	; skip whitespaces
	jg		prepare_parsing			;
	jmp		skip_whitespaces		;

prepare_parsing:
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
	cmp		BYTE [rsp + r10], -1	;
	je		return_res				; if current char is not in base return res
	mov		r9b, BYTE [rsp + r10]	; set r9 to char value in base
	imul	rax, r12				; 
	add		rax, r9					;
	inc		rcx 					; rcx++
	jmp		parse_int

exit_failure:
	mov		r8, 0					;

return_res:
	add		rsp, 128				; restore stack pos
	pop		rbp						; restore rdp
	imul	rax, r8					; res *= sign
	pop		r12						; restore r12
	ret
