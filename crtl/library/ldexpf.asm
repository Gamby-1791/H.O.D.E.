
	.align	2

; float ldexpf (float x, int exp)
	ldexpf_sav3 = -64
	ldexpf_x    = -62
	ldexpf_exp  = -58

	.global	ldexpf
ldexpf:
	lda	%r6,-2(%r6)
	stw	%r3,ldexpf_sav3(%r6)

	ldw	%r0,ldexpf_x+0(%r6)	; get float value
	ldw	%r1,ldexpf_x+2(%r6)

	ldw	%r2,#0x7F80		; extract exponent
	and	%r3,%r2,%r1
	bne	ldexpf_normal
	shl	%r0,%r0
	rol	%r1,%r1
	or	%pc,%r0,%r1
	bne	ldexpf_addexp
	ror	%r1,%r1
	br	ldexpf_return
ldexpf_normal:
	cmp	%r3,%r2			; check non-finite exponent
	beq	ldexpf_return		; - if so, return value as is
	sub	%r1,%r1,%r3		; normal, remove exponent
	ldw	%r2,#0x80		; insert hidden bit
	add	%r1,%r1,%r2

ldexpf_addexp:
	asr	%r3,%r3			; shift for adding
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	ldw	%r2,ldexpf_exp(%r6)	; add given exponent
	add	%r3,%r3,%r2
	ble	ldexpf_subnor		; - so small it is subnormal or zero
	ldw	%r2,#0x80		; shift to get hidden bit
ldexpf_normlize:
	and	%pc,%r1,%r2
	bne	ldexpf_normlizd
	shl	%r0,%r0
	rol	%r1,%r1
	lda	%r3,-1(%r3)
	tst	%r3
	bgt	ldexpf_normlize
	lsr	%r1,%r1			; exponent went zero looking for hidden bit,
	ror	%r0,%r0			; ... result is subnormal
	br	ldexpf_retsign
ldexpf_normlizd:
	sub	%r1,%r1,%r2		; found hidden bit, remove it
	ldw	%r2,#0xFF		; check for exponent too big
	cmp	%r3,%r2
	bge	ldexpf_retinf		; - if so, return infinity
	shl	%r3,%r3			; insert non-zero (normal) exponent
	shl	%r3,%r3
	shl	%r3,%r3
	shl	%r3,%r3
	shl	%r3,%r3
	shl	%r3,%r3
	shl	%r3,%r3
	or	%r1,%r1,%r3
	br	ldexpf_retsign

ldexpf_subnor:
	beq	ldexpf_subnormz
	ldw	%r2,#-23		; subnormal, see if too small
	cmp	%r3,%r2
	blo	ldexpf_retzero		; - yes unsigned, pos %r3 means add above underflowed
ldexpf_subnormz:
	shl	%r1,%r1			; clear sign bit
	lsr	%r1,%r1
ldexpf_subnorml:
	lsr	%r1,%r1			; shift subnormals in place
	ror	%r0,%r0
	inc	%r3,%r3
	ble	ldexpf_subnorml
	br	ldexpf_retsign		; put sign bit back
ldexpf_retinf:
	ldw	%r1,#0x7F80
	br	ldexpf_retloz
ldexpf_retzero:
	clr	%r1
ldexpf_retloz:
	clr	%r0
ldexpf_retsign:
	ldw	%r2,ldexpf_x+2(%r6)
	shl	%r1,%r1
	shl	%r2,%r2
	ror	%r1,%r1
ldexpf_return:
	ldw	%r3,ldexpf_sav3(%r6)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
