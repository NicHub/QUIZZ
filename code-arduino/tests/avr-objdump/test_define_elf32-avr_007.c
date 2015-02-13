
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
00000000 l    d  .debug_loc	00000000 .debug_loc
00000000 l    d  .debug_ranges	00000000 .debug_ranges
00000000 l    df *ABS*	00000000 test_define.ino.cpp
0000003e l       *ABS*	00000000 __SP_H__
0000003d l       *ABS*	00000000 __SP_L__
0000003f l       *ABS*	00000000 __SREG__
00000000 l       *ABS*	00000000 __tmp_reg__
00000001 l       *ABS*	00000000 __zero_reg__
00000000 l    df *ABS*	00000000 wiring_digital.c
0000003e l       *ABS*	00000000 __SP_H__
0000003d l       *ABS*	00000000 __SP_L__
0000003f l       *ABS*	00000000 __SREG__
00000000 l       *ABS*	00000000 __tmp_reg__
00000001 l       *ABS*	00000000 __zero_reg__
000000d8 l     F .text	00000052 turnOffPWM
00000000 l    df *ABS*	00000000 _exit.o
00000198 l       .text	00000000 __stop_program
00000000 l    df *ABS*	00000000 
0000019a l       *ABS*	00000000 __data_load_start
000000c2  w      .text	00000000 __vector_22
000000c2  w      .text	00000000 __vector_1
00000068 g       .text	00000000 __trampolines_start
0000019a g       .text	00000000 _etext
000000c2  w      .text	00000000 __vector_24
000000c2  w      .text	00000000 __vector_12
000000c2 g       .text	00000000 __bad_interrupt
0000019a g       *ABS*	00000000 __data_load_end
000000c2  w      .text	00000000 __vector_6
00000068 g       .text	00000000 __trampolines_end
000000c2  w      .text	00000000 __vector_3
0000012a g     F .text	0000006c digitalWrite
00000090 g     O .text	00000014 digital_pin_to_port_PGM
000000c2  w      .text	00000000 __vector_23
000000ae g       .text	00000000 __dtors_end
000000c2  w      .text	00000000 __vector_25
000000c2  w      .text	00000000 __vector_11
000000ae  w      .text	00000000 __init
000000c2  w      .text	00000000 __vector_13
000000c2  w      .text	00000000 __vector_17
000000c2  w      .text	00000000 __vector_19
000000c2  w      .text	00000000 __vector_7
00810000 g       .text	00000000 __eeprom_end
0000007c g     O .text	00000014 digital_pin_to_bit_mask_PGM
00000000 g       .text	00000000 __vectors
00000000  w      .text	00000000 __vector_default
000000c2  w      .text	00000000 __vector_5
000000ae g       .text	00000000 __ctors_start
000000c6 g     F .text	00000012 main
000000c2  w      .text	00000000 __vector_4
00000000  w      *ABS*	00000000 __heap_end
000000c2  w      .text	00000000 __vector_9
000000c2  w      .text	00000000 __vector_2
000000c2  w      .text	00000000 __vector_21
000000c2  w      .text	00000000 __vector_15
000000a4 g     O .text	0000000a port_to_output_PGM
000000ae g       .text	00000000 __dtors_start
000000ae g       .text	00000000 __ctors_end
000008ff  w      *ABS*	00000000 __stack
00800100 g       .data	00000000 _edata
00800100 g       .text	00000000 _end
000000c2  w      .text	00000000 __vector_8
00000068 g     O .text	00000014 digital_pin_to_timer_PGM
00000196  w      .text	00000000 .hidden exit
00000196 g       .text	00000000 .hidden _exit
000000c2  w      .text	00000000 __vector_14
000000c2  w      .text	00000000 __vector_10
000000c2  w      .text	00000000 __vector_16
000000c2  w      .text	00000000 __vector_18
000000c2  w      .text	00000000 __vector_20


DYNAMIC SYMBOL TABLE:
no symbols



Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 57 00 	jmp	0xae	; 0xae <__ctors_end>
   4:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
   8:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
   c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  10:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  14:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  18:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  1c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  20:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  24:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  28:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  2c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  30:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  34:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  38:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  3c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  40:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  44:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  48:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  4c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  50:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  54:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  58:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  5c:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  60:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>
  64:	0c 94 61 00 	jmp	0xc2	; 0xc2 <__bad_interrupt>

00000068 <__trampolines_end>:
  68:	00 00       	nop
  6a:	00 08       	sbc	r0, r0
  6c:	00 02       	muls	r16, r16
  6e:	01 00       	.word	0x0001	; ????
  70:	00 03       	mulsu	r16, r16
  72:	04 07       	cpc	r16, r20
	...

