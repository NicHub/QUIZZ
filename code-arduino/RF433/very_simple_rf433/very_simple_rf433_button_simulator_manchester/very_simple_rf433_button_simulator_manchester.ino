/*
 *
 */

#include <avr/io.h>
#include <util/delay.h>

// LED 13 -> LED du board
#define L13_PIN    PORTB5
#define L13_INIT   bitSet  ( DDRB,  L13_PIN )
#define L13_SET    bitSet  ( PORTB, L13_PIN )
#define L13_CLEAR  bitClear( PORTB, L13_PIN )
#define L13_TOGGLE PORTB ^= 1<<L13_PIN
// TRIGGER BUTTON SIMULATOR 1
#define TRIG1_PIN    PORTD2
#define TRIG1_INIT   bitSet  ( DDRD,  TRIG1_PIN )
#define TRIG1_SET    bitSet  ( PORTD, TRIG1_PIN )
#define TRIG1_CLEAR  bitClear( PORTD, TRIG1_PIN )
#define TRIG1_TOGGLE PORTD ^= 1<<TRIG1_PIN
// TRIGGER BUTTON SIMULATOR 2
#define TRIG2_PIN    PORTD3
#define TRIG2_INIT   bitSet  ( DDRD,  TRIG2_PIN )
#define TRIG2_SET    bitSet  ( PORTD, TRIG2_PIN )
#define TRIG2_CLEAR  bitClear( PORTD, TRIG2_PIN )
#define TRIG2_TOGGLE PORTD ^= 1<<TRIG2_PIN
// TRIGGER BUTTON SIMULATOR 3
#define TRIG3_PIN    PORTD4
#define TRIG3_INIT   bitSet  ( DDRD,  TRIG3_PIN )
#define TRIG3_SET    bitSet  ( PORTD, TRIG3_PIN )
#define TRIG3_CLEAR  bitClear( PORTD, TRIG3_PIN )
#define TRIG3_TOGGLE PORTD ^= 1<<TRIG3_PIN
// TRIGGER BUTTON SIMULATOR 4
#define TRIG4_PIN    PORTD5
#define TRIG4_INIT   bitSet  ( DDRD,  TRIG4_PIN )
#define TRIG4_SET    bitSet  ( PORTD, TRIG4_PIN )
#define TRIG4_CLEAR  bitClear( PORTD, TRIG4_PIN )
#define TRIG4_TOGGLE PORTD ^= 1<<TRIG4_PIN



void setup()
{
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    DDRD = 0b11111111;

    L13_INIT;
    TRIG1_INIT;
    TRIG2_INIT;
    TRIG3_INIT;
    TRIG4_INIT;

    L13_CLEAR;
    TRIG1_CLEAR;
    TRIG2_CLEAR;
    TRIG3_CLEAR;
    TRIG4_CLEAR;
}

void loop()
{
    TRIG1_SET;   _delay_ms( 50 );
    TRIG1_CLEAR; _delay_ms( 50 );
    L13_TOGGLE;
}


