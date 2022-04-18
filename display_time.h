#ifndef DISPLAY_TIME_H
#define DISPLAY_TIME_H

typedef struct time{
    int hour;
    int minute;
    int blink_speed;
    int blink_index;
} time_t;

void print_hour(int hour);

int print_minute(int minute);

int define_blink_speed(int hour);
#endif