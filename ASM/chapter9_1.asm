;有如下程序段,填写两条指令,使该程序在运行中将s处的一条指令复制到s0处
assume cs:codesg

codesg segment
  s:
    mov ax,bx
    mov si,offset s
    mov di,offset s0
    ;不能内存单元 ——> 内存单元,需要通过CPU来传送数据
    ;需要明白内存单元和寄存器分别是在内存与CPU上,不能只专注于数据的传送,也要关注数据存储在哪个部分
    ;mov cs:[di],cs:[si]
    ;填入①
    mov ax,cs:[si]
    ;填入②
    mov cs:[di],ax
  s0:
    ;空指令,什么都不做,但是会占用一个指令的时间
    nop
    nop
codesg ends

end s