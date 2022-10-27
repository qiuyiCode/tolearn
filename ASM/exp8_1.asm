assume cs:codesg,ds:datasg

datasg segment
  dd 100001
  dw 100
  dd 0
datasg ends

codesg segment

start:
  mov ax,datasg
  mov ds,ax
  mov ax,ds:[0]
  mov dx,ds:[2]
  mov bx,ds:[4]
  div word ptr bx
  mov ds:[6],ax

codesg ends

end start