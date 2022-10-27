; assume cs:codesg,ss:stacksg

; stacksg segment
;   db 16 dup (0)
; stacksg ends

; codesg segment
;   mov ax,4c00h
;   int 21h
;   start:
;     mov ax,stacksg
;     mov ss,ax
;     mov sp,16
;     mov ax,0
;     push ax
;     mov bx,0
;     ret ; 将栈中的数据作为IP
; codesg ends
; end start


; stacksg segment
;   db 16 dup (0)
; stacksg ends

; codesg segment
;   mov ax,4c00h
;   int 21h
;   start:
;     mov ax,stacksg
;     mov ss,ax
;     mov sp,16
;     mov ax,0
;     push cs
;     push ax
;     mov bx,0
;     retf ;低字节 = IP,高字节 = CS
; codesg ends
; end start


; 补全程序,实现从内存1000:0000处开始执行指令
; 注:你需要知道地址(段地址、偏移地址)是10进制还是16进制 ? 
; assume cs:code

; stack segment
;   db 16 dup (0)
; stack ends

; code segment
;   start:
;     mov ax,stack
;     mov ss,ax
;     mov sp,16
;     mov ax,1000h
;     push ax
;     mov ax,0000
;     push ax
;     retf
; code ends

; end start

