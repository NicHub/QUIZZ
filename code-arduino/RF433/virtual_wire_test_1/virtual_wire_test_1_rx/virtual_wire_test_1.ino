/*

rf433_rx.ino

PROGRAMME DE TEST DU KIT ÉMETTEUR-RÉCEPTEUR RF433 D’ALIEXPRESS
http://fr.aliexpress.com/item/1pcs-433Mhz-RF-transmitter-and-receiver-kit-for-Arduino-project-FREE-SHIPPING-3235/1308017760.html

RÉCEPTEUR (RX)
Testé sur Arduino UNO & Diduino
Les pin “data” du récepteur sont connectés sur les pins 2 et 3. Le programme fonctionne indiféremment avec l’une ou l’autre.
Quatre LED de status sont connectées à PB1, PB2, PB3, PB4. La LED 13 sur PB5 est aussi utilisée.

ÉMETTEUR (TX)
Testé sur Arduino UNO & Diduino
La pin data est connectée à la pin 5.
Quatre LED de status sont connectées à PB1, PB2, PB3, PB4. La LED 13 sur PB5 est aussi utilisée.

FONCTIONNEMENT DU PROGRAMME
L’émetteur envoie successivement les caractères '0', '1', '2', '3' et allume les LEDs correspondantes. Le récepteur reçoit les caractères et alllume lui aussi les LEDs correspondantes.

LA LIBRAIRIE VIRTUALWIRE VIENT DE :
http://www.airspayce.com/mikem/arduino/VirtualWire/
http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire-1.27.zip

UN EXEMPLE D’UTILISATION DE LA LIBRAIRIE VIRTUALWIRE SE TROUVE À :
http://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/

LA LIBRAIRIE VIRTUALWIRE N’EST PLUS MAINTENUE ET SON AUTEUR RECOMMANDE D’UTILISER LA LIBRAIRIE RADIOHEAD :
http://www.airspayce.com/mikem/arduino/RadioHead

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

#define RXPin   3 // 2 fonctionne aussi

uint8_t buf[ VW_MAX_MESSAGE_LEN ];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
uint16_t i;



void setup()
{
    vw_set_ptt_inverted( true );
    vw_set_rx_pin( RXPin );
    vw_setup( 4000 );
    vw_rx_start();
    DDRB = 0b11111111;
    PORTB = ( 1 << bLb1 );
}



void loop()
{
    if( vw_get_message( buf, &buflen ) )
    {
        if     ( buf[ 0 ] == '0' )
        {
            L0Toggle;
        }
        else if( buf[ 0 ] == '1' )
        {
            L1Toggle;
        }
        else if( buf[ 0 ] == '2' )
        {
            L2Toggle;
        }
        else if( buf[ 0 ] == '3' )
        {
            L3Toggle;
        }
        else
        {
            PORTB = 0b11111111;
        }
    }

    // Fait clignoter la LED 13
    if( i++ > 32768 )
    {
        Lb1Toggle;
        i = 0;
    }
}

