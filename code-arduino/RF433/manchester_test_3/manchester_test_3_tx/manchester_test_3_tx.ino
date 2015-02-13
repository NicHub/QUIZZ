
#include <Manchester.h>

// PORTB4 -> LED 0
#define bL0  PORTB4
#define      L0Read    bitRead (  PINB, bL0 )
#define      L0Set     bitSet  ( PORTB, bL0 )
#define      L0Clear   bitClear( PORTB, bL0 )
#define      L0Toggle  PORTB ^= 1<<bL0



// PORTB1 -> Bouton
#define bBouton    PORTB1
#define boutonRead bitRead( PINB, bBouton )

// TX
#define TXPin    3

int i = 0;

#define bouton 2

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


void wait( int delayMs )
{
    for( volatile int i=0; i<delayMs; i++ )
    {
        for( volatile int j=0; j<45; j++ );;
    }
}



void setup()
{
    DDRB = 0b11111111;
    bitClear( DDRB, bBouton );
    man.setupTransmit( TXPin, MAN_600 );
}

void loop()
{
    while( boutonRead )
    {
        man.transmit( transmit_data );
        wait( 1 );
        L0Toggle;
    }
}

