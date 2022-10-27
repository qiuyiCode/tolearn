; assume cs:codesg

; ;利用除法计算 100010/100
; ;AX存储被除数的低16位,DX存储被除数的高16位

; codesg segment
; start:
;   ;100001 = 186a1
;   mov bx,100
;   mov ax,86a1h
;   mov dx,0001h
;   div word ptr bx
; codesg ends
; end start

assume cs:codesg

;利用除法计算 1001/100

codesg segment
start:
  mov ax,1001 ;AX低8位存除法的商,高8位存结果的余数
  mov bl,100
  div bl
codesg ends
end start