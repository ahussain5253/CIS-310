
.386
.model flat,stdcall
ExitProcess Proto, dwExitCode:DWORD

INCLUDE Irvine32.inc

.data
decNum    DWORD ?
promptBad BYTE "Invalid input, please enter again",0
.code
main PROC
read:  call ReadDec
       jnc  goodInput

       jmp  read        ;go input again

goodInput:
       mov  decNum,eax  ;store good value

	

	INVOKE ExitProcess, 0
main ENDP
END main