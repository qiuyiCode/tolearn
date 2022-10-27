;若要使程序中的jmp指令执行后,CS:IP指向程序的第一条指令，在data段中应该定义哪些数据 ?
assume cs:code
data segment
  ; db ' ',cs:[0]
  db 3 dup (0)
data ends

code segment 
  start:
    mov ax,data
    mov ds,ax
    mov bx,0
    jmp word ptr [bx+1] ;jmp word是段内近转移,只会修改IP

code ends

end start


;补全程序,使得jmp指令执行后,CS:IP指向程序的第一条指令
; assume cs:code
; data segment
;   dd 12345678H
; data ends

; code segment

;   start:
;     mov ax,data
;     mov bx,0
;     ; mov word ptr [bx],0
;     mov word ptr [bx],bx
;     mov word ptr [bx+2],ds ;段寄存器到内存单元是允许的
;     jmp dword ptr ds:[0] ;这里的内存单元高地址位存的是CS,低地址位存的是IP

; code ends

; end start