#ifndef PROJECT_WEATHER__WIND_PRINTING_H
#define PROJECT_WEATHER__WIND_PRINTING_H

#include "base.h"
#include "wind_constants.h"
#include "weather.h"

StringArray ConvertWindDirection(StringArray directions, int word_ending_type);
void PrintWindDirection(FILE* output_file, StringArray wind_direction_text);
void PrintWindSpeedValue(FILE* output_file, int speed_min, int speed_max, int if_previous_day_exists);
void PrintGustsValue(FILE* output_file, int min_val, int max_val, int if_previous_day_exists);
void PrintWindComment(FILE* output_file, int average_speed);

int GetAverageSpeed(const int min_speed, const int max_speed);
int GetSpeedDiff(int min_speed, int max_speed, int min_speed_prev_day, int max_speed_prev_day);

void PrintWindSpeedChange(FILE *output_file, const WIND *wind, const WIND *previous_day_wind);
void PrintWindComparedWithPreviousDay(FILE* output_file, const WIND* wind, const WIND* previous_day_wind);
void PrintWindWithoutComparing(FILE* output_file, const WIND* wind);

void PrintWind(FILE* output_file, WIND* wind, WIND* previous_day_wind);

#endif //PROJECT_WEATHER__WIND_PRINTING_H
