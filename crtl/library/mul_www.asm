	.align	2
	.global	__mul_www
__mul_www:
	lda	%r6,-8(%r6)
	stw	%r3,-62(%r6)
	stw	%r4,-60(%r6)
	stw	%r5,-58(%r6)
	mov	%r0,%r1
	bpl	mul_www_posi
	neg	%r1,%r1
mul_www_posi:
	tst	%r2
	bpl	mul_www_posj
	com	%r0,%r0
	neg	%r2,%r2
mul_www_posj:
	stw	%r0,-64(%r6)
	clr	%r3
	lda	%r5,mul_www_done
	ldw	%pc,#__umul
mul_www_done:
	ldw	%r1,-64(%r6)
	tst	%r1
	bpl	mul_www_poso
	neg	%r0,%r0
mul_www_poso:
	ldw	%r3,-62(%r6)
	ldw	%r4,-60(%r6)
	ldw	%r5,-58(%r6)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
