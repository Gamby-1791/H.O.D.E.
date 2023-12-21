; char *memchr (char *, char, int)
	.align	2
	.global	memchr
memchr:
	ldw	%r0,-64(%r6)
	ldbs	%r1,-62(%r6)
	ldw	%r2,-60(%r6)
	stw	%r3,-64(%r6)
	neg	%r2,%r2
	beq	memchr_null
memchr_loop:
	ldbs	%r3,0(%r0)
	cmp	%r3,%r1
	beq	memchr_done
	lda	%r0,1(%r0)
	inc	%r2,%r2
	bne	memchr_loop
memchr_null:
	clr	%r0
memchr_done:
	ldw	%r3,-64(%r6)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)

