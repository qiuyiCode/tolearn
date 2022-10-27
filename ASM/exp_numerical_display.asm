;实验10 问题3 数值显示
;编程，将data段中的数据以十进制的形式显示出来。
assume cs:code
 
data segment
	dw 123,12666,1,8,3,38
data ends
;存放word型数据对应的ASCII码，word型数据最大为65536 对应的10进制只有5位
;字符串 0 结尾占一位，所以string 段 用6位就够了
string segment
	db 6 dup (0)
string ends
 
code segment
start:
 
	mov cx,6
	mov ax,data
	mov ds,ax
	mov bx,0
	mov dh,8
	s:
		;下面循环中有更改cs,ds 故将其放入临时区
		push cx
		push ds
		
		mov ax,ds:[bx]
		call dtoc
		mov dl,3
		mov cl,2
		mov ax,string
		mov ds,ax
		call show_str
		inc dh
		add bx,2
		
		pop ds
		pop cx
	loop s
	
	mov ax,4c00h
	int 21h
	
	
	;名称：dtoc
	;功能：将word型数据转变为表示十进制数的字符串，字符串以0为结尾符。
	;参数：（ax）=word型数据，ds:si指向字符串的首地址
	;返回：si ,修改si的值,si指向字符串的首地址
	dtoc:
		push ax
		push bx
		push cx
		push dx
		push es
		push di
		
		mov bx,string
		mov es,bx
		mov di,5
		mov si,di
		get_num:
			;用32位除 16位 ax存商 dx余数
			mov dx,0
			mov bx,10
			div bx
			;将余数转ASCII码值
			add dx,48	
			mov es:[di],dl
			dec di
			
			mov cl,al
			mov ch,0
			jcxz dtoc_ok
			mov si,di
			jmp short get_num
		
	dtoc_ok:
		pop di
		pop es
		pop dx
		pop cx
		pop bx
		pop ax
		ret
	
	;名称：show_str
	;功能：在指定的位置，用指定的颜色，显示一个用0结束的字符串。
	;参数：（dh）行号（取值范围0~24），（dl）=列号（取值范围0~79），
	;	（cl）=颜色，ds:si指向字符串的首地址
	;返回：无
	show_str:
		push ax
		push bx
		push cx
		push dx
		push es
		push si
		push di
		;显存起始位置，目的地址
		mov ax,0b800H
		mov es,ax
		;确定 di = dh*160+dl*2，ax 、bx、di 没有用户数据被占用 可以进行使用
		;mov di,(dh)*160+(dl)*2
		mov al,dh
		mov ah,0
		mov bl,160
		mul bl
		mov di,ax
		
		mov al,dl
		mov ah,0
		mov bl,2
		mul bl
		add di,ax
		
		mov dl,cl		;存放颜色
		str_set:
			
			mov cl,ds:[si]
			mov ch,0
			jcxz show_ok			;控制结束条件
			
			mov ax,ds:[si]
			mov es:[di],ax	;设置字母
			mov es:[di+1],dl;设置颜色
			add di,2
			inc si
			jmp short str_set
	show_ok:
		pop di
		pop si
		pop es
		pop dx
		pop cx
		pop bx
		pop ax
		ret	
	
code ends
end start