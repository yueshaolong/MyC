	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Hello, World!\12\316\322\265\304C\0"
.LC1:
	.ascii "%d\12\0"
.LC2:
	.ascii "%hhd\12\0"
.LC3:
	.ascii "%hd\12\0"
.LC4:
	.ascii "%hu\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	call	puts
	movb	$-128, -1(%rbp)
	movsbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movsbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movsbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movsbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
