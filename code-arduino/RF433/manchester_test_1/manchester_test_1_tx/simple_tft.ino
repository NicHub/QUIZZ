/*
 * Pin Change Interrupt Example
 * Version: 1.0
 * Author: Alex from Inside Gadgets (http://www.insidegadgets.com)
 * Created: 25/02/2011
 * Adaptation RT 27/08/2014 for Alex
 * Interrupt on digital pin 2
 * 10k resistor on digital pin 2 to GND
 * Attiny [6] logical pin 1 -> led
 * Attiny [7] logical pin 2 -> bouton
 * Attiny [8] vcc
 * Attiny [4] gnd
 * Attiny [3] logical pin 3 -> +alimradio
 * Attiny [2] logical pin 4 -> dataPin radio
 *
 *
 */
 // #include <avr/sleep.h>
 #include <Manchester.h>


// Bouton Pin  2
const int bouton = 2;
int state ;
uint16_t transmit_data = 0;
// Led Pin 4
const int led = 13;
// radio Pin 1
const int dataPin = 4;
// Alim radio Pin3
const int alimradio = 3;
void setup()
{
    pinMode( led, OUTPUT );
    pinMode( bouton, INPUT_PULLUP );
    pinMode( alimradio, OUTPUT );
    man.setupTransmit( dataPin, MAN_600 );
    digitalWrite( led, LOW );
    digitalWrite( alimradio, LOW );
}

void loop()
{
    state = !digitalRead( bouton );
    if( state == HIGH )
    {
        digitalWrite( alimradio, HIGH );
        digitalWrite( led, HIGH );
        man.transmit( transmit_data );
        while( !digitalRead( bouton ) ) {}
        digitalWrite( led, LOW );
        digitalWrite( alimradio, LOW );
    }

}

