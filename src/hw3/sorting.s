	.file	"sorting.c"
	.text
	.p2align 4
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB11:
	.cfi_startproc
	movq	%rdi, %r8
	movl	%esi, %edx
	cmpl	$1, %esi
	jle	.L6
	movslq	%esi, %rax
	salq	$2, %rax
	leaq	-8(%rdi,%rax), %r9
	leaq	-4(%rdi,%rax), %rsi
	xorl	%edi, %edi
	leal	-2(%rdx), %eax
	salq	$2, %rax
	subq	%rax, %r9
	.p2align 4
	.p2align 3
.L3:
	movq	%r8, %rax
	.p2align 6
	.p2align 4
	.p2align 3
.L5:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %edx
	movd	%xmm1, %ecx
	cmpl	%edx, %ecx
	jge	.L4
	pshufd	$225, %xmm0, %xmm0
	addl	$2, %edi
	movq	%xmm0, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
	subq	$4, %rsi
	cmpq	%r9, %rsi
	jne	.L3
	movl	%edi, %eax
	ret
.L6:
	xorl	%edi, %edi
	movl	%edi, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (GNU) 15.2.1 20251112"
	.section	.note.GNU-stack,"",@progbits
