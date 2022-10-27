assume cs:codesg,ds:datasg
;将data段中每个单词都改为大写
datasg segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
    dw 0 ;开辟个字的内存单元用来存储外层循环的cx
datasg ends

codesg segment
start:
    mov ax,datasg
    mov ds,ax
    mov bx,0
    mov cx,4
s: 
    ; 这种方式虽然不用过多占用寄存器资源,但是如果需要保存多个数据的时候,
    ; 必须要记住数据放到了哪个单元里,这样的话程序容易混乱
    ; 用内存来暂存数据是确定的了,需要使用栈来让数据存储的方式更加清晰
    mov ds:[40h],cx
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
    mov cx,ds:[40h]
    loop s
    mov ax,4c00h
    int 21h
codesg ends

end start

