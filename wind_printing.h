#ifndef PROJECT_WEATHER__WIND_PRINTING_H
#define PROJECT_WEATHER__WIND_PRINTING_H

#include "base.h"
#include "wind_constants.h"
#include "weather.h"

StringArray ConvertWindDirection(StringArray directions, int word_ending_type);
void PrintWindDirection(FILE* output_file, StringArray wind_dir_text);
void PrintWindSpeed(FILE* output_file, int speed_min, int speed_max);
void PrintGusts(FILE* output_file, int min_val, int max_val);
void PrintWindComment(FILE* output_file, int average_speed);
void PrintWind(FILE* output_file, WEATHER* weather);

#endif //PROJECT_WEATHER__WIND_PRINTING_H
