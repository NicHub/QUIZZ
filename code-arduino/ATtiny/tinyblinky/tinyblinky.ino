/*
    tinyblinky.ino
    Programme pour tester la programmation en mode ISP d’un ATtiny25V
    Fait clignoter une LED sur PB4, pin 3
*/

#include <avr/io.h>
#define LedPin PORTB4
#define LedToggle PORTB ^= ( 1<<LedPin )
#define delay1 250
#define delay2 5000

void wait( int delay_ms )
{
    for( volatile int i=0; i<delay_ms; i++ )
    {
        for( volatile int j=0; j<50; j++ ) {}
    }
}

int main()
{
    DDRB |= ( 1<<LedPin );
    while( true )
    {
        LedToggle;  wait( delay1 );
        LedToggle;  wait( delay2 );
    }
}

