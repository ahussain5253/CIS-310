

INCLUDE Irvine32.inc

.data
	prompt byte "Please enter a number from 0 - 100: "
    decNum BYTE ?
	grade BYTE ?
   


.code
main PROC

	mov edx, offset prompt
	call writestring

	call readint
	mov decNum, al

	.IF decNUM > 90
		mov al, 'A'
	.ENDIF




	

	INVOKE ExitProcess, 0
main ENDP
END main