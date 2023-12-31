	.include "magicdefs.asm"

;
; internal multiply
;
;	%r3%r2
;     x	   %r1
;	%r1%r0
;
;  %r3,%r2 = unchanged
;  %r4 = zeroed
;  %r5 = return address
;
	.global	__umul
__umul:
.if RASPIMULDIV
	lda	%r6,-8(%r6)
	stw	%r2,-62(%r6)
	stw	%r3,-60(%r6)
	stw	%r1,-58(%r6)
	ldw	%r0,ss_umul
	stw	%r0,-64(%r6)
	lda	%r1,-64(%r6)
	stw	%r1,MAGIC_SCN-SCN_UMUL(%r0)
	ldw	%r0,-62(%r6)
	ldw	%r1,-60(%r6)
	clr	%r4
	lda	%r6,8(%r6)
	lda	%pc,0(%r5)
ss_umul: .word	SCN_UMUL
.else
	clr	%r0
	lda	%r4,-16(%r0)
umul_loop:
	shl	%r0,%r0
	rol	%r1,%r1
	bcc	umul_skip
	add	%r0,%r0,%r2
	adc	%r1,%r1,%r3
umul_skip:
	inc	%r4,%r4
	bne	umul_loop
	lda	%pc,0(%r5)
.endif
