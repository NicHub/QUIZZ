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
const unsigned long Pmask = ( 1 << P0pin )
                          | ( 1 << P1pin )
                          | ( 1 << P2pin )
                          | ( 1 << P3pin );
const int LEDpin = PORTB5;
const int HPpin  = PORTC0;
const char deviceIDStr[] = "CB0\n";
unsigned long T1 = millis();
boolean serverTalked = false;
String serverCommand = "";
unsigned long P1_4Readcopy = 0;

#define HPToggle  PORTC ^=  ( 1 << HPpin  )
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
    DDRB  |=  ( 1 << LEDpin );
    DDRB  &= ~( 1 << P0pin  )
          &  ~( 1 << P1pin  )
          &  ~( 1 << P2pin  )
          &  ~( 1 << P3pin  );
    PORTB  = 0b11111111
          &  ~( 1 << LEDpin );

    DDRC  |=  ( 1 << HPpin  );
    PORTC &= ~( 1 << HPpin  );

    DDRD   = 0b00000000;
    PORTD  = 0b11111111;

    serverCommand.reserve( 200 );
    Serial.begin( 115200 );
    Serial.print( deviceIDStr );
    beep();
}




void loop()
{
    // On stocke l’état des boutons dans P1_4Readcopy.
    P1_4Readcopy = P1_4Read;

    // On envoie l’état des boutons par RS232 à la condition qu’au moins un
    // des boutons soit pressé. Les valeurs reçues par le serveur sont les
    // suivantes :
    //
    // case 56: var buttonID = 1; break;
    // case 52: var buttonID = 2; break;
    // case 50: var buttonID = 3; break;
    // case 49: var buttonID = 4; break;
    //
    // Si deux boutons ou plus sont pressés en même temps, les codes seront
    // évidemment différents, mais ce cas a peu de chance d’arriver car il
    // faudrait que les boutons soient pressés dans un intervalle de quelques
    // cycles d’horloge (62.5 ns sur l’Arduino Nano à 16 MHz).
    if( P1_4Readcopy )
    {
        Serial.print( P1_4Readcopy, DEC );
        Serial.print( "\n" );
    }

    // Traitement des commandes envoyées par le serveur via RS232.
    if( serverTalked )
    {
        int whatToDo = serverCommand.toInt();

        // Envoie l’ID de l’Arduino par le port série.
        if( whatToDo == -1 )
        {
            Serial.print( deviceIDStr );
            beep( 2 );
        }

        // Émet un signal sonore le nombre de fois spécifié.
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


