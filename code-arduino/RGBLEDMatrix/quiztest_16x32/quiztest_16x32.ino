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

#define CLK  8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE   9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix( A, B, C, CLK, LAT, OE, false );

uint16_t couleurR;
uint16_t couleurV;
uint16_t couleurB;
uint16_t couleurJ;
uint16_t couleurN;


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete



void clearScreen()
{
    matrix.fillScreen( matrix.Color333( 0, 0, 0 ) );
}



void afficheNombre( int nombre, uint16_t couleur, bool forceRefresh )
{
    static byte oldDigits[ 4 ] = { 10, 10, 10, 10 };
    byte newDigits[ 4 ] = { 10, 10, 10, 10 };
    int digit;
    int i;
    int nbDigits;
    int16_t posX;

    if( forceRefresh )
    {
        for( i=0; i<4; i++ )
        {
            oldDigits[ i ] = 10;
        }
    }

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
            matrix.drawBitmap( posX, 0, chiffres_8x16[ oldDigits[ i ] ], 8, 16, couleurN );
            matrix.drawBitmap( posX, 0, chiffres_8x16[ newDigits[ i ] ], 8, 16, couleur  );
        }
        oldDigits[ i ] = newDigits[ i ];
    }
}




uint16_t couleur;
uint16_t i;
uint16_t nombreActuel;


#define MX 1
uint16_t rPiCouleur;



void setup()
{
    matrix.begin();
    changeCouleur( 160 );
    afficheNombre( MX, rPiCouleur, false );
    Serial.begin( 115200 );
    Serial.print( "MX" ); Serial.print( MX ); Serial.print( "\n" );
    inputString.reserve( 200 );     // reserve 200 bytes for the inputString
}





void loop()
{

    if( stringComplete )
    {
        int cmd = inputString.toInt();
        if( cmd >= 0 && cmd < 10000 )
        {
            nombreActuel = cmd;
            afficheNombre( nombreActuel, rPiCouleur, false );
        }
        else
        {
            // cmd = -1 ⇒ ID de la matrice
            if( cmd == -1 )
            { Serial.print( "MX" );Serial.print( MX ); Serial.print( "\n" ); }
            // -255 <= cmd <= -66 ⇒ intensité lumineuse
            if( -255 <= cmd && cmd <= -66 )
            {
                changeCouleur( -cmd );
                afficheNombre( nombreActuel, rPiCouleur, true );
                Serial.print( rPiCouleur ); Serial.print( "\n" );
            }
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


void changeCouleur( uint8_t cVal )
{
    // cVal ⇒ Min 66, Max 255 // Se rappeler de brancher l’alim de la matrice !!!
    couleurR = matrix.Color888( cVal,    0,    0, true );
    couleurV = matrix.Color888(    0, cVal,    0, true );
    couleurB = matrix.Color888(    0,    0, cVal, true );
    couleurJ = matrix.Color888( cVal, cVal,    0, true );
    couleurN = matrix.Color888(    0,    0,    0, true );
    if     ( MX == 1 )
        rPiCouleur = couleurR;
    else if( MX == 2 )
        rPiCouleur = couleurB;
    else if( MX == 3 )
        rPiCouleur = couleurV;
    else if( MX == 4 )
        rPiCouleur = couleurJ;

}

