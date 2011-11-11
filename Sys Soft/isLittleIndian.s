	.file	"isLittleIndian.cpp"
.lcomm __ZSt8__ioinit,16
	.text
	.align 2
	.p2align 4,,15
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$65535, 12(%ebp)
	movl	%ebx, -4(%ebp)
	movl	8(%ebp), %ebx
	je	L4
L1:
	movl	-4(%ebp), %ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L4:
	cmpl	$1, %ebx
	je	L5
L2:
	testl	%ebx, %ebx
	jne	L1
	movl	$__ZSt8__ioinit, 8(%ebp)
	movl	-4(%ebp), %ebx
	movl	%ebp, %esp
	popl	%ebp
	jmp	__ZNSt8ios_base4InitD1Ev
L5:
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	jmp	L2
	.def	___main;	.scl	2;	.type	32;	.endef
LC0:
	.ascii "pause\0"
	.align 2
	.p2align 4,,15
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	leal	-8(%ebp), %ebx
	andl	$-16, %esp
	call	__alloca
	call	___main
	movl	$11, -8(%ebp)
	movl	%ebx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	call	__ZNSolsEPFRSoS_E
	movsbl	-8(%ebp),%ecx
	movl	$__ZSt4cout, (%esp)
	movl	%ecx, 4(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	%eax, (%esp)
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	call	__ZNSolsEPFRSoS_E
	movsbl	-7(%ebp),%edx
	movl	$__ZSt4cout, (%esp)
	movl	%edx, 4(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	%eax, (%esp)
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	call	__ZNSolsEPFRSoS_E
	movl	%ebx, (%esp)
	call	_strlen
	movl	%eax, %edx
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %ecx
	addl	$__ZSt4cout+4, %ecx
	movl	8(%ecx), %eax
	testb	$64, %al
	jne	L10
	testb	$8, %al
	je	L9
L10:
	movl	%edx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEm
L13:
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movsbl	(%ebx),%edx
	movl	__ZSt4cout, %ecx
	movl	-12(%ecx), %ebx
	addl	$__ZSt4cout+4, %ebx
	movl	8(%ebx), %eax
	testb	$64, %al
	jne	L18
	testb	$8, %al
	je	L17
L18:
	movl	%edx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEm
L21:
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC0, (%esp)
	call	_system
	movl	-4(%ebp), %ebx
	xorl	%eax, %eax
	leave
	ret
	.p2align 4,,7
L17:
	movl	%edx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	jmp	L21
	.p2align 4,,7
L9:
	movl	%edx, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	jmp	L13
.globl __ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE
	.section	.rdata$_ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE,""
	.linkonce same_size
	.align 4
__ZNSt15basic_streambufIcSt11char_traitsIcEE13_S_pback_sizeE:
	.long	1
	.text
	.align 2
	.p2align 4,,15
	.def	__GLOBAL__I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__I_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_main
	.text
	.align 2
	.p2align 4,,15
	.def	__GLOBAL__D_main;	.scl	3;	.type	32;	.endef
__GLOBAL__D_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	movl	%ebp, %esp
	popl	%ebp
	ret
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D_main
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEl;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEm;	.scl	3;	.type	32;	.endef
	.def	_system;	.scl	3;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	3;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	3;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	3;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	3;	.type	32;	.endef
