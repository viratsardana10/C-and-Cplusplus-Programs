	.file	"func.cpp"
	.text
	.align 2
	.p2align 4,,15
.globl __Z4funciii
	.def	__Z4funciii;	.scl	2;	.type	32;	.endef
__Z4funciii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %ecx
	movl	12(%ebp), %eax
	subl	%ecx, %eax
	movl	8(%ebp), %ecx
	popl	%ebp
	imull	%eax, %ecx
	sall	$31, %eax
	sarl	$31, %eax
	xorl	%ecx, %eax
	ret
