#include <Wire.h>
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

int number = 0;
int state = 0;
const int ledPin    = 13;

#define SLAVE_ADDRESS 0x04

#define CLK  8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE   9
#define A   A0
#define B   A1
#define C   A2
#define couleurR matrix.Color333( 255,   0,   0 )
#define couleurV matrix.Color333(   0, 255,   0 )
#define couleurB matrix.Color333(   0,   0, 255 )
#define couleurJ matrix.Color333( 255, 255,   0 )
#define couleurN matrix.Color333(   0,   0,   0 )
RGBmatrixPanel matrix( A, B, C, CLK, LAT, OE, false );
const unsigned char PROGMEM chiffres[ 11 ][ 16 ] =
{
    { 0x00,0x00,0x3C,0x7E,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x3C,0x00,0x00 },  // Chiffre 0
    { 0x00,0x00,0x18,0x38,0x78,0x58,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x7E,0x00,0x00 },  // Chiffre 1
    { 0x00,0x00,0x3C,0x7E,0x66,0x06,0x06,0x3E,0x7C,0x60,0x60,0x60,0x7E,0x7E,0x00,0x00 },  // Chiffre 2
    { 0x00,0x00,0x3C,0x7E,0x66,0x06,0x06,0x3C,0x3C,0x06,0x06,0x66,0x7E,0x3C,0x00,0x00 },  // Chiffre 3
    { 0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x7E,0x3E,0x06,0x06,0x06,0x06,0x06,0x00,0x00 },  // Chiffre 4
    { 0x00,0x00,0x7E,0x7E,0x60,0x60,0x60,0x7C,0x7E,0x06,0x06,0x06,0x7E,0x7C,0x00,0x00 },  // Chiffre 5
    { 0x00,0x00,0x3C,0x7E,0x66,0x60,0x60,0x7C,0x7E,0x66,0x66,0x66,0x7E,0x3C,0x00,0x00 },  // Chiffre 6
    { 0x00,0x00,0x7E,0x7E,0x06,0x06,0x06,0x0C,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00 },  // Chiffre 7
    { 0x00,0x00,0x3C,0x7E,0x66,0x66,0x66,0x3C,0x3C,0x66,0x66,0x66,0x7E,0x3C,0x00,0x00 },  // Chiffre 8
    { 0x00,0x00,0x3C,0x7E,0x66,0x66,0x66,0x7E,0x3E,0x06,0x06,0x66,0x7E,0x3C,0x00,0x00 },  // Chiffre 9
    { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }   // Chiffre vide
};


void clearScreen()
{
    matrix.fillScreen( matrix.Color333( 0, 0, 0 ) );
}



void afficheNombre( int nombre, uint16_t couleur )
{
    static byte oldDigits[ 4 ] = { 10, 10, 10, 10 };
    byte newDigits[ 4 ] = { 10, 10, 10, 10 };
    int digit;
    int i;
    int nbDigits;
    int16_t posX;

    digit = nombre;

         if( nombre <    10 ) { nbDigits = 1; }
    else if( nombre <   100 ) { nbDigits = 2; }
    else if( nombre <  1000 ) { nbDigits = 3; }
    else if( nombre < 10000 ) { nbDigits = 4; }
    for( i=0; i<nbDigits; i++ )
    {
        newDigits[ i ] = digit % 10;
        digit = digit / 10;
    }

    for( i=0; i<4; i++ )
    {
        if( newDigits[ i ] != oldDigits[ i ] )
        {
            posX = 24-i*8;
            matrix.drawBitmap( posX, 0, chiffres[ oldDigits[ i ] ], 8, 16, couleurN );
            matrix.drawBitmap( posX, 0, chiffres[ newDigits[ i ] ], 8, 16, couleur  );
        }
        oldDigits[ i ] = newDigits[ i ];
    }
}



// callback for received data
void receiveData( int byteCount )
{
    while( Wire.available() )
    {
        number = Wire.read();
    }
    afficheNombre( number, couleurV );

}

// callback for sending data
void sendData()
{
    Wire.write( number );
}

void multiBlink( int number )
{
    for( int i=0; i<number; i++ )
    {
        digitalWrite( ledPin, true );
        delay( 50 );
        digitalWrite( ledPin, false );
        delay( 50 );
    }
}



void setup()
{
    // initialize i2c as slave
    Wire.begin( SLAVE_ADDRESS );

    // define callbacks for i2c communication
    Wire.onReceive( receiveData );
    Wire.onRequest( sendData );

    matrix.begin();
    afficheNombre( 0, couleurV );

    pinMode( ledPin, OUTPUT );
    multiBlink( 20 );


}

void loop()
{
    if( number )
    {
        multiBlink( 2 );
        number = 0;
    }
}