// Nom du fichier original : RF_Rcv_101.ino


#include <Manchester.h>

const int ledPin =  13;
const int ledPin0 = 12;
const int dataPin =  3;


void setup()
{
    pinMode( ledPin,  OUTPUT );
    pinMode( ledPin0, OUTPUT );
    pinMode( dataPin,  INPUT );
    man.setupReceive( dataPin, MAN_1200 );
    man.beginReceive();
}

void loop()
{
    if( man.receiveComplete() )
    {
        digitalWrite( ledPin, HIGH );
        uint16_t m = man.getMessage();

        if( m == 10101 )
        {
            digitalWrite( ledPin0, HIGH );
        }

        man.beginReceive();
        delay( 100 );
    }
    digitalWrite( ledPin,  LOW );
    digitalWrite( ledPin0, LOW );
}

