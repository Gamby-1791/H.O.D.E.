
	.align	2
	.global	isinff
isinff:
	clr	%r0
	ldw	%r2,2-64(%r6)
	ldw	%r1,#0x80
	add	%r2,%r2,%r1
	shl	%r2,%r2
	ldw	%r1,0-64(%r6)
	or	%r2,%r2,%r1
	bne	notinff
	inc	%r0,%r0
notinff:
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
