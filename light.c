#include <avr/io.h>
#define F_CPU 0x10 * 0xF4240 // 16 * 1 MHz
#include <util/delay.h>
#include "display_time.h"
#include "blink_mode.h"
#include <avr/interrupt.h>

time_t T;
int LOOP = 1;



int main(){
    { // config
        DDRB |=  (1<<PD3) |
                 (1<<PD4) |
                 (1<<PD5);
        { // setting up timer
            TCCR1B = (1 << WGM12); // set ctc bit
            OCR1A = 19531;
            TIMSK1 = (1 << OCIE1A);
            sei();
            TCCR1B |= (1 << CS12) | (1 << CS10);
        }
        T.hour = 18;
        T.minute = 25;
    }
    { // first setup
        PORTB = 0;
        T.b_diode_id = print_hour(T.hour);
        T.b_speed = define_blink_speed(T.hour);
        T.b_mode = (T.minute<20)? 0
                : (T.minute<40)? 1
                : 2;
    }
    while(1){
        void(*blink)(int, int) = (T.b_mode==0)? cont
            : (T.b_mode==1)? burst2
            : burst3;
        LOOP = 1;
        while(LOOP){
            if (T.b_diode_id!= -1)
                blink(T.b_speed, T.b_diode_id);
            else
                for(int i =0; i <60 ; i++)
                _delay_ms(1000);
        }
    }
}
ISR (TIMER1_COMPA_vect){
    static int count = 0;
    count = (count<59)? count+1 : 0;
    if (!count){
        T.minute = (T.minute<59)? T.minute+1 : 0;
        T.b_mode = (T.minute<20)? 0
            : (T.minute<40)? 1
            : 2;
        if (T.minute && T.minute%20 == 0){
            LOOP = 0;
        }
    }
    if (!T.minute && !count){
        T.hour = (T.hour<24)? T.hour+1 : 0;
        // [1d] change active diodes and get oldest active bit
        T.b_diode_id = print_hour(T.hour);
        T.b_speed = define_blink_speed(T.hour);
        T.b_mode = 0;
        LOOP = 0;
    }
}