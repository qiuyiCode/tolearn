assume cs:codesg,ss:stacksg

stacksg segment
  dw 8 dup (0)
stacksg ends

codesg segment
  start:
    mov ax,stacksg
    mov ss,ax
    mov sp,10h
    ; 将dword型被除数的低16位放到ax,高16位放到dx,除数放到cx中
    mov ax,4240h
    mov dx,000fh
    mov cx,0ah

    call divdw
    mov ax,4c00h
    int 21h

    divdw:
      ; 将数据暂存到栈中
      mov si,ax
      mov di,dx

      ; 这段程序计算(H / N)  * 65536 , *65536实际上就是将乘出来的结果放入DX寄存器中,因为最后的32位结果的高16位是放在DX中的
      ; *65536实际上就是将一个十六进制数据左移4位, 65536 = 16的四次方
      mov ax,di
      mov dx,0000h
      div cx
      ; 高16位放在bx暂存
      mov bx,ax

      ; 计算X / N 公式的第二部分
      mov ax,si
      div cx

      mov cx,dx
      mov dx,bx
   
      ret
      
codesg ends
end start