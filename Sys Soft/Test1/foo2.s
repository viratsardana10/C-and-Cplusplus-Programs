	.file	"foo2.cpp"
	.text
	.align 2
.globl __Z4foo2i
	.def	__Z4foo2i;	.scl	2;	.type	32;	.endef
__Z4foo2i:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	testl	%eax, %eax
	jns	L2
	addl	$15, %eax
L2:
	sarl	$4, %eax
	popl	%ebp
	ret
