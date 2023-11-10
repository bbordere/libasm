global  ft_write

section .data

extern __errno_location

section .text

ft_write:
    mov		rax, 1						; write syscall number
    syscall								; syscall
	cmp		rax, 0						; check return value of write
	jl		error						; goto to error if return value < 0
    ret									; end

error:
	neg		rax							; get absolute value of syscall return
	mov		rdi, rax					; tmp store rax value into rdi
	call    __errno_location wrt ..plt	; get errno pointer location into rax
	mov		[rax], rdi					; set rdi value into address of rdi
	mov		rax, -1						; set return value of write call
	ret									; end