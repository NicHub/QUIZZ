
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
00000000 l    d  .debug_ranges	00000000 .debug_ranges
00000000 l    df *ABS*	00000000 manchester_test_5_tx.cpp
0000003d l       *ABS*	00000000 __SP_L__
0000003f l       *ABS*	00000000 __SREG__
00000000 l       *ABS*	00000000 __tmp_reg__
00000001 l       *ABS*	00000000 __zero_reg__
00000000 l    df *ABS*	00000000 _exit.o
00000032 l       .text	00000000 __stop_program
00000000 l    df *ABS*	00000000 
00000034 l       *ABS*	00000000 __data_load_start
0000002a  w      .text	00000000 __vector_1
0000001e g       .text	00000000 __trampolines_start
00000034 g       .text	00000000 _etext
0000002a  w      .text	00000000 __vector_12
0000002a g       .text	00000000 __bad_interrupt
00000034 g       *ABS*	00000000 __data_load_end
0000002a  w      .text	00000000 __vector_6
0000001e g       .text	00000000 __trampolines_end
0000002a  w      .text	00000000 __vector_3
0000001e g       .text	00000000 __dtors_end
0000002a  w      .text	00000000 __vector_11
0000001e  w      .text	00000000 __init
0000002a  w      .text	00000000 __vector_13
0000002a  w      .text	00000000 __vector_7
00810000 g       .data	00000000 __eeprom_end
00000000 g       .text	00000000 __vectors
00000000  w      .text	00000000 __vector_default
0000002a  w      .text	00000000 __vector_5
0000001e g       .text	00000000 __ctors_start
0000002c g     F .text	00000004 main
0000002a  w      .text	00000000 __vector_4
00000000  w      *ABS*	00000000 __heap_end
0000002a  w      .text	00000000 __vector_9
0000002a  w      .text	00000000 __vector_2
0000001e g       .text	00000000 __dtors_start
0000001e g       .text	00000000 __ctors_end
000000df  w      *ABS*	00000000 __stack
00800060 g       .data	00000000 _edata
00800060 g       .data	00000000 _end
0000002a  w      .text	00000000 __vector_8
00000030  w      .text	00000000 .hidden exit
00000030 g       .text	00000000 .hidden _exit
0000002a  w      .text	00000000 __vector_14
0000002a  w      .text	00000000 __vector_10


DYNAMIC SYMBOL TABLE:
no symbols



Disassembly of section .text:

00000000 <__vectors>:
   0:	0e c0       	rjmp	.+28     	; 0x1e <__ctors_end>
   2:	13 c0       	rjmp	.+38     	; 0x2a <__bad_interrupt>
   4:	12 c0       	rjmp	.+36     	; 0x2a <__bad_interrupt>
   6:	11 c0       	rjmp	.+34     	; 0x2a <__bad_interrupt>
   8:	10 c0       	rjmp	.+32     	; 0x2a <__bad_interrupt>
   a:	0f c0       	rjmp	.+30     	; 0x2a <__bad_interrupt>
   c:	0e c0       	rjmp	.+28     	; 0x2a <__bad_interrupt>
   e:	0d c0       	rjmp	.+26     	; 0x2a <__bad_interrupt>
  10:	0c c0       	rjmp	.+24     	; 0x2a <__bad_interrupt>
  12:	0b c0       	rjmp	.+22     	; 0x2a <__bad_interrupt>
  14:	0a c0       	rjmp	.+20     	; 0x2a <__bad_interrupt>
  16:	09 c0       	rjmp	.+18     	; 0x2a <__bad_interrupt>
  18:	08 c0       	rjmp	.+16     	; 0x2a <__bad_interrupt>
  1a:	07 c0       	rjmp	.+14     	; 0x2a <__bad_interrupt>
  1c:	06 c0       	rjmp	.+12     	; 0x2a <__bad_interrupt>

0000001e <__ctors_end>:
  1e:	11 24       	eor	r1, r1
  20:	1f be       	out	0x3f, r1	; 63
  22:	cf ed       	ldi	r28, 0xDF	; 223
  24:	cd bf       	out	0x3d, r28	; 61
  26:	02 d0       	rcall	.+4      	; 0x2c <main>
  28:	03 c0       	rjmp	.+6      	; 0x30 <_exit>

0000002a <__bad_interrupt>:
  2a:	ea cf       	rjmp	.-44     	; 0x0 <__vectors>

0000002c <main>:
  2c:	b3 9a       	sbi	0x16, 3	; 22
  2e:	ff cf       	rjmp	.-2      	; 0x2e <main+0x2>

00000030 <_exit>:
  30:	f8 94       	cli

00000032 <__stop_program>:
  32:	ff cf       	rjmp	.-2      	; 0x32 <__stop_program>
