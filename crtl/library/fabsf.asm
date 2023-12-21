	.align	2
	.global	fabsf
fabsf:
	ldw	%r1,-62(%r6)
	ldw	%r0,fabsf_7FFF
	and	%r1,%r1,%r0
	ldw	%r0,-64(%r6)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)
fabsf_7FFF: .word 0x7FFF
