#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
# define LED1 DDB12
int main(){
    //DDRB |= DDRB | 0B010000;
    DDRB |=  (1<<PD4);
    while(1){
        PORTB |= (1<<PD4);
        _delay_ms(5000);
        PORTB &= ~(1<<PD4);
        _delay_ms(5000);
    }
}