#include "date.h"
#include <time.h>

/* проверка, является ли comparing_date предыдущей датой */
bool AreConsecutiveDates(DATE* current_date, DATE* comparing_date) {
    struct tm current_tm = {
            .tm_mday = current_date->day,
            .tm_mon = (current_date->month - 1),
            .tm_year = (current_date->year - 1900)
    };

    // получить предыдущий день
    current_tm.tm_mday--;
    mktime(&current_tm); // чтоб были пересчитаны поля структуры

    if (current_tm.tm_mday == comparing_date->day
        && current_tm.tm_mon == (comparing_date->month - 1)
        && current_tm.tm_year == (comparing_date->year - 1900)) {
        return true;
    }
    return false;
}

