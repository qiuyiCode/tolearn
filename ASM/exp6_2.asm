assume cd:codesg
;实现用内存0:0~0:15单元中的内容改写程序中的数据,数据的传送用栈来进行，栈空间设置在程序内。
codesg segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
    dw 0,0,0,0,0,0,0,0,0,0 ;十个字单元的栈空间
start:
    ;定义栈段地址
    mov ax,cs
    mov ss,ax
    ;定义栈顶指针(栈由高向低增长)
    mov sp,1ah

    mov ax,0
    mov ds,ax
    mov bx,0
    mov cx,8

s:
    push [bx]
    pop cs:[bx]
    add bx,2
    loop s

    mov ax,4c00h
    int 21h

codesg ends

end start