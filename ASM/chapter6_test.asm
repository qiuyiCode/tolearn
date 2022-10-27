assume cs:codesg

codesg segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

start:
    ;定义栈段
    mov ax,cs
    mov ss,ax
    ;栈指针 8*2 = 10h , 16*2=20h
    mov sp,30h
    ;内存单元和循环变量
    mov bx,0  
    mov cx,8

s:
    push cs:[bx];入栈
    add bx,2
    loop s

    mov bx,0
    mov cx,8
      
s0:
    pop cs:[bx]
    add bx,2
    loop s0

    mov ax,4c00h
    int 21h

codesg ends

end start