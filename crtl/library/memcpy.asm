; void memcpy (char *, char const *, int)
	.align	2
	.global	memcpy
memcpy:
	ldw	%r0,-64(%r6)
	ldw	%r1,-62(%r6)
	ldw	%r2,-60(%r6)
	lda	%r6,6(%r6)
	ldw	%pc,#__memcpy

