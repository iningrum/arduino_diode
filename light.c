#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "display_time.h"
#include "blink_mode.h"

time_t T;
int LOOP = 1;




int main(){
    //DDRB |= DDRB | 0B010000;
    DDRB |=  (1<<PD3) |
             (1<<PD4) |
             (1<<PD5);
    
    T.hour = 12;
    T.minute = 30;

    while(1){
        void(*blink)(int, int) = (T.b_mode==0)? cont
            : (T.b_mode==1)? burst2
            : burst3;
        LOOP = 1;
        while(LOOP){
            blink(T.b_speed, T.b_diode_id);
        }
    }
}
ISR (TIMER0_COMPA_vect){
    static int count = 0;
    count = (count<59)? count+1 : 0;
    if (!count){
        T.minute = (T.minute<59)? T.minute+1 : 0;
        T.b_mode = (T.minute<20)? 0
            : (T.minute<40)? 1
            : 2;
    }
    if (!T.minute){
        T.hour = (T.hour<24)? T.hour+1 : 0;
        T.b_diode_id = print_hour(T.hour);
        T.b_speed = define_blink_speed(T.hour);
        LOOP = 0;
    }
}