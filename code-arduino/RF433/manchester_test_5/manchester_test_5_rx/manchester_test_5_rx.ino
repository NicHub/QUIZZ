/*

RX

*/



// PORTD2 -> RX1
#define bRX1  PORTD2
#define      RX1Read    bitRead (  PIND,        bRX1 )
#define      RX1Set     bitSet  ( PORTD,        bRX1 )
#define      RX1Clear   bitClear( PORTD,        bRX1 )
#define      RX1Toggle          ( PORTD ^= 1 << bRX1 )

// PORTD3 -> RX2
#define bRX2  PORTD3
#define      RX2Read    bitRead (  PIND,        bRX2 )
#define      RX2Set     bitSet  ( PORTD,        bRX2 )
#define      RX2Clear   bitClear( PORTD,        bRX2 )
#define      RX2Toggle          ( PORTD ^= 1 << bRX2 )


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
#define RXPin2    3

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

bool prevRX1Read;

void setup()
{
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    L13Set;
    DDRD  = 0b11111111;
    bitClear( DDRD, bRX1 );
    bitClear( DDRD, bRX2 );
    bitClear( DDRD, bBouton );
    prevRX1Read = RX1Read;
    Serial.begin( 9600 );
}

unsigned long times[ 10 ];
byte nTimes;
unsigned long curTime;
unsigned long prevTime;
unsigned long dT;
void loop()
{

    if( RX1Read )
    {
        if( !prevRX1Read )
        {
            curTime = micros();
            dT = curTime - prevTime;
            prevTime = curTime;
            // if( dT > 34295 & dT < 34363 )
            if( true )
            {
                L0Toggle;
                Serial.print( dT ); Serial.print( "\n" );
            }
        }
    }



}