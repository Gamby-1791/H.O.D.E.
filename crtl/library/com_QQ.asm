; complement quadword
;  input:
;   R0 = points to output quadword
;   R1 = points to input quadword
;   R3 = return address
;  output:
;   R0,R4,R5 = as on input
;   R1,R2,R3 = trashed
;
	.align	2
	.global	__com_QQ
__com_QQ:
	ldw	%r2,0(%r1)
	com	%r2,%r2
	stw	%r2,0(%r0)
	ldw	%r2,2(%r1)
	com	%r2,%r2
	stw	%r2,2(%r0)
	ldw	%r2,4(%r1)
	com	%r2,%r2
	stw	%r2,4(%r0)
	ldw	%r2,6(%r1)
	com	%r2,%r2
	stw	%r2,6(%r0)
	lda	%pc,0(%r3)
