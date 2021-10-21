

INCLUDE Irvine32.inc

.data

	promptFirst BYTE "Enter a number from 0 - 100: ", 0
	promptScore BYTE "SCORE ", 0
	promptGrade BYTE "GRADE ", 0
   


.code
main PROC

	mov edx, offset promptFirst
	call writestring

	call readint

	call crlf

	mov edx, offset promptScore
	call writestring
	call writedec

	.IF al >= 90
		mov al, 'A'

	.ELSEIF al >= 80
		mov al, 'B'

	.ELSEIF al >= 70
		mov al, 'C'

	.ELSEIF al >= 60
		mov al, 'D'

	.ELSEIF al < 60
		mov al, 'E'

	.ENDIF

	call crlf

	mov edx, offset promptGrade
	call writestring
	call writechar

	call crlf


	INVOKE ExitProcess, 0
main ENDP
END main