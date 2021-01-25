#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <uchar.h>
#include "weather.h"
#include "date.h"
#include "temperature.h"
#include "wind.h"
#include "base.h"
#include "test.h"
#include "weekday.h"
#include "month_name.h"
#include "average_temperature.h"



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

void print_date(int day, int mounth, int year, WEATHER* weather){
    int day_of_week_number = weekday(weather->date.year, weather->date.month, weather->date.day);
    switch (rand()%4) {
        case 0:
            if (day_of_week_number != 2) // В среду 13 января
                printf("V ");
            else
                printf("Vo ");
            print_weekday(day_of_week_number);
            printf(" ");
            printf("%d ", weather->date.day);
            print_month(weather->date.month);
            printf(" ");
            break;
        case 1:
            printf("%d ", weather->date.day); // 13 января в среду
            print_month(weather->date.month);
            printf(" ");
            if (day_of_week_number != 2)
                printf("v ");
            else
                printf("vo ");
            print_weekday(day_of_week_number);
            printf(" ");
            break;
        case 2:
            printf("%d.%d.%d ", weather->date.day, weather->date.month, weather->date.year); // 13.01.2021
            printf(" ");
            break;
        case 3:
            printf("%d ", weather->date.day); // 13 января
            print_month(weather->date.month);
            printf(" ");
            break;
    }
}

void print_day_temperature(int day_temp_min, int day_temp_max, WEATHER * weather){
    int average_temperature = (day_temp_min + day_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            printf("dnyevnaya temperatura nachoditsa v promeshutke ot %d do %d gradusov C. ", day_temp_min,
                   day_temp_max); // Дневная температуры назодится в промежутке от %d до %d градусов С
            print_average_day_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;

        case 1:
            printf("nizhnyaya granitsa temperatury dnya: %dC, ", day_temp_min); // Нижняя граница температуры дня %dC
            printf("verchnyaya: %dC. ", day_temp_max); // Верхняя: %dC
            print_average_day_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;
        case 2:
            printf("dnem ot %d do %d gradusov. ", weather->day_temp.min_val, weather->day_temp.max_val);
            print_average_day_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;
        case 3:
            printf("dnyevnaya temperatura nachoditsa v promeshutke ot %d do %d gradusov C. ", day_temp_min,
                   day_temp_max);
            break;
        case 4:
            printf("nizhnyaya granitsa temperatury dnya: %dC, ", day_temp_min); // Нижняя граница температуры дня %dC
            printf("verchnyaya: %dC. ", day_temp_max);
            break;
        case 5:
            printf("dnem ot %d do %d gradusov. ", weather->day_temp.min_val, weather->day_temp.max_val);
            break;
    }
    }

void print_night_temperature(int night_temp_min, int night_temp_max, WEATHER* weather){
    int average_temperature = (night_temp_min + night_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            printf("Nochnaya temperatura nachoditsa v promeshutke ot %d do %d gradusov C. ", night_temp_min,
                   night_temp_max); // Дневная температуры назодится в промежутке от %d до %d градусов С
            print_average_night_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;

        case 1:
            printf("Nizhnyaya granitsa temperatury nochi: %dC, ", night_temp_min); // Нижняя граница температуры дня %dC
            printf("verchnyaya: %dC. ", night_temp_max); // Верхняя: %dC
            print_average_night_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;
        case 2:
            printf("Nochyu ot %d do %d gradusov. ", weather->night_temp.min_val, weather->night_temp.max_val);
            print_average_night_temperature(average_temperature, weather->date.month);
            printf(". ");
            break;
        case 3:
            printf("Nochnaya temperatura nachoditsa v promeshutke ot %d do %d gradusov C. ", night_temp_min,
                   night_temp_max);
            break;
        case 4:
            printf("Nizhnyaya granitsa temperatury nochi: %dC, ", night_temp_min); // Нижняя граница температуры дня %dC
            printf("verchnyaya: %dC. ", night_temp_max);
            break;
        case 5:
            printf("Nochyu ot %d do %d gradusov. ", weather->night_temp.min_val, weather->night_temp.max_val);
            break;
    }
}

void print_pressure(WEATHER* weather){
    int pressure = weather->pressure;
            if (pressure >= 755)
                printf("Atmosfernoe davlenie visokoe: %d mm rtutnogo stolba", pressure);
            if (pressure < 755 && pressure > 745)
                printf("Atmosfernoe davlenie v norme: %d mm rtutnogo stolba", pressure);
            if (pressure <= 745)
                printf("Atmosfernoe davlenie nizkoe: %d mm rtutnogo stolba", pressure);

    }



int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru-RU.utf8");
    srand(time(NULL));
    rand();
    if (argc > 2 && strcmp(argv[2], TEST) == 0) {
        Test();
    }

    char* path = argv[1];
    FILE* input_file = fopen("C:/Users/igor/Project-Weather-/weather_input.txt", "rt");
    int str_number = 0;
    fscanf(input_file, "%d\n", &str_number);
    WEATHER* weather = ParseInput(input_file, str_number);
    print_date(weather->date.day, weather->date.month, weather->date.year, weather);
    print_day_temperature(weather->day_temp.min_val, weather->day_temp.max_val, weather);
    print_night_temperature(weather->night_temp.min_val, weather->night_temp.max_val, weather);
    print_pressure(weather);

    fclose(input_file);
    return 0;
}
