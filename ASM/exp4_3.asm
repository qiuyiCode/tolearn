assume cs:codesg
codesg segment
;将mov ax,4c00h之前的指令复制到内存0:200处
;补全
    mov ax,cs
    mov ds,ax
    mov ax,0020h
    mov es,ax
    mov bx,0
;补全
    mov cx,17h
  s:mov al,[bx]
    mov es:[bx],al
    inc bx
    loop s
    mov ax,4c00h
    int 21h
codesg ends

end
