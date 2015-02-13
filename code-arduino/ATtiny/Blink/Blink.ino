/*
    Blink
    Programme pour tester la programmation en mode ISP d’un ATtiny25V
*/

#define LedPin 4
#define delay_ms 200

void setup()
{
    pinMode( LedPin, OUTPUT );
}

void loop()
{
    heartbeat();
    // digitalWrite( LedPin, HIGH );
    // delay( delay_ms );
    // digitalWrite( LedPin, LOW );
    // delay( delay_ms );
}


// this provides a heartbeat on pin 9, so you can tell the software is running.
uint8_t hbval = 128;
int8_t hbdelta = 8;
void heartbeat() {
  if (hbval > 192) hbdelta = -hbdelta;
  if (hbval < 32) hbdelta = -hbdelta;
  hbval += hbdelta;
  analogWrite(LedPin, hbval);
  delay(20);
}

