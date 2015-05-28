


#include <util/delay.h>

const int P0pin = PORTB0;
const int P1pin = PORTB1;
const int P2pin = PORTB2;
const int P3pin = PORTB3;
const unsigned long Pmask = ( 1 << P0pin ) | ( 1 << P1pin ) | ( 1 << P2pin ) | ( 1 << P3pin );
const int LEDpin = PORTB5;
const int HPpin = PORTC0;

#define HPToggle  PORTC ^=  ( 1 << HPpin )
#define LEDSet    PORTB |=  ( 1 << LEDpin )
#define LEDClear  PORTB &= ~( 1 << LEDpin )
#define LEDToggle PORTB ^=  ( 1 << LEDpin )
#define P1_4Read  ~PINB & Pmask

unsigned long P1_4Readcopy = 0;


void beep( byte nbBeep = 1 )
{
    for( int beepCNT=0; beepCNT<nbBeep; beepCNT++ )
    {
        for( int i=0; i<100; i++ )
        {
            HPToggle;
            _delay_ms( 1 );
        }
        _delay_ms( 10 );
    }
}

void setup()
{
    DDRB |=    ( 1 << LEDpin );
    DDRB &=   ~( 1 << P0pin )
            & ~( 1 << P1pin )
            & ~( 1 << P2pin )
            & ~( 1 << P3pin );
    PORTB = 0b11111111
        & ~( 1 << LEDpin );;

    DDRC  |=  ( 1 << HPpin );
    PORTC &= ~( 1 << HPpin );

    DDRD  = 0b00000000;
    PORTD = 0b11111111;

    beep();
    Serial.begin( 115200 );
    Serial.print( "\n###\nPmask = " );
    Serial.print( Pmask, BIN );

}

void loop()
{
    // LEDSet;
    // _delay_ms( 100 );
    // LEDClear;
    // _delay_ms( 50 );


    P1_4Readcopy = P1_4Read;
    // Serial.print( "\n" );
    // Serial.print( P1_4Readcopy, BIN );
    // _delay_ms( 200 );

    switch( P1_4Readcopy )
    {
        case 0:
            break;
        case 0b0001:
            beep( 1 );
            blockUntilDepressed();
            break;
        case 0b0010:
            beep( 2 );
            blockUntilDepressed();
            break;
        case 0b0100:
            beep( 3 );
            blockUntilDepressed();
            break;
        case 0b1000:
            beep( 4 );
            blockUntilDepressed();
            break;
    }


}


void blockUntilDepressed()
{
    do {
        P1_4Readcopy = P1_4Read;
        LEDSet;
        _delay_ms( 100 );
        Serial.print( "\nP1_4Readcopy, BIN = " );
        Serial.print( P1_4Readcopy, BIN );
        LEDClear;
        _delay_ms( 100 );
    }
    while( P1_4Read );
    LEDClear;
}

