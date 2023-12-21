
	.align	2
	.global	isfinitef
isfinitef:
	clr	%r0
	ldw	%r2,2-64(%r6)
	ldw	%r1,#0x7F80
	and	%r2,%r2,%r1
	cmp	%r2,%r1
	beq	notfinf
	inc	%r0,%r0
notfinf:
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
