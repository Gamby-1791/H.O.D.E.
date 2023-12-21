
	.align	2
	.global	isnanf
isnanf:
	ldw	%r2,2-64(%r6)
	ldw	%r1,#0x7F80
	and	%r0,%r2,%r1
	cmp	%r0,%r1
	bne	notnanf
	ldw	%r0,#0x7F
	and	%r2,%r2,%r0
	ldw	%r1,0-64(%r6)
	or	%r2,%r2,%r1
	beq	notnanf
	ldw	%r0,#1
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
notnanf:
	clr	%r0
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
