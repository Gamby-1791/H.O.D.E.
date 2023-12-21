
	.align	2
	.global	isnan
isnan:
	ldw	%r2,6-64(%r6)
	ldw	%r1,isnan_7FF0
	and	%r0,%r2,%r1
	sub	%r0,%r0,%r1
	bne	notnan
	lda	%r0,0x0F(%r0)
	and	%r2,%r2,%r0
	ldw	%r1,4-64(%r6)
	or	%r2,%r2,%r1
	ldw	%r1,2-64(%r6)
	or	%r2,%r2,%r1
	ldw	%r1,0-64(%r6)
	or	%r2,%r2,%r1
	beq	notnan
	lda	%r0,-14(%r0)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
notnan:
	clr	%r0
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
isnan_7FF0: .word 0x7FF0
