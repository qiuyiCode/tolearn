assume cd:codesg
;实现用内存0:0~0:15单元中的内容改写程序中的数据
codesg segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h

start:
    ;定义数据段地址ds
    mov ax,0
    mov ds,ax
    ;定义偏移地址bx和循环所需的参数cx
    mov bx,0
    mov cx,8

s:
    mov ax,ds:[bx]
    mov cs:[bx],ax
    add bx,2
    loop s

    mov ax,4c00h
    int 21h

codesg ends

end start