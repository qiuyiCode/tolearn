; ;补全程序,利用jcxz指令,实现在内存2000h段中查找第一个值为0的字节,找到后,将它的偏移地址存储在dx中
; assume cs:code

; code segment
;   start:
;     mov ax,2000h
;     mov ds,ax
;     mov bx,0
;     s:
;       mov cl,ds:[bx]
;       mov ch,0 ;因为jcxz的执行判断条件是cx == 0,所以要保证整个cx的低位与高位都是0
;       jcxz ok
;       add bx,1
;       jmp short s
;     ok:
;       mov dx,bx
;       mov ax,4c00h
;       int 21h
; code ends
; end start


;补全程序,利用loop指令,实现在内存2000H段中查找第一个值为0的字节,找到后,将它的偏移地址存储在dx中
assume cs:code
code segment
  start:
    mov ax,2000h
    mov ds,ax
    mov bx,0
    s:
      mov cl,ds:[bx]
      mov ch,0
      inc cx
      inc bx ;因为ok段有一个dec bx,所以这个当cx == 0时候,这条指令也会执行,loop s会进行cx = cx - 1,所以添加inc cx
      loop s
    ok:
      dec bx
      mov dx,bx
      mov ax,4c00h
      int 21h
code ends
end start
