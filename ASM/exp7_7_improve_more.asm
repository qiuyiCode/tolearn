assume cs:codesg,ds:datasg,ss:stacksg
;将data段中每个单词都改为大写
datasg segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
datasg ends

;使用一个栈来暂存cx中的数据
stacksg segment
  dw 0,0,0,0,0,0,0,0
stacksg ends

codesg segment
start:
    mov ax,stacksg
    mov ss,ax
    mov sp,16 ; 之所以定义16,是因为栈段有16个字节,对数据而言是针对字节进行计算的
    mov ax,datasg
    mov ds,ax
    mov bx,0
    mov cx,4
s: 
    push cx
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
    pop cx
    loop s
    mov ax,4c00h
    int 21h
codesg ends

end start

