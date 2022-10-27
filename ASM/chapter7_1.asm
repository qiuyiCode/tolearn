assume cs:codesg,ds:data

data segment
    db 'unIX'
    db 'foRK'
data ends

codesg segment

start:
    mov ax,data
    mov ds,ax
    mov al,'a'
    mov bl,'b'
    mov ax,4c00h
    int 21h
codesg ends

end start