0000007c <digital_pin_to_bit_mask_PGM>:
  7c:	01 02 04 08 10 20 40 80 01 02 04 08 10 20 01 02     ..... @...... ..
  8c:	04 08 10 20                                         ... 

00000090 <digital_pin_to_port_PGM>:
  90:	04 04 04 04 04 04 04 04 02 02 02 02 02 02 03 03     ................
  a0:	03 03 03 03                                         ....

000000a4 <port_to_output_PGM>:
  a4:	00 00 00 00 25 00 28 00 2b 00                       ....%.(.+.

000000ae <__ctors_end>:
  ae:	11 24       	eor	r1, r1
  b0:	1f be       	out	0x3f, r1	; 63
  b2:	cf ef       	ldi	r28, 0xFF	; 255
  b4:	d8 e0       	ldi	r29, 0x08	; 8
  b6:	de bf       	out	0x3e, r29	; 62
  b8:	cd bf       	out	0x3d, r28	; 61
  ba:	0e 94 63 00 	call	0xc6	; 0xc6 <main>
  be:	0c 94 cb 00 	jmp	0x196	; 0x196 <_exit>

000000c2 <__bad_interrupt>:
  c2:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

000000c6 <main>:
int main();

int main()
{

	DDRB=0b11111111;
  c6:	8f ef       	ldi	r24, 0xFF	; 255
  c8:	84 b9       	out	0x04, r24	; 4

	digitalWrite( 13, 1 );
  ca:	61 e0       	ldi	r22, 0x01	; 1
  cc:	8d e0       	ldi	r24, 0x0D	; 13
  ce:	0e 94 95 00 	call	0x12a	; 0x12a <digitalWrite>
  d2:	80 e0       	ldi	r24, 0x00	; 0
  d4:	90 e0       	ldi	r25, 0x00	; 0
  d6:	08 95       	ret

000000d8 <turnOffPWM>:
//
//static inline void turnOffPWM(uint8_t timer) __attribute__ ((always_inline));
//static inline void turnOffPWM(uint8_t timer)
static void turnOffPWM(uint8_t timer)
{
	switch (timer)
  d8:	83 30       	cpi	r24, 0x03	; 3
  da:	81 f0       	breq	.+32     	; 0xfc <turnOffPWM+0x24>
  dc:	28 f4       	brcc	.+10     	; 0xe8 <turnOffPWM+0x10>
  de:	81 30       	cpi	r24, 0x01	; 1
  e0:	99 f0       	breq	.+38     	; 0x108 <turnOffPWM+0x30>
  e2:	82 30       	cpi	r24, 0x02	; 2
  e4:	a1 f0       	breq	.+40     	; 0x10e <turnOffPWM+0x36>
  e6:	08 95       	ret
  e8:	87 30       	cpi	r24, 0x07	; 7
  ea:	a9 f0       	breq	.+42     	; 0x116 <turnOffPWM+0x3e>
  ec:	88 30       	cpi	r24, 0x08	; 8
  ee:	b9 f0       	breq	.+46     	; 0x11e <turnOffPWM+0x46>
  f0:	84 30       	cpi	r24, 0x04	; 4
  f2:	d1 f4       	brne	.+52     	; 0x128 <turnOffPWM+0x50>
	{
		#if defined(TCCR1A) && defined(COM1A1)
		case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
		#endif
		#if defined(TCCR1A) && defined(COM1B1)
		case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
  f4:	80 91 80 00 	lds	r24, 0x0080
  f8:	8f 7d       	andi	r24, 0xDF	; 223
  fa:	03 c0       	rjmp	.+6      	; 0x102 <turnOffPWM+0x2a>
static void turnOffPWM(uint8_t timer)
{
	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1)
		case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
  fc:	80 91 80 00 	lds	r24, 0x0080
 100:	8f 77       	andi	r24, 0x7F	; 127
		#endif
		#if defined(TCCR1A) && defined(COM1B1)
		case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
 102:	80 93 80 00 	sts	0x0080, r24
 106:	08 95       	ret
		#if defined(TCCR2) && defined(COM21)
		case  TIMER2:   cbi(TCCR2, COM21);      break;
		#endif
		
		#if defined(TCCR0A) && defined(COM0A1)
		case  TIMER0A:  cbi(TCCR0A, COM0A1);    break;
 108:	84 b5       	in	r24, 0x24	; 36
 10a:	8f 77       	andi	r24, 0x7F	; 127
 10c:	02 c0       	rjmp	.+4      	; 0x112 <turnOffPWM+0x3a>
		#endif
		
		#if defined(TIMER0B) && defined(COM0B1)
		case  TIMER0B:  cbi(TCCR0A, COM0B1);    break;
 10e:	84 b5       	in	r24, 0x24	; 36
 110:	8f 7d       	andi	r24, 0xDF	; 223
 112:	84 bd       	out	0x24, r24	; 36
 114:	08 95       	ret
		#endif
		#if defined(TCCR2A) && defined(COM2A1)
		case  TIMER2A:  cbi(TCCR2A, COM2A1);    break;
 116:	80 91 b0 00 	lds	r24, 0x00B0
 11a:	8f 77       	andi	r24, 0x7F	; 127
 11c:	03 c0       	rjmp	.+6      	; 0x124 <turnOffPWM+0x4c>
		#endif
		#if defined(TCCR2A) && defined(COM2B1)
		case  TIMER2B:  cbi(TCCR2A, COM2B1);    break;
 11e:	80 91 b0 00 	lds	r24, 0x00B0
 122:	8f 7d       	andi	r24, 0xDF	; 223
 124:	80 93 b0 00 	sts	0x00B0, r24
 128:	08 95       	ret

0000012a <digitalWrite>:
		#endif
	}
}

void digitalWrite(uint8_t pin, uint8_t val)
{
 12a:	0f 93       	push	r16
 12c:	1f 93       	push	r17
 12e:	cf 93       	push	r28
 130:	df 93       	push	r29
 132:	1f 92       	push	r1
 134:	cd b7       	in	r28, 0x3d	; 61
 136:	de b7       	in	r29, 0x3e	; 62
	uint8_t timer = digitalPinToTimer(pin);
 138:	28 2f       	mov	r18, r24
 13a:	30 e0       	ldi	r19, 0x00	; 0
 13c:	f9 01       	movw	r30, r18
 13e:	e8 59       	subi	r30, 0x98	; 152
 140:	ff 4f       	sbci	r31, 0xFF	; 255
 142:	84 91       	lpm	r24, Z
	uint8_t bit = digitalPinToBitMask(pin);
 144:	f9 01       	movw	r30, r18
 146:	e4 58       	subi	r30, 0x84	; 132
 148:	ff 4f       	sbci	r31, 0xFF	; 255
 14a:	14 91       	lpm	r17, Z
	uint8_t port = digitalPinToPort(pin);
 14c:	f9 01       	movw	r30, r18
 14e:	e0 57       	subi	r30, 0x70	; 112
 150:	ff 4f       	sbci	r31, 0xFF	; 255
 152:	04 91       	lpm	r16, Z
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;
 154:	00 23       	and	r16, r16
 156:	c9 f0       	breq	.+50     	; 0x18a <digitalWrite+0x60>

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);
 158:	88 23       	and	r24, r24
 15a:	21 f0       	breq	.+8      	; 0x164 <digitalWrite+0x3a>
 15c:	69 83       	std	Y+1, r22	; 0x01
 15e:	0e 94 6c 00 	call	0xd8	; 0xd8 <turnOffPWM>
 162:	69 81       	ldd	r22, Y+1	; 0x01

	out = portOutputRegister(port);
 164:	e0 2f       	mov	r30, r16
 166:	f0 e0       	ldi	r31, 0x00	; 0
 168:	ee 0f       	add	r30, r30
 16a:	ff 1f       	adc	r31, r31
 16c:	ec 55       	subi	r30, 0x5C	; 92
 16e:	ff 4f       	sbci	r31, 0xFF	; 255
 170:	a5 91       	lpm	r26, Z+
 172:	b4 91       	lpm	r27, Z

	uint8_t oldSREG = SREG;
 174:	9f b7       	in	r25, 0x3f	; 63
	cli();
 176:	f8 94       	cli

	if (val == LOW) {
		*out &= ~bit;
 178:	8c 91       	ld	r24, X
	out = portOutputRegister(port);

	uint8_t oldSREG = SREG;
	cli();

	if (val == LOW) {
 17a:	61 11       	cpse	r22, r1
 17c:	03 c0       	rjmp	.+6      	; 0x184 <digitalWrite+0x5a>
		*out &= ~bit;
 17e:	10 95       	com	r17
 180:	81 23       	and	r24, r17
 182:	01 c0       	rjmp	.+2      	; 0x186 <digitalWrite+0x5c>
	} else {
		*out |= bit;
 184:	81 2b       	or	r24, r17
 186:	8c 93       	st	X, r24
	}

	SREG = oldSREG;
 188:	9f bf       	out	0x3f, r25	; 63
}
 18a:	0f 90       	pop	r0
 18c:	df 91       	pop	r29
 18e:	cf 91       	pop	r28
 190:	1f 91       	pop	r17
 192:	0f 91       	pop	r16
 194:	08 95       	ret

00000196 <_exit>:
 196:	f8 94       	cli

00000198 <__stop_program>:
 198:	ff cf       	rjmp	.-2      	; 0x198 <__stop_program>
