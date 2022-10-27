;分析下面的程序,在运行前思考,这个程序可以正确返回吗 ?
;运行后再思考,为什么是这种结果 ?
; jmp short 标号的8位位移就是:标号处的地址 - jmp指令后的第一个字节的地址
assume cs:codesg
codesg segment
  mov ax,4c00h
  int 21h
start:
  mov ax,0
  s:
    nop ;什么也不做,占一个字节
    nop

    mov di,offset s ;将s的偏移地址送入di
    mov si,offset s2 ;将s2的偏移地址送入si
    mov ax,cs:[si] ;送入jmp short s1的机器码送入ax
    mov cs:[di],ax ;将ax中存储的jmp short s1机器码送入s段

    s0:
      jmp short s

    s1:
      mov ax,0
      int 21h
      mov ax,0
    s2:
      jmp short s1 ;短转移中标号不代表实际地址,在字节码中表示的是需要跳转的距离(位移、步数)
      nop

codesg ends
end start
