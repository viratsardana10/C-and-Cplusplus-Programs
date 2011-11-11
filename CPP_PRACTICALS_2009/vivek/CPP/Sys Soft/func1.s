	.file	"func.cpp"
	.text
	.align 2
.globl __Z4funciii
	.def	__Z4funciii;	.scl	2;	.type	32;	.endef
__Z4funciii:
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
