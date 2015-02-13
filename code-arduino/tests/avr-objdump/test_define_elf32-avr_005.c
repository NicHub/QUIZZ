
/Users/nico/Documents/Arduino_Build/test_define/test_define.elf:     file format elf32-avr

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .data         00000000  00800100  00000090  00000104  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  1 .text         00000090  00000000  00000000  00000074  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .comment      00000011  00000000  00000000  00000104  2**0
                  CONTENTS, READONLY
  3 .debug_aranges 00000020  00000000  00000000  00000115  2**0
                  CONTENTS, READONLY, DEBUGGING
  4 .debug_info   0000015e  00000000  00000000  00000135  2**0
                  CONTENTS, READONLY, DEBUGGING
  5 .debug_abbrev 00000076  00000000  00000000  00000293  2**0
                  CONTENTS, READONLY, DEBUGGING
  6 .debug_line   00000139  00000000  00000000  00000309  2**0
                  CONTENTS, READONLY, DEBUGGING
  7 .debug_frame  00000024  00000000  00000000  00000444  2**2
                  CONTENTS, READONLY, DEBUGGING
  8 .debug_str    00000179  00000000  00000000  00000468  2**0
                  CONTENTS, READONLY, DEBUGGING
  9 .debug_ranges 00000010  00000000  00000000  000005e1  2**0
                  CONTENTS, READONLY, DEBUGGING

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
	//PORTB |= 1 << PORTB5;
  86:	80 e0       	ldi	r24, 0x00	; 0
  88:	90 e0       	ldi	r25, 0x00	; 0
  8a:	08 95       	ret

0000008c <_exit>:
  8c:	f8 94       	cli

0000008e <__stop_program>:
  8e:	ff cf       	rjmp	.-2      	; 0x8e <__stop_program>
