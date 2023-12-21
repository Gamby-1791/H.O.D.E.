
	.include "magicdefs.asm"

;
; shift right
;  input:
;   R1 = signed word
;   R2 = unsigned word
;   R3 = return address
;  output:
;   R0 = signed word
;
	.align	2
	.global	__shr_wwW
__shr_wwW:
	ldw	%r0,#15
	and	%r2,%r2,%r0
	shl	%r2,%r2
	sub	%r2,%pc,%r2
shr_wwW_base:
	lda	%pc,shr_wwW_zero-shr_wwW_base(%r2)
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
	asr	%r1,%r1
shr_wwW_zero:
	mov	%r0,%r1
	lda	%pc,0(%r3)

