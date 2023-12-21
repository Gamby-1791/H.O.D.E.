	.include "magicdefs.asm"

; void exit (int16) noreturn
	.align	2
	.global	exit
exit:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_exit
	stw	%r0,0(%r1)
exit_loop:
	stw	%r1,MAGIC_SCN-SCN_EXIT(%r0)
	br	exit_loop
ss_exit: .word	SCN_EXIT

