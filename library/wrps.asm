	.include "magicdefs.asm"

; uint16 wrps (uint16)
	.align	2
	.global	wrps
wrps:
	ldw	%r1,-64(%r6)
	rdps	%r0
	wrps	%r1
	lda	%r6,2(%r6)
	lda	%pc,0(%r3)

