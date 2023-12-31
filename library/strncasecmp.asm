; int strncasecmp (char const *, char const *, size len)

	.align	2
A:	.word	'A'

	.global	strncasecmp
strncasecmp:
	lda	%r6,-6(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)
	stw	%r5,-60(%r6)
	ldw	%r2,-58(%r6)		; point to A string
	ldw	%r3,-56(%r6)		; point to B string
	ldw	%r4,A			; lowest upper case letter
	lda	%r5,26-'A'(%r4)		; number of letters
loop:
	ldw	%r0,-54(%r6)		; see if run out of room
	tst	%r0
	beq	done
	lda	%r0,-1(%r0)
	stw	%r0,-54(%r6)
	ldbs	%r0,0(%r2)		; get A character
	sub	%r0,%r0,%r4		; make it relative to 'A'
	cmp	%r0,%r5
	bhis	aok
	lda	%r0,'a'-'A'(%r0)	; update to lower case
aok:
	ldbs	%r1,0(%r3)		; get B character
	sub	%r1,%r1,%r4		; make it relative to 'A'
	cmp	%r1,%r5
	bhis	bok
	lda	%r1,'a'-'A'(%r1)	; update to lower case
bok:
	sub	%r0,%r0,%r1		; compare characters
	bne	done			; stop if different
	lda	%r2,1(%r2)
	lda	%r3,1(%r3)
	add	%r0,%r1,%r4		; check for null terminator
	bne	loop
done:
	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	ldw	%r5,-60(%r6)
	lda	%r6,12(%r6)
	lda	%pc,0(%r3)

