	.file	"time_func.cpp"
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I__Z8functionv
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D__Z8functionv
.lcomm __ZSt8__ioinit,16
	.section .rdata,"dr"
LC0:
	.ascii "hello vivek \0"
	.text
	.align 2
	.p2align 4,,15
.globl __Z8functionv
	.def	__Z8functionv;	.scl	2;	.type	32;	.endef
__Z8functionv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	$9999, %ebx
	.p2align 4,,15
L5:
	movl	$__ZSt4cout, (%esp)
	movl	$LC0, %eax
	movl	%eax, 4(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	decl	%ebx
	jns	L5
	movl	$__ZSt4cout, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.align 2
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ebx, -8(%ebp)
	cmpl	$65535, %edx
	sete	%bl
	movl	%esi, -4(%ebp)
	cmpl	$1, %eax
	movl	%eax, %esi
	sete	%al
	testb	%al, %bl
	jne	L13
	testl	%esi, %esi
	sete	%al
	testb	%al, %bl
	jne	L14
L10:
	movl	-8(%ebp), %ebx
	movl	-4(%ebp), %esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L13:
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	testl	%esi, %esi
	sete	%al
	testb	%al, %bl
	je	L10
	.p2align 4,,15
L14:
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	movl	-8(%ebp), %ebx
	movl	-4(%ebp), %esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.align 2
	.p2align 4,,15
	.def	__GLOBAL__I__Z8functionv;	.scl	3;	.type	32;	.endef
__GLOBAL__I__Z8functionv:
	pushl	%ebp
	movl	$65535, %edx
	movl	%esp, %ebp
	popl	%ebp
	movl	$1, %eax
	jmp	__Z41__static_initialization_and_destruction_0ii
	.align 2
	.p2align 4,,15
	.def	__GLOBAL__D__Z8functionv;	.scl	3;	.type	32;	.endef
__GLOBAL__D__Z8functionv:
	pushl	%ebp
	movl	$65535, %edx
	movl	%esp, %ebp
	popl	%ebp
	xorl	%eax, %eax
	jmp	__Z41__static_initialization_and_destruction_0ii
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	3;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	3;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	3;	.type	32;	.endef
