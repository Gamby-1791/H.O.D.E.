; divide
;  input:
;   R1 = signed word
;   R2 = signed word
;   R3 = return address
;  output:
;   R0 = signed word
;   R1,R2,R3 = trashed
;   R4,R5 = as on input
;
	.align	2
	.global	__div_www
__div_www:
	lda	%r6,-6(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)
	stw	%r5,-60(%r6)
	mov	%r3,%r1
	mov	%r0,%r1
	bpl	div_www_posr1
	neg	%r0,%r1
div_www_posr1:
	tst	%r2
	bpl	div_www_posr2
	com	%r3,%r3
	neg	%r2,%r2
div_www_posr2:
	clr	%r1
	lda	%r5,div_www_subret
	ldw	%pc,#__udiv
div_www_subret:
	tst	%r3
	bpl	div_www_posr0
	neg	%r0,%r0
div_www_posr0:
	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	stw	%r5,-60(%r6)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)
