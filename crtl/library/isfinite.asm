
	.align	2
	.global	isfinite
isfinite:
	clr	%r0
	ldw	%r2,6-64(%r6)
	ldw	%r1,isfin_7FF0
	and	%r2,%r2,%r1
	cmp	%r2,%r1
	beq	notfin
	inc	%r0,%r0
notfin:
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
isfin_7FF0: .word 0x7FF0
