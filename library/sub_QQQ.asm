	.include "magicdefs.asm"

;
; unsigned quad subtract
;  input:
;   R0 = output address
;   R1 = input address
;   R2 = input address
;   R3 = return address
;  output:
;   R0,R4,R5 = same as on input
;   R1,R2,R3 = trashed
;
	.align	2
	.global	__sub_QQQ
__sub_QQQ:
	lda	%r6,-4(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)

	ldw	%r3,0(%r1)
	ldw	%r4,0(%r2)
	sub	%r3,%r3,%r4
	stw	%r3,0(%r0)

	ldw	%r3,2(%r1)
	ldw	%r4,2(%r2)
	sbb	%r3,%r3,%r4
	stw	%r3,2(%r0)

	ldw	%r3,4(%r1)
	ldw	%r4,4(%r2)
	sbb	%r3,%r3,%r4
	stw	%r3,4(%r0)

	ldw	%r3,6(%r1)
	ldw	%r4,6(%r2)
	sbb	%r3,%r3,%r4
	stw	%r3,6(%r0)

	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
