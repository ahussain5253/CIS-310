

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
A DWORD 30
B DWORD 20
C1 DWORD 10
D DWORD 5

finalsum DWORD ?

.code
main PROC


	mov eax,A
	mov ebx,B
	mov ecx,C1
	mov edx,D

;Main program executions

	add eax,ebx
	add ecx,edx
	sub eax,ecx
	mov finalsum,eax




	INVOKE ExitProcess, 0
main ENDP
END main