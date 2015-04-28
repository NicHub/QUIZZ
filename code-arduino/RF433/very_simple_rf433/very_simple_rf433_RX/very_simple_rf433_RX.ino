/*
    very_simple_rf433_TX.ino
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED1PIN PORTB1
#define LED1SET    bitWrite( PORTB, LED1PIN, 1 )
#define LED1CLEAR  bitWrite( PORTB, LED1PIN, 0 )
#define LED1TOGGLE bitWrite( PORTB, LED1PIN, !bitRead( PINB, LED1PIN ) )
#define LED2PIN PORTB2
#define LED2SET    bitWrite( PORTB, LED2PIN, 1 )
#define LED2CLEAR  bitWrite( PORTB, LED2PIN, 0 )
#define LED2TOGGLE bitWrite( PORTB, LED2PIN, !bitRead( PINB, LED2PIN ) )
#define LED3PIN PORTB3
#define LED3SET    bitWrite( PORTB, LED3PIN, 1 )
#define LED3CLEAR  bitWrite( PORTB, LED3PIN, 0 )
#define LED3TOGGLE bitWrite( PORTB, LED3PIN, !bitRead( PINB, LED3PIN ) )
#define LED4PIN PORTB4
#define LED4SET    bitWrite( PORTB, LED4PIN, 1 )
#define LED4CLEAR  bitWrite( PORTB, LED4PIN, 0 )
#define LED4TOGGLE bitWrite( PORTB, LED4PIN, !bitRead( PINB, LED4PIN ) )
#define LED5PIN PORTB5
#define LED5SET    bitWrite( PORTB, LED5PIN, 1 )
#define LED5CLEAR  bitWrite( PORTB, LED5PIN, 0 )
#define LED5TOGGLE bitWrite( PORTB, LED5PIN, !bitRead( PINB, LED5PIN ) )

// RXDATA1
#define RXDATA1PIN    PORTD2
#define RXDATA1INIT   bitClear( DDRD,  RXDATA1PIN )
#define RXDATA1READ   bitRead ( PIND,  RXDATA1PIN )

// TXDATA
#define TXDATA1PIN    PORTD3
#define TXDATA1INIT   bitSet  ( DDRD,  TXDATA1PIN )
#define TXDATA1SET    bitSet  ( PORTD, TXDATA1PIN )
#define TXDATA1CLEAR  bitClear( PORTD, TXDATA1PIN )
#define TXDATA1TOGGLE bitWrite( PORTD, TXDATA1PIN, !bitRead( PIND, TXDATA1PIN ) )

int main()
{
     DDRB = 0b00000000;
    PORTB = 0b11111111;
     DDRC = 0b00000000;
    PORTC = 0b11111111;
    // DDRD = 0b00001000;
    // PORTD = 0b11101011;

    RXDATA1INIT;
    TXDATA1INIT;

    // initialize Timer1
    cli();                   // disable global interrupts
    TCCR1A = 0b00000000;     // set entire TCCR1A register to 0
    TCCR1B = 0b00000000
        | (1 << WGM12)       // turn on CTC mode:
        | (1 << CS11);
    OCR1A = 99;              // set compare match register to desired timer count:
    TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt:
    sei();                   // enable global interrupts

    while( true ){}
}

ISR( TIMER1_COMPA_vect )
{
    static byte ISRcount;
    ISRcount++;

    if( ISRcount <= 51 )
        { if( ISRcount % 4 == 0 ) { TXDATA1TOGGLE; } }
    else if( ISRcount <= 102 )
        { TXDATA1CLEAR; }
    else if( ISRcount <= 153 )
        { TXDATA1CLEAR; }
    else if( ISRcount <= 204 )
        { TXDATA1CLEAR; }
    else if( ISRcount <= 255 )
        { TXDATA1CLEAR; }
    else
        { ISRcount = 0; }
}
