global ft_read

extern __errno_location

section .text

ft_read:
	xor		rax, rax			;set rax to 0 (read number syscall)
    syscall						;syscall
	cmp		rax, 0				;check return value of write
	jl		error				;goto to error if return value < 0
    ret							;end

error:
	neg		rax					;get absolute value of syscall return
	mov		rdi, rax			;tmp store rax value into rdi
	call	__errno_location	;get errno pointer location into rax
	mov		[rax], rdi			;set rdi value into address of rdi
	mov		rax, -1				;set return value of write call
	ret	