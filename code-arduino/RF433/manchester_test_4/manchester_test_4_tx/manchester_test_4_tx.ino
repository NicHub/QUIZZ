
// #include <Manchester.h>
#include <Manchester-Lausanne.h>

// PORTB4 -> LED 0
#define bL0  PORTB4
#define      L0Read    bitRead (  PINB, bL0 )
#define      L0Set     bitSet  ( PORTB, bL0 )
#define      L0Clear   bitClear( PORTB, bL0 )
#define      L0Toggle  PORTB ^= 1<<bL0

// PORTB1 -> Bouton
#define bBouton    PORTB1
#define boutonRead bitRead( PINB, bBouton )

// PORTB2 -> Générateur de nombres aléatoires
#define pinRandom  PORTB1
#define randomRead analogRead( PORTB1 )


#define bouton    2 // À modifier pour que chaque bouton soit unique.
#define TXPin     3
#define minWait 100
#define maxWait 300


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



void wait( byte delayMs )
{
    for( volatile byte i=0; i<delayMs; i++ )
    {
        for( volatile byte j=0; j<255; j++ ) {}
    }
}



int main()
{
    DDRB = 0b11111111;
    bitClear( DDRB, bBouton );
    man.setupTransmit( TXPin, MAN_600 );
    byte waitTime = 0;

    while( true )
    {
        while( boutonRead )
        {
            for( byte i=0; i<6; i++ )
            {
                L0Toggle;
                man.transmit( transmit_data );
                waitTime = random( 10, 255 );
                wait( waitTime );
            }
        }
    }
}
