#ifndef DISPLAY_TIME_H
#define DISPLAY_TIME_H

typedef struct time{
    int hour;
    int minute;
    int b_mode;
    int b_speed;
    int b_diode_id;
} time_t;

int print_hour(int hour);

int define_blink_speed(int hour);
#endif