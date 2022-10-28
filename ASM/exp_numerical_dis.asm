assume cs:code

data segment
  dw 123,12666,1,8,3,38
data ends

string segment
  db 6 dup (0)
string ends

code segment
  start:
    mov cx,6
    mov ax,data
    mov ds,ax
    mov bx,0
    ; 将要显示数字的第一行,下面的循环中要递增dh
    mov dh,8

    s:
      push cx
      push ds
      
      mov ax,ds:[bx]
      call dtoc
      mov dl,3
      mov cl,2
      mov ax,string
      mov ds,ax
      call show_str
      inc dh
      add bx,2

      pop ds
      pop cx
    loop s

    mov ax,4c00h
    int 21h

    dtoc:
      push ax
      push bx
      push cx
      push dx
      push di
      push es

      mov si,5
      mov di,si
      mov bx,string
      mov es,bx

      get_num:
        mov dx,0
        mov bx,10
        div bx
        ; 将数字放入es段中
        add dx,48
        mov es:[di],dl
        dec di
        
        mov ch,0
        mov cl,al
        jcxz dtoc_ok
        mov si,di
        jmp short get_num

      dtoc_ok:
        pop es
        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        ret

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

      s1:
        mov ch,0
        mov cl,ds:[si]
        jcxz ok
        mov ax,ds:[si]
        mov es:[di],ax
        mov es:[di+1],dl
        add di,2
        inc si
        jmp short s1
        ok:
          pop di
          pop si
          pop es
          pop dx
          pop cx
          pop bx
          pop ax
          ret

code ends
end start