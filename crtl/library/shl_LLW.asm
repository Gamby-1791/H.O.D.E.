	.include "magicdefs.asm"

;
; shift left
;  input:
;   R0 = long address result
;   R1 = long address operand
;   R2 = shift count
;   R3 = return address
;  output:
;   R0,R4,R5 = same as on input
;   R1,R2,R3 = trashed
;
	.global	__shl_llB
	.global	__shl_llW
	.global	__shl_LLB
	.global	__shl_LLW
__shl_llB:
__shl_llW:
__shl_LLB:
__shl_LLW:
	lda	%r6,-4(%r6)
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)

	; build 32-bit value in R4.R3
	ldw	%r3,0(%r1)
	ldw	%r4,2(%r1)

	; R2 = masked number of bits to shift by
	ldw	%r1,#31
	and	%r2,%r2,%r1

	; see if shifting at least one whole word
	lsr	%r1,%r1
	cmp	%r2,%r1
	blos	shl_LLW_small
	and	%r2,%r2,%r1
	mov	%r4,%r3
	clr	%r3
shl_LLW_small:

	; shift R4.R3 left by R2 bits
	neg	%r2,%r2
	beq	shl_LLW_done
shl_LLW_loop:
	shl	%r3,%r3
	rol	%r4,%r4
	inc	%r2,%r2
	bne	shl_LLW_loop
shl_LLW_done:

	; store result
	stw	%r3,0(%r0)
	stw	%r4,2(%r0)

	; all done
	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	lda	%r6,4(%r6)
	lda	%pc,0(%r3)

