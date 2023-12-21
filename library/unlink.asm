	.include "magicdefs.asm"

; int16 unlink (char const *)
	.align	2
	.global	unlink
unlink:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_unlink
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_UNLINK(%r0)
	ldw	%r0,MAGIC_SCN-SCN_UNLINK(%r0)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
ss_unlink: .word SCN_UNLINK

