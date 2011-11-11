	.file	"loop.c"
	.text
	.p2align 4,,15
.globl _loop
	.def	_loop;	.scl	2;	.type	32;	.endef
_loop:
	pushl	%ebp
	movl	$2, %edx
	movl	%esp, %ebp
	movl	8(%ebp), %ecx
	movl	$1, %eax
	cmpl	%ecx, %edx
	jge	L8
	.p2align 4,,15
L6:
	addl	%edx, %eax
	incl	%edx
	cmpl	%ecx, %edx
	jl	L6
L8:
	popl	%ebp
	ret
