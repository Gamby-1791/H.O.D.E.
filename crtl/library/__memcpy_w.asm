; R0 = dest address
; R1 = source address
; R2 = word count
	.global	__memcpy_w
__memcpy_w:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	neg	%r2,%r2
	beq	memcpy_w_done
memcpy_w_loop:
	ldw	%r3,0(%r1)
	stw	%r3,0(%r0)
	lda	%r0,2(%r0)
	lda	%r1,2(%r1)
	inc	%r2,%r2
	bne	memcpy_w_loop
memcpy_w_done:
	ldw	%r3,-64(%r6)
	lda	%r6,2(%r6)
	lda	%r7,0(%r3)

