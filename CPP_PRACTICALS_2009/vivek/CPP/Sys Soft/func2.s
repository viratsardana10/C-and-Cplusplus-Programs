	.file	"func.cpp"
	.text
	.align 2
	.p2align 4,,15
.globl __Z4funciii
	.def	__Z4funciii;	.scl	2;	.type	32;	.endef
__Z4funciii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %edx
	movl	12(%ebp), %eax
	subl	%edx, %eax
	movl	8(%ebp), %edx
	popl	%ebp
	imull	%eax, %edx
	sall	$31, %eax
	sarl	$31, %eax
	xorl	%edx, %eax
	ret
