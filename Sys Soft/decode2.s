	.file	"decode2.c"
	.text
.globl _decode2
	.def	_decode2;	.scl	2;	.type	32;	.endef
_decode2:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	subl	16(%ebp), %eax
	movl	8(%ebp), %edx
	imull	%eax, %edx
	sall	$31, %eax
	sarl	$31, %eax
	xorl	%edx, %eax
	popl	%ebp
	ret
