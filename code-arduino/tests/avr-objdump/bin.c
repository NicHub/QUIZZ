
/var/folders/3l/c6_nv3414rb_sxjkb8z9z1fr0000gn/T/build2496477641271170334.tmp/manchester_test_5_tx.cpp.elf:     file format elf32-avr
/var/folders/3l/c6_nv3414rb_sxjkb8z9z1fr0000gn/T/build2496477641271170334.tmp/manchester_test_5_tx.cpp.elf

SYMBOL TABLE:
00000000 l    d  .text	00000000 .text
00800060 l    d  .data	00000000 .data
00000000 l    d  .comment	00000000 .comment
00000000 l    d  .debug_aranges	00000000 .debug_aranges
00000000 l    d  .debug_info	00000000 .debug_info
00000000 l    d  .debug_abbrev	00000000 .debug_abbrev
00000000 l    d  .debug_line	00000000 .debug_line
00000000 l    d  .debug_frame	00000000 .debug_frame
00000000 l    d  .debug_str	00000000 .debug_str
00000000 l    d  .debug_loc	00000000 .debug_loc
00000000 l    d  .debug_ranges	00000000 .debug_ranges
00000000 l    df *ABS*	00000000 manchester_test_5_tx.cpp
0000003d l       *ABS*	00000000 __SP_L__
0000003f l       *ABS*	00000000 __SREG__
00000000 l       *ABS*	00000000 __tmp_reg__
00000001 l       *ABS*	00000000 __zero_reg__
00000000 l    df *ABS*	00000000 _exit.o
00000082 l       .text	00000000 __stop_program
00000000 l    df *ABS*	00000000 
00000040  w      .text	00000000 __vector_1
0000001e g       .text	00000000 __trampolines_start
00000084 g       .text	00000000 _etext
00000040  w      .text	00000000 __vector_12
00000040 g       .text	00000000 __bad_interrupt
00000084 g       *ABS*	00000000 __data_load_end
00000040  w      .text	00000000 __vector_6
0000001e g       .text	00000000 __trampolines_end
00000068 g     F .text	00000018 __vector_3
00000084 g       *ABS*	00000000 __data_load_start
0000001e g       .text	00000000 __dtors_end
00000040  w      .text	00000000 __vector_11
0000001e  w      .text	00000000 __init
00000040  w      .text	00000000 __vector_13
00000040  w      .text	00000000 __vector_7
00810000 g       .data	00000000 __eeprom_end
00000000 g       .text	00000000 __vectors
00800060 g       .data	00000000 __data_end
00000000  w      .text	00000000 __vector_default
00000040  w      .text	00000000 __vector_5
0000001e g       .text	00000000 __ctors_start
00000026 g       .text	00000016 .hidden __do_copy_data
00000042 g     F .text	0000001a _Z17initTimerCounter1v
0000005c g     F .text	0000000c main
00000040  w      .text	00000000 __vector_4
00000000  w      *ABS*	00000000 __heap_end
00000040  w      .text	00000000 __vector_9
00000040  w      .text	00000000 __vector_2
0000001e g       .text	00000000 __dtors_start
0000001e g       .text	00000000 __ctors_end
000000df  w      *ABS*	00000000 __stack
00800060 g       .data	00000000 _edata
00800060 g       .data	00000000 _end
00000040  w      .text	00000000 __vector_8
00000080  w      .text	00000000 .hidden exit
00000080 g       .text	00000000 .hidden _exit
00000040  w      .text	00000000 __vector_14
00000040  w      .text	00000000 __vector_10
00800060 g       .data	00000000 __data_start


DYNAMIC SYMBOL TABLE:
no symbols



Disassembly of section .text:

