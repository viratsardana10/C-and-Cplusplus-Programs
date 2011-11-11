	.file	"switch.cpp"
	.text
	.align 2
.globl __Z7_switchi
	.def	__Z7_switchi;	.scl	2;	.type	32;	.endef
__Z7_switchi:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	leal	-100(%edx), %eax
	cmpl	$6, %eax
	ja	L8
	jmp	*L9(,%eax,4)
	.p2align 2
	.align 4
L9:
	.long	L3
	.long	L8
	.long	L4
	.long	L5
	.long	L7
	.long	L8
	.long	L7
L3:
	leal	(%edx,%edx,2), %eax
	leal	(%edx,%eax,4), %edx
	jmp	L2
L4:
	addl	$10, %edx
L5:
	addl	$11, %edx
	jmp	L2
L7:
	imull	%edx, %edx
	jmp	L2
L8:
	movl	$0, %edx
L2:
	movl	%edx, %eax
	popl	%ebp
	ret
