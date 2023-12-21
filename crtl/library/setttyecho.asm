	.include "magicdefs.asm"

; int16 setttyecho (int16, bool)
	.align	2
	.global	setttyecho
setttyecho:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_setttyecho
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_SETTTYECHO(%r0)
	ldw	%r0,MAGIC_SCN-SCN_SETTTYECHO(%r0)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)
ss_setttyecho: .word SCN_SETTTYECHO

