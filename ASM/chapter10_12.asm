assume cs:codesg,ds:datasg

datasg segment
  db 'conversation',0
datasg ends

codesg segment
  start:
    mov ax,datasg
    mov ds,ax
    mov si,0
    call capital
    mov ax,4c00h
    int 21h

    capital:
      mov ch,0
      mov cl,ds:[si]
      jcxz ok  ;jump if cx is zero
      and byte ptr [si],11011111b
      inc si
      call capital

    ok:ret

codesg ends
end start