#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "display_time.h"







int main(){
    //DDRB |= DDRB | 0B010000;
    DDRB |=  (1<<PD3) |
             (1<<PD4) |
             (1<<PD5);
    time_t T;
    T.hour = 12;
    T.minute = 30;
    while(1){
        switch(T.blink_speed){
            case 0:
            _delay_ms(250);
            break;
            case 1:
            _delay_ms(500);
            break;
        }
        PORTB ^= T.blink_index;
    }
}
