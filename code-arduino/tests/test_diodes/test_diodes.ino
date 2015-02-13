
/*
    Blink LEDs
*/

// PORTB5 -> LED du board Diduino – Arduino
#define bLb1 PORTB5
#define      Lb1Read   bitRead (  PINB, bLb1 )
#define      Lb1Set    bitSet  ( PORTB, bLb1 )
#define      Lb1Clear  bitClear( PORTB, bLb1 )
#define      Lb1Toggle PORTB ^= 1<<bLb1
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

void wait( int delayMs ) // calibré 8 Mega avec 450 (56 à 1 MHz)
{
    for( volatile int i=0; i<delayMs; i++ )
    {
        for( volatile int j=0; j<450; j++ ) {}
    }
}

int main()
{
    DDRB = 0b11111111;
    // while( true )
    // {
    //     L0Toggle; wait( 100 );
    //     L1Toggle; wait( 100 );
    //     L2Toggle; wait( 100 );
    //     L3Toggle; wait( 100 );
    // }
}