; 将data段中的字符串全部转化为大写

assume cs:codesg,ds:datasg

datasg segment
  db 'word',0
  db 'unix',0
  db 'wind',0
  db 'good',0
datasg ends

codesg segment
start:
  mov ax,datasg
  mov ds,ax
  mov bx,0
  mov cx,4
  s:
    mov si,0
    ;push cx 如果在这里将cx压栈,那么会导致cx在IP下
    call capital
    add bx,5
    loop s

  mov ax,4c00h
  int 21h

  capital: ; 每次子程序开始将cx存入栈
    push cx
    change:
      mov ch,0
      mov cl,[bx+si]
      jcxz ok
      and byte ptr[bx+si],11011111b
      inc si
      jmp short change
    ok:
      pop cx
      ret
      
codesg ends
end start