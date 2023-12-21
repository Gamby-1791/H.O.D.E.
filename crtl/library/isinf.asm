
	.align	2
	.global	isinf
isinf:
	clr	%r0
	ldw	%r2,6-64(%r6)
	lda	%r2,0x10(%r2)
	shl	%r2,%r2
	ldw	%r1,4-64(%r6)
	or	%r2,%r2,%r1
	ldw	%r1,2-64(%r6)
	or	%r2,%r2,%r1
	ldw	%r1,0-64(%r6)
	or	%r2,%r2,%r1
	bne	notinf
	inc	%r0,%r0
notinf:
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
