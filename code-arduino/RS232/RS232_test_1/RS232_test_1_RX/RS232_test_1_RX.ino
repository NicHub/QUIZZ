
// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13
// PORTD7 -> LED 0
#define bL0  PORTD7
#define      L0Read    bitRead (  PIND,      bL0 )
#define      L0Set     bitSet  ( PORTD,      bL0 )
#define      L0Clear   bitClear( PORTD,      bL0 )
#define      L0Toggle            PORTD ^= 1<<bL0

int incomingByte = 0;

void setup()
{
    Serial.begin( 9600 );
    bitSet( DDRB, bL13 );
    for( int i=0; i<10; i++ )
    {
        L13Toggle;
        L0Toggle;
        delay( 100 );
    }
}

void loop()
{
    if( Serial.available() > 0 )
    {
        incomingByte = Serial.read();
        Serial.print( "TX reception " );
        Serial.println( incomingByte, DEC );
        L0Toggle;
        delay( 100 );
    }
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