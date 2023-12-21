	.include "magicdefs.asm"

; void watchwrite (uint16)
	.align	2
	.global	watchwrite
watchwrite:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_watchwrite
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_WATCHWRITE(%r0)
	ldw	%r0,MAGIC_SCN-SCN_WATCHWRITE(%r0)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
ss_watchwrite: .word SCN_WATCHWRITE

