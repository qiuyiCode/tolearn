assume cs:codesg,ss:stacksg

datasg segment
  db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
  db '1984','1985','1986','1987','1988','1989','1990','1991','1992' 
  db '1993','1994','1995'

  ;双字,4个字节
  dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
  dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000

  ;字,2个字节
  dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
  dw 11542,14430,15257,17800
datasg ends

table segment 
  db 21 dup ('year summ ne ?? ')
table ends

stacksg segment
  dw 0,0,0,0,0,0,0,0
stacksg ends

codesg segment
start:
  mov ax,datasg
  ;组合定位datasg中数据,ds为段地址,bx为偏移地址
  mov ds,ax
  mov bx,0 ;用来定位年份,收入,雇员数量

  mov ax,stacksg
  ;定位栈段
  mov ss,ax
  mov sp,10h

  ;定位tablesg中数据,es为段地址,bp为偏移地址
  mov ax,table
  mov es,ax
  mov bp,0

  mov si,0
  mov di,0
  mov cx,21
  
  s:
    ;放入年份
    push cx
    mov cx,4
    s0:
      mov byte ptr al,ds:[bx+si]
      mov byte ptr es:[bp+si],al
      inc si
      loop s0

    inc si ;跳过空格

    ;放入收入
    mov word ptr ax,ds:[bx+84]
    mov word ptr es:[bp+si],ax
    mov word ptr ax,ds:[bx+84+2]
    mov word ptr es:[bp+2+si],ax

    add si,5 ;跳过空格

    ;放入雇员数
    push bx
    mov bx,168
    mov word ptr ax,ds:[bx+di]
    mov word ptr es:[bp+si],ax
    pop bx

    inc si ;跳过空格

    ;除数为8位,被除数为16位,AL存商,AH存余数
    ;除数为16位,被除数为32位,AX存商,DX存余数
    mov word ptr ax,es:[bp+5]
    mov word ptr dx,es:[bp+7]
    div word ptr es:[bp+10]
    mov es:[bp+13],AX

    pop cx
    add bx,4
    add di,2
    add bp,10h
    mov si,0
    loop s

    mov ax,4c00h
    int 21h

codesg ends

end start

