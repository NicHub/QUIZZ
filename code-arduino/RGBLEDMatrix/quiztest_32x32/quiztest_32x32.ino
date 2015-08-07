/*


     ██████  ██    ██ ██ ███████ ███████     ██
    ██    ██ ██    ██ ██    ███     ███      ██
    ██    ██ ██    ██ ██   ███     ███       ██
    ██    ██ ██    ██ ██  ███     ███
     ██████   ██████  ██ ███████ ███████     ██
        ██


    MATRICE 32×32

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

#define MX 0
#define STR1( x ) #x
#define toStr( x ) STR1( x )
const char deviceIDStr[] = "MX" toStr( MX ) "\n";

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
RGBmatrixPanel matrix( A, B, C, D, CLK, LAT, OE, false );


uint16_t couleurM;
uint16_t couleurR;
uint16_t couleurV;
uint16_t couleurB;
uint16_t couleurJ;
uint16_t couleurN   = matrix.Color888(   0,    0,    0 );
uint16_t rPiCouleur = matrix.Color888( 160,    0,    0 );
uint16_t nombreActuel;
String serverCommand = "";
boolean serverTalked = false;
boolean globalForceRefresh = false;



void clearScreen()
{
    matrix.fillScreen( couleurN );
    globalForceRefresh = true;
}



void fillScreen()
{
    matrix.fillScreen( rPiCouleur );
    globalForceRefresh = true;
}



void afficheNombre( int nombre, uint16_t couleur, bool forceRefresh=false )
{
    static byte oldDigits[ 2 ] = { 10, 10 };
    byte newDigits[ 2 ] = { 10, 10 };
    int digit;
    int i;
    int nbDigits;
    int16_t posX;

    if( forceRefresh || globalForceRefresh )
    {
        globalForceRefresh = false;
        for( i=0; i<2; i++ )
        {
            oldDigits[ i ] = 10;
        }
    }

         if( nombre <    10 ) { nbDigits = 1; }
    else if( nombre <   100 ) { nbDigits = 2; }


    digit = nombre;
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



void changeCouleur( uint8_t cVal )
{
    // cVal min = 66
    // cVal max = 255
    // Se rappeler de brancher l’alim de la matrice !!!
    couleurM = matrix.Color888( cVal,    0, cVal, true );
    couleurR = matrix.Color888( cVal,    0,    0, true );
    couleurV = matrix.Color888(    0, cVal,    0, true );
    couleurB = matrix.Color888(    0,    0, cVal, true );
    couleurJ = matrix.Color888( cVal, cVal,    0, true );
    couleurN = matrix.Color888(    0,    0,    0, true );
    if     ( MX == 0 )
        rPiCouleur = couleurR;
    else if( MX == 1 )
        rPiCouleur = couleurM;
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
        char serverChar = ( char )Serial.read();
        if( serverChar == '\n' )
            serverTalked = true;
        else
            serverCommand += serverChar;
    }
}



void setup()
{
    serverCommand.reserve( 200 );
    Serial.begin( 115200 );
    Serial.print( deviceIDStr );
    matrix.begin();
    // changeCouleur( 160 ); // Ne fonctionne pas sur la matrice 32×32 et c’est bizarre...
    afficheNombre( 60, rPiCouleur, true );
}



void loop()
{
    // Traitement des commandes envoyées par le serveur via RS232.
    if( serverTalked )
    {
        int whatToDo = serverCommand.toInt();

        // Affichage d’un nombre.
        if( whatToDo >= 0 && whatToDo < 100 )
        {
            nombreActuel = whatToDo;
            afficheNombre( nombreActuel, rPiCouleur, false );
        }

        // Envoie l’ID de l’Arduino via RS232.
        else if( whatToDo == -1 )
        {
            Serial.print( deviceIDStr );
        }

        // Toutes les LEDs éteintes.
        else if( whatToDo == -2 )
        {
            clearScreen();
        }

        // Toutes les LEDs allumées.
        else if( whatToDo == -3 )
        {
            fillScreen();
        }

        // Modification de l’intensité lumineuse.
        else if( -255 <= whatToDo && whatToDo <= -66 )
        {
            // changeCouleur( -whatToDo );
            // afficheNombre( nombreActuel, rPiCouleur, true );
        }

        serverCommand = "";
        serverTalked = false;
    }
}


