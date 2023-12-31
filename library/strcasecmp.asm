; int strcasecmp (char const *, char const *)
	.align	2
	.global	strcasecmp
strcasecmp:
	lda	%r6,-6(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)
	stw	%r5,-60(%r6)
	ldw	%r2,-58(%r6)		; point to A string
	ldw	%r3,-56(%r6)		; point to B string
	ldw	%r4,strcasecmp_A	; lowest upper case letter
	lda	%r5,26-'A'(%r4)		; number of letters
strcasecmp_loop:
	ldbs	%r0,0(%r2)		; get A character
	sub	%r0,%r0,%r4		; make it relative to 'A'
	cmp	%r0,%r5
	bhis	strcasecmp_aok
	lda	%r0,'a'-'A'(%r0)	; update to lower case
strcasecmp_aok:
	ldbs	%r1,0(%r3)		; get B character
	sub	%r1,%r1,%r4		; make it relative to 'A'
	cmp	%r1,%r5
	bhis	strcasecmp_bok
	lda	%r1,'a'-'A'(%r1)	; update to lower case
strcasecmp_bok:
	sub	%r0,%r0,%r1		; compare characters
	bne	strcasecmp_done		; stop if different
	lda	%r2,1(%r2)
	lda	%r3,1(%r3)
	add	%r0,%r1,%r4		; check for null terminator
	bne	strcasecmp_loop
strcasecmp_done:
	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	ldw	%r5,-60(%r6)
	lda	%r6,10(%r6)
	lda	%pc,0(%r3)
strcasecmp_A: .word 'A'

