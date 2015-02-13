/*
 * Pin Change Interrupt Example
 * Version: 1.0
 * Author: Alex from Inside Gadgets (http://www.insidegadgets.com)
 * Created: 25/02/2011
 * Adaptation RT 27/08/2014 for Alex
 * 10k resistor on digital pin 2 to GND
 * Attiny [5] logical pin 2 -> enc0
 * Attiny [6] logical pin 3 -> led
 * Attiny [7] logical pin 0 -> bouton
 * Attiny [8] vcc
 * Attiny [4] gnd
 * Attiny [3] logical pin 1 -> dataradio
 * Attiny [2] logical pin 4 -> enc1
 *
 *
 */
#include <avr/sleep.h>
#include <Manchester.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

// Bouton Pin  0 Physique [5]
const int bouton = 0;
const int enc0 = 2; //Physique [7]
const int enc1 = 4; //Physique [3]
int state ;
uint16_t transmit_data = 10101;
int val_enc0 = 0;
int val_enc1 = 0;
// Led Pin 1
const int led = 3; // Physique [2]
// radio Pin 1
const int dataPin = 1; // Physique [6]
// Alim radio Pin3
void setup(){
  pinMode(led,OUTPUT);
  pinMode(bouton,INPUT);
  pinMode(enc0,INPUT);
  pinMode(enc1,INPUT);
  if(digitalRead(enc0)== HIGH) {
     if(digitalRead(enc1)== HIGH) {
       transmit_data = 10404 ;
     } else { transmit_data = 10303 ;}
  } else {
  if(digitalRead(enc1)== HIGH) {transmit_data = 10202;}
  }

  sbi(GIMSK,PCIE); // Turn on Pin Change interrupt
  sbi(PCMSK,PCINT0); // Which pins are affected by the interrupt
  man.setupTransmit(dataPin, MAN_600);
}

void loop(){
  delay(50);
  state=digitalRead(bouton);
  if(state == HIGH) {
     digitalWrite(led, HIGH);
    man.transmit(transmit_data);
     digitalWrite(led, LOW);
  state=digitalRead(bouton);
  }
    system_sleep();
}

// From http://interface.khm.de/index.php/lab/experiments/sleep_watchdog_battery/
void system_sleep() {
  cbi(ADCSRA,ADEN); // Switch Analog to Digital converter OFF
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode
  sleep_mode(); // System sleeps here
  sbi(ADCSRA,ADEN);  // Switch Analog to Digital converter ON
  state=digitalRead(bouton);
}

ISR(PCINT0_vect) {
}