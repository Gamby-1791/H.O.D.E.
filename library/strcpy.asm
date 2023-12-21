; void strcpy (char *, char const *)
	.align	2
	.global	strcpy
strcpy:
	ldw	%r0,-64(%r6)
	ldw	%r1,-62(%r6)
strcpy_loop:
	ldbs	%r2,0(%r1)
	stb	%r2,0(%r0)
	lda	%r1,1(%r1)
	lda	%r0,1(%r0)
	tst	%r2
	bne	strcpy_loop
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)

