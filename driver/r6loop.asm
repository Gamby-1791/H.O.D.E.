
	.include "../asm/magicdefs.asm"

start:
	clr	%r6
loop:
	inc	%r6,%r6
	stw	%r6,temp
	bne	loop
	lda	%r6,printctl
	stw	%r6,start+MAGIC_SCN
	br	start

temp:	.word	0

printctl:
	.word	SCN_PRINTLN
	.word	message
message: .asciz "pass complete"

