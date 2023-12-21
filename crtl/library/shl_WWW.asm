	.include "magicdefs.asm"

;
; shift left
;  input:
;   R1 = unsigned word
;   R2 = unsigned word
;   R3 = return address
;  output:
;   R0 = unsigned word
;
	.align	2
	.global	__shl_WWW
	.global	__shl_WwW
	.global	__shl_wWW
	.global	__shl_wwW
__shl_WWW:
__shl_WwW:
__shl_wWW:
__shl_wwW:
	ldw	%r0,#15
	and	%r2,%r2,%r0
	shl	%r2,%r2
	sub	%r2,%pc,%r2
shl_WWW_base:
	lda	%pc,shl_WWW_zero-shl_WWW_base(%r2)
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
	shl	%r1,%r1
shl_WWW_zero:
	mov	%r0,%r1
	lda	%pc,0(%r3)

