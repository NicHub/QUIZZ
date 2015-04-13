
#include <Manchester.h>
#include <avr/io.h>
#include <util/delay.h>

// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13

// TX
#define TXDATA    3
#define TXVCC PORTB2
#define TXGND PORTB1

// Boutons
#define BoutonRead bitRead ( PIND, 7 )

// À modifier pour chaque Arduino
const uint16_t codeBouton = 2;

bool TriggerArmed = true;

void setup()
{
    bitSet( DDRB, bL13 );
    L13Clear;

    bitSet( DDRB, TXVCC );
    bitSet( DDRB, TXGND );
    bitClear( PORTB, TXGND );
    bitSet( PORTB, TXVCC );
    man.setupTransmit( TXDATA, MAN_600 );

    bitClear( DDRD, 4 );
    bitClear( DDRD, 5 );
    bitClear( DDRD, 6 );
    bitClear( DDRD, 7 );
}


void loop()
{
    uint16_t transmit_data = 0;
    if( BoutonRead ) { transmit_data = codeBouton; }

    if( transmit_data )
    {
        if( TriggerArmed )
        {
            for( int i=0; i<2; i++ )
            {
                man.transmit( transmit_data );
                L13Set;
                _delay_ms( 1 );
                L13Clear;
            }
            TriggerArmed = false;
        }
    }
    else
    {
        _delay_ms( 10 );
        TriggerArmed = true;
    }
}

