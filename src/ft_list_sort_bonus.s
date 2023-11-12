global ft_list_sort

section .text

; rdi begin_list, rsi cmp_fct

ft_list_sort:
	cmp		rdi, 0			;
	je		exit			; exit if rdi == NULL
	cmp		rsi, 0			;
	je		exit			; exit if rsi == NULL
	push	r12				; save r12
	push	r13				; save r13
	mov		r12, [rdi]		; r12 = current

reset_cursors:
	cmp		r12, 0			; 
	je		exit			; exit if current == NULL
	mov		r13, [r12 + 8]	; r13 = current->next
	jmp		compare			; 

inc_current:
	mov		r12, [r12 + 8]	; r12 = current->next
	jmp		reset_cursors	;

inc_next
	mov		r13, [r13 + 8]	; r13 = next->next;

compare:
	cmp		r13, 0			;
	je		inc_current		; exit if current->next == NULL
	push	rdi				; save rdi
	push	rsi				; save rsi
	mov		rax, rsi		; rax = *cmp
	mov		rdi, [r12]		; rdi = current->data
	mov		rsi, [r13]		; rsi = next->data
	call	rax				; 
	pop		rsi				; restore rsi
	pop		rdi				; restore rdi
	cmp		rax, 0			; 
	jg		swap 			;
	jmp		inc_next

swap:
	mov		r10, [r12]		; r10 = *(current->data)
	mov		r11, [r13]		; r11 = *(next->data)
	mov		[r12], r11		;
	mov		[r13], r10		; 
	jmp		inc_next

exit:
	pop		r13;
	pop		r12;
	ret