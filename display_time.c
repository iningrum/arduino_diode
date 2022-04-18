#include "display_time.h"
#include <avr/io.h>
void print_hour(int hour){
    hour = hour%2? hour-1 : hour;
    int bit = 3;
    int value = 0b000000;
    while(bit && hour){
        if(hour-(2^bit)>0){
            value |= (1<<bit);
            hour-=(2^bit);
        }
        bit--;
    }
    PORTB &= value;
}
int print_minute(int minute){
    if (minute<20){
        return (1<<PD3);
    }
    else if (minute<40){
        return (1<<PD4);
    }
    else if (minute<60){
        return (1<<PD5);
    }
    
}
int define_blink_speed(int hour){
    return hour%2? 0: 1;
}