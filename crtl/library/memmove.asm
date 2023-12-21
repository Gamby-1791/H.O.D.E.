; void memmove (char *, char const *, int)
	.align	2
	.global	memmove
memmove:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	ldw	%r0,-62(%r6)
	ldw	%r1,-60(%r6)
	ldw	%r2,-58(%r6)
	cmp	%r0,%r1
	beq	memmove_done
	blo	memmove_fwd
	add	%r0,%r0,%r2
	add	%r1,%r1,%r2
	or	%r3,%r0,%r1
	or	%r3,%r3,%r2
	lsr	%r3,%r3
	bcc	memmove_w
	neg	%r2,%r2
	beq	memmove_done
memmove_loop:
	lda	%r1,-1(%r1)
	lda	%r0,-1(%r0)
	ldbu	%r3,0(%r1)
	stb	%r3,0(%r0)
	inc	%r2,%r2
	bne	memmove_loop
memmove_done:
	ldw	%r3,-64(%r6)
	lda	%r6,8(%r6)
	lda	%r7,0(%r3)
memmove_w:
	lsr	%r2,%r2
	neg	%r2,%r2
	beq	memmove_w_done
memmove_w_loop:
	lda	%r1,-2(%r1)
	lda	%r0,-2(%r0)
	ldw	%r3,0(%r1)
	stw	%r3,0(%r0)
	inc	%r2,%r2
	bne	memmove_w_loop
memmove_w_done:
	ldw	%r3,-64(%r6)
	lda	%r6,8(%r6)
	lda	%r7,0(%r3)
memmove_fwd:
	lda	%r6,8(%r6)
	ldw	%pc,#__memcpy

