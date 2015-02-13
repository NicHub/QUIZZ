#include <avr/io.h>
#include <avr/interrupt.h>

void initTimerCounter1(void);

int main()
{
    bitSet( DDRB, PINB3 );
    bitSet( DDRB, PINB4 );
    PINB = 0b00011000;
    initTimerCounter1();
    while( true );
}

void initTimerCounter1( void )
{
    TCCR1 = 0;                  //stop the timer
    TCNT1 = 0;                  //zero the timer
    GTCCR = 1 << PSR1;          //reset the prescaler
    OCR1A = 0;                //set the compare value
    OCR1C = 255;
    // OCR1C = 127;
    TIMSK = _BV(OCIE1A);        //interrupt on Compare Match A
    //start timer, ctc mode, prescaler clk/16384
    // TCCR1 = _BV(CTC1) | _BV(CS13) | _BV(CS12) | _BV(CS11) | _BV(CS10);

//            C   CCCC
//            T   SSSS
//            C   1111
//            1   3210
    TCCR1 = 0b10001101;
    sei();
}


ISR( TIMER1_COMPA_vect )
{
    PINB = 0b00011000;

    OCR1C -= 15;

}


/*

TCCR1              OCR1C        dT
0b10001111         255        5200
0b10001110         255        5200


*/