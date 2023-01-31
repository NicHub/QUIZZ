



//#include <avr/io.h>
//#include "Arduino.h"

// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13
// PORTB4 -> LED 0
#define bL0  PORTB4
#define      L0Read    bitRead (  PINB, bL0 )
#define      L0Set     bitSet  ( PORTB, bL0 )
#define      L0Clear   bitClear( PORTB, bL0 )
#define      L0Toggle  PORTB ^= 1<<bL0
// PORTB3 -> LED 1
#define bL1  PORTB3
#define      L1Read    bitRead (  PINB, bL1 )
#define      L1Set     bitSet  ( PORTB, bL1 )
#define      L1Clear   bitClear( PORTB, bL1 )
#define      L1Toggle  PORTB ^= 1<<bL1
// PORTB2 -> LED 2
#define bL2  PORTB2
#define      L2Read    bitRead (  PINB, bL2 )
#define      L2Set     bitSet  ( PORTB, bL2 )
#define      L2Clear   bitClear( PORTB, bL2 )
#define      L2Toggle  PORTB ^= 1<<bL2
// PORTB1 -> LED 0
#define bL3  PORTB1
#define      L3Read    bitRead (  PINB, bL3 )
#define      L3Set     bitSet  ( PORTB, bL3 )
#define      L3Clear   bitClear( PORTB, bL3 )
#define      L3Toggle  PORTB ^= 1<<bL3
// PORTD2 -> Bouton 1
#define bP1  PORTD2
#define      P1Read    !bitRead(  PIND, bP1 )
// Pin Data sur le transmetteur

#define RXPin1    2
#define bRX1 PORTD2
#define RXPin2    3
#define bRX2 PORTD3



void wait( int delayMs ) // calibré 8 Mega avec 450 (56 à 1 MHz)
{
    for( volatile int i=0; i<delayMs; i++ )
    {
        for( volatile int j=0; j<450; j++ ) {}
    }
}


int main()
{
    DDRB = 0b11111111;
    L13Set;
    pinMode( 13, OUTPUT );

    while( true )
    {
        L13Toggle;
        wait( 100 );
//        digitalWrite( 13, HIGH );
    }
}

