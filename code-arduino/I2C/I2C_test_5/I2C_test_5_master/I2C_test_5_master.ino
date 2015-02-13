

#include <Wire.h>

#define bL13 PORTB5
#define L13Toggle PORTB ^= 1 << bL13

void setup()
{
    Wire.begin();
    DDRB |= 1 << bL13;
}

byte x[ 2 ];
int i;
int nbToSend;
void loop()
{
    if( i > 9999 )
        i = 0;
    nbToSend = i++;
    x[ 0 ] =   nbToSend        & 0b0000000001111111; // bits  0 -  6
    x[ 1 ] = ( nbToSend >> 7 ) & 0b0000000001111111; // bits  7 - 13
    Wire.beginTransmission( 4 );
    Wire.write( x, 2 );
    Wire.endTransmission();
    delay( 2 );
    L13Toggle;
}
