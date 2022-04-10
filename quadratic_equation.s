	.file	"quadratic_equation.c"
	.text
	.globl	discrim
	.type	discrim, @function
discrim:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm2, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	mulsd	%xmm0, %xmm0
	movsd	-8(%rbp), %xmm2
	movsd	.LC0(%rip), %xmm1
	mulsd	%xmm2, %xmm1
	mulsd	-24(%rbp), %xmm1
	subsd	%xmm1, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	discrim, .-discrim
	.section	.rodata
.LC1:
	.string	"%lf %lf %lf"
.LC2:
	.string	"Error: wrong input."
	.align 8
.LC4:
	.string	"Error: Not a quadratic equation!"
.LC5:
	.string	"No roots"
.LC7:
	.string	"%.5f %.5f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-24(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -44(%rbp)
	cmpl	$3, -44(%rbp)
	je	.L4
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$1, %eax
	jmp	.L10
.L4:
	movsd	-40(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jp	.L6
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	.L6
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	movl	$2, %eax
	jmp	.L10
.L6:
	movsd	-24(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	movq	-40(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	discrim
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	pxor	%xmm0, %xmm0
	comisd	-16(%rbp), %xmm0
	jbe	.L14
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L10
.L14:
	movq	-16(%rbp), %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-32(%rbp), %xmm1
	movsd	-16(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	movsd	-40(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	movapd	%xmm1, %xmm2
	divsd	%xmm0, %xmm2
	movsd	-32(%rbp), %xmm0
	movq	.LC6(%rip), %xmm1
	xorpd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	subsd	-16(%rbp), %xmm1
	movsd	-40(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movapd	%xmm2, %xmm1
	leaq	.LC7(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movl	$0, %eax
.L10:
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1074790400
	.align 16
.LC6:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
