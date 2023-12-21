; R0 = points to 4-word word-aligned output
; R1 = points to 4-word word-aligned input
; R3 = return address
	.global	__memcpy_4w
__memcpy_4w:
	ldw	%r2,0(%r1)
	stw	%r2,0(%r0)
	ldw	%r2,2(%r1)
	stw	%r2,2(%r0)
	ldw	%r2,4(%r1)
	stw	%r2,4(%r0)
	ldw	%r2,6(%r1)
	stw	%r2,6(%r0)
	lda	%r7,0(%r3)

