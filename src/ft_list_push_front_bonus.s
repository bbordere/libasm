global ft_list_push_front

section .text

extern malloc

; rdi = **list, rsi = *data
ft_list_push_front:
	cmp		rdi, 0				;
	je		exit				; exit if !list
	push	rdi					; save rdi
	push	rsi					; save rsi
	mov		rdi, 16				; 
	call	malloc	 wrt ..plt	; malloc(sizeof(list_t))
	cmp		rax, 0				;
	je		exit				; exit if malloc failed
	pop		rsi					; restore rsi
	pop		rdi					; restore rdi
	mov		[rax], rsi			; new.data = data
	mov		r8, [rdi]			; save *begin in r8
	mov		[rax + 8], r8		; new.next = begin
	mov		[rdi], rax			; *begin = new

exit:
	ret
	