#include "curent_date.h"

/* void CurrentDatePrint(WEATHER * weather, int cur_day, int cur_month, int cur_year){
    int day = weather->date.day,
        month = weather->date.month,
        year = weather->date.year;
        struct timespec ts;
        timespec(&ts, TIME_UTC);
        char buff[100];
        strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
        printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
    }
} */