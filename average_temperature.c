#include "average_temperature.h"

void PrintAverageDayTemperature(int average_temperature, int month, FILE* out) {
    if (month >= 1 && month <= 2 || month == 12) { // зима
        if (average_temperature <= -10)
            fprintf(out, "Эти значения ниже средней температуры зимы");
        else if (average_temperature > -10 && average_temperature < -6)
            fprintf(out, "Это средние значения для зимы в Нижнем Новгороде");
        else if (average_temperature > -6)
            fprintf(out, "Эти значения выше средней температуры зимы");
    }
    if (month >= 3 && month <= 5) { // весна
        if (average_temperature < 6)
            fprintf(out,"Эти значения ниже средней температуры весны");
        else if (average_temperature >= 6 && average_temperature <= 10) {
            fprintf(out,"Это средние значения для весны в Нижнем Новгороде");
        }
        else if (average_temperature > 10) {
            fprintf(out,"Эти значения выше средней температуры весной");
        }
    }
    if (month >= 6 && month <= 8) { // лето
        if (average_temperature < 20)
            fprintf(out,"Эти значения ниже средней температуры летом");
        else if (average_temperature >= 20 && average_temperature <= 24) {
            fprintf(out,"Это средние значения для лета в Нижнем Новгороде");
        }
        else if (average_temperature > 24) {
            fprintf(out,"Эти значения выше средней температуры летом");
        }
    }
    if (month >= 9 && month <= 11) { // осень
        if (average_temperature < 20)
            fprintf(out, " Эти значения ниже средней температуры осенью");
        else if (average_temperature >= 20 && average_temperature <= 24) {
            fprintf(out, "Это средние значения для осени в Нижнем Новгороде");
        }
        else if (average_temperature > 24) {
            fprintf(out, "Эти значения выше средней температуры осенью");
        }
    }
}
void PrintAverageNightTemperature(int average_temperature, int month, FILE * out){
    if (month >= 1 && month <= 2 || month == 12) { // зима
        if (average_temperature <= -13)
            fprintf(out, "Эти значения ниже средней ночной температуры зимы");
        else if (average_temperature > -13 && average_temperature < -9)
            fprintf(out,"Это средние значения для ночной температуры зимы в Нижнем Новгороде");
        else if (average_temperature > -9)
            fprintf(out, "Эти значения выше средней ночной температуры зимы");
    }
    if (month >= 3 && month <= 5) { // весна
        if (average_temperature < 3)
            fprintf(out, "Эти значения ниже средней ночной температуры весны");
        else if (average_temperature >= 3 && average_temperature <= 7) {
            fprintf(out,"Это средние значения для ночной температуры весны в Нижнем Новгороде");
        }
        else if (average_temperature > 7) {
            fprintf(out, "Эти значения выше средней ночной температуры весной");
        }
    }
    if (month >= 6 && month <= 8) { // лето
        if (average_temperature < 17)
            fprintf(out, "Эти значения ниже средней ночной температуры летом");
        else if (average_temperature >= 17 && average_temperature <= 21) {
            fprintf(out, "Это средние значения для ночной температуры лета в Нижнем Новгороде");
        }
        else if (average_temperature > 21) {
            fprintf(out, "Эти значения выше средней ночной температуры летом");
        }
    }
    if (month >= 9 && month <= 11) { // осень
        if (average_temperature < 17)
            fprintf(out, "Эти значения ниже средней ночной температуры осенью");
        else if (average_temperature >= 17 && average_temperature <= 21) {
            fprintf(out, "Это средние значения для ночной температуры осени в Нижнем Новгороде");
        }
        else if (average_temperature > 21) {
            fprintf(out, "Эти значения выше средней ночной температуры осенью");
        }
    }
}