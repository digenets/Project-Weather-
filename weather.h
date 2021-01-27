#ifndef PROJECT_WEATHER__WEATHER_H
#define PROJECT_WEATHER__WEATHER_H

#include "date.h"
#include "temperature.h"
#include "wind.h"

typedef struct Weather {
    DATE date;
    TEMPERATURE night_temp;
    TEMPERATURE day_temp;
    TEMPERATURE temp_feels_like;
    char* precipitation;
    WIND wind;
    int pressure;
    StringArray earth_phenomena;
}WEATHER;

#endif //PROJECT_WEATHER__WEATHER_H