assume cs:codesg,ss:stacksg,ds:datasg
; 绿色  绿底红色  白底蓝色

datasg segment
  db 'welcome to masm!'
  db 02h,24h,71h
datasg ends

stacksg segment
  dw 8 dup (0)
stacksg ends

codesg segment
start:
  ;定义栈段
  mov ax,stacksg
  mov ss,ax
  mov sp,10h ;栈顶

  ;指定写入数据的区域
  mov ax,0B872H ;显示在第一页的中间位置
  mov es,ax
  mov si,0
  
  ;指定数据区域
  mov ax,datasg
  mov ds,ax
  mov bx,0
  mov di,0

  mov cx,3
  s:
    push cx
    mov cx,10h
    s0:
    mov al,ds:[di]
    mov ah,ds:[bx+10h]
    mov es:[si],ax
    add si,2
    inc di
    loop s0
    
    mov ax,es
    add ax,00ah ;段地址增加160个字节,跳转到下一行,160 = 0a0h,则只需要增加00ah,寻址时会乘16
    mov es,ax
    ;循环初始化
    mov si,0
    mov di,0
    inc bx
    pop cx
    loop s

  mov ax,4c00h
  int 21h

codesg ends

end start
