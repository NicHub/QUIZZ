
/Users/nico/Documents/Arduino_Build/test_define/test_define.elf:     file format elf32-avr
/Users/nico/Documents/Arduino_Build/test_define/test_define.elf

SYMBOL TABLE:
00800100 l    d  .data	00000000 .data
00000000 l    d  .text	00000000 .text
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .debug_aranges	00000000 .debug_aranges
00000000 l    d  .debug_info	00000000 .debug_info
00000000 l    d  .debug_abbrev	00000000 .debug_abbrev
00000000 l    d  .debug_line	00000000 .debug_line
00000000 l    d  .debug_frame	00000000 .debug_frame
00000000 l    d  .debug_str	00000000 .debug_str
00000000 l    d  .debug_ranges	00000000 .debug_ranges
00000000 l    df *ABS*	00000000 test_define.ino.cpp
0000003e l       *ABS*	00000000 __SP_H__
0000003d l       *ABS*	00000000 __SP_L__
0000003f l       *ABS*	00000000 __SREG__
00000000 l       *ABS*	00000000 __tmp_reg__
00000001 l       *ABS*	00000000 __zero_reg__
00000000 l    df *ABS*	00000000 _exit.o
0000008e l       .text	00000000 __stop_program
00000000 l    df *ABS*	00000000 
00000090 l       *ABS*	00000000 __data_load_start
0000007c  w      .text	00000000 __vector_22
0000007c  w      .text	00000000 __vector_1
00000068 g       .text	00000000 __trampolines_start
00000090 g       .text	00000000 _etext
0000007c  w      .text	00000000 __vector_24
0000007c  w      .text	00000000 __vector_12
0000007c g       .text	00000000 __bad_interrupt
00000090 g       *ABS*	00000000 __data_load_end
0000007c  w      .text	00000000 __vector_6
00000068 g       .text	00000000 __trampolines_end
0000007c  w      .text	00000000 __vector_3
0000007c  w      .text	00000000 __vector_23
00000068 g       .text	00000000 __dtors_end
0000007c  w      .text	00000000 __vector_25
0000007c  w      .text	00000000 __vector_11
00000068  w      .text	00000000 __init
0000007c  w      .text	00000000 __vector_13
0000007c  w      .text	00000000 __vector_17
0000007c  w      .text	00000000 __vector_19
0000007c  w      .text	00000000 __vector_7
00810000 g       .text	00000000 __eeprom_end
00000000 g       .text	00000000 __vectors
00000000  w      .text	00000000 __vector_default
0000007c  w      .text	00000000 __vector_5
00000068 g       .text	00000000 __ctors_start
00000080 g     F .text	0000000c main
0000007c  w      .text	00000000 __vector_4
00000000  w      *ABS*	00000000 __heap_end
0000007c  w      .text	00000000 __vector_9
0000007c  w      .text	00000000 __vector_2
0000007c  w      .text	00000000 __vector_21
0000007c  w      .text	00000000 __vector_15
00000068 g       .text	00000000 __dtors_start
00000068 g       .text	00000000 __ctors_end
000008ff  w      *ABS*	00000000 __stack
00800100 g       .data	00000000 _edata
00800100 g       .text	00000000 _end
0000007c  w      .text	00000000 __vector_8
0000008c  w      .text	00000000 .hidden exit
0000008c g       .text	00000000 .hidden _exit
0000007c  w      .text	00000000 __vector_14
0000007c  w      .text	00000000 __vector_10
0000007c  w      .text	00000000 __vector_16
0000007c  w      .text	00000000 __vector_18
0000007c  w      .text	00000000 __vector_20


DYNAMIC SYMBOL TABLE:
no symbols



Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 34 00 	jmp	0x68	; 0x68 <__ctors_end>
   4:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
   8:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
   c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  10:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  14:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  18:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  1c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  20:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  24:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  28:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  2c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  30:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  34:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  38:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  3c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  40:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  44:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  48:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  4c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  50:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  54:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  58:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  5c:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  60:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>
  64:	0c 94 3e 00 	jmp	0x7c	; 0x7c <__bad_interrupt>

00000068 <__ctors_end>:
  68:	11 24       	eor	r1, r1
  6a:	1f be       	out	0x3f, r1	; 63
  6c:	cf ef       	ldi	r28, 0xFF	; 255
  6e:	d8 e0       	ldi	r29, 0x08	; 8
  70:	de bf       	out	0x3e, r29	; 62
  72:	cd bf       	out	0x3d, r28	; 61
  74:	0e 94 40 00 	call	0x80	; 0x80 <main>
  78:	0c 94 46 00 	jmp	0x8c	; 0x8c <_exit>

0000007c <__bad_interrupt>:
  7c:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000080 <main>:
int main();

int main()
{

	DDRB=0b11111111;
  80:	8f ef       	ldi	r24, 0xFF	; 255
  82:	84 b9       	out	0x04, r24	; 4

	bitSet( PORTB, LED13 );
  84:	2d 9a       	sbi	0x05, 5	; 5
  86:	80 e0       	ldi	r24, 0x00	; 0
  88:	90 e0       	ldi	r25, 0x00	; 0
  8a:	08 95       	ret

0000008c <_exit>:
  8c:	f8 94       	cli

0000008e <__stop_program>:
  8e:	ff cf       	rjmp	.-2      	; 0x8e <__stop_program>
