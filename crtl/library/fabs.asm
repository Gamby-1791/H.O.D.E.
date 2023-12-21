	.align	2
	.global	fabs
fabs:
	ldw	%r2,-64(%r6)
	ldw	%r1,-62(%r6)
	stw	%r1,0(%r2)
	ldw	%r1,-60(%r6)
	stw	%r1,2(%r2)
	ldw	%r1,-58(%r6)
	stw	%r1,4(%r2)
	ldw	%r1,-56(%r6)
	ldw	%r0,fabs_7FFF
	and	%r1,%r1,%r0
	stw	%r1,6(%r2)
	lda	%r6,10(%r6)
	lda	%pc,0(%r3)
fabs_7FFF: .word 0x7FFF
