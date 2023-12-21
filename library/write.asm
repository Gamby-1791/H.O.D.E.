	.include "magicdefs.asm"

; int16 write (int16, void const *, int16)
	.align	2
	.global	write
write:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_write
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_WRITE(%r0)
	ldw	%r0,MAGIC_SCN-SCN_WRITE(%r0)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
ss_write: .word	SCN_WRITE

