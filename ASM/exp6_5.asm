assume cs:code
;将a段和b段中的数据依次相加，并将结果存到c段中
a segment
    db 1,2,3,4,5,6,7,8
a ends

b segment
    db 1,2,3,4,5,6,7,8
b ends

cc segment
    db 0,0,0,0,0,0,0,0
cc ends

code segment
start:
    mov ax,a
    mov ds,ax
    mov ax,b
    mov es,ax
    mov bx,0
    mov cx,8
    mov ax,0
s:  ;将a段和b段中的数据相加
    mov al,ds:[bx]
    add es:[bx],al
    inc bx
    loop s

    mov ax,cc
    mov ds,ax
    mov bx,0
    mov cx,8
s0: ;将s中相加的数据存放至c段
    mov al,es:[bx]
    mov [bx],al
    inc bx
    loop s0

    mov ax,4c00h
    int 21h
    
code ends

end start