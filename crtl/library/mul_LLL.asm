
	.include "magicdefs.asm"

;
; multiply
;  input:
;   R0 = unsigned long address
;   R1 = unsigned long address
;   R2 = unsigned long address
;   R3 = return address
;  output:
;   R0,R4,R5 = same as on input
;   R1,R2,R3 = trashed
;
;  stack:
;   -64 : input R0
;   -62 : input R1
;   -60 : top word partial product
;   -58 : input R3
;   -56 : input R4
;   -54 : input R5
;
	.align	2
	.global	__mul_LLL
__mul_LLL:
	lda	%r6,-12(%r6)
	stw	%r0,-64(%r6)
	stw	%r1,-62(%r6)
	stw	%r3,-58(%r6)
	stw	%r4,-56(%r6)
	stw	%r5,-54(%r6)

	ldw	%r3,2(%r2)	; get multiplier in R3R2
	ldw	%r2,0(%r2)

	ldw	%r1,2(%r1)	; R1R0 = multiplier * high multiplicand
	lda	%r5,mul_LLL_hi
	ldw	%pc,#__umul
mul_LLL_hi:
	stw	%r1,-60(%r6)	; save high result

	ldw	%r1,-62(%r6)	; R1R0 = multiplier * low multiplicand
	ldw	%r1,0(%r1)
	lda	%r5,mul_LLL_lo
	ldw	%pc,#__umul
mul_LLL_lo:
	mov	%r2,%r0		; save low result
	ldw	%r0,-60(%r6)	; add two high results
	add	%r1,%r1,%r0

	ldw	%r0,-64(%r6)	; store result
	stw	%r2,0(%r0)
	stw	%r1,2(%r0)

	ldw	%r3,-58(%r6)	; restore and return
	ldw	%r4,-56(%r6)
	ldw	%r5,-54(%r6)
	lda	%r6,12(%r6)
	lda	%pc,0(%r3)
