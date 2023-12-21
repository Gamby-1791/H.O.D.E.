	.include "magicdefs.asm"

;
; shift right
;  input:
;   R0 = long address result
;   R1 = long address operand
;   R2 = shift count
;   R3 = return address
;  output:
;   R0,R4,R5 = same as on input
;   R1,R2,R3 = trashed
;
	.align	2
	.global	__shr_llW
__shr_llW:
	lda	%r6,-6(%r6)
	stw	%r5,-60(%r6)
	ldw	%r5,2(%r1)	; sign-extend result
	shl	%r5,%r5
	sbb	%r5,%r5,%r5
	br	shr_LLW_common

	.global	__shr_LLW
__shr_LLW:
	lda	%r6,-6(%r6)
	stw	%r5,-60(%r6)
	clr	%r5		; zero-extend result

shr_LLW_common:
	stw	%r3,-64(%r6)
	stw	%r4,-62(%r6)

	; build 48-bit value in R5.R4.R3
	ldw	%r3,0(%r1)
	ldw	%r4,2(%r1)

	; R2 = masked number of bits to shift by
	ldw	%r1,#31
	and	%r2,%r2,%r1

	; see if shifting at least one whole word
	lsr	%r1,%r1
	cmp	%r2,%r1
	blos	shr_LLW_small
	and	%r2,%r2,%r1
	mov	%r3,%r4
	mov	%r4,%r5
shr_LLW_small:

	; shift R5.R4.R3 right by R2 bits
	; don't shift into R5 so it keeps feeding bits
	neg	%r2,%r2
	beq	shr_LLW_done
shr_LLW_loop:
	lsr	%pc,%r5
	ror	%r4,%r4
	ror	%r3,%r3
	inc	%r2,%r2
	bne	shr_LLW_loop
shr_LLW_done:

	; store result
	stw	%r3,0(%r0)
	stw	%r4,2(%r0)

	; all done
	ldw	%r3,-64(%r6)
	ldw	%r4,-62(%r6)
	ldw	%r5,-60(%r6)
	lda	%r6,6(%r6)
	lda	%pc,0(%r3)

