/*
  Example for different sending methods

  http://code.google.com/p/rc-switch/

*/

#include <RCSwitch.h>

RCSwitch mySwitch1 = RCSwitch();
// RCSwitch mySwitch2 = RCSwitch();


void setup() {

  //Serial.begin(9600);

  // Transmitter is connected to Arduino Pin #10
  mySwitch1.enableTransmit(10);
  // mySwitch2.enableTransmit(11);

  // Optional set pulse length.
  // mySwitch1.setPulseLength(320);

  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch1.setProtocol(2);

  // Optional set number of transmission repetitions.
  // mySwitch1.setRepeatTransmit(15);

}

void loop() {

  /* See Example: TypeA_WithDIPSwitches */
  // mySwitch1.switchOn("11111", "00010");
  // delay(1000);
  // mySwitch1.switchOn("11111", "00010");
  // delay(1000);

  // /* Same switch as above, but using decimal code */
  mySwitch1.send(1111, 24);
//  mySwitch2.send(2222, 24);
  // delay(1000);
  // mySwitch1.send(5396, 24);
  // delay(1000);

  // /* Same switch as above, but using binary code */
  // mySwitch1.send("000000000001010100010001");
  // delay(1000);
  // mySwitch1.send("000000000001010100010100");
  // delay(1000);

  // /* Same switch as above, but tri-state code */
  // mySwitch1.sendTriState("00000FFF0F0F");
  // delay(1000);
  // mySwitch1.sendTriState("00000FFF0FF0");
  // delay(1000);

  // delay(20000);
}
