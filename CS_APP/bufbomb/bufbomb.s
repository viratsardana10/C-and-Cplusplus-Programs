	.file	"bufbomb.c"
	.text
	.align 2
.globl __Z5getxsPc
	.def	__Z5getxsPc;	.scl	2;	.type	32;	.endef
__Z5getxsPc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$1, -8(%ebp)
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
L2:
	call	_getchar
	movl	%eax, -4(%ebp)
	cmpl	$-1, -4(%ebp)
	je	L3
	cmpl	$10, -4(%ebp)
	je	L3
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	_isxdigit
	testl	%eax, %eax
	je	L2
	cmpl	$47, -4(%ebp)
	jle	L5
	cmpl	$57, -4(%ebp)
	jg	L5
	movl	-4(%ebp), %eax
	subl	$48, %eax
	movl	%eax, -20(%ebp)
	jmp	L6
L5:
	cmpl	$64, -4(%ebp)
	jle	L7
	cmpl	$70, -4(%ebp)
	jg	L7
	movl	-4(%ebp), %eax
	subl	$55, %eax
	movl	%eax, -20(%ebp)
	jmp	L6
L7:
	movl	-4(%ebp), %eax
	subl	$87, %eax
	movl	%eax, -20(%ebp)
L6:
	cmpl	$0, -8(%ebp)
	je	L9
	movl	-20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -8(%ebp)
	jmp	L2
L9:
	movl	-16(%ebp), %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	%eax, %edx
	sall	$4, %edx
	movl	-20(%ebp), %eax
	addb	%dl, %al
	movb	%al, (%ecx)
	leal	-16(%ebp), %eax
	incl	(%eax)
	movl	$1, -8(%ebp)
	jmp	L2
L3:
	movl	-16(%ebp), %eax
	movb	$0, (%eax)
	leal	-16(%ebp), %eax
	incl	(%eax)
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$getchar,"x"
	.linkonce discard
	.align 2
.globl _getchar
	.def	_getchar;	.scl	2;	.type	32;	.endef
_getchar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	__imp___iob, %eax
	decl	4(%eax)
	cmpl	$0, 4(%eax)
	js	L12
	movl	__imp___iob, %eax
	movl	(%eax), %edx
	movzbl	(%edx), %edx
	movl	%edx, -4(%ebp)
	incl	(%eax)
	jmp	L13
L12:
	movl	__imp___iob, %eax
	movl	%eax, (%esp)
	call	__filbuf
	movl	%eax, -4(%ebp)
L13:
	movl	-4(%ebp), %eax
	leave
	ret
	.text
	.align 2
.globl __Z6getbufv
	.def	__Z6getbufv;	.scl	2;	.type	32;	.endef
__Z6getbufv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z5getxsPc
	movl	$1, %eax
	leave
	ret
	.section .rdata,"dr"
LC0:
	.ascii "Type Hex string:\0"
LC1:
	.ascii "getbuf returned 0x%x\12\0"
	.text
	.align 2
.globl __Z4testv
	.def	__Z4testv;	.scl	2;	.type	32;	.endef
__Z4testv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$LC0, (%esp)
	call	_printf
	call	__Z6getbufv
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.align 2
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$120, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -92(%ebp)
	movl	-92(%ebp), %eax
	call	__alloca
	call	___main
	leal	-72(%ebp), %eax
	andl	$4095, %eax
	movl	%eax, -76(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -80(%ebp)
	movl	-80(%ebp), %eax
	movl	$0, (%eax)
	call	__Z4testv
	movl	$0, %eax
	leave
	ret
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_isxdigit;	.scl	3;	.type	32;	.endef
	.def	__filbuf;	.scl	3;	.type	32;	.endef
