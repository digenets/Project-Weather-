#include "weekday.h"

Weekday weekday(Year year, Month month, Day day) {
    if (month < 3u) {
        --year;
        month += 10u;
    } else
        month -= 2u;
    return (Weekday)((day + 31u * month / 12u + year + year / 4u - year / 100u + year / 400u) % 7u);
}
    void PrintWeekday(int number_of_day_in_week, FILE * out){
        switch (number_of_day_in_week) {
            case 0:
                fprintf(out, "воскресенье");
                break;
            case 1:
                fprintf(out, "понедельник");
                break;
            case 2:
                fprintf(out, "вторник");
                break;
            case 3:
                fprintf(out, "среду");
                break;
            case 4:
                fprintf(out, "четверг");
                break;
            case 5:
                fprintf(out, "пятницу");
                break;
            case 6:
                fprintf(out, "субботу");
                break;
        }
}


