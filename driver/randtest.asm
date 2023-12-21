; do all arithmetics on pseudo-random numbers
; let raspictl shadow.cc check the results

	.include "../asm/magicdefs.asm"

start:
	br	loop

r4rand:	.word	0x1234
r5rand:	.word	0x5678

loop:
	ldw	%r6,r4rand
	lda	%r5,.+4
	br	dolfsr
	lda	%r5,.+4
	br	dolfsr
	stw	%r6,r4rand

	ldw	%r6,r5rand
	lda	%r5,.+4
	br	dolfsr
	lda	%r5,.+4
	br	dolfsr
	lda	%r5,.+4
	br	dolfsr
	stw	%r6,r5rand

	ldw	%r4,r4rand
	ldw	%r5,r5rand
	lsr	%r6,%r4
	rdps	%r6
	asr	%r6,%r5
	rdps	%r6
	ror	%r6,%r4
	rdps	%r6
	mov	%r6,%r5
	rdps	%r6
	neg	%r6,%r4
	rdps	%r6
	inc	%r6,%r5
	rdps	%r6
	com	%r6,%r4
	rdps	%r6
	or	%r6,%r4,%r5
	rdps	%r6
	and	%r6,%r4,%r5
	rdps	%r6
	xor	%r6,%r4,%r5
	rdps	%r6
	add	%r6,%r4,%r5
	rdps	%r6
	sub	%r6,%r4,%r5
	rdps	%r6
	adc	%r6,%r4,%r5
	rdps	%r6
	sbb	%r6,%r4,%r5
	rdps	%r6
	br	loop

dolfsr_ret:
	.word	0

dolfsr:
	stw	%r5,dolfsr_ret

	lsr	%r5,%r6
	lsr	%r5,%r5
	xor	%r4,%r6,%r5
	lsr	%r5,%r5
	xor	%r4,%r4,%r5
	lsr	%r5,%r5
	lsr	%r5,%r5
	xor	%r4,%r4,%r5

	lsr	%r4,%r4
	ror	%r6,%r6

	ldw	%pc,dolfsr_ret

