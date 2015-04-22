// testshapes demo for Adafruit RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix:
// http://www.adafruit.com/products/420

// Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon
// for Adafruit Industries.
// BSD license, all text above must be included in any redistribution.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "chiffres.h"

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// If your matrix has the DOUBLE HEADER input, use:
//#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
//#define LAT 9
//#define OE  10
//#define A   A3
//#define B   A2
//#define C   A1
//#define D   A0

#define cVal 66 // Min 66, Max 255 // Se rappeler de brancher l’alim de la matrice !!!
#define couleurR matrix.Color888( cVal,    0,    0, true )
#define couleurV matrix.Color888(    0, cVal,    0, true )
#define couleurB matrix.Color888(    0,    0, cVal, true )
#define couleurJ matrix.Color888( cVal, cVal,    0, true )
#define couleurN matrix.Color888(    0,    0,    0, true )


RGBmatrixPanel matrix( A, B, C, D, CLK, LAT, OE, false );
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
uint16_t couleur;
uint16_t i;
uint16_t nombreActuel;

const uint16_t rPiCouleur = couleurR;





void clearScreen()
{
    matrix.fillScreen( matrix.Color333( 0, 0, 0 ) );
}



void afficheNombre( int nombre, uint16_t couleur )
{
    static byte oldDigits[ 2 ] = { 10, 10 };
    byte newDigits[ 2 ] = { 10, 10 };
    int digit;
    int i;
    int nbDigits;
    int16_t posX;

    digit = nombre;

         if( nombre <    10 ) { nbDigits = 1; }
    else if( nombre <   100 ) { nbDigits = 2; }
    for( i=0; i<nbDigits; i++ )
    {
        newDigits[ i ] = digit % 10;
        digit = digit / 10;
    }

    for( i=0; i<2; i++ )
    {
        if( newDigits[ i ] != oldDigits[ i ] )
        {
            posX = 16-i*16;
            matrix.drawBitmap( posX, 0, chiffres_16x32[ oldDigits[ i ] ], 16, 32, couleurN );
            matrix.drawBitmap( posX, 0, chiffres_16x32[ newDigits[ i ] ], 16, 32, couleur  );
        }
        oldDigits[ i ] = newDigits[ i ];
    }
}





void setup()
{
    // DDRB = 0b00000000; PORTB = 0b11111111;
    // DDRC = 0b00000000; PORTC = 0b11111111;
    // DDRD = 0b00000000; PORTD = 0b11111111;

    Serial.begin( 115200 );
//    Serial.print( "Afficheur 32x32 - couleur " ); Serial.print( 0 ); Serial.print( "\n" );
    matrix.begin();
    afficheNombre( 0, couleurR );
//    toutesLesLEDs( couleurB );
    inputString.reserve( 200 );     // reserve 200 bytes for the inputString
}



void loop()
{

    if( stringComplete )
    {
        int cmd = inputString.toInt();
        if( cmd >= 0 && cmd < 100 )
        {
            nombreActuel = cmd;
            afficheNombre( nombreActuel, rPiCouleur );
        }
        else
        {
            if( cmd == -1 )
                { Serial.print( "0" ); Serial.print( "\n" ); }
        }

        inputString = "";
        stringComplete = false;
    }


}



void serialEvent()
{
    while( Serial.available() )
    {
        char inChar = ( char )Serial.read();
        inputString += inChar;
        if( inChar == '\n' )
        {
            stringComplete = true;
        }
    }
}




void compteur( byte countMax, uint16_t couleur )
{
    static byte i;
    if( i > countMax )
        i = 0;
    afficheNombre( i++, couleur );
    delay( 500 );
}


void toutesLesLEDs( uint16_t couleur )
{
    matrix.drawBitmap( 16, 0, chiffres_16x32[ 11 ], 16, 32, couleur  );
    matrix.drawBitmap(  0, 0, chiffres_16x32[ 11 ], 16, 32, couleur  );
}


