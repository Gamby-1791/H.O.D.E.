; char *strchr (char *, char)
	.align	2
	.global	strchr
strchr:
	ldw	%r0,-64(%r6)
	ldbu	%r1,-62(%r6)
strchr_loop:
	ldbu	%r2,0(%r0)
	cmp	%r2,%r1
	beq	strchr_done
	lda	%r0,1(%r0)
	tst	%r2
	bne	strchr_loop
	clr	%r0
strchr_done:
	lda	%r6,4(%r6)
	lda	%r7,0(%r3)

