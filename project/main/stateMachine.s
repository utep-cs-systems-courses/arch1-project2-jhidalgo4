	;; #include goes up here...
	;; ... end
/***	
	.arch msp430g2553	
	.p2align		
	
	.data 
	.global stateMachine
	.global changed		;set char to 0
changed:	.byte 0		;set changed to 0
	.p2align
	.global curState	;;import this variable from different file to control STATE
	.global led_changed 	;import led_changed variable from other c file
	.global led_update 	;import method from other c file

	;; import the 4 state finctions being called determined by switch state case
	.global state1_red
	.global state2_green
	.global state3_bothOn
	.global state4_bothOff


	
	;; Jumptable
JT:
	.word default	;0
	.word case1
	.word case2
	.word case3
	.word case4

	;; my only function "state_advance" calling the jumptable
	;; .text -> was changed to global
stateMachine:
	mov &curState, r12
	cmp #5, r12		; s-3
	jc default 		;
	add r12, r12
	push #preEnd 		;set to comeback after going to case
	mov JT(r12), r0
preEnd:
	mov &changed, &led_changed
	push #preEnd2
	mov #led_update, r0
preEnd2:
	pop r0 			;end state_advance()

	
	;; case 1
case1:
	push #ra1
	mov #state1_red, r0
ra1:
	mov r12, &changed 	; take returned from calling "state1_red" & store into changed
	pop r0

	;; case 2
case2:
	push #ra2
	mov #state2_green, r0 	; call this function
ra2:
	mov r12, &changed
	pop r0

	;; case 3
case3:
	push #ra3		;prepare to return after calling method next
	mov #state3_bothOn, r0
ra3:
	mov r12, &changed
	pop r0

	;; case 4
	
case4:
	push #ra4
	mov #state4_bothOff, r0
ra4:
	mov r12, &changed 	;return and store r12 parameter into changed
	pop r0

	;; default case
default:
	jmp esac
esac:
	pop r0			;END by default

				;end of commented part out
	
***/

	
	
