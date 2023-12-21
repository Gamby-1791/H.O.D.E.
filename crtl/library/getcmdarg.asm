
	.include "magicdefs.asm"

; int getcmdarg (int idx, int len, char *buf);
	.align	2
	.global	getcmdarg
getcmdarg:
	lda	%r6,-2(%r6)
	lda	%r1,-64(%r6)
	ldw	%r0,ss_getcmdarg
	stw	%r0,0(%r1)
	stw	%r1,MAGIC_SCN-SCN_GETCMDARG(%r0)
	ldw	%r0,MAGIC_SCN-SCN_GETCMDARG(%r0)
	lda	%r6,8(%r6)
	lda	%pc,0(%r3)
ss_getcmdarg: .word SCN_GETCMDARG

