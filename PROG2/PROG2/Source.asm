
INCLUDE Irvine32.inc

.data

   ;define Raw data as a WORD

   array WORD 10, 12, 8, 17, 9, 22, 18, 11, 23, 7, 30, 22, 19, 60, 71

   printMean BYTE "MEAN ", 0

   printVariance BYTE "VAR ", 0

.code
main PROC

       mov ecx,(LENGTHOF array) ; loop counter

       mov esi,OFFSET array    ; esi = 0 index value

       mov ebx, 0

       ;define the loop to find the sum of array elements value

       Sum:

              movzx eax, byte ptr[esi] ;get the value from the array

              add ebx, eax             ;add the values of the array

              mov eax, ebx             

              add esi,2              ;increament esi by 2 for WORD array

              loop Sum          ; go to Sum repeat until cl=0

       mov edx, OFFSET printMean ;print the mean string

       call WriteString

       mov ecx, (LENGTHOF array) ;get the length of the array

       cdq

       idiv ecx                ;find Mean value mean = sum/length of the array

       call WriteDec              ;print the mean value

    call Crlf

      

       mov edx, eax           ; assign eax value to edx. edx = mean

       mov ecx,(LENGTHOF array) ; loop counter

       mov esi,OFFSET array    ; esi = 0 index value

       mov ebx, 0

       ;define loop to find the variance

       Variance:

              movzx eax, byte ptr[esi] ;get the value from the array

              sub eax, edx             ;subtract mean value from eax value

              imul eax, eax            ; find the square value

              add ebx,eax              ;find the sum

              mov eax, ebx  

              add esi,2              ;increament esi by 2 for WORD array

              loop Variance          ; go to Variance repeat until cl=0

       mov edx, OFFSET printVariance ;print the Variance string

       call WriteString

       mov ecx, (LENGTHOF array) ;get the length of the array

       cdq

       idiv ecx        ;find the Variance value

       call WriteDec   ;prints the Variance value

    call Crlf

exit

main ENDP

End main