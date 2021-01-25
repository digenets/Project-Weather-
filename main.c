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
#include "wind_constants.h"
#include "precipitation_constants.h"

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

StringArray ConvertWindDirection(StringArray directions) {
    StringArray result = CreateStringArray(directions.size);
    for (int i = 0; i < directions.size; ++i) {
        if (strcmp(directions.array[i], "С") == 0) {
            result.array[i] = "северный";
        } else if (strcmp(directions.array[i], "Ю") == 0) {
            result.array[i] = "южный";
        } else if (strcmp(directions.array[i], "З") == 0) {
            result.array[i] = "западный";
        } else if (strcmp(directions.array[i], "В") == 0) {
            result.array[i] = "восточный";
        } else if (strcmp(directions.array[i], "С-З") == 0) {
            result.array[i] = "северо-западный";
        } else if (strcmp(directions.array[i], "С-В") == 0) {
            result.array[i] = "северо-восточный";
        } else if (strcmp(directions.array[i], "Ю-З") == 0) {
            result.array[i] = "юго-западный";
        } else if (strcmp(directions.array[i], "Ю-В") == 0) {
            result.array[i] = "юго-восточный";
        }
    }
    return result;
}

void WriteAboutWind(FILE* output_file, WEATHER weather) {
    WIND wind = weather.wind;

    // если ветер есть - "Ветер восточный 3-5 м/с с порывами до 5-7 м/с"
    if (wind.speed_min_val != 0) {
        fprintf(output_file, "Ветер ");

        // направление ветра
        StringArray wind_dir_text = ConvertWindDirection(wind.direction);
        // если направление ветра задаётся одной буквой
        if (wind_dir_text.size == 1) {
            fprintf(output_file, "%s ", wind_dir_text.array[0]); // "восточный "
        } else {
            for (int i = 0; i < wind.direction.size; ++i) { // "юго-восточный, юго-западный "
                fprintf(output_file, "%s", wind_dir_text.array[i]);
                if (i == wind.direction.size - 1) {
                    fprintf(output_file, " ");
                } else {
                    fprintf(output_file, ", ");
                }
            }
        }

        // скорость
        fprintf(output_file, "%d", wind.speed_min_val);
        if (wind.speed_max_val != -1) {
            fprintf(output_file, "-%d", wind.speed_max_val);
        }
        fprintf(output_file, " м/с ");

        // порывы
        fprintf(output_file, "с порывами до ");
        fprintf(output_file, "%d", wind.gusts_min_val);
        if (wind.gusts_max_val != -1) {
            fprintf(output_file, "-%d", wind.gusts_max_val);
        }
        fprintf(output_file, " м/с. ");
    }

    // формируем комментарий в зависимости от средней скорости ветра
    int average = 0;
    if (wind.speed_max_val == -1) {
        average = wind.speed_min_val;
    } else {
        average = (wind.speed_min_val + wind.speed_max_val) / 2;
    }

    if (average == 0) {
        int index = rand() % CommentsWind0().size;
        fprintf(output_file, "%s ", CommentsWind0().array[index]);
    } else if (average > 0 && average <= 3) {
        int index = rand() % CommentsWind1to3().size;
        fprintf(output_file, "%s ", CommentsWind1to3().array[index]);
    } else if (average > 3 && average <= 5) {
        int index = rand() % CommentsWind3to5().size;
        fprintf(output_file, "%s ", CommentsWind3to5().array[index]);
    } else if (average > 5 && average <= 8) {
        int index = rand() % CommentsWind5to8().size;
        fprintf(output_file, "%s ", CommentsWind5to8().array[index]);
    } else if (average > 8 && average <= 14) {
        int index = rand() % CommentsWind8to14().size;
        fprintf(output_file, "%s ", CommentsWind8to14().array[index]);
    } else if (average > 14 && average <= 17) {
        int index = rand() % CommentsWind14to17().size;
        fprintf(output_file, "%s ", CommentsWind14to17().array[index]);
    } else if (average > 17 && average <= 20) {
        int index = rand() % CommentsWind17to20().size;
        fprintf(output_file, "%s ", CommentsWind17to20().array[index]);
    } else if (average > 20 && average <= 25) {
        int index = rand() % CommentsWind20to25().size;
        fprintf(output_file, "%s ", CommentsWind20to25().array[index]);
    } else if (average > 25) {
        int index = rand() % CommentsWindMoreThan25().size;
        fprintf(output_file, "%s ", CommentsWindMoreThan25().array[index]);
    }
    fprintf(output_file, "\n");
}

void WriteAboutPrecipitation(FILE *output_file, WEATHER weather) {
    if (strcmp(weather.precipitation, "-") == 0) {
        int index = rand() % CommentsNoPrecipitation().size;
        fprintf(output_file, "%s ", CommentsNoPrecipitation().array[index]);
    } else {
        if (strcmp(weather.precipitation, SNOW) == 0) {
            int index = rand() % CommentsSnow().size;
            fprintf(output_file, "%s ", CommentsSnow().array[index]);
        } else if (strcmp(weather.precipitation, RAIN) == 0) {
            int index = rand() % CommentsRain().size;
            fprintf(output_file, "%s ", CommentsRain().array[index]);
        } else if (strcmp(weather.precipitation, HAIL) == 0) {
            int index = rand() % CommentsHail().size;
            fprintf(output_file, "%s ", CommentsHail().array[index]);
        } else if (strcmp(weather.precipitation, THUNDER) == 0) {
            int index = rand() % CommentsThunder().size;
            fprintf(output_file, "%s ", CommentsThunder().array[index]);
        } else {
            fprintf(output_file, "Ожидается %s. ", weather.precipitation);
        }
    }
    fprintf(output_file, "\n");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru-RU.utf8");
    srand(time(0));
    rand();

    if (argc > 3 && strcmp(argv[3], TEST) == 0) {
        Test();
    }

    char* path = argv[1];
    FILE* input_file = fopen(path, "r");
    int weather_str_number = 0;
    fscanf(input_file, "%d\n", &weather_str_number);
    WEATHER* weather = ParseInput(input_file, weather_str_number);

    FILE* output_file = fopen(argv[2], "a");
    for (int i = 0; i < weather_str_number; ++i) {
        WriteAboutPrecipitation(output_file, weather[i]);
        WriteAboutWind(output_file, weather[i]);
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
