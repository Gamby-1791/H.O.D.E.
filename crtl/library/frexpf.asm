
	.align	2

; float frexpf (float x, int *exp)
	frexpf_sav3 = -64
	frexpf_x    = -62
	frexpf_exp  = -58

	.global	frexpf
frexpf:
	lda	%r6,-2(%r6)
	stw	%r3,frexpf_sav3(%r6)

	ldw	%r0,frexpf_x+0(%r6)	; get float value
	ldw	%r1,frexpf_x+2(%r6)

	ldw	%r2,#0x7F80		; extract exponent
	and	%r3,%r2,%r1
	beq	frexpf_subnor		; - subnormal
	cmp	%r3,%r2			; check non-finite exponent
	beq	frexpf_retzex		; - if so, return value as is

	ldw	%r2,#0x3F00		; normal exponent, remove bias
	sub	%r3,%r3,%r2

	sub	%r1,%r1,%r3		; remove exponent from float but leave bias in float

	asr	%r3,%r3			; return unbiased/unshifted exponent to caller
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3
	asr	%r3,%r3

frexpf_retexp:
	ldw	%r2,frexpf_exp(%r6)
	stw	%r3,0(%r2)
	ldw	%r3,frexpf_sav3(%r6)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)

frexpf_retzex:
	clr	%r3
	br	frexpf_retexp

frexpf_subnor:
	shl	%r3,%r1			; subnormal, check for zero value
	or	%r3,%r3,%r0
	beq	frexpf_retexp		; - if so, return value as is
	ldw	%r3,#-125		; non-zero subnormal, set up exponent
	ldw	%r2,#0x80		; shift left until hidden bit gets set
frexpf_subloop:
	lda	%r3,-1(%r3)
	shl	%r0,%r0
	rol	%r1,%r1
	cmp	%r1,%r2
	blo	frexpf_subloop
	sub	%r1,%r1,%r2		; strip out hidden bit
	ldw	%r2,frexpf_x+2(%r6)	; re-insert sign bit
	shl	%r1,%r1
	shl	%r2,%r2
	ror	%r1,%r1
	ldw	%r2,#0x3F00		; insert biased exponent in float
	or	%r1,%r1,%r2
	br	frexpf_retexp
