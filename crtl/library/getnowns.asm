
	.include "magicdefs.asm"

; uint64 getnowns () aka getnowns (uint64 *)
	.align  2
	.global	getnowns
getnowns:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_getnowns
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_GETNOWNS(%r0)
	ldw	%r0,MAGIC_SCN-SCN_GETNOWNS(%r0)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
ss_getnowns: .word SCN_GETNOWNS

