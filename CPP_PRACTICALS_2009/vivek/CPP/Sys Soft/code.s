	.file	"code.c"
.globl _accum
	.bss
	.align 4
_accum:
	.space 4
	.text
	.p2align 4,,15
.globl _sum
	.def	_sum;	.scl	2;	.type	32;	.endef
_sum:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	popl	%ebp
	addl	%ecx, %eax
	addl	%eax, _accum
	ret
