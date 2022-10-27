assume cs:codesg,ds:datasg
;将data段中每个单词都改为大写
datasg segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
datasg ends

codesg segment
start:
    mov ax,datasg
    mov ds,ax
    mov bx,0
    mov cx,4
s: 
    ;用dx存储cx中的数据不好,因为循环中可能有对于dx寄存器的使用,因此请看exp7_7_improve
    mov dx,cx
    mov cx,3
    mov si,0
s0:
    ;bx定位行,si定位列,[bx+si]联合定位行列
    mov al,[bx+si]
    and al,0dfh
    mov [bx+si],al
    inc si
    loop s0
    add bx,10h
    mov cx,dx
    loop s
    mov ax,4c00h
    int 21h
codesg ends

end start