00000000 <__vectors>:
   0:	0e c0       	rjmp	.+28     	; 0x1e <__ctors_end>
   2:	1e c0       	rjmp	.+60     	; 0x40 <__bad_interrupt>
   4:	1d c0       	rjmp	.+58     	; 0x40 <__bad_interrupt>
   6:	30 c0       	rjmp	.+96     	; 0x68 <__vector_3>
   8:	1b c0       	rjmp	.+54     	; 0x40 <__bad_interrupt>
   a:	1a c0       	rjmp	.+52     	; 0x40 <__bad_interrupt>
   c:	19 c0       	rjmp	.+50     	; 0x40 <__bad_interrupt>
   e:	18 c0       	rjmp	.+48     	; 0x40 <__bad_interrupt>
  10:	17 c0       	rjmp	.+46     	; 0x40 <__bad_interrupt>
  12:	16 c0       	rjmp	.+44     	; 0x40 <__bad_interrupt>
  14:	15 c0       	rjmp	.+42     	; 0x40 <__bad_interrupt>
  16:	14 c0       	rjmp	.+40     	; 0x40 <__bad_interrupt>
  18:	13 c0       	rjmp	.+38     	; 0x40 <__bad_interrupt>
  1a:	12 c0       	rjmp	.+36     	; 0x40 <__bad_interrupt>
  1c:	11 c0       	rjmp	.+34     	; 0x40 <__bad_interrupt>

0000001e <__ctors_end>:
  1e:	11 24       	eor	r1, r1
  20:	1f be       	out	0x3f, r1	; 63
  22:	cf ed       	ldi	r28, 0xDF	; 223
  24:	cd bf       	out	0x3d, r28	; 61

00000026 <__do_copy_data>:
  26:	10 e0       	ldi	r17, 0x00	; 0
  28:	a0 e6       	ldi	r26, 0x60	; 96
  2a:	b0 e0       	ldi	r27, 0x00	; 0
  2c:	e4 e8       	ldi	r30, 0x84	; 132
  2e:	f0 e0       	ldi	r31, 0x00	; 0
  30:	02 c0       	rjmp	.+4      	; 0x36 <__do_copy_data+0x10>
  32:	05 90       	lpm	r0, Z+
  34:	0d 92       	st	X+, r0
  36:	a0 36       	cpi	r26, 0x60	; 96
  38:	b1 07       	cpc	r27, r17
  3a:	d9 f7       	brne	.-10     	; 0x32 <__do_copy_data+0xc>
  3c:	0f d0       	rcall	.+30     	; 0x5c <main>
  3e:	20 c0       	rjmp	.+64     	; 0x80 <_exit>

00000040 <__bad_interrupt>:
  40:	df cf       	rjmp	.-66     	; 0x0 <__vectors>

00000042 <_Z17initTimerCounter1v>:
  42:	10 be       	out	0x30, r1	; 48
  44:	1f bc       	out	0x2f, r1	; 47
  46:	82 e0       	ldi	r24, 0x02	; 2
  48:	8c bd       	out	0x2c, r24	; 44
  4a:	1e bc       	out	0x2e, r1	; 46
  4c:	8f ef       	ldi	r24, 0xFF	; 255
  4e:	8d bd       	out	0x2d, r24	; 45
  50:	80 e4       	ldi	r24, 0x40	; 64
  52:	89 bf       	out	0x39, r24	; 57
  54:	8d e8       	ldi	r24, 0x8D	; 141
  56:	80 bf       	out	0x30, r24	; 48
  58:	78 94       	sei
  5a:	08 95       	ret

0000005c <main>:
  5c:	bb 9a       	sbi	0x17, 3	; 23
  5e:	bc 9a       	sbi	0x17, 4	; 23
  60:	88 e1       	ldi	r24, 0x18	; 24
  62:	86 bb       	out	0x16, r24	; 22
  64:	ee df       	rcall	.-36     	; 0x42 <_Z17initTimerCounter1v>
  66:	ff cf       	rjmp	.-2      	; 0x66 <main+0xa>

00000068 <__vector_3>:
  68:	1f 92       	push	r1
  6a:	0f 92       	push	r0
  6c:	0f b6       	in	r0, 0x3f	; 63
  6e:	0f 92       	push	r0
  70:	11 24       	eor	r1, r1
  72:	b3 9a       	sbi	0x16, 3	; 22
  74:	b4 9a       	sbi	0x16, 4	; 22
  76:	0f 90       	pop	r0
  78:	0f be       	out	0x3f, r0	; 63
  7a:	0f 90       	pop	r0
  7c:	1f 90       	pop	r1
  7e:	18 95       	reti

00000080 <_exit>:
  80:	f8 94       	cli

00000082 <__stop_program>:
  82:	ff cf       	rjmp	.-2      	; 0x82 <__stop_program>
