#include <avr/io.h>
// #define F_CPU 16000000UL //define CPU clock 16MHz
#include <avr/interrupt.h>
#include <util/delay.h>

int n;

int main(void) 
{
	cli();

	DDRD = 0xF0;
	PORTD = 0xF0;

	EICRA |= (1<<ISC01) ;  // falling edge interrupt
	EIMSK |= (1<<INT0);   // enable INTO 
	
    // TCCR1A = 0b01000000;
    TCCR1B = 0b00001001;
    TIMSK1 = 0x02;

	sei();

	while(1){
		_delay_ms(2);



	};

	return 0;
}


void change_ocr1a(uint8)


ISR(INT0_vect)
{
	int i;
	
	for (i = 0; i < 3; i++)
	{
		PORTD = 0XF0;
		_delay_ms(250);
		PORTD = 0X00;
		_delay_ms(250);
	}

	PORTD = 0xF0;
}