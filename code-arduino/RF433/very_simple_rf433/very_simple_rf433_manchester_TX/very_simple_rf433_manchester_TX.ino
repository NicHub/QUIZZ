
#include <Manchester.h>

const uint8_t RX_PIN = 2;
const uint8_t TX_PIN = 3;
uint16_t messages;
const uint16_t TRIGGER_MSG = 1;

// À modifier pour chaque Arduino
#define TX_ID 1
#if TX_ID == 1
const unsigned long dT = 0;
#elif TX_ID == 2
const unsigned long dT = 200;
#elif TX_ID == 3
const unsigned long dT = 400;
#elif TX_ID == 4
const unsigned long dT = 600;
#endif


void setup()
{
    man.setupTransmit( TX_PIN, MAN_600 );
    man.setupReceive( RX_PIN, MAN_600 );
    man.beginReceive();
    pinMode( 13, OUTPUT );
}

void loop()
{
    if( man.receiveComplete() )
    {
        messages = man.getMessage();
        if( messages == TRIGGER_MSG )
        {
            _delay_ms( dT );
            man.transmit( ( uint16_t )micros() );
            digitalWrite( 13, HIGH );
            _delay_ms( 10 );
            digitalWrite( 13, LOW );
        }
        man.beginReceive();
    }
}
