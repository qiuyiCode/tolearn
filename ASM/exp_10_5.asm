; assume cs:codesg,ss:stacksg

; stack segment
;   dw 8 dup (0)
; stack ends

; codesg segment
;   start:
;     mov ax,stack  
;     mov ss,ax
;     mov sp,16
;     mov ds,ax ; 将栈的段地址存入ds
;     mov ax,0
;     call word ptr ds:[0EH] ; IP = 0
;     int ax
;     int ax
;     int ax
;     mov ax,4c00h
;     int 21h
; codesg ends
; end start



assume cs:codesg,ds:datasg

datasg segment
  dw 8 dup (0)
datasg ends

codesg segment
  start:
    mov ax,datasg
    mov ss,ax
    mov sp,16
    mov word ptr ss:[0],offset s ;将s的偏移地址放入ss:[0]处,占两个字节
    mov ss:[2],cs
    call dword ptr ss:[0] ;这一步隐含的操作是push CS,push IP
    nop
    s:
      mov ax,offset s
      sub ax,ss:[0ch]
      mov bx,cs
      sub bx,ss:[0eh]
      mov ax,4c00h
      int 21h
codesg ends
end start
