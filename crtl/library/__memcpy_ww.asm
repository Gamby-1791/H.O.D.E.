; R0 = dest address
; R1 = source address
; R2 = double-word count
	.global	__memcpy_ww
__memcpy_ww:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	neg	%r2,%r2
	beq	memcpy_ww_done
memcpy_ww_loop:
	ldw	%r3,0(%r1)
	stw	%r3,0(%r0)
	ldw	%r3,2(%r1)
	stw	%r3,2(%r0)
	lda	%r0,4(%r0)
	lda	%r1,4(%r1)
	inc	%r2,%r2
	bne	memcpy_ww_loop
memcpy_ww_done:
	ldw	%r3,-64(%r6)
	lda	%r6,2(%r6)
	lda	%r7,0(%r3)

