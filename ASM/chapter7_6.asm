;将datasg中的第一个字符串转化为大写，第二个字符串转化为小写

assume cs:codesg,ds:datasg

datasg segment
    db 'BaSiC'
    db 'MinIX'
datasg ends

codesg segment
start:
    mov ax,datasg
    mov ds,ax
    mov bx,0
    mov cx,5
s:
    mov al,[bx]
    and al,0dfh
    mov [bx],al
    mov al,[bx+5]
    or al,20h
    mov [bx+5],al
    inc bx
    loop s

    mov ax,4c00h
    int 21h

codesg ends
end start