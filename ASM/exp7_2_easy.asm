assume cs:codesg,ds:datasg
;用si和di实现将字符串‘welcome to masm!’复制到它后面的数据区中
datasg segment
    db 'welcome to masm!'
    db '................'
datasg ends

codesg segment
start:
    mov ax,datasg
    mov ds,ax
    ;使用si指定第一段需要移动的数据
    mov si,0
    ;使用di指定第一段数据所到达的目的地
    mov cx,8
s:
    ;(ax)=((ds)*16+(bx)+200),也可以表示为mov ax,200[bx]
    mov ax,0[si]
    mov 16[si],ax
    add si,2
    loop s

    mov ax,4c00h
    int 21h
    
codesg ends

end start