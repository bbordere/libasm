global ft_list_remove_if

section .text

extern free

; rdi = **begin, rsi = *data_ref, rdx = cmp_fct, rcx = free_ftc
; r12 = current
; r13 = prev

ft_list_remove_if:
	push	r12				; save r12
	push	r13				; save r13
	push	r14				; save r14
	push	r15				; save r15

	cmp		rdi, 0			;
	je		exit			; exit if begin == NULL
	cmp		rsi, 0			;
	je		exit			; exit if data_ref == NULL
	mov		r12, [rdi]		; current = *begin
	xor		r13, r13		; prev = NULL
	mov		r14, rdx		; r14 = cmp_fct
	mov		r15, rcx		; r15 = free_fct
	jmp		loop_list		;

inc_loop:
	mov		r13, r12		; prev = current
	mov		r12, [r12 + 8]	; current = current->next

loop_list:
	cmp		r12, 0			; 
	je		exit			; exit if current == NULL
	push	rdi				; save rdi
	push	rsi				; save rsi
	mov		rax, r14		; 
	mov		rdi, [r12]		;
	call	r14				; cmp_fct(current->data, data_ref)
	pop		rsi				; restore rsi
	pop		rdi				; restore rdi
	cmp		rax, 0			;
	je		link_items		; if cmp == 0 go to link_items
	jmp		inc_loop		;

link_items:
	cmp		r13, 0			;
	je		change_head		;
	mov		r8, [r12 + 8]	;
	mov		[r13 + 8], r8	;
	jmp		free_item		;

change_head:
	mov		r8, [rdi]		; r8 = begin
	mov		r8, [r8 + 8]	; r8 = begin->next
	mov		[rdi], r8		; *begin = begin->next

free_item:
	push	rdi				; save rdi
	push	rsi				; save rsi
	mov		rax, r15		;
	mov		rdi, [r12]		;
	call	rax				; free(current->data)
	mov		rdi, r12		;
	call	free wrt ..plt	; free(current)
	pop		rsi				; restore rsi
	pop		rdi				;
	cmp		r13, 0			;
	jne		restore_ptr
	mov		r12, [rdi]		;
	jmp		loop_list

restore_ptr:
	mov 	r12, r13		;
	jmp		inc_loop		;

exit:
	pop		r15				; restore r15
	pop		r14				; restore r14
	pop		r13				; restore r13
	pop		r12				; restore r12
	ret
