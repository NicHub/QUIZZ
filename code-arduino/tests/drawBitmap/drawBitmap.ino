// testshapes demo for RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 16x32 RGB LED matrix.

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

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
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

const int cVal = 66;
#define couleurR matrix.Color888( cVal,    0,    0, true )
#define couleurV matrix.Color888(    0, cVal,    0, true )
#define couleurB matrix.Color888(    0,    0, cVal, true )
#define couleurJ matrix.Color888( cVal, cVal,    0, true )
#define couleurN matrix.Color888(    0,    0,    0, true )



const uint8_t PROGMEM test_bmp[] =
{ 0b11111111,0b01111111,0b01111111,0b01111111 };



void setup()
{
	matrix.begin();
	matrix.drawBitmap( 0, 0, test_bmp, 8, 4, couleurR );

	matrix.drawBitmap( 16, 0, test_bmp, 3, 8, couleurR );

	matrix.drawBitmap( 16, 16, test_bmp, 10, 4, couleurR );
}

void loop()
{

}