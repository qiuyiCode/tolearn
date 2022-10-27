; 显示颜色的区域在B8000H ~ BFFFFH
assume cs:codesg,ds:datasg

datasg segment
  db 'Welcome to masm!',0
datasg ends

codesg segment
  start:
    mov ax,datasg
    mov ds,ax
    mov dh,7
    mov dl,9
    mov cl,2
    mov si,0
    call show_str
    mov ax,4c00h
    int 21h
    show_str:
      ;执行子程序之前,将寄存器的值保存下来
      push ax
      push bx
      push cx
      push dx
      push es
      push si
      push di

      ; 计算需要显示颜色的区域,可以用偏移地址定位当前需要显示区域的地址

      mov ax,0b800h
      mov es,ax
      
      ; 使用行数计算偏移地址(行数最多24,字节数为160.均小于255,al存储一个乘数,一个八位寄存器或者八位内存单元存储另一个单元)
      mov al,dh
      mov ah,0
      mov bl,160
      mul bl
      mov di,ax

      ; 使用列数计算偏移地址
      mov al,dl
      mov ah,0
      mov bl,2
      mul bl
      add di,ax
      mov dl,cl

      s:
        push cx
        mov ch,0
        mov cl,ds:[si]
        jcxz ok
        pop cx
        mov ax,ds:[si]
        mov es:[di],ax
        mov es:[di+1],dl
        add di,2
        inc si
        jmp short s
        ok:
          pop di
          pop si
          pop es
          pop dx
          pop cx
          pop bx
          pop ax
          ret
    
codesg ends 
end start