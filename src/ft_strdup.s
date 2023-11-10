global ft_strdup

section .data

extern __errno_location

section .text

extern malloc

extern ft_strlen

extern ft_strcpy

ft_strdup:
	call	ft_strlen					; get len of string
	push	rdi							; push string pointer on stack
	inc		rax							; rax = strlen + 1
	mov		rdi, rax					; set rdi to rax value
	call	malloc	 wrt ..plt			; malloc(len of str)
	cmp		rax, 0						; 
	je		error						; if malloc return null go to error
	pop		rsi							; pop stack into rdi (str pointer)
	mov		rdi, rax					; rax = pointer returned by malloc
	call	ft_strcpy					; copy rsi string into rdi
	ret									; 

error:
	neg		rax							; get absolute value of syscall return
	mov		rdi, rax					; tmp store rax value into rdi
	call    __errno_location wrt ..plt	; get errno pointer location into rax
	mov		[rax], rdi					; set rdi value into address of rdi
	mov		rax, -1						; set return value of write call
	ret	
