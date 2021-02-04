#include <stdio.h>
#include "weekday.h"
#include "weather.h"
#include "month_name.h"
void PrintDate(DATE* date, FILE* out){
    int day_of_week_number = weekday(date->year, date->month, date->day);
    switch (rand()%4) {
        case 0:
            if (day_of_week_number != 2) // В среду 13 января
                fprintf(out, "В ");
            else
                fprintf(out, "Во ");
            PrintWeekday(day_of_week_number, out);
            fprintf(out , " ");
            fprintf(out, "%d ", date->day);
            PrintMonth(date->month, out);
            fprintf(out, " ");
            break;
        case 1:
            fprintf(out, "%d ", date->day); // 13 января в среду
            PrintMonth(date->month, out);
            fprintf(out , " ");
            if (day_of_week_number != 2)
                fprintf(out, "в ");
            else
                fprintf(out, "во ");
            PrintWeekday(day_of_week_number, out);
            fprintf(out, " ");
            break;
        case 2:
            fprintf(out, "%d.%d.%d ", date->day, date->month, date->year); // 13.01.2021
            fprintf(out, " ");
            break;
        case 3:
            fprintf(out, "%d ", date->day); // 13 января
            PrintMonth(date->month, out);
            fprintf(out, " ");
            break;
    }
}