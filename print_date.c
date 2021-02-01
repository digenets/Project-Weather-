#include <stdio.h>
#include "weekday.h"
#include "weather.h"
#include "month_name.h"
void PrintDate(int day, int mounth, int year, WEATHER* weather, FILE* out){
    int day_of_week_number = weekday(weather->date.year, weather->date.month, weather->date.day);
    switch (rand()%4) {
        case 0:
            if (day_of_week_number != 2) // В среду 13 января
                fprintf(out, "В ");
            else
                fprintf(out, "Во ");
            PrintWeekday(day_of_week_number, out);
            fprintf(out , " ");
            fprintf(out, "%d ", weather->date.day);
            PrintMonth(weather->date.month, out);
            fprintf(out, " ");
            break;
        case 1:
            fprintf(out, "%d ", weather->date.day); // 13 января в среду
            PrintMonth(weather->date.month, out);
            fprintf(out , " ");
            if (day_of_week_number != 2)
                fprintf(out, "в ");
            else
                fprintf(out, "во ");
            PrintWeekday(day_of_week_number, out);
            fprintf(out, " ");
            break;
        case 2:
            fprintf(out, "%d.%d.%d ", weather->date.day, weather->date.month, weather->date.year); // 13.01.2021
            fprintf(out, " ");
            break;
        case 3:
            fprintf(out, "%d ", weather->date.day); // 13 января
            PrintMonth(weather->date.month, out);
            fprintf(out, " ");
            break;
    }
}