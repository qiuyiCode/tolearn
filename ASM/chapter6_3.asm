assume cs:codesg,ds:data,ss:stack.
;数据段
data segment
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
data ends
;栈段
stack segment
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
stack ends
;代码段
codesg segment
start:
    ;定义栈段
    mov ax,stack
    mov ss,ax
    ;栈指针 8*2 = 10h , 16*2=20h
    mov sp,20h
    ;定义数据段
    mov ax,data
    mov ds,ax

    mov bx,0
    mov cx,8

s:
    push [bx];入栈
    add bx,2
    loop s

    mov bx,0
    mov cx,8
      
s0:
    pop [bx]
    add bx,2
    loop s0

    mov ax,4c00h
    int 21h

codesg ends
