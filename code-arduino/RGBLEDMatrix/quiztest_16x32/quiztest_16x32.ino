/*

    MATRICE 16×32

    Instructions de câblage :
    https://learn.adafruit.com/32x16-32x32-rgb-led-matrix?view=all

    Librairie de fonctions graphiques générales :
    https://github.com/adafruit/Adafruit-GFX-Library

    Libraire de fonctions spécifiques aux matrices :
    https://github.com/adafruit/RGB-matrix-Panel

    Librairie de définition des chiffres :
    chiffres.h

    Nicolas Jeanmonod, David Le Neillon, 2015

 */

#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>
#include "chiffres.h"

#define CLK  8
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
uint16_t rPiCouleur;
uint16_t couleur;
// uint16_t i;
uint16_t nombreActuel;
String inputString = "";
boolean stringComplete = false;

#define MX 1
#define STR1( x ) #x
#define toStr( x ) STR1( x )
const char MX_ID_CHAR[] = "MX" toStr( MX ) "\n";



void clearScreen()
{
    matrix.fillScreen( matrix.Color333( 0, 0, 0 ) );
}



void afficheNombre( int nombre, uint16_t couleur, bool forceRefresh = false )
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

         if( nombre <    10 ) { nbDigits = 1; }
    else if( nombre <   100 ) { nbDigits = 2; }
    else if( nombre <  1000 ) { nbDigits = 3; }
    else if( nombre < 10000 ) { nbDigits = 4; }
    digit = nombre;
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



void changeCouleur( uint8_t cVal )
{
    // cVal min = 66
    // cVal max = 255
    // Se rappeler de brancher l’alim de la matrice !!!
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



void setup()
{
    matrix.begin();
    changeCouleur( 160 );
    afficheNombre( MX, rPiCouleur );
    Serial.begin( 115200 );
    Serial.print( MX_ID_CHAR );
    inputString.reserve( 200 );
}



void loop()
{
    if( stringComplete )
    {
        int cmd = inputString.toInt();

        // Affichage d’un nombre.
        if( cmd >= 0 && cmd < 10000 )
        {
            nombreActuel = cmd;
            afficheNombre( nombreActuel, rPiCouleur );
        }

        // Envoie l’ID de la matrice par le port série.
        else if( cmd == -1 )
        {
            Serial.print( MX_ID_CHAR );
        }

        // Clear Screen.
        else if( cmd == -2 )
        {
            clearScreen();
        }

        // Modification de l’intensité lumineuse.
        else if( -255 <= cmd && cmd <= -66 )
        {
            changeCouleur( -cmd );
            afficheNombre( nombreActuel, rPiCouleur, true );
            Serial.print( rPiCouleur ); Serial.print( "\n" );
        }

        inputString = "";
        stringComplete = false;
    }
}


