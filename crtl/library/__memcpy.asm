; R0 = dest address
; R1 = source address
; R2 = byte count
; R3 = return address
	.global	__memcpy
__memcpy:
	lda	%r6,-2(%r6)
	stw	%r3,-64(%r6)
	neg	%r2,%r2
	beq	memcpy_done
memcpy_loop:
	ldbu	%r3,0(%r1)
	stb	%r3,0(%r0)
	lda	%r0,1(%r0)
	lda	%r1,1(%r1)
	inc	%r2,%r2
	bne	memcpy_loop
memcpy_done:
	ldw	%r3,-64(%r6)
	lda	%r6,2(%r6)
	lda	%r7,0(%r3)

