#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)

{
	cli();

	EICRA = 0X02;
	EIMSK = 0X01;
	
	sei();
	
	int i;
	DDRD = 0xF0;
	while(1)
	{
		PORTD = 0x80;
		for (i = 0; i < 2; i++)
		{
			_delay_ms(500);
			PORTD = PORTD >> 1;
		}
		
		_delay_ms(500);
	}
	return 0;
}

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
}
