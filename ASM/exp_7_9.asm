assume cs:codesg,ss:stacksg,ds:datasg
;将datasg段中每个单词的前四个字母改为大写字母
stacksg segment
  dw 0,0,0,0,0,0,0,0
stacksg ends

datasg segment
  db '1. display      '
  db '2. brows        '
  db '3. replace      '
  db '4. modify       '
datasg ends

codesg segment
start:
  mov ax,stacksg
  mov ss,ax
  mov sp,16
  mov ax,datasg
  mov ds,ax
  mov bx,3 ;bx是基址
  mov cx,4 ;给s设置
s:
  push cx ;保存外层cx
  mov cx,4 ;给s0设置
  mov si,0
  s0:
    mov al,ds:[bx+si]
    and al,0dfh
    mov ds:[bx+si],al
    inc si
    loop s0
    add bx,16
    mov si,0
    pop cx
    loop s ;执行loop s,会进行两步操作:1.cx = cx - 1; 2.判断cx == 0 ?,为0则按照顺序执行下一条指令,结束循环,否则进行下一轮循环
  mov ax,4c00h
  int 21h

codesg ends

end start