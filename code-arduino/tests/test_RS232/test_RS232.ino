#include <Streaming.h>


void setup()
{
	Serial.begin( 115200 );
}
int lettera = 'A';
void loop()
{

  int i = 1234;
  char buffer [33];
  // printf ("Enter a number: ");
  // scanf ("%d",&i);
  itoa (i,buffer,10);
  // Serial.print( bsuffer );
  // Serial.print( i );
  Serial.print( "1234" );
  // printf ("decimal: %s\n",buffer);
  // itoa (i,buffer,16);
  // printf ("hexadecimal: %s\n",buffer);
  // itoa (i,buffer,2);
  // printf ("binary: %s\n",buffer);
  // return 0;

	delay( 1000 );
}