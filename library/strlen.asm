; int strlen (char const *)
	.align	2
	.global	strlen
strlen:
	ldw	%r0,-64(%r6)
	lda	%r1,1(%r0)
strlen_loop:
	ldbu	%r2,0(%r0)
	lda	%r0,1(%r0)
	tst	%r2
	bne	strlen_loop
	sub	%r0,%r0,%r1
	lda	%r6,2(%r6)
	lda	%r7,0(%r3)

