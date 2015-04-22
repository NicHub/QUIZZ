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

// LED 13 -> LED du board
#define L13_PIN    PORTB5
#define L13_PORT   PORTB
#define L13_INIT   bitSet  ( DDRB,     L13_PIN )
#define L13_READ   bitRead ( L13_PORT, L13_PIN )
#define L13_SET    bitSet  ( L13_PORT, L13_PIN )
#define L13_CLEAR  bitClear( L13_PORT, L13_PIN )
#define L13_TOGGLE L13_PORT ^= 1<<L13_PIN
// LED 1
#define L1_PIN    PORTB4
#define L1_PORT   PORTB
#define L1_INIT   bitSet  ( DDRB,    L1_PIN )
#define L1_READ   bitRead ( L1_PORT, L1_PIN )
#define L1_SET    bitSet  ( L1_PORT, L1_PIN )
#define L1_CLEAR  bitClear( L1_PORT, L1_PIN )
#define L1_TOGGLE L1_PORT ^= 1<<L1_PIN
// LED 2
#define L2_PIN    PORTB3
#define L2_PORT   PORTB
#define L2_INIT   bitSet  ( DDRB,    L2_PIN )
#define L2_READ   bitRead ( L2_PORT, L2_PIN )
#define L2_SET    bitSet  ( L2_PORT, L2_PIN )
#define L2_CLEAR  bitClear( L2_PORT, L2_PIN )
#define L2_TOGGLE L2_PORT ^= 1<<L2_PIN
// LED 3
#define L3_PIN    PORTB2
#define L3_PORT   PORTB
#define L3_INIT   bitSet  ( DDRB,    L3_PIN )
#define L3_READ   bitRead ( L3_PORT, L3_PIN )
#define L3_SET    bitSet  ( L3_PORT, L3_PIN )
#define L3_CLEAR  bitClear( L3_PORT, L3_PIN )
#define L3_TOGGLE L3_PORT ^= 1<<L3_PIN
// LED 4
#define L4_PIN    PORTB1
#define L4_PORT   PORTB
#define L4_INIT   bitSet  ( DDRB,    L4_PIN )
#define L4_READ   bitRead ( L4_PORT, L4_PIN )
#define L4_SET    bitSet  ( L4_PORT, L4_PIN )
#define L4_CLEAR  bitClear( L4_PORT, L4_PIN )
#define L4_TOGGLE L4_PORT ^= 1<<L4_PIN



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

    L1_INIT;
    L2_INIT;
    L3_INIT;
    L4_INIT;
    L13_INIT;
    for(int i=0; i<10; i++)
    {
        L1_TOGGLE;
        L2_TOGGLE;
        L3_TOGGLE;
        L4_TOGGLE;
        L13_TOGGLE;
        _delay_ms( 400 );
    }

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
            L13_SET;
        }
        else
        {
            L13_CLEAR;
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

