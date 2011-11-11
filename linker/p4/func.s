	.file	"func.cpp"
	.text
	.align 2
.globl __Z4funci
	.def	__Z4funci;	.scl	2;	.type	32;	.endef
__Z4funci:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	imull	_j, %eax
	popl	%ebp
	ret
