global ft_list_size

section .text

ft_list_size:
	xor		rax, rax		; set rax to 0

loop_list:
	cmp		rdi, 0			; 
	je		exit			; exit if *rdi == NULL
	mov		rdi, [rdi + 8]	; lst = lst->next
	inc		rax				; rax++
	jmp		loop_list		; go to loop_list

exit:
	ret