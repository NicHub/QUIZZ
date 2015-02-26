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

#define cVal 66 // Min 66, Max 255 // Se rappeler de brancher l’alim de la matrice !!!
#define couleurR matrix.Color888( cVal,    0,    0, true )
#define couleurV matrix.Color888(    0, cVal,    0, true )
#define couleurB matrix.Color888(    0,    0, cVal, true )
#define couleurJ matrix.Color888( cVal, cVal,    0, true )
#define couleurN matrix.Color888(    0,    0,    0, true )




RGBmatrixPanel matrix( A, B, C, CLK, LAT, OE, false );


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete



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

#if MX == 1
const uint16_t rPiCouleur = couleurR;
#elif MX == 2
const uint16_t rPiCouleur = couleurV;
#elif MX == 3
const uint16_t rPiCouleur = couleurB;
#elif MX == 4
const uint16_t rPiCouleur = couleurJ;
#endif


void setup()
{
    matrix.begin();
    afficheNombre( 0, rPiCouleur );
    Serial.begin( 115200 );
    Serial.print( "Afficheur 16x32 - couleur " );
    Serial.print( MX );
    Serial.print( "\n" );
    inputString.reserve( 200 );     // reserve 200 bytes for the inputString
}





void loop()
{

    if( stringComplete )
    {
        afficheNombre( nombreActuel, rPiCouleur );
        inputString = "";
        stringComplete = false;
    }
    return;



/*
    afficheNombre( 7000, couleurR );
    afficheNombre( 7500, couleurV );
    afficheNombre( 7530, couleurB );
    afficheNombre( 7531, couleurJ );
    while(true){}
*/



    switch( i++ % 4 )
    {
        case 0:
            couleur = couleurR;
            break;
        case 1:
            couleur = couleurV;
            break;
        case 2:
            couleur = couleurB;
            break;
        case 3:
            couleur = couleurJ;
            break;
        default:
            couleur = couleurN;
    }

    for( int i=9000; i>=1000; i-=1000 )
    {
        { afficheNombre( i, couleur ); }
        delay( 200 );
    }
    for( int i=900; i>=100; i-=100 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }
    for( int i=90; i>=10; i-=10 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }
    for( int i=9; i>=0; i-=1 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }


    for( int i=0; i<10; i++ )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }
    for( int i=10; i<100; i+=10 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }
    for( int i=100; i<1000; i+=100 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
    }
    for( int i=1000; i<10000; i+=1000 )
    {
        afficheNombre( i, couleur );
        delay( 200 );
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
            nombreActuel = inputString.toInt();
            if( nombreActuel > 9999 )
                { nombreActuel = nombreActuel % 10000; }
        }
    }
}

