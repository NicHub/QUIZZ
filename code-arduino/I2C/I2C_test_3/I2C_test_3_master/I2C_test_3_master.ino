// http://www.bajdi.com
// I2C communication between 2 Arduino
// Analog joystick connected to analog pins A0 and A1
// Values from joystick are sent to another Arduino (the slave)

#include <Wire.h>
#include <I2C_Anything.h>

const byte SLAVE_ADDRESS = 42;

void setup()
{
  Wire.begin ();
}  // end of setup

int i;
void loop()
{
  int X = i++;
  int Y = X*2;

  if( i> 1000) i=0;

  Wire.beginTransmission (SLAVE_ADDRESS);
  I2C_writeAnything (X);
  I2C_writeAnything (Y);
  Wire.endTransmission ();

}