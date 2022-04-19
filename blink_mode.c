#include "blink_mode.h"
#include <avr/io.h>
#define F_CPU 0x10 * 0xF4240
#include <util/delay.h>
void cont(int mode, int diode_id){
    for (int i=0; i<2; i++){    
        mode? _delay_ms(125) : _delay_ms(750);
        PORTB ^= (1<<diode_id);
    }
    _delay_ms(2000);
}
void burst2(int mode, int diode_id){
    for(int i=0; i<4; i++){
        mode? _delay_ms(125) : _delay_ms(750);
        PORTB ^= (1<<diode_id);
    }
    _delay_ms(2000);
}
void burst3(int mode, int diode_id){
    for(int i=0; i<6; i++){
        mode? _delay_ms(125) : _delay_ms(750);
        PORTB ^= (1<<diode_id);
    }
    _delay_ms(2000);
}