assume cs:codesg,ds:datasg

datasg segment
  db 'DEC'
  db 'Ken Oslen'
  dw 89h
  dw 28h
  db 'PDP'
datasg ends

codesg segment
start:
  mov ax,datasg
  mov ds,ax
  mov bx,0

  mov word ptr [bx].0ch,38
  add word ptr [bx].0eh,70

  mov si,0
  mov byte ptr [bx].10h[si],'V'
  inc si
  mov byte ptr [bx].10h[si],'A'
  inc si
  mov byte ptr [bx].10h[si],'X'

codesg ends

end start