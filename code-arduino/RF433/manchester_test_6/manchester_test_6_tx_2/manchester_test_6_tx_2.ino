
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
// const uint16_t codeBouton = 2;
#define codeBouton 1

bool TriggerArmed = true;

void setup()
{
    bitSet( DDRB, bL13 );
    L13Clear;

    bitSet( DDRB, TXVCC );
    bitSet( DDRB, TXGND );
    bitSet( DDRB, TXDATA );
    bitClear( PORTB, TXGND );
    bitSet( PORTB, TXVCC );
    man.setupTransmit( TXDATA, MAN_1200 );


// MAN_300
// MAN_600
// MAN_1200
// MAN_2400
// MAN_4800
// MAN_9600
// MAN_19200
// MAN_38400

    bitClear( DDRD, 4 );
    bitClear( DDRD, 5 );
    bitClear( DDRD, 6 );
    bitClear( DDRD, 7 );
}


#if codeBouton == 1
const double dt1 = 196 / 2;
const double dt2 = 804 / 2;
#elif codeBouton == 2
const double dt1 = 311 / 2;
const double dt2 = 689 / 2;
#elif codeBouton == 3
const double dt1 = 494 / 2;
const double dt2 = 506 / 2;
#elif codeBouton == 4
const double dt1 = 784 / 2;
const double dt2 = 216 / 2;
#endif


void loop()
{
    // man.transmit( 1 );
    // _delay_ms( 100 );

    // for(int i=0; i<6; i++)
    // {
    //     bitSet( PORTB, TXDATA );
    //     _delay_us( dt1 );
    //     bitClear( PORTB, TXDATA );
    //     _delay_us( dt2 );
    // }
    // _delay_ms( 5 );
    for(int i=0; i<10; i++)
    {
        bitSet( PORTB, TXDATA );
        _delay_us( 100 );
        bitClear( PORTB, TXDATA );
        _delay_us( 100 );
    }

    bitSet( PORTB, TXDATA );
    _delay_us( 100 );
    bitClear( PORTB, TXDATA );
    _delay_us( 100 );

}
