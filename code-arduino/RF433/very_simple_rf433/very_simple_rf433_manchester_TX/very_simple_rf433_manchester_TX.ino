/*

    Very simple RF433 TX MANCHESTER

*/

#include <avr/io.h>
#include <util/delay.h>
#include <Manchester.h>

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
    DDRD = 0b11111111;

    L13_INIT;
    TRIG_INIT;

    // man.setupTransmit( TX_PIN, MAN_300 );
    // man.setupTransmit( TX_PIN, MAN_600 );
    // man.setupTransmit( TX_PIN, MAN_1200 );
    man.setupTransmit( TX_PIN, MAN_2400 );
    // man.setupTransmit( TX_PIN, MAN_4800 );
    // man.setupTransmit( TX_PIN, MAN_9600 );
    // man.setupTransmit( TX_PIN, MAN_19200 );
    // man.setupTransmit( TX_PIN, MAN_38400 );

}

#if TX_ID == 1
const double dt1 = 196 / 2;
const double dt2 = 804 / 2;
#elif TX_ID == 2
const double dt1 = 311 / 2;
const double dt2 = 689 / 2;
#elif TX_ID == 3
const double dt1 = 494 / 2;
const double dt2 = 506 / 2;
#elif TX_ID == 4
const double dt1 = 784 / 2;
const double dt2 = 216 / 2;
#endif


const uint16_t transmit_data = TX_ID;

void loop()
{
    if( TRIG_READ )
    {
        L13_SET;
        for( int i=0; i<1; i++ )
        {
            man.transmit( transmit_data );
        }
        while( TRIG_READ ){}
        L13_CLEAR;
    }
}
