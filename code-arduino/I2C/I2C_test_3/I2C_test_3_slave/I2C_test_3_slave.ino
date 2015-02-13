// http://www.bajdi.com
// I2C communication between 2 Arduino
// Slave receives the integers X and Y from the master
// Values X and Y are printed to the serial monitor

#include <Wire.h>
#include <I2C_Anything.h>

const byte MY_ADDRESS = 42;

void setup()
{
  Wire.begin (MY_ADDRESS);
  Serial.begin (9600);
  Wire.onReceive (receiveEvent);
}  // end of setup

volatile boolean haveData = false;
volatile int X;
volatile int Y;

void loop()
{
  if (haveData)
  {
    Serial.print ("\nReceived X = ");
    Serial.print (X);
    Serial.print ("\nReceived Y = ");
    Serial.print (Y);
    haveData = false;
    delay(100);
  }  // end if haveData

}  // end of loop

// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany)
{
  if (howMany >= (sizeof X) + (sizeof Y))
  {
    I2C_readAnything (X);
    I2C_readAnything (Y);
    haveData = true;
  }
}