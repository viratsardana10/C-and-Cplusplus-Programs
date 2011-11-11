	.file	"foo3.cpp"
	.text
	.align 2
.globl __Z4foo3i
	.def	__Z4foo3i;	.scl	2;	.type	32;	.endef
__Z4foo3i:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	sarl	$31, %eax
	popl	%ebp
	ret
