#ifndef PROJECT_WEATHER__DATE_H
#define PROJECT_WEATHER__DATE_H

#include <stdbool.h>

typedef struct Date {
    int day;
    int month;
    int year;
}DATE;

bool AreConsecutiveDates(DATE* current_date, DATE* comparing_date);

#endif //PROJECT_WEATHER__DATE_H