	.file	"not_eq.cpp"
.lcomm __ZSt8__ioinit,16
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
LC0:
	.ascii "test true\0"
LC1:
	.ascii "pause\0"
	.align 2
	.p2align 4,,15
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	subl	$24, %esp
	andl	$-16, %esp
	call	__alloca
	call	___main
	movl	$__ZSt3cin, (%esp)
	leal	-1(%ebp), %eax
	movl	%eax, 4(%esp)
	call	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	cmpb	$97, -1(%ebp)
	je	L2
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, (%esp)
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	call	__ZNSolsEPFRSoS_E
L2:
	movl	$LC1, (%esp)
	call	_system
	movl	%ebp, %esp
	xorl	%eax, %eax
	popl	%ebp
	ret
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
	je	L6
L3:
	movl	-4(%ebp), %ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.p2align 4,,7
L6:
	cmpl	$1, %ebx
	je	L7
L4:
	testl	%ebx, %ebx
	jne	L3
	movl	$__ZSt8__ioinit, 8(%ebp)
	movl	-4(%ebp), %ebx
	movl	%ebp, %esp
	popl	%ebp
	jmp	__ZNSt8ios_base4InitD1Ev
L7:
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	jmp	L4
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
	.def	_system;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	3;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	3;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	3;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_;	.scl	3;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	3;	.type	32;	.endef
