#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "display_time.h"
#include "blink_mode.h"






int main(){
    //DDRB |= DDRB | 0B010000;
    DDRB |=  (1<<PD3) |
             (1<<PD4) |
             (1<<PD5);
    time_t T;
    int LOOP = 1;
    T.hour = 12;
    T.minute = 30;

    while(1){
        void(*blink)(int) = (T.b_mode==0)? cont
            : (T.b_mode==1)? burst2
            : burst3;
        while(LOOP){
            blink(T.b_speed);
        }
    }
}
