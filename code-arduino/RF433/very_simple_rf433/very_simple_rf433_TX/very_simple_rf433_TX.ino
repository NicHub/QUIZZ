/*

    Very simple RF433 TX

*/

#include <avr/io.h>
#include <util/delay.h>

// LED 13 -> LED du board
#define L13_PIN    PORTB5
#define L13_INIT   bitSet  ( DDRB,  L13_PIN )
#define L13_READ   bitRead ( PINB,  L13_PIN )
#define L13_SET    bitSet  ( PORTB, L13_PIN )
#define L13_CLEAR  bitClear( PORTB, L13_PIN )
#define L13_TOGGLE PORTB ^= 1<<L13_PIN

// TX
#define TX_PIN    PORTD3
#define TX_INIT   bitSet  ( DDRD,  TX_PIN )
#define TX_READ   bitRead ( PIND,  TX_PIN )
#define TX_SET    bitSet  ( PORTD, TX_PIN )
#define TX_CLEAR  bitClear( PORTD, TX_PIN )
#define TX_TOGGLE PORTD ^= 1<<TX_PIN

// TRIGGER BUTTON
#define TRIG_PIN    PORTD4
#define TRIG_INIT   bitClear( DDRD,  TRIG_PIN )
#define TRIG_READ   bitRead ( PIND,  TRIG_PIN )
#define TRIG_SET    bitSet  ( PORTD, TRIG_PIN )
#define TRIG_CLEAR  bitClear( PORTD, TRIG_PIN )
#define TRIG_TOGGLE PORTD ^= 1<<TRIG_PIN

// À modifier pour chaque Arduino
#define TX_ID 1

void setup()
{
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    // DDRD = 0b11111111;
    DDRD = 0b11111011;

    TX_INIT;
    L13_INIT;
    TRIG_INIT;
}

#if TX_ID == 1
const double dt1 = 196 / 1;
const double dt2 = 804 / 1;
#elif TX_ID == 2
const double dt1 = 311 / 1;
const double dt2 = 689 / 1;
#elif TX_ID == 3
const double dt1 = 494 / 1;
const double dt2 = 506 / 1;
#elif TX_ID == 4
const double dt1 = 784 / 1;
const double dt2 = 216 / 1;
#endif

void loop()
{
    if( TRIG_READ )
    {
        L13_SET;
        for( int i=0; i<10; i++ )
        {
            TX_SET;    _delay_us( dt1 );
            TX_CLEAR;  _delay_us( dt2 );
        }
        while( TRIG_READ ){}
        L13_CLEAR;
    }
}
