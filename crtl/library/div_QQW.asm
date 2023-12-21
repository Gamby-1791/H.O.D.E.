; divide
;  input:
;   R0 = unsigned quad address
;   R1 = unsigned quad address
;   R2 = unsigned word
;  output:
;   R0 = same as input
;
	.align	2
	.global	__div_QQW
__div_QQW:
	lda	%r6,-10(%r6)
	stw	%r0,-64(%r6)
	stw	%r1,-62(%r6)
	stw	%r3,-60(%r6)
	stw	%r4,-58(%r6)
	stw	%r5,-56(%r6)

	ldw	%r0,6(%r1)
	clr	%r1
	lda	%r5,div_QQW_6348
	ldw	%pc,#__udiv
div_QQW_6348:
	ldw	%r3,-64(%r6)
	stw	%r0,6(%r3)

	ldw	%r3,-62(%r6)
	ldw	%r0,4(%r3)
	lda	%r5,div_QQW_4732
	ldw	%pc,#__udiv
div_QQW_4732:
	ldw	%r3,-64(%r6)
	stw	%r0,4(%r3)

	ldw	%r3,-62(%r6)
	ldw	%r0,2(%r3)
	lda	%r5,div_QQW_3116
	ldw	%pc,#__udiv
div_QQW_3116:
	ldw	%r3,-64(%r6)
	stw	%r0,2(%r3)

	ldw	%r3,-62(%r6)
	ldw	%r0,0(%r3)
	lda	%r5,div_QQW_1500
	ldw	%pc,#__udiv
div_QQW_1500:
	ldw	%r3,-64(%r6)
	stw	%r0,0(%r3)

	ldw	%r0,-64(%r6)
	ldw	%r3,-60(%r6)
	ldw	%r4,-58(%r6)
	ldw	%r5,-56(%r6)
	lda	%r6,10(%r6)
	lda	%pc,0(%r3)
