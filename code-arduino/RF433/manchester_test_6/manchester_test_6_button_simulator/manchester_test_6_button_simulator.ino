/*
 *
 * Simulateur de boutons pour RF433
 *
 */

#include <avr/io.h>
#include <util/delay.h>

// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13

#define B1Set bitSet ( PORTD, 7 )
#define B2Set bitSet ( PORTD, 6 )
#define B3Set bitSet ( PORTD, 5 )
#define B4Set bitSet ( PORTD, 4 )

#define B1Clear bitClear ( PORTD, 7 )
#define B2Clear bitClear ( PORTD, 6 )
#define B3Clear bitClear ( PORTD, 5 )
#define B4Clear bitClear ( PORTD, 4 )

const int delay1 = 100;
const int delay2 = 2000;

void B1SetOnly()
{
    B1Set;   B2Clear; B3Clear; B4Clear;     L13Set;    _delay_ms( delay1 ); L13Clear; _delay_ms( delay1 );
}
void B2SetOnly()
{
    B1Clear; B2Set;   B3Clear; B4Clear;     L13Set;    _delay_ms( delay1 ); L13Clear; _delay_ms( delay1 );
}
void B3SetOnly()
{
    B1Clear; B2Clear; B3Set;   B4Clear;     L13Set;    _delay_ms( delay1 ); L13Clear; _delay_ms( delay1 );
}
void B4SetOnly()
{
    B1Clear; B2Clear; B3Clear; B4Set;       L13Set;    _delay_ms( delay1 ); L13Clear; _delay_ms( delay1 );
}
void BClearAll()
{
    B1Clear; B2Clear; B3Clear; B4Clear;     L13Clear;  _delay_ms( delay2 );
}

int main( void )
{
    DDRB = 0b11111111;
    DDRD = 0b11111111;
    BClearAll();
    while( true )
    {
        // B1SetOnly();
        // B2SetOnly();
        // B3SetOnly();
        // B4SetOnly();
        // BClearAll();

        B2SetOnly();
        B3SetOnly();
        B4SetOnly();
        B1SetOnly();
        BClearAll();

        // B3SetOnly();
        // B4SetOnly();
        // B1SetOnly();
        // B2SetOnly();
        // BClearAll();

        // B4SetOnly();
        // B1SetOnly();
        // B2SetOnly();
        // B3SetOnly();
        // BClearAll();
    }
    return 0;
}

