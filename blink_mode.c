#include "blink_mode.h"
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
void cont(int mode){
    for (int i=0; i<2; i++){    
        mode? _delay_ms(250) : _delay_ms(500);
        PORTB ^= (1<<PD3);
    }
    _delay_ms(1000);
}
void burst2(int mode){
    for(int i=0; i<4; i++){
        mode? _delay_ms(250) : _delay_ms(500);
        PORTB ^= (1<<PD3);
    }
    _delay_ms(1000);
}
void burst3(int mode){
    for(int i=0; i<6; i++){
        mode? _delay_ms(250) : _delay_ms(500);
        PORTB ^= (1<<PD3);
    }
    _delay_ms(1000);
}