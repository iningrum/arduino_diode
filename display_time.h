#ifndef DISPLAY_TIME_H
#define DISPLAY_TIME_H

typedef struct time{
    int hour;
    int minute;
    int b_mode;
    int b_speed;
} time_t;

void print_hour(int hour);

int print_minute(int minute);

int define_blink_speed(int hour);
#endif