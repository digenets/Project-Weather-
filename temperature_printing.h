#ifndef PROJECT_WEATHER__TEMPERATURE_PRINTING_H
#define PROJECT_WEATHER__TEMPERATURE_PRINTING_H
#include "weather.h"
void PrintNightTemperature(int night_temp_min, int night_temp_max, DATE* date, FILE * out);
void PrintDayTemperature(int day_temp_min, int day_temp_max, DATE* date, FILE * out);
#endif //PROJECT_WEATHER__TEMPERATURE_PRINTING_H
