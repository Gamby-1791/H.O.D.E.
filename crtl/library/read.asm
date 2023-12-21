	.include "magicdefs.asm"

; int16 read (int16, void *, int16)
	.align	2
	.global	read
read:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_read
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_READ(%r0)
	ldw	%r0,MAGIC_SCN-SCN_READ(%r0)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
ss_read: .word	SCN_READ

