assume cs:codesg,ss:stacksg,ds:datasg
; 绿色  绿底红色  白底蓝色

datasg segment
  db 'welcome to masm!'
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
  mov ax,0B872H ;汇编程序中,数字不能以字母开头
  mov es,ax
  mov bx,0
  mov si,0
  
  ;指定数据区域
  mov ax,datasg
  mov ds,ax
  mov di,0

  mov cx,10h
  green:
    mov al,ds:[di]
    mov es:[bx+si],al
    inc si
    mov al,02h
    mov es:[bx+si],al
    inc si
    inc di
    loop green

    add bx,0a0h
    ;循环初始化
    mov si,0
    mov di,0

    mov cx,10h
    red:
      mov al,ds:[di]
      mov es:[bx+si],al
      inc si
      mov al,42h
      mov es:[bx+si],al
      inc si
      inc di
      loop red

    add bx,0a0h
    ;循环初始化
    mov si,0
    mov di,0
    mov cx,10h

    blue:
      mov al,ds:[di]
      mov es:[bx+si],al
      inc si
      mov al,71h
      mov es:[bx+si],al
      inc si
      inc di
      loop blue

  mov ax,4c00h
  int 21h

codesg ends

end start


; assume cs:codesg, ds:datasg, ss:stacksg
  
; datasg segment
;         db 'welcome to masm!'
;         db 2h,24h,71h                ;三行文字的颜色
; datasg ends


; stacksg segment stack
;         db 16 dup (0)
; stacksg ends

; codesg segment

; start:
;         mov ax,datasg
;         mov ds,ax

;         mov ax,stacksg
;         mov ss,ax
;         mov sp,16

;         mov ax,0B872h
;         mov es,ax

;         mov cx,3               ;三行的显示代码是外层循环三次
;         mov bx,0               ;记录当前是第几行，也是外层循环的次数
; s:
;         push cx
;         mov cx,16               ;每行显示16个字符，内存循环16次

;         mov di,0                ;记录内存循环的次数
; s0:
;         mov al,ds:[di]           ;低字节显示文字
;         mov ah,ds:[bx+16]        ;高字节显示颜色属性
;         mov si,di
;         add si,si                ;一个文字占两个字节
;         mov es:[si],ax

;         inc di
;         loop s0

;         pop cx
;         mov ax,es
;         add ax,00ah               ;切换到下一行的位置
;         mov es,ax 
;         inc bx
;         loop s

;         mov ax,4c00h
;         int 21h

; codesg ends

; end start
