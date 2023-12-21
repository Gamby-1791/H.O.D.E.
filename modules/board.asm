
	.set	magic 0xFFF0

start:
	lda	r0 printctl-.-2 r7
	stw	r0 magic-.-2 r7
halt:
	lda	r0 haltctl-.-2 r7
	stw	r0 magic-.-2 r7
	br	halt

printctl:
	.word	1
	.word	message

haltctl:
	.word	0

message:
	.ascii	the cat is fat
	.byte	0
