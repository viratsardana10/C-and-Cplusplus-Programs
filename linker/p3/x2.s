	.file	"x2.cpp"
.globl _x
	.bss
	.align 4
_x:
	.space 4
	.text
	.align 2
.globl __Z1fv
	.def	__Z1fv;	.scl	2;	.type	32;	.endef
__Z1fv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, _x
	popl	%ebp
	ret
