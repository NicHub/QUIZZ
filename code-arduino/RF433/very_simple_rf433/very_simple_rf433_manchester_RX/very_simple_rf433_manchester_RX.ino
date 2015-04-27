
#include <Manchester.h>

const uint8_t RX_PIN = 2;
const uint8_t TX_PIN = 3;
const unsigned long dT = 1000;
uint16_t messages[ 4 ];
const uint16_t TRIGGER_MSG = 1;
void setup()
{
    man.setupTransmit( TX_PIN, MAN_600 );
    man.setupReceive( RX_PIN, MAN_600 );
    man.beginReceive();
    pinMode(  9, OUTPUT );
    pinMode( 10, OUTPUT );
    pinMode( 11, OUTPUT );
    pinMode( 12, OUTPUT );
    pinMode( 13, OUTPUT );
}

void loop()
{
    man.transmit( ( uint16_t )TRIGGER_MSG );
	_delay_ms( 100 );
    for( int i=0; i<4; i++ )
    {
        if( man.receiveComplete() )
        {
            messages[ i ] = man.getMessage();
            man.beginReceive();

                if( i == 0 )
            	{ digitalWrite( 9, LOW  ); digitalWrite( 10, LOW  ); digitalWrite( 11, LOW  ); digitalWrite( 12, HIGH ); digitalWrite( 13, LOW  ); }
            else if( i == 1 )
            	{ digitalWrite( 9, LOW  ); digitalWrite( 10, LOW  ); digitalWrite( 11, HIGH ); digitalWrite( 12, LOW  ); digitalWrite( 13, LOW  ); }
            else if( i == 2 )
            	{ digitalWrite( 9, LOW  ); digitalWrite( 10, HIGH ); digitalWrite( 11, LOW  ); digitalWrite( 12, LOW  ); digitalWrite( 13, LOW  ); }
            else
            	{ digitalWrite( 9, HIGH ); digitalWrite( 10, LOW  ); digitalWrite( 11, LOW  ); digitalWrite( 12, LOW  ); digitalWrite( 13, LOW  ); }
        }
	    _delay_ms( 200 );
    }
}

