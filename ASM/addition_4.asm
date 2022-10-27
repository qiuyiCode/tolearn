assume cs:codesg,ds:datasg

datasg segment
  dw 1,3,0
datasg ends

codesg segment
  start:
    mov ax,datasg
    mov ds,ax
    mov ax,ds:[0]
    push ax
    mov ax,ds:[2]
    push ax
    call cube
    mov ax,4c00h
    int 21h
  cube:
    push bp
    mov bp,sp
    mov ax,[bp+4]
    sub ax,[bp+6] ;sub a,b -> a = a - b
    mov bp,ax
    mul bp
    mul bp
    mov ds:[4],ax
    pop bp
    ret 4 ;ret n的含义用汇编语法描述为: pop ip,add sp,n
codesg ends
end start