#include <Wire.h>

#define SLAVE_ADDRESS 0x05
bool bouton;
const int boutonPin = 3;
const int ledPin    = 13;





// callback for received data
void receiveData( int byteCount )
{
    digitalWrite( ledPin, false );
    delay( 200 );
    digitalWrite( ledPin, true );
    delay( 200 );

    int number;
    while( Wire.available() )
    {
        number = Wire.read();
        multiBlink( number );
    }
}

// callback for sending data
void sendData()
{
    bool bouton = digitalRead( boutonPin );
    Wire.write( bouton );
}


void multiBlink( int number )
{
    for( int i=0; i<number; i++ )
    {
        digitalWrite( ledPin, true );
        delay( 100 );
        digitalWrite( ledPin, false );
        delay( 200 );
    }
}




void setup()
{

    // I²C
    Wire.begin( SLAVE_ADDRESS );
    Wire.onReceive( receiveData );
    Wire.onRequest( sendData );


    pinMode( boutonPin, INPUT_PULLUP );
    pinMode( ledPin, OUTPUT );

    multiBlink( 20 );
}

void loop()
{
    bouton = digitalRead( boutonPin );
    digitalWrite( ledPin, bouton );

// digitalWrite( ledPin, true );
// delay( 200 );
// digitalWrite( ledPin, false );
// delay( 200 );
}