#include <stdlib.h>
#include <locale.h>
#include <uchar.h>
#include <time.h>
#include "weather.h"
#include "date.h"
#include "temperature.h"
#include "wind.h"
#include "base.h"
#include "test.h"
#include "precipitation_printing.h"
#include "wind_printing.h"
#include "print_date.h"
#include "average_temperature.h"
#include "temperature_pinting.h"
#include "print_pressure.h"

#define INPUT_MAX_LEN 200
#define TEST "test"

DATE ParseDate(char* date_str) {
    int day = 0, month = 0, year = 0;
    sscanf(date_str, "%d.%d.%d", &day, &month, &year);
    DATE date = {day, month, year};
    return date;
}

TEMPERATURE ParseTemperature(char* temp_str) {
    int min_val = 0, max_val = 0;
    sscanf(temp_str, "%d..%d", &min_val, &max_val);
    TEMPERATURE temp = {min_val, max_val};
    return temp;
}

WIND ParseWind(char* speed_str, char* direction_str, char* gusts_str) {
    int speed_min_val = -1;
    int speed_max_val = -1;
    if (strchr(speed_str, '-') != NULL) { // есть тире
        sscanf(speed_str, "%d-%d", &speed_min_val, &speed_max_val);
    } else {
        sscanf(speed_str, "%d", &speed_min_val);
    }

    StringArray direction = Split(direction_str, ',');

    int gusts_min_val = -1;
    int gusts_max_val = -1;
    if (strchr(gusts_str, '-') != NULL) {
        sscanf(gusts_str, "%d-%d", &gusts_min_val, &gusts_max_val);
    } else {
        sscanf(gusts_str, "%d", &gusts_min_val);
    }

    WIND wind = {speed_min_val, speed_max_val, direction, gusts_min_val, gusts_max_val};
    return wind;
}

WEATHER* ParseInput(FILE* file, int strings_number) {
    char input[INPUT_MAX_LEN];

    WEATHER* parsed = (WEATHER*) malloc(strings_number * sizeof(WEATHER));

    for (int i = 0; i < strings_number; ++i) {
        fgets(input, INPUT_MAX_LEN, file); // считали строку данных целиком

        StringArray input_split = Split(input, ':');
        char* date_str = input_split.array[0];
        DATE date = ParseDate(date_str);

        char* night_temp_str = input_split.array[1];
        TEMPERATURE night_temp = ParseTemperature(night_temp_str);
        char* day_temp_str = input_split.array[2];
        TEMPERATURE day_temp = ParseTemperature(day_temp_str);
        char* temp_feels_str = input_split.array[3];
        TEMPERATURE temp_feels = ParseTemperature(temp_feels_str);

        char* precipitation = input_split.array[4];

        char* wind_speed = input_split.array[5];
        char* wind_direction = input_split.array[6];
        char* wind_gusts = input_split.array[7];
        WIND wind = ParseWind(wind_speed, wind_direction, wind_gusts);

        char* pressure_str = input_split.array[8];
        int pressure = atoi(pressure_str);

        char* earth_phenom_str = input_split.array[9];
        earth_phenom_str[strlen(earth_phenom_str) - 1] = '\0';
        StringArray earth_phenomena = Split(earth_phenom_str, ',');

        WEATHER weather = {date, night_temp, day_temp, temp_feels, precipitation, wind, pressure, earth_phenomena};
        parsed[i] = weather;
    }
    return parsed;
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru-RU.utf8");
    srand(time(0));
    rand();

    if (argc > 3 && strcmp(argv[3], TEST) == 0) {
        Test();
    }

    char* path = argv[1];
    FILE* input_file = fopen(path, "rt");
    int weather_str_number = 0;
    fscanf(input_file, "%d\n", &weather_str_number);
    WEATHER* weather = ParseInput(input_file, weather_str_number);

    FILE* output_file = fopen(argv[2], "wt");
    for (int i = 0; i < weather_str_number; ++i) {
        PrintDate(weather[i].date.day, weather[i].date.month, weather[i].date.year, &weather[i], output_file);
        PrintDayTemperature(weather[i].day_temp.min_val, weather[i].day_temp.max_val, &weather[i], output_file);
        PrintNightTemperature(weather[i].night_temp.min_val, weather[i].night_temp.max_val, &weather[i], output_file);
        PrintPressure(&weather[i], output_file);
        PrintPrecipitation(output_file, &weather[i]);
        if (i > 0) {
            PrintWind(output_file, &weather[i].wind, &weather[i-1].wind);
        } else {
            PrintWind(output_file, &weather[i].wind, NULL);
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
