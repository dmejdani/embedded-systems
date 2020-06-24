#include <avr/io.h>
//#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <avr/interrupt.h>

int main(void)

{
	cli();
	DDRD = 0xF0;
	PORTD = 0x00;
	//TCNT1 = 3036;
	OCR1A = 62500;
	TIMSK1 = 0x02; //Output Compare A interrupt enable
	TCCR1A |= (1<<COM1A0); //Set toggle port A compare match
	TCCR1B = 0b00000100;
	sei();
	while(1){
	}
	return 0;
}


ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 3036;
}
