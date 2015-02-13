
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK  8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE   9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix( A, B, C, CLK, LAT, OE, false );
uint16_t couleur;


void setup()
{
    Serial.begin( 9600 );
    matrix.begin();
    matrix.fillScreen( 0 );

    // for( int iCol=0; iCol<511; iCol++ )
    // {
    //     couleur = matrix.Color888( iCol, 0, 0, true );
    //     Serial.print( "\niCol = " ); Serial.print( iCol );
    //     Serial.print( "    couleur = " ); Serial.print( couleur );
    //     Serial.print( "    couleur = " ); Serial.print( couleur, BIN );
    //     matrix.fillScreen( couleur );
    // }

    uint16_t iCol;
    Serial.print( "\n\n\n ###### START #####\n " );
    for(int iCol=0; iCol<16; iCol++)
    {
        couleur = 1 << iCol;
        couleur = iCol;
        Serial.print(   "\ncouleur= " ); Serial.print( couleur );
        Serial.print( "    couleur= " ); Serial.print( couleur, BIN );
        matrix.fillScreen( couleur );
        delay( 1000 );
    }
    Serial.print( "\n\n\n ###### STOP #####\n " );
    matrix.fillScreen( 0 );
}


void loop()
{

}