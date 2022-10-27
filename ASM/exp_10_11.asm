; 编程,将data段中的字符串转化为大写
assume cs:codesg,ds:datasg

datasg segment
  db 'conversation'
datasg ends

codesg segment
start:
  mov ax,datasg
  mov ds,ax
  mov si,0
  mov cx,12
  call lower_to_upper
  mov ax,4c00h
  int 21h

  lower_to_upper:
    and byte ptr [si],11011111b
    inc si
    loop lower_to_upper
    ret

codesg ends

end start