	.file	"time.cpp"
	.text
	.align 2
	.def	__ZSt17__verify_groupingPKcjRKSs;	.scl	3;	.type	32;	.endef
__ZSt17__verify_groupingPKcjRKSs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %edi
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	(%eax), %eax
	movl	-12(%eax), %eax
	decl	%eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	decl	%eax
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %edx
	cmpl	-16(%ebp), %eax
	jb	L6
	leal	-16(%ebp), %edx
L6:
	movl	(%edx), %ebx
	movl	-16(%ebp), %edx
	movb	$1, -25(%ebp)
	movl	$0, %ecx
	cmpl	%ebx, %ecx
	jae	L8
	movl	-24(%ebp), %eax
	movl	(%eax), %esi
L12:
	movzbl	(%esi,%edx), %eax
	cmpb	(%ecx,%edi), %al
	sete	-25(%ebp)
	decl	%edx
	incl	%ecx
	cmpl	%ebx, %ecx
	jae	L8
	cmpb	$0, -25(%ebp)
	jne	L12
L8:
	testl	%edx, %edx
	je	L14
	cmpb	$0, -25(%ebp)
	je	L14
	movl	-24(%ebp), %eax
	movl	(%eax), %ecx
L18:
	movzbl	(%ecx,%edx), %eax
	cmpb	(%ebx,%edi), %al
	sete	-25(%ebp)
	decl	%edx
	je	L14
	cmpb	$0, -25(%ebp)
	jne	L18
L14:
	movl	-24(%ebp), %edx
	movl	(%edx), %eax
	movzbl	(%eax), %eax
	movb	$0, %dl
	cmpb	(%ebx,%edi), %al
	jg	L20
	movzbl	-25(%ebp), %edx
	andb	$1, %dl
L20:
	movl	%edx, %eax
	andl	$1, %eax
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
.lcomm __ZSt8__ioinit,16
	.def	___main;	.scl	2;	.type	32;	.endef
	.align 2
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	andl	$-16, %esp
	movl	$16, %eax
	call	__alloca
	call	___main
	movl	$1, %esi
	movl	$1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	call	_clock
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$0, (%esp)
	call	_time
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
L29:
	addl	%esi, %esi
	incl	%eax
	cmpl	$999999, %eax
	jle	L29
	movl	$0, (%esp)
	call	_time
	movl	%eax, %ebx
	movl	%esi, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEl
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEl
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ebx, -8(%ebp)
	movl	%esi, -4(%ebp)
	movl	8(%ebp), %esi
	movl	12(%ebp), %ebx
	cmpl	$65535, %ebx
	sete	%dl
	cmpl	$1, %esi
	sete	%al
	testb	%al, %dl
	je	L33
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L33:
	cmpl	$65535, %ebx
	sete	%dl
	testl	%esi, %esi
	sete	%al
	testb	%al, %dl
	je	L32
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L32:
	movl	-8(%ebp), %ebx
	movl	-4(%ebp), %esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.align 2
	.def	__GLOBAL__I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__I_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_main
	.text
	.align 2
	.def	__GLOBAL__D_main;	.scl	3;	.type	32;	.endef
__GLOBAL__D_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D_main
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	3;	.type	32;	.endef
	.def	_time;	.scl	3;	.type	32;	.endef
	.def	_clock;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	3;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	3;	.type	32;	.endef
	.def	__ZNSolsEl;	.scl	3;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	3;	.type	32;	.endef
