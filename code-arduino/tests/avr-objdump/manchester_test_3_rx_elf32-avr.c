
/Users/nico/Documents/Arduino_Build/manchester_test_3_rx/manchester_test_3_rx.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
}

void __cxa_deleted_virtual(void) {
  // We might want to write some diagnostics to uart in this case
  //std::terminate();
  abort();
   0:	0c 94 63 00 	jmp	0xc6	; 0xc6 <__ctors_end>
   4:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
   8:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
   c:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  10:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  14:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  18:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  1c:	0c 94 b5 05 	jmp	0xb6a	; 0xb6a <__vector_7>
  20:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  24:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  28:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  2c:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  30:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  34:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  38:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  3c:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  40:	0c 94 9a 04 	jmp	0x934	; 0x934 <__vector_16>
  44:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  48:	0c 94 e8 02 	jmp	0x5d0	; 0x5d0 <__vector_18>
  4c:	0c 94 1a 03 	jmp	0x634	; 0x634 <__vector_19>
  50:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  54:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  58:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  5c:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  60:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>
  64:	0c 94 8b 00 	jmp	0x116	; 0x116 <__bad_interrupt>

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

000000a4 <port_to_input_PGM>:
  a4:	00 00 00 00 23 00 26 00 29 00                       ....#.&.).

000000ae <port_to_output_PGM>:
  ae:	00 00 00 00 25 00 28 00 2b 00                       ....%.(.+.

000000b8 <port_to_mode_PGM>:
  b8:	00 00 00 00 24 00 27 00 2a 00                       ....$.'.*.

000000c2 <__ctors_start>:
  c2:	4a 03       	fmul	r20, r18
  c4:	7d 06       	cpc	r7, r29

000000c6 <__ctors_end>:
  c6:	11 24       	eor	r1, r1
  c8:	1f be       	out	0x3f, r1	; 63
  ca:	cf ef       	ldi	r28, 0xFF	; 255
  cc:	d8 e0       	ldi	r29, 0x08	; 8
  ce:	de bf       	out	0x3e, r29	; 62
  d0:	cd bf       	out	0x3d, r28	; 61

000000d2 <__do_copy_data>:
  d2:	11 e0       	ldi	r17, 0x01	; 1
  d4:	a0 e0       	ldi	r26, 0x00	; 0
  d6:	b1 e0       	ldi	r27, 0x01	; 1
  d8:	ea eb       	ldi	r30, 0xBA	; 186
  da:	fe e0       	ldi	r31, 0x0E	; 14
  dc:	02 c0       	rjmp	.+4      	; 0xe2 <__do_copy_data+0x10>
  de:	05 90       	lpm	r0, Z+
  e0:	0d 92       	st	X+, r0
  e2:	aa 33       	cpi	r26, 0x3A	; 58
  e4:	b1 07       	cpc	r27, r17
  e6:	d9 f7       	brne	.-10     	; 0xde <__do_copy_data+0xc>

000000e8 <__do_clear_bss>:
  e8:	21 e0       	ldi	r18, 0x01	; 1
  ea:	aa e3       	ldi	r26, 0x3A	; 58
  ec:	b1 e0       	ldi	r27, 0x01	; 1
  ee:	01 c0       	rjmp	.+2      	; 0xf2 <.do_clear_bss_start>

000000f0 <.do_clear_bss_loop>:
  f0:	1d 92       	st	X+, r1

000000f2 <.do_clear_bss_start>:
  f2:	ad 3f       	cpi	r26, 0xFD	; 253
  f4:	b2 07       	cpc	r27, r18
  f6:	e1 f7       	brne	.-8      	; 0xf0 <.do_clear_bss_loop>

000000f8 <__do_global_ctors>:
  f8:	10 e0       	ldi	r17, 0x00	; 0
  fa:	c6 ec       	ldi	r28, 0xC6	; 198
  fc:	d0 e0       	ldi	r29, 0x00	; 0
  fe:	04 c0       	rjmp	.+8      	; 0x108 <__do_global_ctors+0x10>
 100:	22 97       	sbiw	r28, 0x02	; 2
 102:	fe 01       	movw	r30, r28
 104:	0e 94 57 07 	call	0xeae	; 0xeae <__tablejump__>
 108:	c2 3c       	cpi	r28, 0xC2	; 194
 10a:	d1 07       	cpc	r29, r17
 10c:	c9 f7       	brne	.-14     	; 0x100 <__do_global_ctors+0x8>
 10e:	0e 94 8b 04 	call	0x916	; 0x916 <main>
 112:	0c 94 5b 07 	jmp	0xeb6	; 0xeb6 <_exit>

00000116 <__bad_interrupt>:
 116:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

0000011a <_Z4waiti>:

void wait( int delayMs );
void beep( int dt );

void wait( int delayMs )
{
 11a:	cf 93       	push	r28
 11c:	df 93       	push	r29
 11e:	00 d0       	rcall	.+0      	; 0x120 <_Z4waiti+0x6>
 120:	00 d0       	rcall	.+0      	; 0x122 <_Z4waiti+0x8>
 122:	cd b7       	in	r28, 0x3d	; 61
 124:	de b7       	in	r29, 0x3e	; 62
    for( volatile int i=0; i<delayMs; i++ )
 126:	1c 82       	std	Y+4, r1	; 0x04
 128:	1b 82       	std	Y+3, r1	; 0x03
 12a:	2b 81       	ldd	r18, Y+3	; 0x03
 12c:	3c 81       	ldd	r19, Y+4	; 0x04
 12e:	28 17       	cp	r18, r24
 130:	39 07       	cpc	r19, r25
 132:	ac f4       	brge	.+42     	; 0x15e <_Z4waiti+0x44>
    {
        for( volatile int j=0; j<450; j++ ) {}
 134:	1a 82       	std	Y+2, r1	; 0x02
 136:	19 82       	std	Y+1, r1	; 0x01
 138:	29 81       	ldd	r18, Y+1	; 0x01
 13a:	3a 81       	ldd	r19, Y+2	; 0x02
 13c:	22 3c       	cpi	r18, 0xC2	; 194
 13e:	31 40       	sbci	r19, 0x01	; 1
 140:	3c f4       	brge	.+14     	; 0x150 <_Z4waiti+0x36>
 142:	29 81       	ldd	r18, Y+1	; 0x01
 144:	3a 81       	ldd	r19, Y+2	; 0x02
 146:	2f 5f       	subi	r18, 0xFF	; 255
 148:	3f 4f       	sbci	r19, 0xFF	; 255
 14a:	3a 83       	std	Y+2, r19	; 0x02
 14c:	29 83       	std	Y+1, r18	; 0x01
 14e:	f4 cf       	rjmp	.-24     	; 0x138 <_Z4waiti+0x1e>
void wait( int delayMs );
void beep( int dt );

void wait( int delayMs )
{
    for( volatile int i=0; i<delayMs; i++ )
 150:	2b 81       	ldd	r18, Y+3	; 0x03
 152:	3c 81       	ldd	r19, Y+4	; 0x04
 154:	2f 5f       	subi	r18, 0xFF	; 255
 156:	3f 4f       	sbci	r19, 0xFF	; 255
 158:	3c 83       	std	Y+4, r19	; 0x04
 15a:	2b 83       	std	Y+3, r18	; 0x03
 15c:	e6 cf       	rjmp	.-52     	; 0x12a <_Z4waiti+0x10>
    {
        for( volatile int j=0; j<450; j++ ) {}
    }
}
 15e:	0f 90       	pop	r0
 160:	0f 90       	pop	r0
 162:	0f 90       	pop	r0
 164:	0f 90       	pop	r0
 166:	df 91       	pop	r29
 168:	cf 91       	pop	r28
 16a:	08 95       	ret

0000016c <_Z4beepi>:

void beep( int dt )
{
 16c:	df 92       	push	r13
 16e:	ef 92       	push	r14
 170:	ff 92       	push	r15
 172:	0f 93       	push	r16
 174:	1f 93       	push	r17
 176:	cf 93       	push	r28
 178:	df 93       	push	r29
 17a:	8c 01       	movw	r16, r24
    for( int j=0; j<300/dt; j++ )
 17c:	8c e2       	ldi	r24, 0x2C	; 44
 17e:	91 e0       	ldi	r25, 0x01	; 1
 180:	b8 01       	movw	r22, r16
 182:	0e 94 0b 07 	call	0xe16	; 0xe16 <__divmodhi4>
 186:	7b 01       	movw	r14, r22
 188:	c0 e0       	ldi	r28, 0x00	; 0
 18a:	d0 e0       	ldi	r29, 0x00	; 0
    {
        BuzzerToggle;
 18c:	dd 24       	eor	r13, r13
 18e:	d3 94       	inc	r13
    }
}

void beep( int dt )
{
    for( int j=0; j<300/dt; j++ )
 190:	ce 15       	cp	r28, r14
 192:	df 05       	cpc	r29, r15
 194:	44 f4       	brge	.+16     	; 0x1a6 <_Z4beepi+0x3a>
    {
        BuzzerToggle;
 196:	88 b1       	in	r24, 0x08	; 8
 198:	8d 25       	eor	r24, r13
 19a:	88 b9       	out	0x08, r24	; 8
        wait( dt );
 19c:	c8 01       	movw	r24, r16
 19e:	0e 94 8d 00 	call	0x11a	; 0x11a <_Z4waiti>
    }
}

void beep( int dt )
{
    for( int j=0; j<300/dt; j++ )
 1a2:	21 96       	adiw	r28, 0x01	; 1
 1a4:	f5 cf       	rjmp	.-22     	; 0x190 <_Z4beepi+0x24>
    {
        BuzzerToggle;
        wait( dt );
    }
}
 1a6:	df 91       	pop	r29
 1a8:	cf 91       	pop	r28
 1aa:	1f 91       	pop	r17
 1ac:	0f 91       	pop	r16
 1ae:	ff 90       	pop	r15
 1b0:	ef 90       	pop	r14
 1b2:	df 90       	pop	r13
 1b4:	08 95       	ret

000001b6 <setup>:

void setup()
{
    DDRB = 0b11111111;
 1b6:	8f ef       	ldi	r24, 0xFF	; 255
 1b8:	84 b9       	out	0x04, r24	; 4
    DDRC = 0b11111111;
 1ba:	87 b9       	out	0x07, r24	; 7
    L13Set;
 1bc:	2d 9a       	sbi	0x05, 5	; 5
    DDRD  = 0b11111111;
 1be:	8a b9       	out	0x0a, r24	; 10
    bitClear( DDRD, bRX1 );
 1c0:	52 98       	cbi	0x0a, 2	; 10
    bitClear( DDRD, bRX2 );
 1c2:	53 98       	cbi	0x0a, 3	; 10
    bitClear( DDRD, bBouton );
 1c4:	54 98       	cbi	0x0a, 4	; 10

    man.setupReceive( RXPin1, MAN_600 );
 1c6:	41 e0       	ldi	r20, 0x01	; 1
 1c8:	62 e0       	ldi	r22, 0x02	; 2
 1ca:	8a ee       	ldi	r24, 0xEA	; 234
 1cc:	91 e0       	ldi	r25, 0x01	; 1
 1ce:	0e 94 55 05 	call	0xaaa	; 0xaaa <_ZN10Manchester12setupReceiveEhh>
    man.beginReceive();
 1d2:	8a ee       	ldi	r24, 0xEA	; 234
 1d4:	91 e0       	ldi	r25, 0x01	; 1
 1d6:	0e 94 70 05 	call	0xae0	; 0xae0 <_ZN10Manchester12beginReceiveEv>
  public:
    inline HardwareSerial(
      volatile uint8_t *ubrrh, volatile uint8_t *ubrrl,
      volatile uint8_t *ucsra, volatile uint8_t *ucsrb,
      volatile uint8_t *ucsrc, volatile uint8_t *udr);
    void begin(unsigned long baud) { begin(baud, SERIAL_8N1); }
 1da:	26 e0       	ldi	r18, 0x06	; 6
 1dc:	40 e8       	ldi	r20, 0x80	; 128
 1de:	55 e2       	ldi	r21, 0x25	; 37
 1e0:	60 e0       	ldi	r22, 0x00	; 0
 1e2:	70 e0       	ldi	r23, 0x00	; 0
 1e4:	84 e4       	ldi	r24, 0x44	; 68
 1e6:	91 e0       	ldi	r25, 0x01	; 1
 1e8:	0e 94 86 02 	call	0x50c	; 0x50c <_ZN14HardwareSerial5beginEmh>

    #if debug
        Serial.begin( 9600 );
        Serial.print( "\n\n# RX READY #" );
 1ec:	65 e0       	ldi	r22, 0x05	; 5
 1ee:	71 e0       	ldi	r23, 0x01	; 1
 1f0:	84 e4       	ldi	r24, 0x44	; 68
 1f2:	91 e0       	ldi	r25, 0x01	; 1
 1f4:	0c 94 cb 03 	jmp	0x796	; 0x796 <_ZN5Print5printEPKc>

000001f8 <loop>:
}

void loop()
{

    if( man.receiveComplete() )
 1f8:	8a ee       	ldi	r24, 0xEA	; 234
 1fa:	91 e0       	ldi	r25, 0x01	; 1
 1fc:	0e 94 31 05 	call	0xa62	; 0xa62 <_ZN10Manchester15receiveCompleteEv>
 200:	88 23       	and	r24, r24
 202:	09 f4       	brne	.+2      	; 0x206 <loop+0xe>
 204:	98 c0       	rjmp	.+304    	; 0x336 <loop+0x13e>
    {
        #if debug
            t2 = millis();
 206:	0e 94 e4 04 	call	0x9c8	; 0x9c8 <millis>
 20a:	60 93 3a 01 	sts	0x013A, r22
 20e:	70 93 3b 01 	sts	0x013B, r23
 212:	80 93 3c 01 	sts	0x013C, r24
 216:	90 93 3d 01 	sts	0x013D, r25
            Serial.print( "\nt2 = " ); Serial.print( t2 );
 21a:	64 e1       	ldi	r22, 0x14	; 20
 21c:	71 e0       	ldi	r23, 0x01	; 1
 21e:	84 e4       	ldi	r24, 0x44	; 68
 220:	91 e0       	ldi	r25, 0x01	; 1
 222:	0e 94 cb 03 	call	0x796	; 0x796 <_ZN5Print5printEPKc>
 226:	40 91 3a 01 	lds	r20, 0x013A
 22a:	50 91 3b 01 	lds	r21, 0x013B
 22e:	60 91 3c 01 	lds	r22, 0x013C
 232:	70 91 3d 01 	lds	r23, 0x013D
 236:	2a e0       	ldi	r18, 0x0A	; 10
 238:	30 e0       	ldi	r19, 0x00	; 0
 23a:	84 e4       	ldi	r24, 0x44	; 68
 23c:	91 e0       	ldi	r25, 0x01	; 1
 23e:	0e 94 2d 04 	call	0x85a	; 0x85a <_ZN5Print5printEli>
            Serial.print( "\ndt = " ); Serial.print( t2 - t1 );
 242:	6b e1       	ldi	r22, 0x1B	; 27
 244:	71 e0       	ldi	r23, 0x01	; 1
 246:	84 e4       	ldi	r24, 0x44	; 68
 248:	91 e0       	ldi	r25, 0x01	; 1
 24a:	0e 94 cb 03 	call	0x796	; 0x796 <_ZN5Print5printEPKc>
 24e:	40 91 3a 01 	lds	r20, 0x013A
 252:	50 91 3b 01 	lds	r21, 0x013B
 256:	60 91 3c 01 	lds	r22, 0x013C
 25a:	70 91 3d 01 	lds	r23, 0x013D
 25e:	80 91 3e 01 	lds	r24, 0x013E
 262:	90 91 3f 01 	lds	r25, 0x013F
 266:	a0 91 40 01 	lds	r26, 0x0140
 26a:	b0 91 41 01 	lds	r27, 0x0141
 26e:	48 1b       	sub	r20, r24
 270:	59 0b       	sbc	r21, r25
 272:	6a 0b       	sbc	r22, r26
 274:	7b 0b       	sbc	r23, r27
 276:	2a e0       	ldi	r18, 0x0A	; 10
 278:	30 e0       	ldi	r19, 0x00	; 0
 27a:	84 e4       	ldi	r24, 0x44	; 68
 27c:	91 e0       	ldi	r25, 0x01	; 1
 27e:	0e 94 2d 04 	call	0x85a	; 0x85a <_ZN5Print5printEli>
        #endif

        L13Set;
 282:	2d 9a       	sbi	0x05, 5	; 5
        msg = man.getMessage();
 284:	8a ee       	ldi	r24, 0xEA	; 234
 286:	91 e0       	ldi	r25, 0x01	; 1
 288:	0e 94 7d 05 	call	0xafa	; 0xafa <_ZN10Manchester10getMessageEv>
 28c:	90 93 43 01 	sts	0x0143, r25
 290:	80 93 42 01 	sts	0x0142, r24
             if( msg == codeBouton1 ){ L0Set;   L1Clear; L2Clear; L3Clear; beep(  5 ); }
 294:	85 38       	cpi	r24, 0x85	; 133
 296:	2e e4       	ldi	r18, 0x4E	; 78
 298:	92 07       	cpc	r25, r18
 29a:	29 f4       	brne	.+10     	; 0x2a6 <loop+0xae>
 29c:	2c 9a       	sbi	0x05, 4	; 5
 29e:	2b 98       	cbi	0x05, 3	; 5
 2a0:	2a 98       	cbi	0x05, 2	; 5
 2a2:	29 98       	cbi	0x05, 1	; 5
 2a4:	2c c0       	rjmp	.+88     	; 0x2fe <loop+0x106>
        else if( msg == codeBouton2 ){ L0Clear; L1Set;   L2Clear; L3Clear; beep( 10 ); }
 2a6:	8a 3e       	cpi	r24, 0xEA	; 234
 2a8:	2e e4       	ldi	r18, 0x4E	; 78
 2aa:	92 07       	cpc	r25, r18
 2ac:	39 f4       	brne	.+14     	; 0x2bc <loop+0xc4>
 2ae:	2c 98       	cbi	0x05, 4	; 5
 2b0:	2b 9a       	sbi	0x05, 3	; 5
 2b2:	2a 98       	cbi	0x05, 2	; 5
 2b4:	29 98       	cbi	0x05, 1	; 5
 2b6:	8a e0       	ldi	r24, 0x0A	; 10
 2b8:	90 e0       	ldi	r25, 0x00	; 0
 2ba:	23 c0       	rjmp	.+70     	; 0x302 <loop+0x10a>
        else if( msg == codeBouton3 ){ L0Clear; L1Clear; L2Set;   L3Clear; beep( 15 ); }
 2bc:	8f 34       	cpi	r24, 0x4F	; 79
 2be:	2f e4       	ldi	r18, 0x4F	; 79
 2c0:	92 07       	cpc	r25, r18
 2c2:	39 f4       	brne	.+14     	; 0x2d2 <loop+0xda>
 2c4:	2c 98       	cbi	0x05, 4	; 5
 2c6:	2b 98       	cbi	0x05, 3	; 5
 2c8:	2a 9a       	sbi	0x05, 2	; 5
 2ca:	29 98       	cbi	0x05, 1	; 5
 2cc:	8f e0       	ldi	r24, 0x0F	; 15
 2ce:	90 e0       	ldi	r25, 0x00	; 0
 2d0:	18 c0       	rjmp	.+48     	; 0x302 <loop+0x10a>
        else if( msg == codeBouton4 ){ L0Clear; L1Clear; L2Clear; L3Set;   beep( 20 ); }
 2d2:	84 3b       	cpi	r24, 0xB4	; 180
 2d4:	9f 44       	sbci	r25, 0x4F	; 79
 2d6:	39 f4       	brne	.+14     	; 0x2e6 <loop+0xee>
 2d8:	2c 98       	cbi	0x05, 4	; 5
 2da:	2b 98       	cbi	0x05, 3	; 5
 2dc:	2a 98       	cbi	0x05, 2	; 5
 2de:	29 9a       	sbi	0x05, 1	; 5
 2e0:	84 e1       	ldi	r24, 0x14	; 20
 2e2:	90 e0       	ldi	r25, 0x00	; 0
 2e4:	0e c0       	rjmp	.+28     	; 0x302 <loop+0x10a>
        else                         { L0Set;   L1Set;   L2Set;   L3Set;   beep( 5 ); wait( 2 ); beep( 5 ); }
 2e6:	2c 9a       	sbi	0x05, 4	; 5
 2e8:	2b 9a       	sbi	0x05, 3	; 5
 2ea:	2a 9a       	sbi	0x05, 2	; 5
 2ec:	29 9a       	sbi	0x05, 1	; 5
 2ee:	85 e0       	ldi	r24, 0x05	; 5
 2f0:	90 e0       	ldi	r25, 0x00	; 0
 2f2:	0e 94 b6 00 	call	0x16c	; 0x16c <_Z4beepi>
 2f6:	82 e0       	ldi	r24, 0x02	; 2
 2f8:	90 e0       	ldi	r25, 0x00	; 0
 2fa:	0e 94 8d 00 	call	0x11a	; 0x11a <_Z4waiti>
 2fe:	85 e0       	ldi	r24, 0x05	; 5
 300:	90 e0       	ldi	r25, 0x00	; 0
 302:	0e 94 b6 00 	call	0x16c	; 0x16c <_Z4beepi>
        #if debug
            Serial.print( "\nmsg = " ); Serial.print( msg );
 306:	62 e2       	ldi	r22, 0x22	; 34
 308:	71 e0       	ldi	r23, 0x01	; 1
 30a:	84 e4       	ldi	r24, 0x44	; 68
 30c:	91 e0       	ldi	r25, 0x01	; 1
 30e:	0e 94 cb 03 	call	0x796	; 0x796 <_ZN5Print5printEPKc>
 312:	60 91 42 01 	lds	r22, 0x0142
 316:	70 91 43 01 	lds	r23, 0x0143
 31a:	4a e0       	ldi	r20, 0x0A	; 10
 31c:	50 e0       	ldi	r21, 0x00	; 0
 31e:	84 e4       	ldi	r24, 0x44	; 68
 320:	91 e0       	ldi	r25, 0x01	; 1
 322:	0e 94 84 04 	call	0x908	; 0x908 <_ZN5Print5printEji>
        #endif
        wait( 2000 );
 326:	80 ed       	ldi	r24, 0xD0	; 208
 328:	97 e0       	ldi	r25, 0x07	; 7
 32a:	0e 94 8d 00 	call	0x11a	; 0x11a <_Z4waiti>
        man.beginReceive();
 32e:	8a ee       	ldi	r24, 0xEA	; 234
 330:	91 e0       	ldi	r25, 0x01	; 1
 332:	0c 94 70 05 	jmp	0xae0	; 0xae0 <_ZN10Manchester12beginReceiveEv>
    }
    else
    {
        L13Clear;
 336:	2d 98       	cbi	0x05, 5	; 5
        L0Clear;   L1Clear;   L2Clear;   L3Clear;
 338:	2c 98       	cbi	0x05, 4	; 5
 33a:	2b 98       	cbi	0x05, 3	; 5
 33c:	2a 98       	cbi	0x05, 2	; 5
 33e:	29 98       	cbi	0x05, 1	; 5
 340:	08 95       	ret

00000342 <_ZN14HardwareSerial9availableEv>:
  // clear any received data
  _rx_buffer_head = _rx_buffer_tail;
}

int HardwareSerial::available(void)
{
 342:	fc 01       	movw	r30, r24
  return (int)(SERIAL_RX_BUFFER_SIZE + _rx_buffer_head - _rx_buffer_tail) % SERIAL_RX_BUFFER_SIZE;
 344:	81 8d       	ldd	r24, Z+25	; 0x19
 346:	22 8d       	ldd	r18, Z+26	; 0x1a
 348:	90 e0       	ldi	r25, 0x00	; 0
 34a:	80 5c       	subi	r24, 0xC0	; 192
 34c:	9f 4f       	sbci	r25, 0xFF	; 255
 34e:	82 1b       	sub	r24, r18
 350:	91 09       	sbc	r25, r1
 352:	60 e4       	ldi	r22, 0x40	; 64
 354:	70 e0       	ldi	r23, 0x00	; 0
 356:	0e 94 0b 07 	call	0xe16	; 0xe16 <__divmodhi4>
}
 35a:	08 95       	ret

0000035c <_ZN14HardwareSerial4peekEv>:

int HardwareSerial::peek(void)
{
 35c:	fc 01       	movw	r30, r24
  if (_rx_buffer_head == _rx_buffer_tail) {
 35e:	91 8d       	ldd	r25, Z+25	; 0x19
 360:	82 8d       	ldd	r24, Z+26	; 0x1a
 362:	98 17       	cp	r25, r24
 364:	31 f0       	breq	.+12     	; 0x372 <_ZN14HardwareSerial4peekEv+0x16>
    return -1;
  } else {
    return _rx_buffer[_rx_buffer_tail];
 366:	82 8d       	ldd	r24, Z+26	; 0x1a
 368:	e8 0f       	add	r30, r24
 36a:	f1 1d       	adc	r31, r1
 36c:	85 8d       	ldd	r24, Z+29	; 0x1d
 36e:	90 e0       	ldi	r25, 0x00	; 0
 370:	08 95       	ret
}

int HardwareSerial::peek(void)
{
  if (_rx_buffer_head == _rx_buffer_tail) {
    return -1;
 372:	8f ef       	ldi	r24, 0xFF	; 255
 374:	9f ef       	ldi	r25, 0xFF	; 255
  } else {
    return _rx_buffer[_rx_buffer_tail];
  }
}
 376:	08 95       	ret

00000378 <_ZN14HardwareSerial4readEv>:

int HardwareSerial::read(void)
{
 378:	fc 01       	movw	r30, r24
  // if the head isn't ahead of the tail, we don't have any characters
  if (_rx_buffer_head == _rx_buffer_tail) {
 37a:	91 8d       	ldd	r25, Z+25	; 0x19
 37c:	82 8d       	ldd	r24, Z+26	; 0x1a
 37e:	98 17       	cp	r25, r24
 380:	61 f0       	breq	.+24     	; 0x39a <_ZN14HardwareSerial4readEv+0x22>
    return -1;
  } else {
    unsigned char c = _rx_buffer[_rx_buffer_tail];
 382:	82 8d       	ldd	r24, Z+26	; 0x1a
 384:	df 01       	movw	r26, r30
 386:	a8 0f       	add	r26, r24
 388:	b1 1d       	adc	r27, r1
 38a:	5d 96       	adiw	r26, 0x1d	; 29
 38c:	8c 91       	ld	r24, X
    _rx_buffer_tail = (rx_buffer_index_t)(_rx_buffer_tail + 1) % SERIAL_RX_BUFFER_SIZE;
 38e:	92 8d       	ldd	r25, Z+26	; 0x1a
 390:	9f 5f       	subi	r25, 0xFF	; 255
 392:	9f 73       	andi	r25, 0x3F	; 63
 394:	92 8f       	std	Z+26, r25	; 0x1a
    return c;
 396:	90 e0       	ldi	r25, 0x00	; 0
 398:	08 95       	ret

int HardwareSerial::read(void)
{
  // if the head isn't ahead of the tail, we don't have any characters
  if (_rx_buffer_head == _rx_buffer_tail) {
    return -1;
 39a:	8f ef       	ldi	r24, 0xFF	; 255
 39c:	9f ef       	ldi	r25, 0xFF	; 255
  } else {
    unsigned char c = _rx_buffer[_rx_buffer_tail];
    _rx_buffer_tail = (rx_buffer_index_t)(_rx_buffer_tail + 1) % SERIAL_RX_BUFFER_SIZE;
    return c;
  }
}
 39e:	08 95       	ret

000003a0 <_Z14serialEventRunv>:
#endif

void serialEventRun(void)
{
#if defined(HAVE_HWSERIAL0)
  if (Serial0_available && serialEvent && Serial0_available()) serialEvent();
 3a0:	80 e4       	ldi	r24, 0x40	; 64
 3a2:	93 e0       	ldi	r25, 0x03	; 3
 3a4:	89 2b       	or	r24, r25
 3a6:	49 f0       	breq	.+18     	; 0x3ba <_Z14serialEventRunv+0x1a>
 3a8:	80 e0       	ldi	r24, 0x00	; 0
 3aa:	90 e0       	ldi	r25, 0x00	; 0
 3ac:	89 2b       	or	r24, r25
 3ae:	29 f0       	breq	.+10     	; 0x3ba <_Z14serialEventRunv+0x1a>
 3b0:	0e 94 40 03 	call	0x680	; 0x680 <_Z17Serial0_availablev>
 3b4:	81 11       	cpse	r24, r1
 3b6:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>
 3ba:	08 95       	ret

000003bc <_ZN14HardwareSerial17_tx_udr_empty_irqEv>:
}

// Actual interrupt handlers //////////////////////////////////////////////////////////////

void HardwareSerial::_tx_udr_empty_irq(void)
{
 3bc:	fc 01       	movw	r30, r24
  // If interrupts are enabled, there must be more data in the output
  // buffer. Send the next byte
  unsigned char c = _tx_buffer[_tx_buffer_tail];
 3be:	84 8d       	ldd	r24, Z+28	; 0x1c
 3c0:	df 01       	movw	r26, r30
 3c2:	a8 0f       	add	r26, r24
 3c4:	b1 1d       	adc	r27, r1
 3c6:	a3 5a       	subi	r26, 0xA3	; 163
 3c8:	bf 4f       	sbci	r27, 0xFF	; 255
 3ca:	2c 91       	ld	r18, X
  _tx_buffer_tail = (_tx_buffer_tail + 1) % SERIAL_TX_BUFFER_SIZE;
 3cc:	84 8d       	ldd	r24, Z+28	; 0x1c
 3ce:	90 e0       	ldi	r25, 0x00	; 0
 3d0:	01 96       	adiw	r24, 0x01	; 1
 3d2:	8f 73       	andi	r24, 0x3F	; 63
 3d4:	99 27       	eor	r25, r25
 3d6:	84 8f       	std	Z+28, r24	; 0x1c

  *_udr = c;
 3d8:	a6 89       	ldd	r26, Z+22	; 0x16
 3da:	b7 89       	ldd	r27, Z+23	; 0x17
 3dc:	2c 93       	st	X, r18

  // clear the TXC bit -- "can be cleared by writing a one to its bit
  // location". This makes sure flush() won't return until the bytes
  // actually got written
  sbi(*_ucsra, TXC0);
 3de:	a0 89       	ldd	r26, Z+16	; 0x10
 3e0:	b1 89       	ldd	r27, Z+17	; 0x11
 3e2:	8c 91       	ld	r24, X
 3e4:	80 64       	ori	r24, 0x40	; 64
 3e6:	8c 93       	st	X, r24

  if (_tx_buffer_head == _tx_buffer_tail) {
 3e8:	93 8d       	ldd	r25, Z+27	; 0x1b
 3ea:	84 8d       	ldd	r24, Z+28	; 0x1c
 3ec:	98 13       	cpse	r25, r24
 3ee:	06 c0       	rjmp	.+12     	; 0x3fc <_ZN14HardwareSerial17_tx_udr_empty_irqEv+0x40>
    // Buffer empty, so disable interrupts
    cbi(*_ucsrb, UDRIE0);
 3f0:	02 88       	ldd	r0, Z+18	; 0x12
 3f2:	f3 89       	ldd	r31, Z+19	; 0x13
 3f4:	e0 2d       	mov	r30, r0
 3f6:	80 81       	ld	r24, Z
 3f8:	8f 7d       	andi	r24, 0xDF	; 223
 3fa:	80 83       	st	Z, r24
 3fc:	08 95       	ret

000003fe <_ZN14HardwareSerial5flushEv>:
  if (head >= tail) return SERIAL_TX_BUFFER_SIZE - 1 - head + tail;
  return tail - head - 1;
}

void HardwareSerial::flush()
{
 3fe:	cf 93       	push	r28
 400:	df 93       	push	r29
 402:	ec 01       	movw	r28, r24
  // If we have never written a byte, no need to flush. This special
  // case is needed since there is no way to force the TXC (transmit
  // complete) bit to 1 during initialization
  if (!_written)
 404:	88 8d       	ldd	r24, Y+24	; 0x18
 406:	88 23       	and	r24, r24
 408:	c9 f0       	breq	.+50     	; 0x43c <_ZN14HardwareSerial5flushEv+0x3e>
    return;

  while (bit_is_set(*_ucsrb, UDRIE0) || bit_is_clear(*_ucsra, TXC0)) {
 40a:	ea 89       	ldd	r30, Y+18	; 0x12
 40c:	fb 89       	ldd	r31, Y+19	; 0x13
 40e:	80 81       	ld	r24, Z
 410:	85 fd       	sbrc	r24, 5
 412:	05 c0       	rjmp	.+10     	; 0x41e <_ZN14HardwareSerial5flushEv+0x20>
 414:	a8 89       	ldd	r26, Y+16	; 0x10
 416:	b9 89       	ldd	r27, Y+17	; 0x11
 418:	8c 91       	ld	r24, X
 41a:	86 fd       	sbrc	r24, 6
 41c:	0f c0       	rjmp	.+30     	; 0x43c <_ZN14HardwareSerial5flushEv+0x3e>
    if (bit_is_clear(SREG, SREG_I) && bit_is_set(*_ucsrb, UDRIE0))
 41e:	0f b6       	in	r0, 0x3f	; 63
 420:	07 fc       	sbrc	r0, 7
 422:	f5 cf       	rjmp	.-22     	; 0x40e <_ZN14HardwareSerial5flushEv+0x10>
 424:	80 81       	ld	r24, Z
 426:	85 ff       	sbrs	r24, 5
 428:	f2 cf       	rjmp	.-28     	; 0x40e <_ZN14HardwareSerial5flushEv+0x10>
	// Interrupts are globally disabled, but the DR empty
	// interrupt should be enabled, so poll the DR empty flag to
	// prevent deadlock
	if (bit_is_set(*_ucsra, UDRE0))
 42a:	a8 89       	ldd	r26, Y+16	; 0x10
 42c:	b9 89       	ldd	r27, Y+17	; 0x11
 42e:	8c 91       	ld	r24, X
 430:	85 ff       	sbrs	r24, 5
 432:	ed cf       	rjmp	.-38     	; 0x40e <_ZN14HardwareSerial5flushEv+0x10>
	  _tx_udr_empty_irq();
 434:	ce 01       	movw	r24, r28
 436:	0e 94 de 01 	call	0x3bc	; 0x3bc <_ZN14HardwareSerial17_tx_udr_empty_irqEv>
 43a:	e7 cf       	rjmp	.-50     	; 0x40a <_ZN14HardwareSerial5flushEv+0xc>
  }
  // If we get here, nothing is queued anymore (DRIE is disabled) and
  // the hardware finished tranmission (TXC is set).
}
 43c:	df 91       	pop	r29
 43e:	cf 91       	pop	r28
 440:	08 95       	ret

00000442 <_ZN14HardwareSerial5writeEh>:

size_t HardwareSerial::write(uint8_t c)
{
 442:	cf 92       	push	r12
 444:	df 92       	push	r13
 446:	ff 92       	push	r15
 448:	0f 93       	push	r16
 44a:	1f 93       	push	r17
 44c:	cf 93       	push	r28
 44e:	df 93       	push	r29
 450:	1f 92       	push	r1
 452:	cd b7       	in	r28, 0x3d	; 61
 454:	de b7       	in	r29, 0x3e	; 62
 456:	6c 01       	movw	r12, r24
  // If the buffer and the data register is empty, just write the byte
  // to the data register and be done. This shortcut helps
  // significantly improve the effective datarate at high (>
  // 500kbit/s) bitrates, where interrupt overhead becomes a slowdown.
  if (_tx_buffer_head == _tx_buffer_tail && bit_is_set(*_ucsra, UDRE0)) {
 458:	dc 01       	movw	r26, r24
 45a:	5b 96       	adiw	r26, 0x1b	; 27
 45c:	9c 91       	ld	r25, X
 45e:	5b 97       	sbiw	r26, 0x1b	; 27
 460:	5c 96       	adiw	r26, 0x1c	; 28
 462:	8c 91       	ld	r24, X
 464:	5c 97       	sbiw	r26, 0x1c	; 28
 466:	98 13       	cpse	r25, r24
 468:	07 c0       	rjmp	.+14     	; 0x478 <_ZN14HardwareSerial5writeEh+0x36>
 46a:	50 96       	adiw	r26, 0x10	; 16
 46c:	ed 91       	ld	r30, X+
 46e:	fc 91       	ld	r31, X
 470:	51 97       	sbiw	r26, 0x11	; 17
 472:	80 81       	ld	r24, Z
 474:	85 fd       	sbrc	r24, 5
 476:	32 c0       	rjmp	.+100    	; 0x4dc <_ZN14HardwareSerial5writeEh+0x9a>
    *_udr = c;
    sbi(*_ucsra, TXC0);
    return 1;
  }
  tx_buffer_index_t i = (_tx_buffer_head + 1) % SERIAL_TX_BUFFER_SIZE;
 478:	f6 01       	movw	r30, r12
 47a:	03 8d       	ldd	r16, Z+27	; 0x1b
 47c:	10 e0       	ldi	r17, 0x00	; 0
 47e:	0f 5f       	subi	r16, 0xFF	; 255
 480:	1f 4f       	sbci	r17, 0xFF	; 255
 482:	0f 73       	andi	r16, 0x3F	; 63
 484:	11 27       	eor	r17, r17
 486:	f0 2e       	mov	r15, r16
	
  // If the output buffer is full, there's nothing for it other than to 
  // wait for the interrupt handler to empty it a bit
  while (i == _tx_buffer_tail) {
 488:	f6 01       	movw	r30, r12
 48a:	84 8d       	ldd	r24, Z+28	; 0x1c
 48c:	f8 12       	cpse	r15, r24
 48e:	11 c0       	rjmp	.+34     	; 0x4b2 <_ZN14HardwareSerial5writeEh+0x70>
    if (bit_is_clear(SREG, SREG_I)) {
 490:	0f b6       	in	r0, 0x3f	; 63
 492:	07 fc       	sbrc	r0, 7
 494:	f9 cf       	rjmp	.-14     	; 0x488 <_ZN14HardwareSerial5writeEh+0x46>
      // Interrupts are disabled, so we'll have to poll the data
      // register empty flag ourselves. If it is set, pretend an
      // interrupt has happened and call the handler to free up
      // space for us.
      if(bit_is_set(*_ucsra, UDRE0))
 496:	d6 01       	movw	r26, r12
 498:	50 96       	adiw	r26, 0x10	; 16
 49a:	ed 91       	ld	r30, X+
 49c:	fc 91       	ld	r31, X
 49e:	51 97       	sbiw	r26, 0x11	; 17
 4a0:	80 81       	ld	r24, Z
 4a2:	85 ff       	sbrs	r24, 5
 4a4:	f1 cf       	rjmp	.-30     	; 0x488 <_ZN14HardwareSerial5writeEh+0x46>
	_tx_udr_empty_irq();
 4a6:	c6 01       	movw	r24, r12
 4a8:	69 83       	std	Y+1, r22	; 0x01
 4aa:	0e 94 de 01 	call	0x3bc	; 0x3bc <_ZN14HardwareSerial17_tx_udr_empty_irqEv>
 4ae:	69 81       	ldd	r22, Y+1	; 0x01
 4b0:	eb cf       	rjmp	.-42     	; 0x488 <_ZN14HardwareSerial5writeEh+0x46>
    } else {
      // nop, the interrupt handler will free up space for us
    }
  }

  _tx_buffer[_tx_buffer_head] = c;
 4b2:	83 8d       	ldd	r24, Z+27	; 0x1b
 4b4:	e8 0f       	add	r30, r24
 4b6:	f1 1d       	adc	r31, r1
 4b8:	e3 5a       	subi	r30, 0xA3	; 163
 4ba:	ff 4f       	sbci	r31, 0xFF	; 255
 4bc:	60 83       	st	Z, r22
  _tx_buffer_head = i;
 4be:	d6 01       	movw	r26, r12
 4c0:	5b 96       	adiw	r26, 0x1b	; 27
 4c2:	0c 93       	st	X, r16
 4c4:	5b 97       	sbiw	r26, 0x1b	; 27
	
  sbi(*_ucsrb, UDRIE0);
 4c6:	52 96       	adiw	r26, 0x12	; 18
 4c8:	ed 91       	ld	r30, X+
 4ca:	fc 91       	ld	r31, X
 4cc:	53 97       	sbiw	r26, 0x13	; 19
 4ce:	80 81       	ld	r24, Z
 4d0:	80 62       	ori	r24, 0x20	; 32
 4d2:	80 83       	st	Z, r24
  _written = true;
 4d4:	81 e0       	ldi	r24, 0x01	; 1
 4d6:	58 96       	adiw	r26, 0x18	; 24
 4d8:	8c 93       	st	X, r24
 4da:	0d c0       	rjmp	.+26     	; 0x4f6 <_ZN14HardwareSerial5writeEh+0xb4>
  // If the buffer and the data register is empty, just write the byte
  // to the data register and be done. This shortcut helps
  // significantly improve the effective datarate at high (>
  // 500kbit/s) bitrates, where interrupt overhead becomes a slowdown.
  if (_tx_buffer_head == _tx_buffer_tail && bit_is_set(*_ucsra, UDRE0)) {
    *_udr = c;
 4dc:	d6 01       	movw	r26, r12
 4de:	56 96       	adiw	r26, 0x16	; 22
 4e0:	ed 91       	ld	r30, X+
 4e2:	fc 91       	ld	r31, X
 4e4:	57 97       	sbiw	r26, 0x17	; 23
 4e6:	60 83       	st	Z, r22
    sbi(*_ucsra, TXC0);
 4e8:	50 96       	adiw	r26, 0x10	; 16
 4ea:	ed 91       	ld	r30, X+
 4ec:	fc 91       	ld	r31, X
 4ee:	51 97       	sbiw	r26, 0x11	; 17
 4f0:	80 81       	ld	r24, Z
 4f2:	80 64       	ori	r24, 0x40	; 64
 4f4:	80 83       	st	Z, r24
	
  sbi(*_ucsrb, UDRIE0);
  _written = true;
  
  return 1;
}
 4f6:	81 e0       	ldi	r24, 0x01	; 1
 4f8:	90 e0       	ldi	r25, 0x00	; 0
 4fa:	0f 90       	pop	r0
 4fc:	df 91       	pop	r29
 4fe:	cf 91       	pop	r28
 500:	1f 91       	pop	r17
 502:	0f 91       	pop	r16
 504:	ff 90       	pop	r15
 506:	df 90       	pop	r13
 508:	cf 90       	pop	r12
 50a:	08 95       	ret

0000050c <_ZN14HardwareSerial5beginEmh>:
}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(unsigned long baud, byte config)
{
 50c:	bf 92       	push	r11
 50e:	cf 92       	push	r12
 510:	df 92       	push	r13
 512:	ef 92       	push	r14
 514:	ff 92       	push	r15
 516:	cf 93       	push	r28
 518:	df 93       	push	r29
 51a:	ec 01       	movw	r28, r24
 51c:	6a 01       	movw	r12, r20
 51e:	7b 01       	movw	r14, r22
 520:	b2 2e       	mov	r11, r18
  // Try u2x mode first
  uint16_t baud_setting = (F_CPU / 4 / baud - 1) / 2;
  *_ucsra = 1 << U2X0;
 522:	e8 89       	ldd	r30, Y+16	; 0x10
 524:	f9 89       	ldd	r31, Y+17	; 0x11
 526:	82 e0       	ldi	r24, 0x02	; 2
 528:	80 83       	st	Z, r24
  // hardcoded exception for 57600 for compatibility with the bootloader
  // shipped with the Duemilanove and previous boards and the firmware
  // on the 8U2 on the Uno and Mega 2560. Also, The baud_setting cannot
  // be > 4095, so switch back to non-u2x mode if the baud rate is too
  // low.
  if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
 52a:	41 15       	cp	r20, r1
 52c:	81 ee       	ldi	r24, 0xE1	; 225
 52e:	58 07       	cpc	r21, r24
 530:	61 05       	cpc	r22, r1
 532:	71 05       	cpc	r23, r1
 534:	a1 f0       	breq	.+40     	; 0x55e <_ZN14HardwareSerial5beginEmh+0x52>
// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(unsigned long baud, byte config)
{
  // Try u2x mode first
  uint16_t baud_setting = (F_CPU / 4 / baud - 1) / 2;
 536:	60 e0       	ldi	r22, 0x00	; 0
 538:	79 e0       	ldi	r23, 0x09	; 9
 53a:	8d e3       	ldi	r24, 0x3D	; 61
 53c:	90 e0       	ldi	r25, 0x00	; 0
 53e:	a7 01       	movw	r20, r14
 540:	96 01       	movw	r18, r12
 542:	0e 94 1f 07 	call	0xe3e	; 0xe3e <__udivmodsi4>
 546:	21 50       	subi	r18, 0x01	; 1
 548:	31 09       	sbc	r19, r1
 54a:	41 09       	sbc	r20, r1
 54c:	51 09       	sbc	r21, r1
 54e:	56 95       	lsr	r21
 550:	47 95       	ror	r20
 552:	37 95       	ror	r19
 554:	27 95       	ror	r18
  // hardcoded exception for 57600 for compatibility with the bootloader
  // shipped with the Duemilanove and previous boards and the firmware
  // on the 8U2 on the Uno and Mega 2560. Also, The baud_setting cannot
  // be > 4095, so switch back to non-u2x mode if the baud rate is too
  // low.
  if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
 556:	21 15       	cp	r18, r1
 558:	80 e1       	ldi	r24, 0x10	; 16
 55a:	38 07       	cpc	r19, r24
 55c:	98 f0       	brcs	.+38     	; 0x584 <_ZN14HardwareSerial5beginEmh+0x78>
  {
    *_ucsra = 0;
 55e:	e8 89       	ldd	r30, Y+16	; 0x10
 560:	f9 89       	ldd	r31, Y+17	; 0x11
 562:	10 82       	st	Z, r1
    baud_setting = (F_CPU / 8 / baud - 1) / 2;
 564:	60 e8       	ldi	r22, 0x80	; 128
 566:	74 e8       	ldi	r23, 0x84	; 132
 568:	8e e1       	ldi	r24, 0x1E	; 30
 56a:	90 e0       	ldi	r25, 0x00	; 0
 56c:	a7 01       	movw	r20, r14
 56e:	96 01       	movw	r18, r12
 570:	0e 94 1f 07 	call	0xe3e	; 0xe3e <__udivmodsi4>
 574:	21 50       	subi	r18, 0x01	; 1
 576:	31 09       	sbc	r19, r1
 578:	41 09       	sbc	r20, r1
 57a:	51 09       	sbc	r21, r1
 57c:	56 95       	lsr	r21
 57e:	47 95       	ror	r20
 580:	37 95       	ror	r19
 582:	27 95       	ror	r18
  }

  // assign the baud_setting, a.k.a. ubrr (USART Baud Rate Register)
  *_ubrrh = baud_setting >> 8;
 584:	ec 85       	ldd	r30, Y+12	; 0x0c
 586:	fd 85       	ldd	r31, Y+13	; 0x0d
 588:	30 83       	st	Z, r19
  *_ubrrl = baud_setting;
 58a:	ee 85       	ldd	r30, Y+14	; 0x0e
 58c:	ff 85       	ldd	r31, Y+15	; 0x0f
 58e:	20 83       	st	Z, r18

  _written = false;
 590:	18 8e       	std	Y+24, r1	; 0x18

  //set the data bits, parity, and stop bits
#if defined(__AVR_ATmega8__)
  config |= 0x80; // select UCSRC register (shared with UBRRH)
#endif
  *_ucsrc = config;
 592:	ec 89       	ldd	r30, Y+20	; 0x14
 594:	fd 89       	ldd	r31, Y+21	; 0x15
 596:	b0 82       	st	Z, r11
  
  sbi(*_ucsrb, RXEN0);
 598:	ea 89       	ldd	r30, Y+18	; 0x12
 59a:	fb 89       	ldd	r31, Y+19	; 0x13
 59c:	80 81       	ld	r24, Z
 59e:	80 61       	ori	r24, 0x10	; 16
 5a0:	80 83       	st	Z, r24
  sbi(*_ucsrb, TXEN0);
 5a2:	ea 89       	ldd	r30, Y+18	; 0x12
 5a4:	fb 89       	ldd	r31, Y+19	; 0x13
 5a6:	80 81       	ld	r24, Z
 5a8:	88 60       	ori	r24, 0x08	; 8
 5aa:	80 83       	st	Z, r24
  sbi(*_ucsrb, RXCIE0);
 5ac:	ea 89       	ldd	r30, Y+18	; 0x12
 5ae:	fb 89       	ldd	r31, Y+19	; 0x13
 5b0:	80 81       	ld	r24, Z
 5b2:	80 68       	ori	r24, 0x80	; 128
 5b4:	80 83       	st	Z, r24
  cbi(*_ucsrb, UDRIE0);
 5b6:	ea 89       	ldd	r30, Y+18	; 0x12
 5b8:	fb 89       	ldd	r31, Y+19	; 0x13
 5ba:	80 81       	ld	r24, Z
 5bc:	8f 7d       	andi	r24, 0xDF	; 223
 5be:	80 83       	st	Z, r24
}
 5c0:	df 91       	pop	r29
 5c2:	cf 91       	pop	r28
 5c4:	ff 90       	pop	r15
 5c6:	ef 90       	pop	r14
 5c8:	df 90       	pop	r13
 5ca:	cf 90       	pop	r12
 5cc:	bf 90       	pop	r11
 5ce:	08 95       	ret

000005d0 <__vector_18>:
#elif defined(USART_RXC_vect)
  ISR(USART_RXC_vect) // ATmega8
#else
  #error "Don't know what the Data Received vector is called for Serial"
#endif
  {
 5d0:	1f 92       	push	r1
 5d2:	0f 92       	push	r0
 5d4:	0f b6       	in	r0, 0x3f	; 63
 5d6:	0f 92       	push	r0
 5d8:	11 24       	eor	r1, r1
 5da:	2f 93       	push	r18
 5dc:	8f 93       	push	r24
 5de:	9f 93       	push	r25
 5e0:	ef 93       	push	r30
 5e2:	ff 93       	push	r31

// Actual interrupt handlers //////////////////////////////////////////////////////////////

void HardwareSerial::_rx_complete_irq(void)
{
  if (bit_is_clear(*_ucsra, UPE0)) {
 5e4:	e0 91 54 01 	lds	r30, 0x0154
 5e8:	f0 91 55 01 	lds	r31, 0x0155
 5ec:	80 81       	ld	r24, Z
 5ee:	e0 91 5a 01 	lds	r30, 0x015A
 5f2:	f0 91 5b 01 	lds	r31, 0x015B
 5f6:	82 fd       	sbrc	r24, 2
 5f8:	12 c0       	rjmp	.+36     	; 0x61e <__vector_18+0x4e>
    // No Parity error, read byte and store it in the buffer if there is
    // room
    unsigned char c = *_udr;
 5fa:	90 81       	ld	r25, Z
    rx_buffer_index_t i = (unsigned int)(_rx_buffer_head + 1) % SERIAL_RX_BUFFER_SIZE;
 5fc:	80 91 5d 01 	lds	r24, 0x015D
 600:	8f 5f       	subi	r24, 0xFF	; 255
 602:	8f 73       	andi	r24, 0x3F	; 63

    // if we should be storing the received character into the location
    // just before the tail (meaning that the head would advance to the
    // current location of the tail), we're about to overflow the buffer
    // and so we don't write the character or advance the head.
    if (i != _rx_buffer_tail) {
 604:	20 91 5e 01 	lds	r18, 0x015E
 608:	82 17       	cp	r24, r18
 60a:	51 f0       	breq	.+20     	; 0x620 <__vector_18+0x50>
      _rx_buffer[_rx_buffer_head] = c;
 60c:	e0 91 5d 01 	lds	r30, 0x015D
 610:	f0 e0       	ldi	r31, 0x00	; 0
 612:	ec 5b       	subi	r30, 0xBC	; 188
 614:	fe 4f       	sbci	r31, 0xFE	; 254
 616:	95 8f       	std	Z+29, r25	; 0x1d
      _rx_buffer_head = i;
 618:	80 93 5d 01 	sts	0x015D, r24
 61c:	01 c0       	rjmp	.+2      	; 0x620 <__vector_18+0x50>
    }
  } else {
    // Parity error, read byte but discard it
    *_udr;
 61e:	80 81       	ld	r24, Z
    Serial._rx_complete_irq();
  }
 620:	ff 91       	pop	r31
 622:	ef 91       	pop	r30
 624:	9f 91       	pop	r25
 626:	8f 91       	pop	r24
 628:	2f 91       	pop	r18
 62a:	0f 90       	pop	r0
 62c:	0f be       	out	0x3f, r0	; 63
 62e:	0f 90       	pop	r0
 630:	1f 90       	pop	r1
 632:	18 95       	reti

00000634 <__vector_19>:
#elif defined(USART_UDRE_vect)
ISR(USART_UDRE_vect)
#else
  #error "Don't know what the Data Register Empty vector is called for Serial"
#endif
{
 634:	1f 92       	push	r1
 636:	0f 92       	push	r0
 638:	0f b6       	in	r0, 0x3f	; 63
 63a:	0f 92       	push	r0
 63c:	11 24       	eor	r1, r1
 63e:	2f 93       	push	r18
 640:	3f 93       	push	r19
 642:	4f 93       	push	r20
 644:	5f 93       	push	r21
 646:	6f 93       	push	r22
 648:	7f 93       	push	r23
 64a:	8f 93       	push	r24
 64c:	9f 93       	push	r25
 64e:	af 93       	push	r26
 650:	bf 93       	push	r27
 652:	ef 93       	push	r30
 654:	ff 93       	push	r31
  Serial._tx_udr_empty_irq();
 656:	84 e4       	ldi	r24, 0x44	; 68
 658:	91 e0       	ldi	r25, 0x01	; 1
 65a:	0e 94 de 01 	call	0x3bc	; 0x3bc <_ZN14HardwareSerial17_tx_udr_empty_irqEv>
}
 65e:	ff 91       	pop	r31
 660:	ef 91       	pop	r30
 662:	bf 91       	pop	r27
 664:	af 91       	pop	r26
 666:	9f 91       	pop	r25
 668:	8f 91       	pop	r24
 66a:	7f 91       	pop	r23
 66c:	6f 91       	pop	r22
 66e:	5f 91       	pop	r21
 670:	4f 91       	pop	r20
 672:	3f 91       	pop	r19
 674:	2f 91       	pop	r18
 676:	0f 90       	pop	r0
 678:	0f be       	out	0x3f, r0	; 63
 67a:	0f 90       	pop	r0
 67c:	1f 90       	pop	r1
 67e:	18 95       	reti

00000680 <_Z17Serial0_availablev>:
#endif

// Function that can be weakly referenced by serialEventRun to prevent
// pulling in this file if it's not otherwise used.
bool Serial0_available() {
  return Serial.available();
 680:	84 e4       	ldi	r24, 0x44	; 68
 682:	91 e0       	ldi	r25, 0x01	; 1
 684:	0e 94 a1 01 	call	0x342	; 0x342 <_ZN14HardwareSerial9availableEv>
 688:	21 e0       	ldi	r18, 0x01	; 1
 68a:	89 2b       	or	r24, r25
 68c:	09 f4       	brne	.+2      	; 0x690 <_Z17Serial0_availablev+0x10>
 68e:	20 e0       	ldi	r18, 0x00	; 0
}
 690:	82 2f       	mov	r24, r18
 692:	08 95       	ret

00000694 <_GLOBAL__sub_I___vector_18>:
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
 694:	10 92 47 01 	sts	0x0147, r1
 698:	10 92 46 01 	sts	0x0146, r1
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;

    Stream() {_timeout=1000;}
 69c:	88 ee       	ldi	r24, 0xE8	; 232
 69e:	93 e0       	ldi	r25, 0x03	; 3
 6a0:	a0 e0       	ldi	r26, 0x00	; 0
 6a2:	b0 e0       	ldi	r27, 0x00	; 0
 6a4:	80 93 48 01 	sts	0x0148, r24
 6a8:	90 93 49 01 	sts	0x0149, r25
 6ac:	a0 93 4a 01 	sts	0x014A, r26
 6b0:	b0 93 4b 01 	sts	0x014B, r27
  volatile uint8_t *ucsrc, volatile uint8_t *udr) :
    _ubrrh(ubrrh), _ubrrl(ubrrl),
    _ucsra(ucsra), _ucsrb(ucsrb), _ucsrc(ucsrc),
    _udr(udr),
    _rx_buffer_head(0), _rx_buffer_tail(0),
    _tx_buffer_head(0), _tx_buffer_tail(0)
 6b4:	8e e2       	ldi	r24, 0x2E	; 46
 6b6:	91 e0       	ldi	r25, 0x01	; 1
 6b8:	90 93 45 01 	sts	0x0145, r25
 6bc:	80 93 44 01 	sts	0x0144, r24
 6c0:	85 ec       	ldi	r24, 0xC5	; 197
 6c2:	90 e0       	ldi	r25, 0x00	; 0
 6c4:	90 93 51 01 	sts	0x0151, r25
 6c8:	80 93 50 01 	sts	0x0150, r24
 6cc:	84 ec       	ldi	r24, 0xC4	; 196
 6ce:	90 e0       	ldi	r25, 0x00	; 0
 6d0:	90 93 53 01 	sts	0x0153, r25
 6d4:	80 93 52 01 	sts	0x0152, r24
 6d8:	80 ec       	ldi	r24, 0xC0	; 192
 6da:	90 e0       	ldi	r25, 0x00	; 0
 6dc:	90 93 55 01 	sts	0x0155, r25
 6e0:	80 93 54 01 	sts	0x0154, r24
 6e4:	81 ec       	ldi	r24, 0xC1	; 193
 6e6:	90 e0       	ldi	r25, 0x00	; 0
 6e8:	90 93 57 01 	sts	0x0157, r25
 6ec:	80 93 56 01 	sts	0x0156, r24
 6f0:	82 ec       	ldi	r24, 0xC2	; 194
 6f2:	90 e0       	ldi	r25, 0x00	; 0
 6f4:	90 93 59 01 	sts	0x0159, r25
 6f8:	80 93 58 01 	sts	0x0158, r24
 6fc:	86 ec       	ldi	r24, 0xC6	; 198
 6fe:	90 e0       	ldi	r25, 0x00	; 0
 700:	90 93 5b 01 	sts	0x015B, r25
 704:	80 93 5a 01 	sts	0x015A, r24
 708:	10 92 5d 01 	sts	0x015D, r1
 70c:	10 92 5e 01 	sts	0x015E, r1
 710:	10 92 5f 01 	sts	0x015F, r1
 714:	10 92 60 01 	sts	0x0160, r1
 718:	08 95       	ret

0000071a <_ZN5Print5writeEPKhj>:

// Public Methods //////////////////////////////////////////////////////////////

/* default implementation: may be overridden */
size_t Print::write(const uint8_t *buffer, size_t size)
{
 71a:	cf 92       	push	r12
 71c:	df 92       	push	r13
 71e:	ef 92       	push	r14
 720:	ff 92       	push	r15
 722:	0f 93       	push	r16
 724:	1f 93       	push	r17
 726:	cf 93       	push	r28
 728:	df 93       	push	r29
 72a:	6c 01       	movw	r12, r24
 72c:	7a 01       	movw	r14, r20
 72e:	eb 01       	movw	r28, r22
 730:	e6 0e       	add	r14, r22
 732:	f7 1e       	adc	r15, r23
  size_t n = 0;
 734:	00 e0       	ldi	r16, 0x00	; 0
 736:	10 e0       	ldi	r17, 0x00	; 0
  while (size--) {
 738:	ce 15       	cp	r28, r14
 73a:	df 05       	cpc	r29, r15
 73c:	61 f0       	breq	.+24     	; 0x756 <_ZN5Print5writeEPKhj+0x3c>
    n += write(*buffer++);
 73e:	69 91       	ld	r22, Y+
 740:	d6 01       	movw	r26, r12
 742:	ed 91       	ld	r30, X+
 744:	fc 91       	ld	r31, X
 746:	01 90       	ld	r0, Z+
 748:	f0 81       	ld	r31, Z
 74a:	e0 2d       	mov	r30, r0
 74c:	c6 01       	movw	r24, r12
 74e:	09 95       	icall
 750:	08 0f       	add	r16, r24
 752:	19 1f       	adc	r17, r25
 754:	f1 cf       	rjmp	.-30     	; 0x738 <_ZN5Print5writeEPKhj+0x1e>
  }
  return n;
}
 756:	c8 01       	movw	r24, r16
 758:	df 91       	pop	r29
 75a:	cf 91       	pop	r28
 75c:	1f 91       	pop	r17
 75e:	0f 91       	pop	r16
 760:	ff 90       	pop	r15
 762:	ef 90       	pop	r14
 764:	df 90       	pop	r13
 766:	cf 90       	pop	r12
 768:	08 95       	ret

0000076a <_ZN5Print5writeEPKc>:
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == NULL) return 0;
 76a:	61 15       	cp	r22, r1
 76c:	71 05       	cpc	r23, r1
 76e:	81 f0       	breq	.+32     	; 0x790 <_ZN5Print5writeEPKc+0x26>
      return write((const uint8_t *)str, strlen(str));
 770:	db 01       	movw	r26, r22
 772:	0d 90       	ld	r0, X+
 774:	00 20       	and	r0, r0
 776:	e9 f7       	brne	.-6      	; 0x772 <_ZN5Print5writeEPKc+0x8>
 778:	ad 01       	movw	r20, r26
 77a:	41 50       	subi	r20, 0x01	; 1
 77c:	51 09       	sbc	r21, r1
 77e:	46 1b       	sub	r20, r22
 780:	57 0b       	sbc	r21, r23
 782:	dc 01       	movw	r26, r24
 784:	ed 91       	ld	r30, X+
 786:	fc 91       	ld	r31, X
 788:	02 80       	ldd	r0, Z+2	; 0x02
 78a:	f3 81       	ldd	r31, Z+3	; 0x03
 78c:	e0 2d       	mov	r30, r0
 78e:	09 94       	ijmp
    }
 790:	80 e0       	ldi	r24, 0x00	; 0
 792:	90 e0       	ldi	r25, 0x00	; 0
 794:	08 95       	ret

00000796 <_ZN5Print5printEPKc>:
  return write(s.c_str(), s.length());
}

size_t Print::print(const char str[])
{
  return write(str);
 796:	0c 94 b5 03 	jmp	0x76a	; 0x76a <_ZN5Print5writeEPKc>

0000079a <_ZN5Print5printEc>:
}

size_t Print::print(char c)
{
  return write(c);
 79a:	dc 01       	movw	r26, r24
 79c:	ed 91       	ld	r30, X+
 79e:	fc 91       	ld	r31, X
 7a0:	01 90       	ld	r0, Z+
 7a2:	f0 81       	ld	r31, Z
 7a4:	e0 2d       	mov	r30, r0
 7a6:	09 94       	ijmp

000007a8 <_ZN5Print11printNumberEmh>:
  return n;
}

// Private Methods /////////////////////////////////////////////////////////////

size_t Print::printNumber(unsigned long n, uint8_t base) {
 7a8:	8f 92       	push	r8
 7aa:	9f 92       	push	r9
 7ac:	af 92       	push	r10
 7ae:	bf 92       	push	r11
 7b0:	cf 92       	push	r12
 7b2:	df 92       	push	r13
 7b4:	ef 92       	push	r14
 7b6:	ff 92       	push	r15
 7b8:	0f 93       	push	r16
 7ba:	1f 93       	push	r17
 7bc:	cf 93       	push	r28
 7be:	df 93       	push	r29
 7c0:	cd b7       	in	r28, 0x3d	; 61
 7c2:	de b7       	in	r29, 0x3e	; 62
 7c4:	a1 97       	sbiw	r28, 0x21	; 33
 7c6:	0f b6       	in	r0, 0x3f	; 63
 7c8:	f8 94       	cli
 7ca:	de bf       	out	0x3e, r29	; 62
 7cc:	0f be       	out	0x3f, r0	; 63
 7ce:	cd bf       	out	0x3d, r28	; 61
 7d0:	7c 01       	movw	r14, r24
 7d2:	c4 2e       	mov	r12, r20
 7d4:	e5 2f       	mov	r30, r21
 7d6:	cb 01       	movw	r24, r22
 7d8:	d2 2e       	mov	r13, r18
  char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';
 7da:	19 a2       	std	Y+33, r1	; 0x21

  // prevent crash if called with base == 1
  if (base < 2) base = 10;
 7dc:	21 e0       	ldi	r18, 0x01	; 1
 7de:	2d 15       	cp	r18, r13
 7e0:	10 f0       	brcs	.+4      	; 0x7e6 <_ZN5Print11printNumberEmh+0x3e>
 7e2:	2a e0       	ldi	r18, 0x0A	; 10
 7e4:	d2 2e       	mov	r13, r18
 7e6:	8e 01       	movw	r16, r28
 7e8:	0f 5d       	subi	r16, 0xDF	; 223
 7ea:	1f 4f       	sbci	r17, 0xFF	; 255

  do {
    unsigned long m = n;
    n /= base;
 7ec:	8d 2c       	mov	r8, r13
 7ee:	91 2c       	mov	r9, r1
 7f0:	a1 2c       	mov	r10, r1
 7f2:	b1 2c       	mov	r11, r1
 7f4:	6c 2d       	mov	r22, r12
 7f6:	7e 2f       	mov	r23, r30
 7f8:	a5 01       	movw	r20, r10
 7fa:	94 01       	movw	r18, r8
 7fc:	0e 94 1f 07 	call	0xe3e	; 0xe3e <__udivmodsi4>
    char c = m - base * n;
 800:	8c 2d       	mov	r24, r12
 802:	d2 9e       	mul	r13, r18
 804:	80 19       	sub	r24, r0
 806:	11 24       	eor	r1, r1
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
 808:	01 50       	subi	r16, 0x01	; 1
 80a:	11 09       	sbc	r17, r1
 80c:	8a 30       	cpi	r24, 0x0A	; 10
 80e:	14 f4       	brge	.+4      	; 0x814 <_ZN5Print11printNumberEmh+0x6c>
 810:	80 5d       	subi	r24, 0xD0	; 208
 812:	01 c0       	rjmp	.+2      	; 0x816 <_ZN5Print11printNumberEmh+0x6e>
 814:	89 5c       	subi	r24, 0xC9	; 201
 816:	f8 01       	movw	r30, r16
 818:	80 83       	st	Z, r24
  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
 81a:	21 15       	cp	r18, r1
 81c:	31 05       	cpc	r19, r1
 81e:	41 05       	cpc	r20, r1
 820:	51 05       	cpc	r21, r1
 822:	21 f0       	breq	.+8      	; 0x82c <_ZN5Print11printNumberEmh+0x84>
    unsigned long m = n;
    n /= base;
 824:	c2 2e       	mov	r12, r18
 826:	e3 2f       	mov	r30, r19
 828:	ca 01       	movw	r24, r20
 82a:	e4 cf       	rjmp	.-56     	; 0x7f4 <_ZN5Print11printNumberEmh+0x4c>
    char c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  return write(str);
 82c:	b8 01       	movw	r22, r16
 82e:	c7 01       	movw	r24, r14
 830:	0e 94 b5 03 	call	0x76a	; 0x76a <_ZN5Print5writeEPKc>
}
 834:	a1 96       	adiw	r28, 0x21	; 33
 836:	0f b6       	in	r0, 0x3f	; 63
 838:	f8 94       	cli
 83a:	de bf       	out	0x3e, r29	; 62
 83c:	0f be       	out	0x3f, r0	; 63
 83e:	cd bf       	out	0x3d, r28	; 61
 840:	df 91       	pop	r29
 842:	cf 91       	pop	r28
 844:	1f 91       	pop	r17
 846:	0f 91       	pop	r16
 848:	ff 90       	pop	r15
 84a:	ef 90       	pop	r14
 84c:	df 90       	pop	r13
 84e:	cf 90       	pop	r12
 850:	bf 90       	pop	r11
 852:	af 90       	pop	r10
 854:	9f 90       	pop	r9
 856:	8f 90       	pop	r8
 858:	08 95       	ret

0000085a <_ZN5Print5printEli>:
{
  return print((unsigned long) n, base);
}

size_t Print::print(long n, int base)
{
 85a:	cf 92       	push	r12
 85c:	df 92       	push	r13
 85e:	ef 92       	push	r14
 860:	ff 92       	push	r15
 862:	0f 93       	push	r16
 864:	1f 93       	push	r17
 866:	cf 93       	push	r28
 868:	df 93       	push	r29
 86a:	ec 01       	movw	r28, r24
 86c:	6a 01       	movw	r12, r20
 86e:	7b 01       	movw	r14, r22
  if (base == 0) {
 870:	21 15       	cp	r18, r1
 872:	31 05       	cpc	r19, r1
 874:	79 f4       	brne	.+30     	; 0x894 <_ZN5Print5printEli+0x3a>
    return write(n);
 876:	e8 81       	ld	r30, Y
 878:	f9 81       	ldd	r31, Y+1	; 0x01
 87a:	01 90       	ld	r0, Z+
 87c:	f0 81       	ld	r31, Z
 87e:	e0 2d       	mov	r30, r0
 880:	64 2f       	mov	r22, r20
    }
    return printNumber(n, 10);
  } else {
    return printNumber(n, base);
  }
}
 882:	df 91       	pop	r29
 884:	cf 91       	pop	r28
 886:	1f 91       	pop	r17
 888:	0f 91       	pop	r16
 88a:	ff 90       	pop	r15
 88c:	ef 90       	pop	r14
 88e:	df 90       	pop	r13
 890:	cf 90       	pop	r12
}

size_t Print::print(long n, int base)
{
  if (base == 0) {
    return write(n);
 892:	09 94       	ijmp
  } else if (base == 10) {
 894:	2a 30       	cpi	r18, 0x0A	; 10
 896:	31 05       	cpc	r19, r1
 898:	e9 f4       	brne	.+58     	; 0x8d4 <_ZN5Print5printEli+0x7a>
    if (n < 0) {
 89a:	77 ff       	sbrs	r23, 7
 89c:	1a c0       	rjmp	.+52     	; 0x8d2 <_ZN5Print5printEli+0x78>
      int t = print('-');
 89e:	6d e2       	ldi	r22, 0x2D	; 45
 8a0:	0e 94 cd 03 	call	0x79a	; 0x79a <_ZN5Print5printEc>
 8a4:	8c 01       	movw	r16, r24
      n = -n;
 8a6:	44 27       	eor	r20, r20
 8a8:	55 27       	eor	r21, r21
 8aa:	ba 01       	movw	r22, r20
 8ac:	4c 19       	sub	r20, r12
 8ae:	5d 09       	sbc	r21, r13
 8b0:	6e 09       	sbc	r22, r14
 8b2:	7f 09       	sbc	r23, r15
      return printNumber(n, 10) + t;
 8b4:	2a e0       	ldi	r18, 0x0A	; 10
 8b6:	ce 01       	movw	r24, r28
 8b8:	0e 94 d4 03 	call	0x7a8	; 0x7a8 <_ZN5Print11printNumberEmh>
 8bc:	80 0f       	add	r24, r16
 8be:	91 1f       	adc	r25, r17
    }
    return printNumber(n, 10);
  } else {
    return printNumber(n, base);
  }
}
 8c0:	df 91       	pop	r29
 8c2:	cf 91       	pop	r28
 8c4:	1f 91       	pop	r17
 8c6:	0f 91       	pop	r16
 8c8:	ff 90       	pop	r15
 8ca:	ef 90       	pop	r14
 8cc:	df 90       	pop	r13
 8ce:	cf 90       	pop	r12
 8d0:	08 95       	ret
    if (n < 0) {
      int t = print('-');
      n = -n;
      return printNumber(n, 10) + t;
    }
    return printNumber(n, 10);
 8d2:	2a e0       	ldi	r18, 0x0A	; 10
  } else {
    return printNumber(n, base);
 8d4:	b7 01       	movw	r22, r14
 8d6:	a6 01       	movw	r20, r12
 8d8:	ce 01       	movw	r24, r28
  }
}
 8da:	df 91       	pop	r29
 8dc:	cf 91       	pop	r28
 8de:	1f 91       	pop	r17
 8e0:	0f 91       	pop	r16
 8e2:	ff 90       	pop	r15
 8e4:	ef 90       	pop	r14
 8e6:	df 90       	pop	r13
 8e8:	cf 90       	pop	r12
      n = -n;
      return printNumber(n, 10) + t;
    }
    return printNumber(n, 10);
  } else {
    return printNumber(n, base);
 8ea:	0c 94 d4 03 	jmp	0x7a8	; 0x7a8 <_ZN5Print11printNumberEmh>

000008ee <_ZN5Print5printEmi>:
  }
}

size_t Print::print(unsigned long n, int base)
{
  if (base == 0) return write(n);
 8ee:	21 15       	cp	r18, r1
 8f0:	31 05       	cpc	r19, r1
 8f2:	41 f4       	brne	.+16     	; 0x904 <__stack+0x5>
 8f4:	dc 01       	movw	r26, r24
 8f6:	ed 91       	ld	r30, X+
 8f8:	fc 91       	ld	r31, X
 8fa:	01 90       	ld	r0, Z+
 8fc:	f0 81       	ld	r31, Z
 8fe:	e0 2d       	mov	r30, r0
 900:	64 2f       	mov	r22, r20
 902:	09 94       	ijmp
  else return printNumber(n, base);
 904:	0c 94 d4 03 	jmp	0x7a8	; 0x7a8 <_ZN5Print11printNumberEmh>

00000908 <_ZN5Print5printEji>:
{
  return print((long) n, base);
}

size_t Print::print(unsigned int n, int base)
{
 908:	9a 01       	movw	r18, r20
  return print((unsigned long) n, base);
 90a:	ab 01       	movw	r20, r22
 90c:	60 e0       	ldi	r22, 0x00	; 0
 90e:	70 e0       	ldi	r23, 0x00	; 0
 910:	0c 94 77 04 	jmp	0x8ee	; 0x8ee <_ZN5Print5printEmi>

00000914 <initVariant>:
int atexit(void (*func)()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }
 914:	08 95       	ret

00000916 <main>:

int main(void)
{
	init();
 916:	0e 94 f0 04 	call	0x9e0	; 0x9e0 <init>

	initVariant();
 91a:	0e 94 8a 04 	call	0x914	; 0x914 <initVariant>

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
 91e:	0e 94 db 00 	call	0x1b6	; 0x1b6 <setup>
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
 922:	c0 ed       	ldi	r28, 0xD0	; 208
 924:	d1 e0       	ldi	r29, 0x01	; 1
#endif
	
	setup();
    
	for (;;) {
		loop();
 926:	0e 94 fc 00 	call	0x1f8	; 0x1f8 <loop>
		if (serialEventRun) serialEventRun();
 92a:	20 97       	sbiw	r28, 0x00	; 0
 92c:	e1 f3       	breq	.-8      	; 0x926 <main+0x10>
 92e:	0e 94 d0 01 	call	0x3a0	; 0x3a0 <_Z14serialEventRunv>
 932:	f9 cf       	rjmp	.-14     	; 0x926 <main+0x10>

00000934 <__vector_16>:
#if defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
ISR(TIM0_OVF_vect)
#else
ISR(TIMER0_OVF_vect)
#endif
{
 934:	1f 92       	push	r1
 936:	0f 92       	push	r0
 938:	0f b6       	in	r0, 0x3f	; 63
 93a:	0f 92       	push	r0
 93c:	11 24       	eor	r1, r1
 93e:	2f 93       	push	r18
 940:	3f 93       	push	r19
 942:	8f 93       	push	r24
 944:	9f 93       	push	r25
 946:	af 93       	push	r26
 948:	bf 93       	push	r27
	// copy these to local variables so they can be stored in registers
	// (volatile variables must be read from memory on every access)
	unsigned long m = timer0_millis;
 94a:	80 91 e2 01 	lds	r24, 0x01E2
 94e:	90 91 e3 01 	lds	r25, 0x01E3
 952:	a0 91 e4 01 	lds	r26, 0x01E4
 956:	b0 91 e5 01 	lds	r27, 0x01E5
	unsigned char f = timer0_fract;
 95a:	30 91 e1 01 	lds	r19, 0x01E1

	m += MILLIS_INC;
	f += FRACT_INC;
 95e:	23 e0       	ldi	r18, 0x03	; 3
 960:	23 0f       	add	r18, r19
	if (f >= FRACT_MAX) {
 962:	2d 37       	cpi	r18, 0x7D	; 125
 964:	20 f4       	brcc	.+8      	; 0x96e <__vector_16+0x3a>
	// copy these to local variables so they can be stored in registers
	// (volatile variables must be read from memory on every access)
	unsigned long m = timer0_millis;
	unsigned char f = timer0_fract;

	m += MILLIS_INC;
 966:	01 96       	adiw	r24, 0x01	; 1
 968:	a1 1d       	adc	r26, r1
 96a:	b1 1d       	adc	r27, r1
 96c:	05 c0       	rjmp	.+10     	; 0x978 <__vector_16+0x44>
	f += FRACT_INC;
	if (f >= FRACT_MAX) {
		f -= FRACT_MAX;
 96e:	26 e8       	ldi	r18, 0x86	; 134
 970:	23 0f       	add	r18, r19
		m += 1;
 972:	02 96       	adiw	r24, 0x02	; 2
 974:	a1 1d       	adc	r26, r1
 976:	b1 1d       	adc	r27, r1
	}

	timer0_fract = f;
 978:	20 93 e1 01 	sts	0x01E1, r18
	timer0_millis = m;
 97c:	80 93 e2 01 	sts	0x01E2, r24
 980:	90 93 e3 01 	sts	0x01E3, r25
 984:	a0 93 e4 01 	sts	0x01E4, r26
 988:	b0 93 e5 01 	sts	0x01E5, r27
	timer0_overflow_count++;
 98c:	80 91 e6 01 	lds	r24, 0x01E6
 990:	90 91 e7 01 	lds	r25, 0x01E7
 994:	a0 91 e8 01 	lds	r26, 0x01E8
 998:	b0 91 e9 01 	lds	r27, 0x01E9
 99c:	01 96       	adiw	r24, 0x01	; 1
 99e:	a1 1d       	adc	r26, r1
 9a0:	b1 1d       	adc	r27, r1
 9a2:	80 93 e6 01 	sts	0x01E6, r24
 9a6:	90 93 e7 01 	sts	0x01E7, r25
 9aa:	a0 93 e8 01 	sts	0x01E8, r26
 9ae:	b0 93 e9 01 	sts	0x01E9, r27
}
 9b2:	bf 91       	pop	r27
 9b4:	af 91       	pop	r26
 9b6:	9f 91       	pop	r25
 9b8:	8f 91       	pop	r24
 9ba:	3f 91       	pop	r19
 9bc:	2f 91       	pop	r18
 9be:	0f 90       	pop	r0
 9c0:	0f be       	out	0x3f, r0	; 63
 9c2:	0f 90       	pop	r0
 9c4:	1f 90       	pop	r1
 9c6:	18 95       	reti

000009c8 <millis>:

unsigned long millis()
{
	unsigned long m;
	uint8_t oldSREG = SREG;
 9c8:	2f b7       	in	r18, 0x3f	; 63

	// disable interrupts while we read timer0_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to timer0_millis)
	cli();
 9ca:	f8 94       	cli
	m = timer0_millis;
 9cc:	60 91 e2 01 	lds	r22, 0x01E2
 9d0:	70 91 e3 01 	lds	r23, 0x01E3
 9d4:	80 91 e4 01 	lds	r24, 0x01E4
 9d8:	90 91 e5 01 	lds	r25, 0x01E5
	SREG = oldSREG;
 9dc:	2f bf       	out	0x3f, r18	; 63

	return m;
}
 9de:	08 95       	ret

000009e0 <init>:

void init()
{
	// this needs to be called before setup() or some functions won't
	// work there
	sei();
 9e0:	78 94       	sei
	
	// on the ATmega168, timer 0 is also used for fast hardware pwm
	// (using phase-correct PWM would mean that timer 0 overflowed half as often
	// resulting in different millis() behavior on the ATmega8 and ATmega168)
#if defined(TCCR0A) && defined(WGM01)
	sbi(TCCR0A, WGM01);
 9e2:	84 b5       	in	r24, 0x24	; 36
 9e4:	82 60       	ori	r24, 0x02	; 2
 9e6:	84 bd       	out	0x24, r24	; 36
	sbi(TCCR0A, WGM00);
 9e8:	84 b5       	in	r24, 0x24	; 36
 9ea:	81 60       	ori	r24, 0x01	; 1
 9ec:	84 bd       	out	0x24, r24	; 36
	// this combination is for the standard atmega8
	sbi(TCCR0, CS01);
	sbi(TCCR0, CS00);
#elif defined(TCCR0B) && defined(CS01) && defined(CS00)
	// this combination is for the standard 168/328/1280/2560
	sbi(TCCR0B, CS01);
 9ee:	85 b5       	in	r24, 0x25	; 37
 9f0:	82 60       	ori	r24, 0x02	; 2
 9f2:	85 bd       	out	0x25, r24	; 37
	sbi(TCCR0B, CS00);
 9f4:	85 b5       	in	r24, 0x25	; 37
 9f6:	81 60       	ori	r24, 0x01	; 1
 9f8:	85 bd       	out	0x25, r24	; 37

	// enable timer 0 overflow interrupt
#if defined(TIMSK) && defined(TOIE0)
	sbi(TIMSK, TOIE0);
#elif defined(TIMSK0) && defined(TOIE0)
	sbi(TIMSK0, TOIE0);
 9fa:	ee e6       	ldi	r30, 0x6E	; 110
 9fc:	f0 e0       	ldi	r31, 0x00	; 0
 9fe:	80 81       	ld	r24, Z
 a00:	81 60       	ori	r24, 0x01	; 1
 a02:	80 83       	st	Z, r24
	// this is better for motors as it ensures an even waveform
	// note, however, that fast pwm mode can achieve a frequency of up
	// 8 MHz (with a 16 MHz clock) at 50% duty cycle

#if defined(TCCR1B) && defined(CS11) && defined(CS10)
	TCCR1B = 0;
 a04:	e1 e8       	ldi	r30, 0x81	; 129
 a06:	f0 e0       	ldi	r31, 0x00	; 0
 a08:	10 82       	st	Z, r1

	// set timer 1 prescale factor to 64
	sbi(TCCR1B, CS11);
 a0a:	80 81       	ld	r24, Z
 a0c:	82 60       	ori	r24, 0x02	; 2
 a0e:	80 83       	st	Z, r24
#if F_CPU >= 8000000L
	sbi(TCCR1B, CS10);
 a10:	80 81       	ld	r24, Z
 a12:	81 60       	ori	r24, 0x01	; 1
 a14:	80 83       	st	Z, r24
	sbi(TCCR1, CS10);
#endif
#endif
	// put timer 1 in 8-bit phase correct pwm mode
#if defined(TCCR1A) && defined(WGM10)
	sbi(TCCR1A, WGM10);
 a16:	e0 e8       	ldi	r30, 0x80	; 128
 a18:	f0 e0       	ldi	r31, 0x00	; 0
 a1a:	80 81       	ld	r24, Z
 a1c:	81 60       	ori	r24, 0x01	; 1
 a1e:	80 83       	st	Z, r24

	// set timer 2 prescale factor to 64
#if defined(TCCR2) && defined(CS22)
	sbi(TCCR2, CS22);
#elif defined(TCCR2B) && defined(CS22)
	sbi(TCCR2B, CS22);
 a20:	e1 eb       	ldi	r30, 0xB1	; 177
 a22:	f0 e0       	ldi	r31, 0x00	; 0
 a24:	80 81       	ld	r24, Z
 a26:	84 60       	ori	r24, 0x04	; 4
 a28:	80 83       	st	Z, r24

	// configure timer 2 for phase correct pwm (8-bit)
#if defined(TCCR2) && defined(WGM20)
	sbi(TCCR2, WGM20);
#elif defined(TCCR2A) && defined(WGM20)
	sbi(TCCR2A, WGM20);
 a2a:	e0 eb       	ldi	r30, 0xB0	; 176
 a2c:	f0 e0       	ldi	r31, 0x00	; 0
 a2e:	80 81       	ld	r24, Z
 a30:	81 60       	ori	r24, 0x01	; 1
 a32:	80 83       	st	Z, r24
#if defined(ADCSRA)
	// set a2d prescale factor to 128
	// 16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
	// XXX: this will not work properly for other clock speeds, and
	// this code should use F_CPU to determine the prescale factor.
	sbi(ADCSRA, ADPS2);
 a34:	ea e7       	ldi	r30, 0x7A	; 122
 a36:	f0 e0       	ldi	r31, 0x00	; 0
 a38:	80 81       	ld	r24, Z
 a3a:	84 60       	ori	r24, 0x04	; 4
 a3c:	80 83       	st	Z, r24
	sbi(ADCSRA, ADPS1);
 a3e:	80 81       	ld	r24, Z
 a40:	82 60       	ori	r24, 0x02	; 2
 a42:	80 83       	st	Z, r24
	sbi(ADCSRA, ADPS0);
 a44:	80 81       	ld	r24, Z
 a46:	81 60       	ori	r24, 0x01	; 1
 a48:	80 83       	st	Z, r24

	// enable a2d conversions
	sbi(ADCSRA, ADEN);
 a4a:	80 81       	ld	r24, Z
 a4c:	80 68       	ori	r24, 0x80	; 128
 a4e:	80 83       	st	Z, r24
	// here so they can be used as normal digital i/o; they will be
	// reconnected in Serial.begin()
#if defined(UCSRB)
	UCSRB = 0;
#elif defined(UCSR0B)
	UCSR0B = 0;
 a50:	10 92 c1 00 	sts	0x00C1, r1
 a54:	08 95       	ret

00000a56 <_ZN10Manchester8setRxPinEh>:
  bitSet( DDRB, 3 );
}


void Manchester::setRxPin(uint8_t pin)
{
 a56:	86 2f       	mov	r24, r22
  ::RxPin = pin; // user sets the digital pin as output
 a58:	60 93 04 01 	sts	0x0104, r22
  pinMode(::RxPin, INPUT);
 a5c:	60 e0       	ldi	r22, 0x00	; 0
 a5e:	0c 94 a9 06 	jmp	0xd52	; 0xd52 <pinMode>

00000a62 <_ZN10Manchester15receiveCompleteEv>:
  rx_mode = RX_MODE_IDLE;
}

uint8_t MANRX_ReceiveComplete(void)
{
  return (rx_mode == RX_MODE_MSG);
 a62:	81 e0       	ldi	r24, 0x01	; 1
 a64:	90 91 03 01 	lds	r25, 0x0103
 a68:	93 30       	cpi	r25, 0x03	; 3
 a6a:	09 f0       	breq	.+2      	; 0xa6e <_ZN10Manchester15receiveCompleteEv+0xc>
 a6c:	80 e0       	ldi	r24, 0x00	; 0


uint8_t Manchester::receiveComplete(void)
{
  return ::MANRX_ReceiveComplete();
}
 a6e:	08 95       	ret

00000a70 <MANRX_SetupReceive>:
}

//global functions

void MANRX_SetupReceive(uint8_t speedFactor)
{
 a70:	cf 93       	push	r28
 a72:	c8 2f       	mov	r28, r24
  pinMode(RxPin, INPUT);
 a74:	60 e0       	ldi	r22, 0x00	; 0
 a76:	80 91 04 01 	lds	r24, 0x0104
 a7a:	0e 94 a9 06 	call	0xd52	; 0xd52 <pinMode>
    http://www.atmel.com/dyn/resources/prod_documents/doc8161.pdf page 162
    How to find the correct value: (OCRxA +1) = F_CPU / prescaler / 1953.125
    OCR2A is only 8 bit register
    */

    TCCR2A = _BV(WGM21); // reset counter on match
 a7e:	92 e0       	ldi	r25, 0x02	; 2
 a80:	90 93 b0 00 	sts	0x00B0, r25
      OCR2A = (64 >> speedFactor) - 1;
    #elif F_CPU == 8000000UL
      TCCR2B = _BV(CS21) | _BV(CS20); // 1/32 prescaler
      OCR2A = (128 >> speedFactor) - 1;
    #elif F_CPU == 16000000UL
      TCCR2B = _BV(CS22); // 1/64 prescaler
 a84:	84 e0       	ldi	r24, 0x04	; 4
 a86:	80 93 b1 00 	sts	0x00B1, r24
      OCR2A = (128 >> speedFactor) - 1;
 a8a:	20 e8       	ldi	r18, 0x80	; 128
 a8c:	30 e0       	ldi	r19, 0x00	; 0
 a8e:	02 c0       	rjmp	.+4      	; 0xa94 <MANRX_SetupReceive+0x24>
 a90:	35 95       	asr	r19
 a92:	27 95       	ror	r18
 a94:	ca 95       	dec	r28
 a96:	e2 f7       	brpl	.-8      	; 0xa90 <MANRX_SetupReceive+0x20>
 a98:	21 50       	subi	r18, 0x01	; 1
 a9a:	20 93 b3 00 	sts	0x00B3, r18
    #else
    #error "Manchester library only supports 8mhz, 16mhz on ATMega328"
    #endif
    TIMSK2 = _BV(OCIE2A); // Turn on interrupt
 a9e:	90 93 70 00 	sts	0x0070, r25
    TCNT2 = 0; // Set counter to 0
 aa2:	10 92 b2 00 	sts	0x00B2, r1
  #endif

} //end of setupReceive
 aa6:	cf 91       	pop	r28
 aa8:	08 95       	ret

00000aaa <_ZN10Manchester12setupReceiveEhh>:
  #endif
}


void Manchester::setupReceive(uint8_t pin, uint8_t SF)
{
 aaa:	cf 93       	push	r28
 aac:	df 93       	push	r29
 aae:	1f 92       	push	r1
 ab0:	cd b7       	in	r28, 0x3d	; 61
 ab2:	de b7       	in	r29, 0x3e	; 62
  setRxPin(pin);
 ab4:	49 83       	std	Y+1, r20	; 0x01
 ab6:	0e 94 2b 05 	call	0xa56	; 0xa56 <_ZN10Manchester8setRxPinEh>
  ::MANRX_SetupReceive(SF);
 aba:	49 81       	ldd	r20, Y+1	; 0x01
 abc:	84 2f       	mov	r24, r20
}
 abe:	0f 90       	pop	r0
 ac0:	df 91       	pop	r29
 ac2:	cf 91       	pop	r28


void Manchester::setupReceive(uint8_t pin, uint8_t SF)
{
  setRxPin(pin);
  ::MANRX_SetupReceive(SF);
 ac4:	0c 94 38 05 	jmp	0xa70	; 0xa70 <MANRX_SetupReceive>

00000ac8 <MANRX_BeginReceive>:

} //end of setupReceive

void MANRX_BeginReceive(void)
{
  rx_maxBytes = 2;
 ac8:	82 e0       	ldi	r24, 0x02	; 2
 aca:	80 93 02 01 	sts	0x0102, r24
  rx_data = rx_default_data;
 ace:	81 ef       	ldi	r24, 0xF1	; 241
 ad0:	91 e0       	ldi	r25, 0x01	; 1
 ad2:	90 93 01 01 	sts	0x0101, r25
 ad6:	80 93 00 01 	sts	0x0100, r24
  rx_mode = RX_MODE_PRE;
 ada:	10 92 03 01 	sts	0x0103, r1
 ade:	08 95       	ret

00000ae0 <_ZN10Manchester12beginReceiveEv>:
  ::MANRX_BeginReceiveBytes(maxBytes, data);
}

void Manchester::beginReceive(void)
{
  ::MANRX_BeginReceive();
 ae0:	0c 94 64 05 	jmp	0xac8	; 0xac8 <MANRX_BeginReceive>

00000ae4 <MANRX_GetMessage>:
  return (rx_mode == RX_MODE_MSG);
}

uint16_t MANRX_GetMessage(void)
{
  return (((int16_t)rx_data[0]) << 8) | (int16_t)rx_data[1];
 ae4:	e0 91 00 01 	lds	r30, 0x0100
 ae8:	f0 91 01 01 	lds	r31, 0x0101
 aec:	80 81       	ld	r24, Z
 aee:	90 e0       	ldi	r25, 0x00	; 0
 af0:	98 2f       	mov	r25, r24
 af2:	88 27       	eor	r24, r24
 af4:	21 81       	ldd	r18, Z+1	; 0x01
}
 af6:	82 2b       	or	r24, r18
 af8:	08 95       	ret

00000afa <_ZN10Manchester10getMessageEv>:
}


uint16_t Manchester::getMessage(void)
{
  return ::MANRX_GetMessage();
 afa:	0c 94 72 05 	jmp	0xae4	; 0xae4 <MANRX_GetMessage>

00000afe <_Z9AddManBitPjPhS0_S0_h>:
}//end of set transmit pin

void AddManBit(uint16_t *manBits, uint8_t *numMB,
               uint8_t *curByte, uint8_t *data,
               uint8_t bit)
{
 afe:	0f 93       	push	r16
 b00:	cf 93       	push	r28
 b02:	df 93       	push	r29
 b04:	dc 01       	movw	r26, r24
 b06:	eb 01       	movw	r28, r22
  *manBits <<= 1;
 b08:	ed 91       	ld	r30, X+
 b0a:	fc 91       	ld	r31, X
 b0c:	11 97       	sbiw	r26, 0x01	; 1
 b0e:	ee 0f       	add	r30, r30
 b10:	ff 1f       	adc	r31, r31
  *manBits |= bit;
 b12:	e0 2b       	or	r30, r16
 b14:	11 96       	adiw	r26, 0x01	; 1
 b16:	fc 93       	st	X, r31
 b18:	ee 93       	st	-X, r30
  (*numMB)++;
 b1a:	88 81       	ld	r24, Y
 b1c:	8f 5f       	subi	r24, 0xFF	; 255
 b1e:	88 83       	st	Y, r24
  if (*numMB == 16)
 b20:	80 31       	cpi	r24, 0x10	; 16
 b22:	f9 f4       	brne	.+62     	; 0xb62 <_Z9AddManBitPjPhS0_S0_h+0x64>
 b24:	8d 91       	ld	r24, X+
 b26:	9c 91       	ld	r25, X
 b28:	11 97       	sbiw	r26, 0x01	; 1
 b2a:	78 e0       	ldi	r23, 0x08	; 8
 b2c:	60 e0       	ldi	r22, 0x00	; 0
    {
      // ManBits holds 16 bits of manchester data
      // 1 = LO,HI
      // 0 = HI,LO
      // We can decode each bit by looking at the bottom bit of each pair.
      newData <<= 1;
 b2e:	e6 2f       	mov	r30, r22
 b30:	ee 0f       	add	r30, r30
      newData |= (*manBits & 1); // store the one
 b32:	68 2f       	mov	r22, r24
 b34:	61 70       	andi	r22, 0x01	; 1
 b36:	6e 2b       	or	r22, r30
      *manBits = *manBits >> 2; //get next data bit
 b38:	96 95       	lsr	r25
 b3a:	87 95       	ror	r24
 b3c:	96 95       	lsr	r25
 b3e:	87 95       	ror	r24
 b40:	71 50       	subi	r23, 0x01	; 1
  *manBits |= bit;
  (*numMB)++;
  if (*numMB == 16)
  {
    uint8_t newData = 0;
    for (int8_t i = 0; i < 8; i++)
 b42:	a9 f7       	brne	.-22     	; 0xb2e <_Z9AddManBitPjPhS0_S0_h+0x30>
 b44:	8d 93       	st	X+, r24
 b46:	9c 93       	st	X, r25
      // We can decode each bit by looking at the bottom bit of each pair.
      newData <<= 1;
      newData |= (*manBits & 1); // store the one
      *manBits = *manBits >> 2; //get next data bit
    }
    data[*curByte] = newData ^ DECOUPLING_MASK;
 b48:	fa 01       	movw	r30, r20
 b4a:	80 81       	ld	r24, Z
 b4c:	f9 01       	movw	r30, r18
 b4e:	e8 0f       	add	r30, r24
 b50:	f1 1d       	adc	r31, r1
 b52:	8a ec       	ldi	r24, 0xCA	; 202
 b54:	86 27       	eor	r24, r22
 b56:	80 83       	st	Z, r24
    (*curByte)++;
 b58:	fa 01       	movw	r30, r20
 b5a:	80 81       	ld	r24, Z
 b5c:	8f 5f       	subi	r24, 0xFF	; 255
 b5e:	80 83       	st	Z, r24
    *numMB = 0;
 b60:	18 82       	st	Y, r1
  }
}
 b62:	df 91       	pop	r29
 b64:	cf 91       	pop	r28
 b66:	0f 91       	pop	r16
 b68:	08 95       	ret

00000b6a <__vector_7>:
#elif defined(__AVR_ATmega32U4__)
ISR(TIMER3_COMPA_vect)
#else
ISR(TIMER2_COMPA_vect)
#endif
{
 b6a:	1f 92       	push	r1
 b6c:	0f 92       	push	r0
 b6e:	0f b6       	in	r0, 0x3f	; 63
 b70:	0f 92       	push	r0
 b72:	11 24       	eor	r1, r1
 b74:	0f 93       	push	r16
 b76:	1f 93       	push	r17
 b78:	2f 93       	push	r18
 b7a:	3f 93       	push	r19
 b7c:	4f 93       	push	r20
 b7e:	5f 93       	push	r21
 b80:	6f 93       	push	r22
 b82:	7f 93       	push	r23
 b84:	8f 93       	push	r24
 b86:	9f 93       	push	r25
 b88:	af 93       	push	r26
 b8a:	bf 93       	push	r27
 b8c:	cf 93       	push	r28
 b8e:	df 93       	push	r29
 b90:	ef 93       	push	r30
 b92:	ff 93       	push	r31
  if (rx_mode < RX_MODE_MSG) //receiving something
 b94:	80 91 03 01 	lds	r24, 0x0103
 b98:	83 30       	cpi	r24, 0x03	; 3
 b9a:	08 f0       	brcs	.+2      	; 0xb9e <__vector_7+0x34>
 b9c:	99 c0       	rjmp	.+306    	; 0xcd0 <__vector_7+0x166>
  {
    // Increment counter
    rx_count += 8;
 b9e:	80 91 f8 01 	lds	r24, 0x01F8
 ba2:	88 5f       	subi	r24, 0xF8	; 248
 ba4:	80 93 f8 01 	sts	0x01F8, r24

    // Check for value change
    rx_sample = digitalRead(RxPin);
 ba8:	80 91 04 01 	lds	r24, 0x0104
 bac:	0e 94 e2 06 	call	0xdc4	; 0xdc4 <digitalRead>
 bb0:	ec 01       	movw	r28, r24
 bb2:	90 93 fc 01 	sts	0x01FC, r25
 bb6:	80 93 fb 01 	sts	0x01FB, r24
    uint8_t transition = (rx_sample != rx_last_sample);
 bba:	00 91 f9 01 	lds	r16, 0x01F9
 bbe:	10 91 fa 01 	lds	r17, 0x01FA
 bc2:	81 e0       	ldi	r24, 0x01	; 1
 bc4:	c0 17       	cp	r28, r16
 bc6:	d1 07       	cpc	r29, r17
 bc8:	09 f4       	brne	.+2      	; 0xbcc <__vector_7+0x62>
 bca:	80 e0       	ldi	r24, 0x00	; 0

    if (rx_mode == RX_MODE_PRE)
 bcc:	90 91 03 01 	lds	r25, 0x0103
 bd0:	91 11       	cpse	r25, r1
 bd2:	0d c0       	rjmp	.+26     	; 0xbee <__vector_7+0x84>
    {
      // Wait for first transition to HIGH
      if (transition && (rx_sample == 1))
 bd4:	88 23       	and	r24, r24
 bd6:	09 f4       	brne	.+2      	; 0xbda <__vector_7+0x70>
 bd8:	77 c0       	rjmp	.+238    	; 0xcc8 <__vector_7+0x15e>
 bda:	c1 30       	cpi	r28, 0x01	; 1
 bdc:	d1 05       	cpc	r29, r1
 bde:	09 f0       	breq	.+2      	; 0xbe2 <__vector_7+0x78>
 be0:	73 c0       	rjmp	.+230    	; 0xcc8 <__vector_7+0x15e>
      {
        rx_count = 0;
 be2:	10 92 f8 01 	sts	0x01F8, r1
        rx_sync_count = 0;
 be6:	10 92 f7 01 	sts	0x01F7, r1
        rx_mode = RX_MODE_SYNC;
 bea:	81 e0       	ldi	r24, 0x01	; 1
 bec:	5b c0       	rjmp	.+182    	; 0xca4 <__vector_7+0x13a>
      }
    }
    else if (rx_mode == RX_MODE_SYNC)
 bee:	91 30       	cpi	r25, 0x01	; 1
 bf0:	b9 f5       	brne	.+110    	; 0xc60 <__vector_7+0xf6>
    {
      // Initial sync block
      if (transition)
 bf2:	88 23       	and	r24, r24
 bf4:	09 f4       	brne	.+2      	; 0xbf8 <__vector_7+0x8e>
 bf6:	68 c0       	rjmp	.+208    	; 0xcc8 <__vector_7+0x15e>
      {
        if(((rx_sync_count < 20) || (rx_last_sample == 1)) &&
 bf8:	80 91 f7 01 	lds	r24, 0x01F7
 bfc:	84 31       	cpi	r24, 0x14	; 20
 bfe:	18 f0       	brcs	.+6      	; 0xc06 <__vector_7+0x9c>
 c00:	01 30       	cpi	r16, 0x01	; 1
 c02:	11 05       	cpc	r17, r1
 c04:	41 f4       	brne	.+16     	; 0xc16 <__vector_7+0xac>
           ((rx_count < MinCount) || (rx_count > MaxCount)))
 c06:	90 91 f8 01 	lds	r25, 0x01F8
 c0a:	91 52       	subi	r25, 0x21	; 33
    else if (rx_mode == RX_MODE_SYNC)
    {
      // Initial sync block
      if (transition)
      {
        if(((rx_sync_count < 20) || (rx_last_sample == 1)) &&
 c0c:	91 32       	cpi	r25, 0x21	; 33
 c0e:	18 f0       	brcs	.+6      	; 0xc16 <__vector_7+0xac>
           ((rx_count < MinCount) || (rx_count > MaxCount)))
        {
          // First 20 bits and all 1 bits are expected to be regular
          // Transition was too slow/fast
          rx_mode = RX_MODE_PRE;
 c10:	10 92 03 01 	sts	0x0103, r1
 c14:	59 c0       	rjmp	.+178    	; 0xcc8 <__vector_7+0x15e>
        }
        else if((rx_last_sample == 0) &&
 c16:	01 15       	cp	r16, r1
 c18:	11 05       	cpc	r17, r1
 c1a:	29 f4       	brne	.+10     	; 0xc26 <__vector_7+0xbc>
                ((rx_count < MinCount) || (rx_count > MaxLongCount)))
 c1c:	90 91 f8 01 	lds	r25, 0x01F8
 c20:	91 52       	subi	r25, 0x21	; 33
        {
          // First 20 bits and all 1 bits are expected to be regular
          // Transition was too slow/fast
          rx_mode = RX_MODE_PRE;
        }
        else if((rx_last_sample == 0) &&
 c22:	91 36       	cpi	r25, 0x61	; 97
 c24:	a8 f7       	brcc	.-22     	; 0xc10 <__vector_7+0xa6>
          // Transition was too slow/fast
          rx_mode = RX_MODE_PRE;
        }
        else
        {
          rx_sync_count++;
 c26:	8f 5f       	subi	r24, 0xFF	; 255
 c28:	80 93 f7 01 	sts	0x01F7, r24

          if((rx_last_sample == 0) &&
 c2c:	01 2b       	or	r16, r17
 c2e:	99 f4       	brne	.+38     	; 0xc56 <__vector_7+0xec>
 c30:	84 31       	cpi	r24, 0x14	; 20
 c32:	08 f4       	brcc	.+2      	; 0xc36 <__vector_7+0xcc>
 c34:	47 c0       	rjmp	.+142    	; 0xcc4 <__vector_7+0x15a>
             (rx_sync_count >= 20) &&
 c36:	90 91 f8 01 	lds	r25, 0x01F8
 c3a:	92 34       	cpi	r25, 0x42	; 66
 c3c:	60 f0       	brcs	.+24     	; 0xc56 <__vector_7+0xec>
          {
            // We have seen at least 10 regular transitions
            // Lock sequence ends with unencoded bits 01
            // This is encoded and TX as HI,LO,LO,HI
            // We have seen a long low - we are now locked!
            rx_mode = RX_MODE_DATA;
 c3e:	82 e0       	ldi	r24, 0x02	; 2
 c40:	80 93 03 01 	sts	0x0103, r24
            rx_manBits = 0;
 c44:	10 92 f6 01 	sts	0x01F6, r1
 c48:	10 92 f5 01 	sts	0x01F5, r1
            rx_numMB = 0;
 c4c:	10 92 f4 01 	sts	0x01F4, r1
            rx_curByte = 0;
 c50:	10 92 f3 01 	sts	0x01F3, r1
 c54:	37 c0       	rjmp	.+110    	; 0xcc4 <__vector_7+0x15a>
          }
          else if (rx_sync_count >= 32)
 c56:	80 32       	cpi	r24, 0x20	; 32
 c58:	a8 f1       	brcs	.+106    	; 0xcc4 <__vector_7+0x15a>
          {
            rx_mode = RX_MODE_PRE;
 c5a:	10 92 03 01 	sts	0x0103, r1
 c5e:	32 c0       	rjmp	.+100    	; 0xcc4 <__vector_7+0x15a>
          }
          rx_count = 0;
        }
      }
    }
    else if (rx_mode == RX_MODE_DATA)
 c60:	92 30       	cpi	r25, 0x02	; 2
 c62:	91 f5       	brne	.+100    	; 0xcc8 <__vector_7+0x15e>
    {
      // Receive data
      if (transition)
 c64:	88 23       	and	r24, r24
 c66:	81 f1       	breq	.+96     	; 0xcc8 <__vector_7+0x15e>
      {
        if((rx_count < MinCount) ||
 c68:	80 91 f8 01 	lds	r24, 0x01F8
 c6c:	9f ed       	ldi	r25, 0xDF	; 223
 c6e:	98 0f       	add	r25, r24
 c70:	91 36       	cpi	r25, 0x61	; 97
 c72:	70 f6       	brcc	.-100    	; 0xc10 <__vector_7+0xa6>
          // wrong signal lenght, discard the message
          rx_mode = RX_MODE_PRE;
        }
        else
        {
          if(rx_count >= MinLongCount) // was the previous bit a double bit?
 c74:	82 34       	cpi	r24, 0x42	; 66
 c76:	60 f0       	brcs	.+24     	; 0xc90 <__vector_7+0x126>
          {
            AddManBit(&rx_manBits, &rx_numMB, &rx_curByte, rx_data, rx_last_sample);
 c78:	20 91 00 01 	lds	r18, 0x0100
 c7c:	30 91 01 01 	lds	r19, 0x0101
 c80:	43 ef       	ldi	r20, 0xF3	; 243
 c82:	51 e0       	ldi	r21, 0x01	; 1
 c84:	64 ef       	ldi	r22, 0xF4	; 244
 c86:	71 e0       	ldi	r23, 0x01	; 1
 c88:	85 ef       	ldi	r24, 0xF5	; 245
 c8a:	91 e0       	ldi	r25, 0x01	; 1
 c8c:	0e 94 7f 05 	call	0xafe	; 0xafe <_Z9AddManBitPjPhS0_S0_h>
          }
          if ((rx_sample == 1) &&
 c90:	c1 30       	cpi	r28, 0x01	; 1
 c92:	d1 05       	cpc	r29, r1
 c94:	51 f4       	brne	.+20     	; 0xcaa <__vector_7+0x140>
 c96:	90 91 f3 01 	lds	r25, 0x01F3
 c9a:	80 91 02 01 	lds	r24, 0x0102
 c9e:	98 17       	cp	r25, r24
 ca0:	20 f0       	brcs	.+8      	; 0xcaa <__vector_7+0x140>
              (rx_curByte >= rx_maxBytes))
          {
            rx_mode = RX_MODE_MSG;
 ca2:	83 e0       	ldi	r24, 0x03	; 3
 ca4:	80 93 03 01 	sts	0x0103, r24
 ca8:	0f c0       	rjmp	.+30     	; 0xcc8 <__vector_7+0x15e>
          }
          else
          {
            // Add the current bit
            AddManBit(&rx_manBits, &rx_numMB, &rx_curByte, rx_data, rx_sample);
 caa:	20 91 00 01 	lds	r18, 0x0100
 cae:	30 91 01 01 	lds	r19, 0x0101
 cb2:	0c 2f       	mov	r16, r28
 cb4:	43 ef       	ldi	r20, 0xF3	; 243
 cb6:	51 e0       	ldi	r21, 0x01	; 1
 cb8:	64 ef       	ldi	r22, 0xF4	; 244
 cba:	71 e0       	ldi	r23, 0x01	; 1
 cbc:	85 ef       	ldi	r24, 0xF5	; 245
 cbe:	91 e0       	ldi	r25, 0x01	; 1
 cc0:	0e 94 7f 05 	call	0xafe	; 0xafe <_Z9AddManBitPjPhS0_S0_h>
            rx_count = 0;
 cc4:	10 92 f8 01 	sts	0x01F8, r1
        }
      }
    }

    // Get ready for next loop
    rx_last_sample = rx_sample;
 cc8:	d0 93 fa 01 	sts	0x01FA, r29
 ccc:	c0 93 f9 01 	sts	0x01F9, r28
  }
}
 cd0:	ff 91       	pop	r31
 cd2:	ef 91       	pop	r30
 cd4:	df 91       	pop	r29
 cd6:	cf 91       	pop	r28
 cd8:	bf 91       	pop	r27
 cda:	af 91       	pop	r26
 cdc:	9f 91       	pop	r25
 cde:	8f 91       	pop	r24
 ce0:	7f 91       	pop	r23
 ce2:	6f 91       	pop	r22
 ce4:	5f 91       	pop	r21
 ce6:	4f 91       	pop	r20
 ce8:	3f 91       	pop	r19
 cea:	2f 91       	pop	r18
 cec:	1f 91       	pop	r17
 cee:	0f 91       	pop	r16
 cf0:	0f 90       	pop	r0
 cf2:	0f be       	out	0x3f, r0	; 63
 cf4:	0f 90       	pop	r0
 cf6:	1f 90       	pop	r1
 cf8:	18 95       	reti

00000cfa <_GLOBAL__sub_I__ZN10ManchesterC2Ev>:
static uint8_t rx_default_data[2];
static uint8_t* rx_data = rx_default_data;

Manchester::Manchester() //constructor
{
  applyWorkAround1Mhz = 0;
 cfa:	10 92 f0 01 	sts	0x01F0, r1
 cfe:	08 95       	ret

00000d00 <turnOffPWM>:
//
//static inline void turnOffPWM(uint8_t timer) __attribute__ ((always_inline));
//static inline void turnOffPWM(uint8_t timer)
static void turnOffPWM(uint8_t timer)
{
	switch (timer)
 d00:	83 30       	cpi	r24, 0x03	; 3
 d02:	81 f0       	breq	.+32     	; 0xd24 <turnOffPWM+0x24>
 d04:	28 f4       	brcc	.+10     	; 0xd10 <turnOffPWM+0x10>
 d06:	81 30       	cpi	r24, 0x01	; 1
 d08:	99 f0       	breq	.+38     	; 0xd30 <turnOffPWM+0x30>
 d0a:	82 30       	cpi	r24, 0x02	; 2
 d0c:	a1 f0       	breq	.+40     	; 0xd36 <turnOffPWM+0x36>
 d0e:	08 95       	ret
 d10:	87 30       	cpi	r24, 0x07	; 7
 d12:	a9 f0       	breq	.+42     	; 0xd3e <turnOffPWM+0x3e>
 d14:	88 30       	cpi	r24, 0x08	; 8
 d16:	b9 f0       	breq	.+46     	; 0xd46 <turnOffPWM+0x46>
 d18:	84 30       	cpi	r24, 0x04	; 4
 d1a:	d1 f4       	brne	.+52     	; 0xd50 <turnOffPWM+0x50>
	{
		#if defined(TCCR1A) && defined(COM1A1)
		case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
		#endif
		#if defined(TCCR1A) && defined(COM1B1)
		case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
 d1c:	80 91 80 00 	lds	r24, 0x0080
 d20:	8f 7d       	andi	r24, 0xDF	; 223
 d22:	03 c0       	rjmp	.+6      	; 0xd2a <turnOffPWM+0x2a>
static void turnOffPWM(uint8_t timer)
{
	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1)
		case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
 d24:	80 91 80 00 	lds	r24, 0x0080
 d28:	8f 77       	andi	r24, 0x7F	; 127
		#endif
		#if defined(TCCR1A) && defined(COM1B1)
		case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
 d2a:	80 93 80 00 	sts	0x0080, r24
 d2e:	08 95       	ret
		#if defined(TCCR2) && defined(COM21)
		case  TIMER2:   cbi(TCCR2, COM21);      break;
		#endif
		
		#if defined(TCCR0A) && defined(COM0A1)
		case  TIMER0A:  cbi(TCCR0A, COM0A1);    break;
 d30:	84 b5       	in	r24, 0x24	; 36
 d32:	8f 77       	andi	r24, 0x7F	; 127
 d34:	02 c0       	rjmp	.+4      	; 0xd3a <turnOffPWM+0x3a>
		#endif
		
		#if defined(TIMER0B) && defined(COM0B1)
		case  TIMER0B:  cbi(TCCR0A, COM0B1);    break;
 d36:	84 b5       	in	r24, 0x24	; 36
 d38:	8f 7d       	andi	r24, 0xDF	; 223
 d3a:	84 bd       	out	0x24, r24	; 36
 d3c:	08 95       	ret
		#endif
		#if defined(TCCR2A) && defined(COM2A1)
		case  TIMER2A:  cbi(TCCR2A, COM2A1);    break;
 d3e:	80 91 b0 00 	lds	r24, 0x00B0
 d42:	8f 77       	andi	r24, 0x7F	; 127
 d44:	03 c0       	rjmp	.+6      	; 0xd4c <turnOffPWM+0x4c>
		#endif
		#if defined(TCCR2A) && defined(COM2B1)
		case  TIMER2B:  cbi(TCCR2A, COM2B1);    break;
 d46:	80 91 b0 00 	lds	r24, 0x00B0
 d4a:	8f 7d       	andi	r24, 0xDF	; 223
 d4c:	80 93 b0 00 	sts	0x00B0, r24
 d50:	08 95       	ret

00000d52 <pinMode>:
#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_arduino.h"

void pinMode(uint8_t pin, uint8_t mode)
{
 d52:	cf 93       	push	r28
 d54:	df 93       	push	r29
	uint8_t bit = digitalPinToBitMask(pin);
 d56:	90 e0       	ldi	r25, 0x00	; 0
 d58:	fc 01       	movw	r30, r24
 d5a:	e4 58       	subi	r30, 0x84	; 132
 d5c:	ff 4f       	sbci	r31, 0xFF	; 255
 d5e:	24 91       	lpm	r18, Z
	uint8_t port = digitalPinToPort(pin);
 d60:	fc 01       	movw	r30, r24
 d62:	e0 57       	subi	r30, 0x70	; 112
 d64:	ff 4f       	sbci	r31, 0xFF	; 255
 d66:	84 91       	lpm	r24, Z
	volatile uint8_t *reg, *out;

	if (port == NOT_A_PIN) return;
 d68:	88 23       	and	r24, r24
 d6a:	49 f1       	breq	.+82     	; 0xdbe <pinMode+0x6c>

	// JWS: can I let the optimizer do this?
	reg = portModeRegister(port);
 d6c:	90 e0       	ldi	r25, 0x00	; 0
 d6e:	88 0f       	add	r24, r24
 d70:	99 1f       	adc	r25, r25
 d72:	fc 01       	movw	r30, r24
 d74:	e8 54       	subi	r30, 0x48	; 72
 d76:	ff 4f       	sbci	r31, 0xFF	; 255
 d78:	a5 91       	lpm	r26, Z+
 d7a:	b4 91       	lpm	r27, Z
	out = portOutputRegister(port);
 d7c:	82 55       	subi	r24, 0x52	; 82
 d7e:	9f 4f       	sbci	r25, 0xFF	; 255
 d80:	fc 01       	movw	r30, r24
 d82:	c5 91       	lpm	r28, Z+
 d84:	d4 91       	lpm	r29, Z

	if (mode == INPUT) { 
		uint8_t oldSREG = SREG;
 d86:	9f b7       	in	r25, 0x3f	; 63

	// JWS: can I let the optimizer do this?
	reg = portModeRegister(port);
	out = portOutputRegister(port);

	if (mode == INPUT) { 
 d88:	61 11       	cpse	r22, r1
 d8a:	08 c0       	rjmp	.+16     	; 0xd9c <pinMode+0x4a>
		uint8_t oldSREG = SREG;
                cli();
 d8c:	f8 94       	cli
		*reg &= ~bit;
 d8e:	8c 91       	ld	r24, X
 d90:	20 95       	com	r18
 d92:	82 23       	and	r24, r18
 d94:	8c 93       	st	X, r24
		*out &= ~bit;
 d96:	88 81       	ld	r24, Y
 d98:	82 23       	and	r24, r18
 d9a:	0a c0       	rjmp	.+20     	; 0xdb0 <pinMode+0x5e>
		SREG = oldSREG;
	} else if (mode == INPUT_PULLUP) {
 d9c:	62 30       	cpi	r22, 0x02	; 2
 d9e:	51 f4       	brne	.+20     	; 0xdb4 <pinMode+0x62>
		uint8_t oldSREG = SREG;
                cli();
 da0:	f8 94       	cli
		*reg &= ~bit;
 da2:	8c 91       	ld	r24, X
 da4:	32 2f       	mov	r19, r18
 da6:	30 95       	com	r19
 da8:	83 23       	and	r24, r19
 daa:	8c 93       	st	X, r24
		*out |= bit;
 dac:	88 81       	ld	r24, Y
 dae:	82 2b       	or	r24, r18
 db0:	88 83       	st	Y, r24
 db2:	04 c0       	rjmp	.+8      	; 0xdbc <pinMode+0x6a>
		SREG = oldSREG;
	} else {
		uint8_t oldSREG = SREG;
                cli();
 db4:	f8 94       	cli
		*reg |= bit;
 db6:	8c 91       	ld	r24, X
 db8:	82 2b       	or	r24, r18
 dba:	8c 93       	st	X, r24
		SREG = oldSREG;
 dbc:	9f bf       	out	0x3f, r25	; 63
	}
}
 dbe:	df 91       	pop	r29
 dc0:	cf 91       	pop	r28
 dc2:	08 95       	ret

00000dc4 <digitalRead>:

	SREG = oldSREG;
}

int digitalRead(uint8_t pin)
{
 dc4:	cf 93       	push	r28
 dc6:	df 93       	push	r29
	uint8_t timer = digitalPinToTimer(pin);
 dc8:	28 2f       	mov	r18, r24
 dca:	30 e0       	ldi	r19, 0x00	; 0
 dcc:	f9 01       	movw	r30, r18
 dce:	e8 59       	subi	r30, 0x98	; 152
 dd0:	ff 4f       	sbci	r31, 0xFF	; 255
 dd2:	84 91       	lpm	r24, Z
	uint8_t bit = digitalPinToBitMask(pin);
 dd4:	f9 01       	movw	r30, r18
 dd6:	e4 58       	subi	r30, 0x84	; 132
 dd8:	ff 4f       	sbci	r31, 0xFF	; 255
 dda:	d4 91       	lpm	r29, Z
	uint8_t port = digitalPinToPort(pin);
 ddc:	f9 01       	movw	r30, r18
 dde:	e0 57       	subi	r30, 0x70	; 112
 de0:	ff 4f       	sbci	r31, 0xFF	; 255
 de2:	c4 91       	lpm	r28, Z

	if (port == NOT_A_PIN) return LOW;
 de4:	cc 23       	and	r28, r28
 de6:	91 f0       	breq	.+36     	; 0xe0c <digitalRead+0x48>

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);
 de8:	81 11       	cpse	r24, r1
 dea:	0e 94 80 06 	call	0xd00	; 0xd00 <turnOffPWM>

	if (*portInputRegister(port) & bit) return HIGH;
 dee:	ec 2f       	mov	r30, r28
 df0:	f0 e0       	ldi	r31, 0x00	; 0
 df2:	ee 0f       	add	r30, r30
 df4:	ff 1f       	adc	r31, r31
 df6:	ec 55       	subi	r30, 0x5C	; 92
 df8:	ff 4f       	sbci	r31, 0xFF	; 255
 dfa:	a5 91       	lpm	r26, Z+
 dfc:	b4 91       	lpm	r27, Z
 dfe:	2c 91       	ld	r18, X
 e00:	2d 23       	and	r18, r29
 e02:	81 e0       	ldi	r24, 0x01	; 1
 e04:	90 e0       	ldi	r25, 0x00	; 0
 e06:	21 f4       	brne	.+8      	; 0xe10 <digitalRead+0x4c>
 e08:	80 e0       	ldi	r24, 0x00	; 0
 e0a:	02 c0       	rjmp	.+4      	; 0xe10 <digitalRead+0x4c>
{
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PIN) return LOW;
 e0c:	80 e0       	ldi	r24, 0x00	; 0
 e0e:	90 e0       	ldi	r25, 0x00	; 0
	// before getting a digital reading.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}
 e10:	df 91       	pop	r29
 e12:	cf 91       	pop	r28
 e14:	08 95       	ret

00000e16 <__divmodhi4>:
 e16:	97 fb       	bst	r25, 7
 e18:	07 2e       	mov	r0, r23
 e1a:	16 f4       	brtc	.+4      	; 0xe20 <__divmodhi4+0xa>
 e1c:	00 94       	com	r0
 e1e:	07 d0       	rcall	.+14     	; 0xe2e <__divmodhi4_neg1>
 e20:	77 fd       	sbrc	r23, 7
 e22:	09 d0       	rcall	.+18     	; 0xe36 <__divmodhi4_neg2>
 e24:	0e 94 41 07 	call	0xe82	; 0xe82 <__udivmodhi4>
 e28:	07 fc       	sbrc	r0, 7
 e2a:	05 d0       	rcall	.+10     	; 0xe36 <__divmodhi4_neg2>
 e2c:	3e f4       	brtc	.+14     	; 0xe3c <__divmodhi4_exit>

00000e2e <__divmodhi4_neg1>:
 e2e:	90 95       	com	r25
 e30:	81 95       	neg	r24
 e32:	9f 4f       	sbci	r25, 0xFF	; 255
 e34:	08 95       	ret

00000e36 <__divmodhi4_neg2>:
 e36:	70 95       	com	r23
 e38:	61 95       	neg	r22
 e3a:	7f 4f       	sbci	r23, 0xFF	; 255

00000e3c <__divmodhi4_exit>:
 e3c:	08 95       	ret

00000e3e <__udivmodsi4>:
 e3e:	a1 e2       	ldi	r26, 0x21	; 33
 e40:	1a 2e       	mov	r1, r26
 e42:	aa 1b       	sub	r26, r26
 e44:	bb 1b       	sub	r27, r27
 e46:	fd 01       	movw	r30, r26
 e48:	0d c0       	rjmp	.+26     	; 0xe64 <__udivmodsi4_ep>

00000e4a <__udivmodsi4_loop>:
 e4a:	aa 1f       	adc	r26, r26
 e4c:	bb 1f       	adc	r27, r27
 e4e:	ee 1f       	adc	r30, r30
 e50:	ff 1f       	adc	r31, r31
 e52:	a2 17       	cp	r26, r18
 e54:	b3 07       	cpc	r27, r19
 e56:	e4 07       	cpc	r30, r20
 e58:	f5 07       	cpc	r31, r21
 e5a:	20 f0       	brcs	.+8      	; 0xe64 <__udivmodsi4_ep>
 e5c:	a2 1b       	sub	r26, r18
 e5e:	b3 0b       	sbc	r27, r19
 e60:	e4 0b       	sbc	r30, r20
 e62:	f5 0b       	sbc	r31, r21

00000e64 <__udivmodsi4_ep>:
 e64:	66 1f       	adc	r22, r22
 e66:	77 1f       	adc	r23, r23
 e68:	88 1f       	adc	r24, r24
 e6a:	99 1f       	adc	r25, r25
 e6c:	1a 94       	dec	r1
 e6e:	69 f7       	brne	.-38     	; 0xe4a <__udivmodsi4_loop>
 e70:	60 95       	com	r22
 e72:	70 95       	com	r23
 e74:	80 95       	com	r24
 e76:	90 95       	com	r25
 e78:	9b 01       	movw	r18, r22
 e7a:	ac 01       	movw	r20, r24
 e7c:	bd 01       	movw	r22, r26
 e7e:	cf 01       	movw	r24, r30
 e80:	08 95       	ret

00000e82 <__udivmodhi4>:
 e82:	aa 1b       	sub	r26, r26
 e84:	bb 1b       	sub	r27, r27
 e86:	51 e1       	ldi	r21, 0x11	; 17
 e88:	07 c0       	rjmp	.+14     	; 0xe98 <__udivmodhi4_ep>

00000e8a <__udivmodhi4_loop>:
 e8a:	aa 1f       	adc	r26, r26
 e8c:	bb 1f       	adc	r27, r27
 e8e:	a6 17       	cp	r26, r22
 e90:	b7 07       	cpc	r27, r23
 e92:	10 f0       	brcs	.+4      	; 0xe98 <__udivmodhi4_ep>
 e94:	a6 1b       	sub	r26, r22
 e96:	b7 0b       	sbc	r27, r23

00000e98 <__udivmodhi4_ep>:
 e98:	88 1f       	adc	r24, r24
 e9a:	99 1f       	adc	r25, r25
 e9c:	5a 95       	dec	r21
 e9e:	a9 f7       	brne	.-22     	; 0xe8a <__udivmodhi4_loop>
 ea0:	80 95       	com	r24
 ea2:	90 95       	com	r25
 ea4:	bc 01       	movw	r22, r24
 ea6:	cd 01       	movw	r24, r26
 ea8:	08 95       	ret

00000eaa <__tablejump2__>:
 eaa:	ee 0f       	add	r30, r30
 eac:	ff 1f       	adc	r31, r31

00000eae <__tablejump__>:
 eae:	05 90       	lpm	r0, Z+
 eb0:	f4 91       	lpm	r31, Z
 eb2:	e0 2d       	mov	r30, r0
 eb4:	09 94       	ijmp

00000eb6 <_exit>:
 eb6:	f8 94       	cli

00000eb8 <__stop_program>:
 eb8:	ff cf       	rjmp	.-2      	; 0xeb8 <__stop_program>
