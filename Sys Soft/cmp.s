	.file	"cmp.cpp"
	.text
	.align 2
.globl __Z4testii
	.def	__Z4testii;	.scl	2;	.type	32;	.endef
__Z4testii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	cmpl	%eax, 8(%ebp)
	setg	%al
	movsbl	%al,%eax
	popl	%ebp
	ret
