#include <avr/io.h>
// #define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <avr/interrupt.h>
#include <util/delay.h>

int n = 0;
int main(void)

{
cli();
DDRD = 0xFF;

ADMUX = 0x00;
ADCSRA = 0b11000111;

sei();
while(1){
 PORTD = ADCH;
 ADCSRA |= 1<<ADSC;
}
return 0;
}

// ISR(ADC_vect){
//  PORTD = ADCH;
//  ADCSRA |= 1<<ADSC;
//  }