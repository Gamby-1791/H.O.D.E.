;;;;;;;;;;;;;;;;;
;;  Bootstrap  ;;
;;;;;;;;;;;;;;;;;

	intsaver0 = 0xFFEA
	intsaver1 = 0xFFEC
	intsaver2 = 0xFFEE
	intsaver3 = 0xFFF4
	intsaver4 = 0xFFF6
	intsaver5 = 0xFFF8
	intserv   = 0xFFFA
;
; starts at location 0
;
	.psect	.00.boot
	.global	__boot
__boot:					; used by linker to force loading this module
zeropc:	br	procreset		; processor resets here
	stw	%r0,zeropc+intsaver0	; processor interrupts here
	stw	%r1,zeropc+intsaver1
	stw	%r2,zeropc+intsaver2
	stw	%r3,zeropc+intsaver3
	stw	%r4,zeropc+intsaver4
	stw	%r5,zeropc+intsaver5
	lda	%r3,intreturn
	ldw	%pc,zeropc+intserv
intreturn:
	ldw	%r0,zeropc+intsaver0
	ldw	%r1,zeropc+intsaver1
	ldw	%r2,zeropc+intsaver2
	ldw	%r3,zeropc+intsaver3
	ldw	%r4,zeropc+intsaver4
	ldw	%r5,zeropc+intsaver5
	iret

procreset:
	lda	%r0,intreturn
	stw	%r0,zeropc+intserv
	clr	%r0
	clr	%r1
	clr	%r2
	clr	%r3
	clr	%r4
	clr	%r5
	clr	%r6
	ldw	%pc,#_start

