/*
  This is a minimal sketch without using the library at all but only works for
  the 10 pole dip switch sockets. It saves a lot of memory and thus might be
  very useful to use with ATTinys :)

  http://code.google.com/p/rc-switch/
*/


// PORTB2 -> LED du board Diduino – Arduino
#define bRCL1 PORTB2
#define      RCL1Read   bitRead (  PINB, bRCL1 )
#define      RCL1Set    bitSet  ( PORTB, bRCL1 )
#define      RCL1Clear  bitClear( PORTB, bRCL1 )
#define      RCL1Toggle PORTB ^= 1<<bRCL1



int RCLpin1 = 10;
int RCLpin2 = 11;
long lastMillis;
const int timeArraySize = 50;
long timeArray1111[ timeArraySize ] = { 350,1050,1050,350,350,1050,350,1050,350,1050,1050,350,350,1050,1050,350,350,1050,1050,350,350,1050,350,1050,350,1050,1050,350,350,1050,350,1050,350,1050,1050,350,350,1050,350,1050,350,1050,350,1050,350,1050,350,1050,350,10850 };
//long timeArray1111[ timeArraySize ] = { 1,150,150,1,1,150,1,1050,1,1050,1050,1,1,1050,1050,1,1,1050,1050,1,1,1050,1,1050,1,1050,1050,1,1,1050,1,1050,1,1050,1050,1,1,1050,1,1050,1,1050,1,1050,1,1050,350,1050,350,10850 };

void setup() {
    pinMode( RCLpin1, OUTPUT );
    pinMode( RCLpin2, OUTPUT );
    Serial.begin( 9600 );
    Serial.print( "###\n" );
    RCLswitch(RCLpin1, 2222);
}

bool state = 0;
void loop()
{
    return;

    for( int i=0; i<timeArraySize; i++ )
    {
        state = !state;
        digitalWrite( RCLpin1, state );
        delayMicroseconds( timeArray1111[ i ] );
    }
    return;



    RCLswitch(RCLpin1, 1111);  // DIPs an Steckdose: 0100010000 An:01
    delay(2);
    Serial.print( "\n 1111 : " ); Serial.print( millis() - lastMillis ); lastMillis = millis();

    RCLswitch(RCLpin2, 2222);  // DIPs an Steckdose: 0100010000 An:01
    delay(2);
    Serial.print( "\n 2222 : " ); Serial.print( millis() - lastMillis ); lastMillis = millis();

    // RCLswitch(0b010001000010);  // DIPs an Steckdose: 0100010000 Aus:10
    // delay(2000);
}

void RCLswitch(int RCLpin, uint16_t code)
{
    for( int nRepeat=0; nRepeat<6; nRepeat++ )
    {
        for( int i=4; i<16; i++ )
        {
            RCLtransmit( RCLpin, 1, 3 );
            if( ( ( code << ( i-4 ) ) & 2048 ) > 0 )
            {
                RCLtransmit( RCLpin, 1, 3 );
            }
            else
            {
                RCLtransmit( RCLpin, 3, 1 );
            }
        }
        RCLtransmit( RCLpin, 1, 31 );
    }
}

void RCLtransmit( int RCLpin, int nHighPulses, int nLowPulses )
{
    digitalWrite( RCLpin, HIGH );
    delayMicroseconds( 350 * nHighPulses );
    Serial.print( "\n 1111 HIGH: " ); Serial.print( 350 * nHighPulses );


    digitalWrite( RCLpin, LOW );
    delayMicroseconds( 350 * nLowPulses );
    Serial.print( "\n 1111 LOW: " ); Serial.print( 350 * nLowPulses );
}

