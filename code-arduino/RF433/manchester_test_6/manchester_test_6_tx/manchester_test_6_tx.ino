
#include <Manchester.h>
#include <avr/io.h>
#include <util/delay.h>

// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13



// PORTB1 -> Bouton
#define bBouton    PORTB1
#define boutonRead bitRead( PINB, bBouton )

// TX
#define TXDATA    3
#define TXVCC PORTB2
#define TXGND PORTB1

int i = 0;

#define bouton 4

#define codeBouton1 20101
#define codeBouton2 20202
#define codeBouton3 20303
#define codeBouton4 20404

#if   bouton == 1
#define codeBouton codeBouton1
#elif bouton == 2
#define codeBouton codeBouton2
#elif bouton == 3
#define codeBouton codeBouton3
#elif bouton == 4
#define codeBouton codeBouton4
#endif

uint16_t transmit_data = codeBouton;




void setup()
{
    bitSet( DDRB, bL13 );
    bitSet( DDRB, TXVCC );
    bitSet( DDRB, TXGND );

    bitClear( PORTB, TXGND );
    bitSet( PORTB, TXVCC );
    man.setupTransmit( TXDATA, MAN_600 );
}

void loop()
{
    while( true )
    {
        man.transmit( transmit_data );
        L13Toggle;
        _delay_ms( 1000 );
    }
}

