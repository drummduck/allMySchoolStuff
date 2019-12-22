	.file	"Quiz35.c"
	.text
	.globl	setVal
	.type	setVal, @function
setVal:
.LFB0:
	.cfi_startproc
	movslq	12(%rsi), %rax
	addq	32(%rsi), %rax
	movq	%rax, 184(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	setVal, .-setVal
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-9)"
	.section	.note.GNU-stack,"",@progbits
