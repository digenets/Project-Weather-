#ifndef PROJECT_WEATHER__WEEKDAY_H
#define PROJECT_WEATHER__WEEKDAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

typedef unsigned int Year;
typedef unsigned int Month;
typedef unsigned int Day;
typedef unsigned int Weekday;
Weekday weekday(Year year, Month month, Day day);
void print_weekday(int number_of_day_in_week);
#endif //PROJECT_WEATHER__WEEKDAY_H
