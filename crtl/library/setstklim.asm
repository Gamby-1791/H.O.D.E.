	.include "magicdefs.asm"

; int16 setstklim (uint16)
	.align	2
	.global	setstklim
setstklim:
	ldw	%r0,-64(%r6)	; make sure R6 stays 64 above end of malloc area
	lda	%r0,32(%r0)
	lda	%r0,32(%r0)
	stw	%r0,-64(%r6)
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_setstklim
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_SETSTKLIM(%r0)
	ldw	%r0,MAGIC_SCN-SCN_SETSTKLIM(%r0)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
ss_setstklim: .word SCN_SETSTKLIM

