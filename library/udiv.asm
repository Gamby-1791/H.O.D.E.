	.include "magicdefs.asm"

;
; internal divide
;
;	%r1%r0
;     /	   %r2
;	   %r0 r %r1
;
;  %r3,%r2 = unchanged
;  %r4 = zeroed
;  %r5 = return address
;
	.align	2
	.global	__udiv
__udiv:
.if RASPIMULDIV
	lda	%r6,-8(%r6)
	stw	%r0,-62(%r6)
	stw	%r1,-60(%r6)
	stw	%r2,-58(%r6)
	ldw	%r0,ss_udiv
	stw	%r0,-64(%r6)
	lda	%r1,-64(%r6)
	stw	%r1,MAGIC_SCN-SCN_UDIV(%r0)
	ldw	%r0,-62(%r6)
	ldw	%r1,-60(%r6)
	clr	%r4
	lda	%r6,8(%r6)
	lda	%pc,0(%r5)
ss_udiv: .word	SCN_UDIV
.else
	ldw	%r4,udiv__16
udiv_loop:
	shl	%r0,%r0
	rol	%r1,%r1
	bcs	udiv_fits
	cmp	%r1,%r2
	blo	udiv_next
udiv_fits:
	inc	%r0,%r0
	sub	%r1,%r1,%r2
udiv_next:
	inc	%r4,%r4
	bne	udiv_loop
	lda	%pc,0(%r5)
udiv__16: .word	-16
.endif

