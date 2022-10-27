assume cs:codesg

codesg segment
;设定数据段地址ds
    mov ax,0020h
    mov ds,ax
;设定循环需要的参数bx和循环次数cx
    mov bx,0
    mov cx,40h
;循环
  s:mov ds:[bx],bl
    inc bx
    loop s
;程序返回
    mov ax,4c00h
    int 21h
codesg ends

end