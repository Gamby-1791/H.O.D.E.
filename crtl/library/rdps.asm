	.include "magicdefs.asm"

; uint16 rdps ()
	.align	2
	.global	rdps
rdps:
	rdps	%r0
	lda	%pc,0(%r3)

