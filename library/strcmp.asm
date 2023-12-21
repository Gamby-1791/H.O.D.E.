; int strcmp (char const *, char const *)
	.align	2
	.global	strcmp
strcmp:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	ldw	%r2,-62(%r6)
	ldw	%r3,-60(%r6)
strcmp_loop:
	ldbs	%r0,0(%r2)
	ldbs	%r1,0(%r3)
	sub	%r0,%r0,%r1
	bne	strcmp_done
	lda	%r2,1(%r2)
	lda	%r3,1(%r3)
	tst	%r1
	bne	strcmp_loop
strcmp_done:
	ldw	%r3,-64(%r6)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)

