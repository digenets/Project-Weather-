#include "temperature_printing.h"
#include "average_temperature.h"

void PrintDayTemperature(int day_temp_min, int day_temp_max, DATE* date, FILE* out){
    int average_temperature = (day_temp_min + day_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            fprintf(out, "температура днём от %d до %d градусов C. ", day_temp_min, day_temp_max);
            PrintAverageDayTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;

        case 1:
            fprintf(out, "дневная температура от %d до %d градусов C. ", day_temp_min, day_temp_max);
            PrintAverageDayTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;
        case 2:
            fprintf(out, "днём стобики термометров покажут от %d до %d градусов. ",
                    day_temp_min, day_temp_max);
            PrintAverageDayTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;
        case 3:
            fprintf(out, "днём от %d до %d градусов C. ", day_temp_min, day_temp_max);
            break;
        case 4:
            fprintf(out, "температура днём составит от %d до %dC. ", day_temp_min, day_temp_max);
            break;
        case 5:
            fprintf(out, "днём от %d до %d градусов. ", day_temp_min, day_temp_max);
            break;
    }
}

void PrintNightTemperature(int night_temp_min, int night_temp_max, DATE* date, FILE* out){
    int average_temperature = (night_temp_min + night_temp_max) / 2;
    switch(rand()%6) {
        case 0:
            fprintf(out, "Ночная температура от %d до %d градусов C. ", night_temp_min, night_temp_max);
            PrintAverageNightTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;

        case 1:
            fprintf(out, "В ночные часы термометры покажут от %d до %dC. ", night_temp_min, night_temp_max);
            PrintAverageNightTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;
        case 2:
            fprintf(out, "Ночью от %d до %d градусов. ", night_temp_min, night_temp_max);
            PrintAverageNightTemperature(average_temperature, date->month, out);
            fprintf(out, ". ");
            break;
        case 3:
            fprintf(out, "Ночью температура находится в промежутке от %d до %d градусов C. ", night_temp_min,
                    night_temp_max);
            break;
        case 4:
            fprintf(out, "Температура ночью в районе %dC. ", average_temperature);
            break;
        case 5:
            fprintf(out, "Ночью от %d до %d градусов. ", night_temp_min, night_temp_max);
            break;
    }
}

