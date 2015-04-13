/*

RX
modèle jy-js03
http://fr.aliexpress.com/item/1pcs-433Mhz-RF-transmitter-and-receiver-kit-for-Arduino-project-FREE-SHIPPING-3235/1308017760.html?recommendVersion=1
À 600 bit/s, le dt émission-réception est compris entre 90 et 150 ms, et vaut typiquement 100 ms. Mesure faite à 10 cm de distance.

S bit/s     dt ms
    600       100
   1200        47

*/

#include <Manchester.h>
#include <avr/io.h>
#include <util/delay.h>



// PORTB5 -> LED du board Diduino – Arduino
#define bL13 PORTB5
#define      L13Read   bitRead (  PINB, bL13 )
#define      L13Set    bitSet  ( PORTB, bL13 )
#define      L13Clear  bitClear( PORTB, bL13 )
#define      L13Toggle PORTB ^= 1<<bL13
// PORTB4 -> LED 0
#define bL0  PORTB4
#define      L0Read    bitRead (  PINB, bL0 )
#define      L0Set     bitSet  ( PORTB, bL0 )
#define      L0Clear   bitClear( PORTB, bL0 )
#define      L0Toggle  PORTB ^= 1<<bL0
// PORTB3 -> LED 1
#define bL1  PORTB3
#define      L1Read    bitRead (  PINB, bL1 )
#define      L1Set     bitSet  ( PORTB, bL1 )
#define      L1Clear   bitClear( PORTB, bL1 )
#define      L1Toggle  PORTB ^= 1<<bL1
// PORTB2 -> LED 2
#define bL2  PORTB2
#define      L2Read    bitRead (  PINB, bL2 )
#define      L2Set     bitSet  ( PORTB, bL2 )
#define      L2Clear   bitClear( PORTB, bL2 )
#define      L2Toggle  PORTB ^= 1<<bL2
// PORTB1 -> LED 0
#define bL3  PORTB1
#define      L3Read    bitRead (  PINB, bL3 )
#define      L3Set     bitSet  ( PORTB, bL3 )
#define      L3Clear   bitClear( PORTB, bL3 )
#define      L3Toggle  PORTB ^= 1<<bL3
// PORTC5 -> BUZZER
#define bBuzzer  PORTC0
#define      BuzzerRead    bitRead (  PINC, bBuzzer )
#define      BuzzerSet     bitSet  ( PORTC, bBuzzer )
#define      BuzzerClear   bitClear( PORTC, bBuzzer )
#define      BuzzerToggle  PORTC ^= 1<<bBuzzer
// PORTD4 -> Bouton du TX (pour mesurer délai de transmission)
#define bBouton    PORTD4
#define boutonRead bitRead( PIND, bBouton )


#define RXDATA1    6
#define RXDATA2    5
#define RXGND PORTD7
#define RXVCC PORTD4

// RXDATA1
#define      RXDATARead    bitRead (  PIND, RXDATA1 )


#define codeBouton1 20101
#define codeBouton2 20202
#define codeBouton3 20303
#define codeBouton4 20404





uint16_t msg;
uint16_t prev_msg;
long prev_millis;



void setup()
{
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    DDRD = 0b11111111;

    bitClear( DDRD, RXDATA1 );
    bitClear( DDRD, RXDATA2 );

    bitClear( PORTD, RXGND );
    bitSet( PORTD, RXVCC );

    man.setupReceive( RXDATA1, MAN_600 );
    man.beginReceive();

    Serial.begin( 9600 );
    Serial.print( "\n\n# RX READY #" );
}


long m0;
long m1;

const byte arraySize = 1;
long arrayT[ arraySize ];
byte arrayV[ arraySize ];
byte arrayI = 0;

void loop()
{
    if( man.receiveComplete() )
    {
        L13Toggle;
        msg = man.getMessage();
        // if( msg != prev_msg )
        // if( true )
        if( false )
        {
            prev_msg = msg;
            m0 = millis();
            arrayT[ arrayI ] = m0 - m1;
            m1 = m0;
            arrayV[ arrayI ] = msg;
            arrayI++;
            if( arrayI == arraySize )
            {
                arrayI = 0;
                for( int i=0; i<arraySize; i++ )
                {
                    Serial.print( "\n" );
                         if( arrayT[ i ] < 10     ) { Serial.print( "    " ); }
                    else if( arrayT[ i ] < 100    ) { Serial.print( "   " ); }
                    else if( arrayT[ i ] < 1000   ) { Serial.print( "  " ); }
                    else if( arrayT[ i ] < 10000  ) { Serial.print( " " ); }
                    Serial.print( arrayT[ i ] );

                    if( arrayV[ i ] == 1 ){ Serial.print( " " );    }
                    if( arrayV[ i ] == 2 ){ Serial.print( "  " );   }
                    if( arrayV[ i ] == 3 ){ Serial.print( "   " );  }
                    if( arrayV[ i ] == 4 ){ Serial.print( "    " ); }
                    Serial.print( arrayV[ i ] );
                }
                Serial.print( "\n" );
            }
        }
        else
        {
            Serial.print( "\n" ); Serial.print( millis() ); Serial.print( " " ); Serial.print( msg );
        }
        _delay_ms( 1000 );
        man.beginReceive();
    }
    else
    {
        if( RXDATARead )
        {
            L13Set;
        }
        else
        {
            L13Clear;
        }
        // m1 = millis() / 1000;
        // if( m1 > m0 )
        // {
        //     Serial.print( "\n" ); Serial.print( m1 );
        //     Serial.print( "\nArrayI = " ); Serial.print( arrayI );
        //     m0 = m1;
        // }
    }
}

