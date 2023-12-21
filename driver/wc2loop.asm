; test that a worst-case lsof address calculation can reach raspi
; by end of cycle when raspi takes gpio sample before raising clock

; time ./raspictl.armv7l -cpuhz 77000 -mintimes -oddok wc2loop.hex

start:
	lda	%r0,start-1	; r0 = FFFF
	lda	%r1,start+1	; r1 = 0001

	ldw	%r6,loop+0	; copy loop to FFFF
	stw	%r6,start-1
	ldw	%r6,loop+2
	stw	%r6,start+1
	ldw	%r6,loop+4
	stw	%r6,start+3
	ldw	%r6,loop+6
	stw	%r6,start+5

	lda	%pc,start-1	; jump to FFFF

loop:
	ldw	%r6,loop+1	; FFFF: MA = pc=0001 + lsof=FFFF
	ldw	%r6,1(%r0)	; 0001: MA = r0=FFFF + lsof=0001
	ldw	%r6,0-1(%r1)	; 0003: MA = r1=0001 + lsof=FFFF
	br	loop		; 0005

