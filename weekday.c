#pragma once
#include "weekday.h"
#include <stdio.h>

Weekday weekday(Year year, Month month, Day day) {
    if (month < 3u) {
        --year;
        month += 10u;
    } else
        month -= 2u;
    return (Weekday)((day + 31u * month / 12u + year + year / 4u - year / 100u + year / 400u) % 7u);
}
    void print_weekday(int number_of_day_in_week){
        switch (number_of_day_in_week) {
            case 0:
                printf("voskresenye");
                break;
            case 1:
                printf("ponedelnik");
                break;
            case 2:
                printf("vtornik");
                break;
            case 3:
                printf("sredu");
                break;
            case 4:
                printf("chetverg");
                break;
            case 5:
                printf("pyatnitsu");
                break;
            case 6:
                printf("subbotu");
                break;
        }
}


