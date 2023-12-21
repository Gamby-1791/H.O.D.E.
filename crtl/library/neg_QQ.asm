	.include "magicdefs.asm"

;
; negate quadword
;  input:
;   R0 = points to output quadword
;   R1 = points to input quadword
;   R3 = return address
;  output:
;   R0,R4,R5 = as on input
;   R1,R2,R3 = trashed
	.global	__neg_QQ
__neg_QQ:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	clr	%r3

	ldw	%r2,0(%r1)
	sub	%r2,%r3,%r2
	stw	%r2,0(%r0)
	ldw	%r2,2(%r1)
	sbb	%r2,%r3,%r2
	stw	%r2,2(%r0)
	ldw	%r2,4(%r1)
	sbb	%r2,%r3,%r2
	stw	%r2,4(%r0)
	ldw	%r2,6(%r1)
	sbb	%r2,%r3,%r2
	stw	%r2,6(%r0)

	ldw	%r3,-64(%r6)
	lda	%r6,2(%r6)
	lda	%pc,0(%r3)

