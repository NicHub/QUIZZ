


#include <util/delay.h>

const int P0pin = PORTB0;
const int P1pin = PORTB1;
const int P2pin = PORTB2;
const int P3pin = PORTB3;
const unsigned long Pmask = ( 1 << P0pin ) | ( 1 << P1pin ) | ( 1 << P2pin ) | ( 1 << P3pin );
const int LEDpin = PORTB5;
const int HPpin = PORTC0;

#define HPToggle  PORTC ^=  ( 1 << HPpin )
#define LEDSet    PORTB |=  ( 1 << LEDpin )
#define LEDClear  PORTB &= ~( 1 << LEDpin )
#define LEDToggle PORTB ^=  ( 1 << LEDpin )
#define P1_4Read  ~PINB & Pmask

unsigned long P1_4Readcopy = 0;


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

    beep();
    Serial.begin( 115200 );
    Serial.print( "\n###\nPmask = " );
    Serial.print( Pmask, BIN );

}

int serverCMD = 0;
int whatToDo = 0;
unsigned long T1 = millis();

void loop()
{

    if( Serial.available() > 0 )
    {
        serverCMD = Serial.read();
        Serial.print( "\nserverCMD, DEC = " );
        Serial.print( serverCMD, DEC );
        switch( serverCMD )
        {
            case 48:
                whatToDo = 0;
                break;
            case 49:
                whatToDo = 1;
                break;
        }
    }

    switch( whatToDo )
    {
        case 0:
            if( millis() - T1 >= 250 )
            {
                Serial.print( "\nNe rien faire" );
                T1 = millis();
            }
            break;
        case 1:
            if( millis() - T1 >= 250 )
            {
                Serial.print( "\nLire" );
                T1 = millis();
            }
            break;
    }


    // if( mustRead )
    // {
    //     mustRead = false;
    //     LEDSet;
    //     if( P1_4Read )
    //         readAndsendButtons();
    // }


    // P1_4Readcopy = P1_4Read;


    // switch( P1_4Readcopy )
    // {
    //     case 0:
    //         break;
    //     case 0b0001:
    //         // beep( 1 );
    //         readAndsendButtons();
    //         break;
    //     case 0b0010:
    //         // beep( 2 );
    //         readAndsendButtons();
    //         break;
    //     case 0b0100:
    //         // beep( 3 );
    //         readAndsendButtons();
    //         break;
    //     case 0b1000:
    //         // beep( 4 );
    //         readAndsendButtons();
    //         break;
    // }


}


void readAndsendButtons()
{
    unsigned long T1 = millis();
    bool mustBeep = true;

    do {
        if( millis() - T1 >= 100 )
        {
            Serial.print( "\nP1_4Readcopy, BIN = " );
            Serial.print( P1_4Readcopy, BIN );
            LEDToggle;
            T1 = millis();
        }
        if( mustBeep )
        {
            beep();
            mustBeep = false;
        }
        P1_4Readcopy = P1_4Read;
    }
    while( P1_4Readcopy );

    LEDClear;
}

