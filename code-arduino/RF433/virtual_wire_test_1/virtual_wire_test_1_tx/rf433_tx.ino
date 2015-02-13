/*

rf433_tx.ino

PROGRAMME DE TEST DU KIT ÉMETTEUR-RÉCEPTEUR RF433 D’ALIEXPRESS
Ce programme doit être utilisé en parallèle avec le récepteur rf433_rx.ino.

*/

#include <VirtualWire.h>

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
// PORTD2 -> Bouton 1
#define bP1  PORTD2
#define      P1Read    !bitRead(  PIND, bP1 )
// Pin Data sur le transmetteur
#define TXPin    3

char *msgToSend;



void wait( int delayMs ) // calibré 8 Mega avec 450 (56 à 1 MHz)
{
    for( volatile int i=0; i<delayMs; i++ )
    {
        for( volatile int j=0; j<450; j++ ) {}
    }
}



void setup()
{
    vw_set_ptt_inverted( true );
    vw_set_tx_pin( TXPin );
    vw_setup( 4000 );

    msgToSend = "3";
    vw_send( (uint8_t *)msgToSend, strlen( msgToSend ) );

    DDRD  |= ( 1 << bP1 );
    PORTD |= ( 1 << bP1 );

    DDRB = 0b11111111;

    // Il semble que VirtualWire influence PORTB2.
    // Donc on attend et on remet tout PORTB à 0.
    wait( 100 );
    PORTB = 0;
}



uint16_t i;
void loop()
{

    if( P1Read )
    {
        L0Toggle;
        msgToSend = "0";
        vw_send( (uint8_t *)msgToSend, strlen( msgToSend ) );
        // vw_wait_tx();
        while( P1Read ){}
        L2Clear; // À cause de VirtualWire.
    }
    // Fait clignoter la LED 13
    if( i++ > 32768 )
    {
        Lb1Toggle;
        i = 0;
    }

}
