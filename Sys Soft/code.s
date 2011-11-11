	.file	"code.c"
.globl _accum
	.bss
	.align 4
_accum:
	.space 4
	.text
	.align 2
.globl __Z3sumii
	.def	__Z3sumii;	.scl	2;	.type	32;	.endef
__Z3sumii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	addl	%eax, _accum
	popl	%ebp
	ret
