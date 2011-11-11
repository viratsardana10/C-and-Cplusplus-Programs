	.file	"decode1.cpp"
	.text
	.align 2
.globl __Z7decode1PiS_S_
	.def	__Z7decode1PiS_S_;	.scl	2;	.type	32;	.endef
__Z7decode1PiS_S_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edi, 8(%esp)
	movl	8(%ebp), %edi
	movl	12(%ebp), %ebx
	movl	16(%ebp), %esi
	movl	(%edi), %eax
	movl	(%ebx), %edx
	movl	(%esi), %ecx
	movl	%eax, (%ebx)
	movl	%edx, (%esi)
	movl	%ecx, (%edi)
	movl	(%esp), %ebx
	movl	4(%esp), %esi
	movl	8(%esp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
