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


#define RXPin1    2
#define bRX1 PORTD2
#define RXPin2    3
#define bRX2 PORTD3

#define codeBouton1 20101
#define codeBouton2 20202
#define codeBouton3 20303
#define codeBouton4 20404




#define debug true

uint16_t msg;

#if debug
    long t1;
    long t2;
    long prev_t2;
#endif

void wait( int delayMs )
{
    for( volatile int i=0; i<delayMs; i++ )
    {
        for( volatile int j=0; j<450; j++ ) {}
    }
}

void beep( int dt )
{
    for( int j=0; j<300/dt; j++ )
    {
        BuzzerToggle;
        wait( dt );
    }
}

void setup()
{
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    L13Set;
    DDRD  = 0b11111111;
    bitClear( DDRD, bRX1 );
    bitClear( DDRD, bRX2 );
    bitClear( DDRD, bBouton );

    man.setupReceive( RXPin1, MAN_600 );
    man.beginReceive();

    #if debug
        Serial.begin( 9600 );
        Serial.print( "\n\n# RX READY #" );
    #endif
}

void loop()
{

    if( man.receiveComplete() )
    {
        #if debug
            t2 = millis();
            Serial.print( "\nt2 = " ); Serial.print( t2 );
            Serial.print( "\ndt = " ); Serial.print( t2 - t1 );
        #endif

        L13Set;
        msg = man.getMessage();
             if( msg == codeBouton1 ){ L0Set;   L1Clear; L2Clear; L3Clear; beep(  5 ); }
        else if( msg == codeBouton2 ){ L0Clear; L1Set;   L2Clear; L3Clear; beep( 10 ); }
        else if( msg == codeBouton3 ){ L0Clear; L1Clear; L2Set;   L3Clear; beep( 15 ); }
        else if( msg == codeBouton4 ){ L0Clear; L1Clear; L2Clear; L3Set;   beep( 20 ); }
        else                         { L0Set;   L1Set;   L2Set;   L3Set;   beep( 5 ); wait( 2 ); beep( 5 ); }
        #if debug
            Serial.print( "\nmsg = " ); Serial.print( msg );
        #endif
        wait( 2000 );
        man.beginReceive();
    }
    else
    {
        L13Clear;
        L0Clear;   L1Clear;   L2Clear;   L3Clear;
    }
}

