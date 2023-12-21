	.include "magicdefs.asm"

; int16 open (char const *path, uint16, uint16)
	.align	2
	.global	open
open:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_open
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_OPEN(%r0)
	ldw	%r0,MAGIC_SCN-SCN_OPEN(%r0)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
ss_open: .word	SCN_OPEN

