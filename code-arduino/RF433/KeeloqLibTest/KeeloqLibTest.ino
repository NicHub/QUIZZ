#include <Keeloq.h>

void setup()
{
  Serial.begin(9600);
  Keeloq k(0x01020304,0x05060708);
  unsigned long enc = k.encrypt(6623281UL);
  Serial.print("After encrypt: ");
  Serial.print(enc,HEX);
  Serial.print("\n");
  unsigned long dec = k.decrypt(enc);
  Serial.print("After decrypt: ");
  Serial.print(dec,DEC);
  Serial.print("\n");
}

void loop()
{
}

