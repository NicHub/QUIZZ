/*
  Simple example for receiving

  http://code.google.com/p/rc-switch/
*/

#include <RCSwitch.h>





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



RCSwitch mySwitch = RCSwitch();

void setup()
{

    DDRB = 0b11111111;
    DDRC = 0b11111111;
    L13Set;
    DDRD  = 0b11111111;
    bitClear( DDRD, bRX1 );
    bitClear( DDRD, bRX2 );
    bitClear( DDRD, bBouton );

    mySwitch.enableReceive( 0 );  // Receiver on inerrupt 0 => that is pin #2
    Serial.begin( 9600 );
L3Set;
delay(1000);
L3Clear;
}

int i;
void loop()
{
    if( mySwitch.available() )
    {
        int value = mySwitch.getReceivedValue();
             if( value == 17472 ){ L0Set;   L1Clear; L3Clear; }
        else if( value ==  4353 ){ L0Clear;   L1Set; L3Clear; }
        else                     { L0Clear; L1Clear;   L3Set; }
        Serial.print( value ); Serial.print( "\n" );

        // if (value == 0) {
        //   Serial.print("Unknown encoding");
        // } else {
        //   Serial.print("Received ");
        //   Serial.print( mySwitch.getReceivedValue() );
        //   Serial.print(" / ");
        //   Serial.print( mySwitch.getReceivedBitlength() );
        //   Serial.print("bit ");
        //   Serial.print("Protocol: ");
        //   Serial.println( mySwitch.getReceivedProtocol() );
        // }

        mySwitch.resetAvailable();
    }

    // if( i++ > 32000 )
    // {
    //     i = 0;
    //     L2Toggle;
    // }
}
