	.file	"f.c"
	.text
.globl _func
	.def	_func;	.scl	2;	.type	32;	.endef
_func:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	cmpl	$0, (%eax)
	je	L1
	testl	%edx, %edx
	jns	L1
	addl	%edx, (%eax)
L1:
	popl	%ebp
	ret
