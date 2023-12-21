
	.include "magicdefs.asm"

;
; modulus
;  input:
;   R1 = unsigned quad address
;   R2 = unsigned word
;  output:
;   R0 = unsigned word
;
	.align	2
	.global	__mod_WQW
__mod_WQW:
	lda	%r6,-6(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)
	stw	%r5,-60(%r6)
	mov	%r3,%r1
	ldw	%r0,6(%r3)
	clr	%r1
	lda	%r5,mod_WQW_6348
	ldw	%pc,#__udiv
mod_WQW_6348:

	ldw	%r0,4(%r3)
	lda	%r5,mod_WQW_4732
	ldw	%pc,#__udiv
mod_WQW_4732:

	ldw	%r0,2(%r3)
	lda	%r5,mod_WQW_3116
	ldw	%pc,#__udiv
mod_WQW_3116:

	ldw	%r0,0(%r3)
	lda	%r5,mod_WQW_1500
	ldw	%pc,#__udiv
mod_WQW_1500:
	mov	%r0,%r1

	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	ldw	%r5,-60(%r6)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)

