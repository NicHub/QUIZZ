
// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13

int incomingByte = 0;

void setup()
{
    //Serial.begin( 9600 );
    Serial.begin( 115200 );
    Serial.print( "\n## TX ##" );
    bitSet( DDRB, bL13 );
    for( int i=0; i<10; i++ )
    {
        L13Toggle;
        delay( 100 );
    }
}

void loop()
{
    Serial.print( "\nTX millis = " );
    Serial.print( millis() );
    delay( 100 );
}


/*
PRISE USB + ALIM

 tty.usbmodem14241
 tty.usbmodem14231
 tty.usbmodem14221
tty.usbmodem142141
tty.usbmodem142131
tty.usbmodem142121
tty.usbmodem142111


*/