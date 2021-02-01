#ifndef PROJECT_WEATHER__TEMPERATURE_PINTING_H
#define PROJECT_WEATHER__TEMPERATURE_PINTING_H
#include "weather.h"
void PrintNightTemperature(int night_temp_min, int night_temp_max, WEATHER* weather, FILE * out);
void PrintDayTemperature(int day_temp_min, int day_temp_max, WEATHER * weather, FILE * out);
#endif //PROJECT_WEATHER__TEMPERATURE_PINTING_H
