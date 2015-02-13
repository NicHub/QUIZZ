#include <Manchester.h>

//thisValues for ArduinoUno
// const int ledPin =  13      // the number of the LED pin
// const int dataPIN = 10      // the number of the Data pin

const int ledPin =  13;      // the number of the LED pin
const int dataPin = 10;      // the number of the Data pin

const int Relais1 = 4 ;
const int Relais2 = 5 ;
const int Relais3 = 6 ;
const int Relais4 = 7 ;

uint16_t ref1 = 10101; //bouton1
uint16_t ref2 = 20202; //bouton2
uint16_t ref3 = 30303; //bouton3
uint16_t ref4 = 40404; //bouton4





void setup() {

// initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(dataPin, INPUT);

  pinMode(Relais1, OUTPUT);
  pinMode(Relais2, OUTPUT);
  pinMode(Relais3, OUTPUT);
  pinMode(Relais4, OUTPUT);


    man.setupReceive(dataPin, MAN_1200);     // initialisation de la librairie VirtualWire à 2000 bauds
	man.beginReceive();
    }

void loop(){

  if (man.receiveComplete()) {
    uint16_t m = man.getMessage();
    man.beginReceive(); //start listening for next message right after you retrieve the message
//    Serial.println("Done !"); // On signale la fin de l'envoi
    digitalWrite(ledPin, HIGH);
    Serial.print("RX ... "); // On signale le début de la reception
    Serial.print(m);
    Serial.println("Done !"); // On signale la fin de la reception
    if (m == ref1) {
           digitalWrite(Relais1, HIGH);
           delay(50);
           digitalWrite(Relais1, LOW);
    } else if(m == ref1) {
           digitalWrite(Relais2, HIGH);
           delay(50);
           digitalWrite(Relais2, LOW);
    } else if(m == ref1) {
           digitalWrite(Relais3, HIGH);
           delay(50);
           digitalWrite(Relais3, LOW);
    } else if(m == ref1) {
           digitalWrite(Relais4, HIGH);
           delay(50);
           digitalWrite(Relais4, LOW);
    } else {
    Serial.print("RX ... "); // On signale le début de la reception
    Serial.print(m);
    Serial.println("Non attendu !"); // On signale la fin de la reception
    }
    // delay(100); // Et on attend 100ms pour ne pas flooder
  }
    //  turn LED off:
    digitalWrite(ledPin, LOW);
}