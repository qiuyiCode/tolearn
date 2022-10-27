assume cs:codesg,ds:datasg
;将data段中每个单词的头一个字母都改为大写
datasg segment
    db '1. file         '
    db '2. edit         '
    db '3. search       '
    db '4. view         '
    db '5. options      '
    db '6. help         '
datasg ends

codesg segment
start:
    mov ax,datasg
    mov ds,ax
    ;常量3用来定位每个需要转换为大写的小写字母
    mov cx,6
    mov bx,0
s:
    mov al,[3+bx]
    and al,0dfh
    mov [3+bx],al
    add bx,10h
    loop s
    mov ax,4c00h
    int 21h
codesg ends

end start

