
/Users/nico/Documents/Arduino_Build/blink_minimal/blink_minimal.elf:     file format elf32-avr


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
  78:	0c 94 4e 00 	jmp	0x9c	; 0x9c <_exit>

0000007c <__bad_interrupt>:
  7c:	0c 94 00 00 	jmp	0	; 0x0 <__vectors>

00000080 <main>:
int main( void );

int main( void )
{
    byte multCNT;
    TCCR2B = 0b00000111; // PÃ©riode compteurÂ : Tc = TCCR2B/CLK = 1024/16E6 = 64Â Âµs
  80:	87 e0       	ldi	r24, 0x07	; 7
  82:	80 93 b1 00 	sts	0x00B1, r24
            TCNT2 = 0;
            bitSet( TIFR2, TOV2 );
            if( multCNT++ > 61  )  // = (1/2 * 2s) / ( 64Âµs * 256)
            {
                multCNT=0;
                PINB = ( 1<<LEDpin );
  86:	90 e2       	ldi	r25, 0x20	; 32
#define LEDpin  5

int main( void );

int main( void )
{
  88:	8f e3       	ldi	r24, 0x3F	; 63
    byte multCNT;
    TCCR2B = 0b00000111; // PÃ©riode compteurÂ : Tc = TCCR2B/CLK = 1024/16E6 = 64Â Âµs
    while( 1 )
    {
        if ( TIFR2 & ( 1<<TOV2 ) )
  8a:	b8 9b       	sbis	0x17, 0	; 23
  8c:	fe cf       	rjmp	.-4      	; 0x8a <main+0xa>
        {
            TCNT2 = 0;
  8e:	10 92 b2 00 	sts	0x00B2, r1
            bitSet( TIFR2, TOV2 );
  92:	b8 9a       	sbi	0x17, 0	; 23
  94:	81 50       	subi	r24, 0x01	; 1
            if( multCNT++ > 61  )  // = (1/2 * 2s) / ( 64Âµs * 256)
  96:	c9 f7       	brne	.-14     	; 0x8a <main+0xa>
            {
                multCNT=0;
                PINB = ( 1<<LEDpin );
  98:	93 b9       	out	0x03, r25	; 3
  9a:	f6 cf       	rjmp	.-20     	; 0x88 <main+0x8>

0000009c <_exit>:
  9c:	f8 94       	cli

0000009e <__stop_program>:
  9e:	ff cf       	rjmp	.-2      	; 0x9e <__stop_program>
