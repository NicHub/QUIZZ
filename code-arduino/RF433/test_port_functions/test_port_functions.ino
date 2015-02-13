
void setup()
{
    Serial.begin( 9600 );
    Serial.print( "\ndigitalPinToBitMask\n" );
    for( int i=0; i<20; i++ )
    {
        Serial.print( digitalPinToBitMask( i ), BIN ); Serial.print( "\n" );

        //        1
        //       10
        //      100
        //     1000
        //    10000
        //   100000
        //  1000000
        // 10000000
    }

    // Renvoie le numéro du charctère ASCII de la lettre du port
    // 0-7 -> 43 (D)
    // 8-13 -> 37 (B)
    // 14-19 -> 40 (C)
    Serial.print( "\nportOutputRegister( digitalPinToPort( i ) )\n" );
    for( int i=0; i<20; i++ )
    {
        Serial.print( int( portOutputRegister( digitalPinToPort( i ) ) ) ); Serial.print( "\n" );
    }


    // 0-7 -> 4 (D)
    // 8-13 -> 2 (B)
    // 14-19 -> 3 (C)
    Serial.print( "\ndigitalPinToPort( i )\n" );
    for( int i=0; i<20; i++ )
    {
        Serial.print( digitalPinToPort( i ) ); Serial.print( "\n" );
    }


    Serial.print( "\n\nPORTB = " ); Serial.print( PORTB );
    Serial.print( "\n\nPORTC = " ); Serial.print( PORTC );
    Serial.print( "\n\nPORTD = " ); Serial.print( PORTD );

    Serial.print( "\n\nPINB = " ); Serial.print( PINB );
    Serial.print( "\n\nPINC = " ); Serial.print( PINC );
    Serial.print( "\n\nPIND = " ); Serial.print( PIND );

    Serial.print( "\n\nDDRB = " ); Serial.print( DDRB );
    Serial.print( "\n\nDDRC = " ); Serial.print( DDRC );
    Serial.print( "\n\nDDRD = " ); Serial.print( DDRD );

    Serial.print( "\n\nPORTB0 = " ); Serial.print( PORTB0 );
    Serial.print( "\n\nPORTB1 = " ); Serial.print( PORTB1 );
    Serial.print( "\n\nPORTB2 = " ); Serial.print( PORTB2 );
    Serial.print( "\n\nPORTB3 = " ); Serial.print( PORTB3 );
    Serial.print( "\n\nPORTB4 = " ); Serial.print( PORTB4 );
    Serial.print( "\n\nPORTB5 = " ); Serial.print( PORTB5 );
    Serial.print( "\n\nPORTB6 = " ); Serial.print( PORTB6 );
    Serial.print( "\n\nPORTB7 = " ); Serial.print( PORTB7 );

    Serial.print( "\n\nPORTC0 = " ); Serial.print( PORTC0 );
    Serial.print( "\n\nPORTC1 = " ); Serial.print( PORTC1 );
    Serial.print( "\n\nPORTC2 = " ); Serial.print( PORTC2 );
    Serial.print( "\n\nPORTC3 = " ); Serial.print( PORTC3 );
    Serial.print( "\n\nPORTC4 = " ); Serial.print( PORTC4 );
    Serial.print( "\n\nPORTC5 = " ); Serial.print( PORTC5 );
    Serial.print( "\n\nPORTC6 = " ); Serial.print( PORTC6 );


}
void loop()
{

}