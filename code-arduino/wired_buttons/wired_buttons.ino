/*


     ██████  ██    ██ ██ ███████ ███████     ██
    ██    ██ ██    ██ ██    ███     ███      ██
    ██    ██ ██    ██ ██   ███     ███       ██
    ██    ██ ██    ██ ██  ███     ███
     ██████   ██████  ██ ███████ ███████     ██
        ██


    CONTRÔLE DES BOUTONS

    Nicolas Jeanmonod, David Le Neillon, 2015

 */



const int P0pin  = PORTB0;
const int P1pin  = PORTB1;
const int P2pin  = PORTB2;
const int P3pin  = PORTB3;
const unsigned long Pmask = ( 1 << P0pin ) | ( 1 << P1pin ) | ( 1 << P2pin ) | ( 1 << P3pin );
const int LEDpin = PORTB5;
const int HPpin  = PORTC0;
const char deviceIDStr[] = "CB0\n";
unsigned long T1 = millis();
boolean serverTalked = false;
String serverCommand = "";
unsigned long P1_4Readcopy = 0;

#define HPToggle  PORTC ^=  ( 1 << HPpin )
#define LEDSet    PORTB |=  ( 1 << LEDpin )
#define LEDClear  PORTB &= ~( 1 << LEDpin )
#define LEDToggle PORTB ^=  ( 1 << LEDpin )
#define P1_4Read  ~PINB & Pmask



void beep( byte nbBeep = 1 )
{
    for( int beepCNT=0; beepCNT<nbBeep; beepCNT++ )
    {
        for( int i=0; i<100; i++ )
        {
            HPToggle;
            _delay_ms( 1 );
        }
        _delay_ms( 10 );
    }
}



void serialEvent()
{
    while( Serial.available() )
    {
        char serverChar = ( char )Serial.read();
        if( serverChar == '\n' )
            serverTalked = true;
        else
            serverCommand += serverChar;
    }
}



void setup()
{
    DDRB |=    ( 1 << LEDpin );
    DDRB &=   ~( 1 << P0pin )
            & ~( 1 << P1pin )
            & ~( 1 << P2pin )
            & ~( 1 << P3pin );
    PORTB = 0b11111111
        & ~( 1 << LEDpin );;

    DDRC  |=  ( 1 << HPpin );
    PORTC &= ~( 1 << HPpin );

    DDRD  = 0b00000000;
    PORTD = 0b11111111;

    serverCommand.reserve( 200 );
    Serial.begin( 115200 );
    Serial.print( deviceIDStr );
    beep();
}




void loop()
{
    P1_4Readcopy = P1_4Read;
    if( P1_4Readcopy )
    {
        Serial.print( P1_4Readcopy, DEC );
        Serial.print( "\n" );
    }

    int whatToDo = 0;
    if( serverTalked )
    {
        whatToDo = serverCommand.toInt();

        if( whatToDo == -1 )
        {
            Serial.print( deviceIDStr );
            beep( 2 );
        }
        else
        {
            beep( abs( whatToDo ) );
        }

        serverCommand = "";
        serverTalked = false;
    }

    if( millis() - T1 >= 500 )
    {
        LEDToggle;
        T1 = millis();
    }
}


