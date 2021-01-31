#include "temperature_pinting.h"
#include "average_temperature.h"

void PrintDayTemperature(int day_temp_min, int day_temp_max, WEATHER * weather, FILE * out){
    int average_temperature = (day_temp_min + day_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            fprintf(out, "дневная температура находится в промежутке от %d до %d градусов C. ", day_temp_min,
                   day_temp_max); // Дневная температуры назодится в промежутке от %d до %d градусов С
            PrintAverageDayTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;

        case 1:
            fprintf(out, "нижняя граница температуры дня: %dC, ", day_temp_min); // Нижняя граница температуры дня %dC
            fprintf(out, "верхняя: %dC. ", day_temp_max); // Верхняя: %dC
            PrintAverageDayTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;
        case 2:
            fprintf(out, "днём от %d до %d градусов. ", weather->day_temp.min_val, weather->day_temp.max_val);
            PrintAverageDayTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;
        case 3:
            fprintf(out, "дневная температура находится в промежутке от %d до %d градусов C. ", day_temp_min,
                   day_temp_max);
            break;
        case 4:
            fprintf(out, "нижняя граница температуры дня: %dC, ", day_temp_min); // Нижняя граница температуры дня %dC
            fprintf(out, "верхняя: %dC. ", day_temp_max);
            break;
        case 5:
            fprintf(out, "днём от %d до %d градусов. ", weather->day_temp.min_val, weather->day_temp.max_val);
            break;
    }
}

void PrintNightTemperature(int night_temp_min, int night_temp_max, WEATHER* weather, FILE * out){
    int average_temperature = (night_temp_min + night_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            fprintf(out, "Ночная температура находится в промежутке от %d до %d градусов C. ", night_temp_min,
                   night_temp_max); // Дневная температуры назодится в промежутке от %d до %d градусов С
            PrintAverageNightTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;

        case 1:
            fprintf(out, "Нижняя граница температуры ночи: %dC, ", night_temp_min); // Нижняя граница температуры дня %dC
            fprintf(out, "верхняя: %dC. ", night_temp_max); // Верхняя: %dC
            PrintAverageNightTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;
        case 2:
            fprintf(out, "Ночью от %d до %d градусов. ", weather->night_temp.min_val, weather->night_temp.max_val);
            PrintAverageNightTemperature(average_temperature, weather->date.month, out);
            fprintf(out, ". ");
            break;
        case 3:
            fprintf(out, "Ночью температура находится в промежутке от %d до %d градусов C. ", night_temp_min,
                   night_temp_max);
            break;
        case 4:
            fprintf(out, "Нижняя граница температуры ночи: %dC, ", night_temp_min); // Нижняя граница температуры дня %dC
            fprintf(out, "верхняя: %dC. ", night_temp_max);
            break;
        case 5:
            fprintf(out, "Ночью от %d до %d градусов. ", weather->night_temp.min_val, weather->night_temp.max_val);
            break;
    }
}

