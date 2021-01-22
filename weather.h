#pragma once

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