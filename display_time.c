#include "display_time.h"
#include <avr/io.h>
int print_hour(int hour){
    if (hour>12)
        hour-=12;
    if (hour%2)
        hour--;
    int bit = 3;
    int oldest_diode = -1;
    int value = 0b000000;
    while(bit && hour){
        if(hour-(1<<bit)>0){
            oldest_diode = bit+2;
            value |= (1<<bit+2);
            hour-=(1<<bit+2);
        }
        bit--;
    }
    PORTB &= value;
    return oldest_diode;
}

int define_blink_speed(int hour){
    return hour%2? 0: 1;
}