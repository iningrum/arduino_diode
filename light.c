#include <avr/io.h>
#include <util/delay.h>
# define LED1 DDB12
int main(){
    //DDRB |= DDRB | 0B010000;
    DDRB |=  (1<<PD6);
    digitalWrite()
    while(1){
        PORTB |= (1<<PD6);
        _delay_ms(500);
        PORTB &= (1<<PD6);
        _delay_ms(500);
    }
}