

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword







.code
main proc

mov ax, 008h
mov bl, 2
div bl







	invoke ExitProcess, 0

main endp
end main