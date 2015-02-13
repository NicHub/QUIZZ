#include <Wire.h>

#define bL13 PORTB5
#define L13Toggle PORTB ^= 1 << bL13

void setup()
{
    Wire.begin( 4 );
    Wire.onReceive( receiveEvent );
    Serial.begin( 9600 );
    DDRB |= 1 << bL13;
}

void loop()
{
}

byte ans[ 2 ];
int nbSent;
void receiveEvent( int howMany )
{
    for( int i = 0; i < howMany; i++ )
    {
        ans[ i ] = Wire.read();
    }
    nbSent = ( ans[ 1 ] << 7 ) + ans[ 0 ];
    Serial.print( nbSent ); Serial.print( "\n" );
    L13Toggle;
}

