#include "average_temperature.h"

void PrintAverageDayTemperature(int average_temperature, int month, FILE* out) {
    if (month == 1) {
        if (average_temperature <= -13)
            fprintf(out, "Эти значения ниже средней температуры января");
        else if (average_temperature > -13 && average_temperature < -7)
            fprintf(out, "Это средние значения для января в Нижнем Новгороде");
        else if (average_temperature > -7)
            fprintf(out, "Эти значения выше средней температуры января");
    }
    if (month == 2) {
        if (average_temperature <= -12)
            fprintf(out, "Эти значения ниже средней температуры февраля");
        else if (average_temperature > -12 && average_temperature < -6)
            fprintf(out, "Это средние значения для февраля в Нижнем Новгороде");
        else if (average_temperature > -6)
            fprintf(out, "Эти значения выше средней температуры февраля");
    }
    if (month == 3) {
        if (average_temperature <= 0)
            fprintf(out, "Эти значения ниже средней температуры марта");
        else if (average_temperature > 0 && average_temperature < 7)
            fprintf(out, "Это средние значения для марта в Нижнем Новгороде");
        else if (average_temperature > 7)
            fprintf(out, "Эти значения выше средней температуры марта");
    }
    if (month == 4) {
        if (average_temperature <= 1)
            fprintf(out, "Эти значения ниже средней температуры апреля");
        else if (average_temperature > 1 && average_temperature < 10)
            fprintf(out, "Это средние значения для апреля в Нижнем Новгороде");
        else if (average_temperature > 10)
            fprintf(out, "Эти значения выше средней температуры апреля");
    }
    if (month == 5) {
        if (average_temperature <= 8)
            fprintf(out, "Эти значения ниже средней температуры мая");
        else if (average_temperature > 8 && average_temperature < 18)
            fprintf(out, "Это средние значения для мая в Нижнем Новгороде");
        else if (average_temperature > 18)
            fprintf(out, "Эти значения выше средней температуры мая");
    }
    if (month == 6) {
        if (average_temperature <= 12)
            fprintf(out, "Эти значения ниже средней температуры июня");
        else if (average_temperature > 12 && average_temperature < 22)
            fprintf(out, "Это средние значения для июня в Нижнем Новгороде");
        else if (average_temperature > 22)
            fprintf(out, "Эти значения выше средней температуры июня");
    }
    if (month == 7) {
        if (average_temperature <= 14)
            fprintf(out, "Эти значения ниже средней температуры июля");
        else if (average_temperature > 14 && average_temperature <24)
            fprintf(out, "Это средние значения для июля в Нижнем Новгороде");
        else if (average_temperature > 24)
            fprintf(out, "Эти значения выше средней температуры июля");
    }
    if (month == 8) {
        if (average_temperature <= 12)
            fprintf(out, "Эти значения ниже средней температуры августа");
        else if (average_temperature > 12 && average_temperature < 22)
            fprintf(out, "Это средние значения для августа в Нижнем Новгороде");
        else if (average_temperature > 22)
            fprintf(out, "Эти значения выше средней температуры августа");
    }
    if (month == 9) {
        if (average_temperature <= 7)
            fprintf(out, "Эти значения ниже средней температуры сентября");
        else if (average_temperature > 7 && average_temperature < 15)
            fprintf(out, "Это средние значения для сентября в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней температуры сентября");
    }
    if (month == 10) {
        if (average_temperature <= 1)
            fprintf(out, "Эти значения ниже средней температуры октября");
        else if (average_temperature > 1 && average_temperature < 7)
            fprintf(out, "Это средние значения для октября в Нижнем Новгороде");
        else if (average_temperature > 7)
            fprintf(out, "Эти значения выше средней температуры октября");
    }
    if (month == 11) {
        if (average_temperature <= -5)
            fprintf(out, "Эти значения ниже средней температуры ноября");
        else if (average_temperature > -5 && average_temperature < -1)
            fprintf(out, "Это средние значения для ноября в Нижнем Новгороде");
        else if (average_temperature > -1)
            fprintf(out, "Эти значения выше средней температуры ноября");
    }
    if (month == 12) {
        if (average_temperature <= -10)
            fprintf(out, "Эти значения ниже средней температуры декабря");
        else if (average_temperature > -10 && average_temperature < -5)
            fprintf(out, "Это средние значения для декабря в Нижнем Новгороде");
        else if (average_temperature > -5)
            fprintf(out, "Эти значения выше средней температуры декабря");
    }
}
void PrintAverageNightTemperature(int average_temperature, int month, FILE * out){
    if (month == 1) {
        if (average_temperature <= -20)
            fprintf(out, "Эти значения ниже средней ночной температуры января");
        else if (average_temperature > -20 && average_temperature < -14)
            fprintf(out, "Это средние значения для ночной температуры января в Нижнем Новгороде");
        else if (average_temperature > -14)
            fprintf(out, "Эти значения выше средней ночной температуры января");
    }
    if (month == 2) {
        if (average_temperature <= -19)
            fprintf(out, "Эти значения ниже средней ночной температуры февраля");
        else if (average_temperature > -19 && average_temperature < -13)
            fprintf(out, "Это средние значения для ночной температуры февраля в Нижнем Новгороде");
        else if (average_temperature > -13)
            fprintf(out, "Эти значения выше средней ночной температуры февраля");
    }
    if (month == 3) {
        if (average_temperature <= -7)
            fprintf(out, "Эти значения ниже средней ночной температуры марта");
        else if (average_temperature > -7 && average_temperature < 0)
            fprintf(out, "Это средние значения для ночной температуры марта в Нижнем Новгороде");
        else if (average_temperature > 0)
            fprintf(out, "Эти значения выше средней ночной температуры марта");
    }
    if (month == 4) {
        if (average_temperature <= -6)
            fprintf(out, "Эти значения ниже средней ночной температуры апреля");
        else if (average_temperature > -6 && average_temperature < 3)
            fprintf(out, "Это средние значения для ночной температуры апреля в Нижнем Новгороде");
        else if (average_temperature > 3)
            fprintf(out, "Эти значения выше средней ночной температуры апреля");
    }
    if (month == 5) {
        if (average_temperature <= 1)
            fprintf(out, "Эти значения ниже средней ночной температуры мая");
        else if (average_temperature > 1 && average_temperature < 11)
            fprintf(out, "Это средние значения для ночной температуры мая в Нижнем Новгороде");
        else if (average_temperature > 11)
            fprintf(out, "Эти значения выше средней ночной температуры мая");
    }
    if (month == 6) {
        if (average_temperature <= 5)
            fprintf(out, "Эти значения ниже средней ночной температуры июня");
        else if (average_temperature > 5 && average_temperature < 15)
            fprintf(out, "Это средние значения для ночной температуры июня в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней ночной температуры июня");
    }
    if (month == 7) {
        if (average_temperature <= 7)
            fprintf(out, "Эти значения ниже средней ночной температуры июля");
        else if (average_temperature > 7 && average_temperature <17)
            fprintf(out, "Это средние значения для ночной температуры июля в Нижнем Новгороде");
        else if (average_temperature > 17)
            fprintf(out, "Эти значения выше средней ночной температуры июля");
    }
    if (month == 8) {
        if (average_temperature <= 5)
            fprintf(out, "Эти значения ниже средней ночной температуры августа");
        else if (average_temperature > 5 && average_temperature < 15)
            fprintf(out, "Это средние значения для ночной температуры августа в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней ночной температуры августа");
    }
    if (month == 9) {
        if (average_temperature <= 0)
            fprintf(out, "Эти значения ниже средней ночной температуры сентября");
        else if (average_temperature > 0 && average_temperature < 8)
            fprintf(out, "Это средние значения для ночной температуры сентября в Нижнем Новгороде");
        else if (average_temperature > 8)
            fprintf(out, "Эти значения выше средней ночной температуры сентября");
    }
    if (month == 10) {
        if (average_temperature <= -6)
            fprintf(out, "Эти значения ниже средней ночной температуры октября");
        else if (average_temperature > -6 && average_temperature < 0)
            fprintf(out, "Это средние значения для ночной температуры октября в Нижнем Новгороде");
        else if (average_temperature > 0)
            fprintf(out, "Эти значения выше средней ночной температуры октября");
    }
    if (month == 11) {
        if (average_temperature <= -12)
            fprintf(out, "Эти значения ниже средней ночной температуры ноября");
        else if (average_temperature > -12 && average_temperature < -8)
            fprintf(out, "Это средние значения для ночной температуры ноября в Нижнем Новгороде");
        else if (average_temperature > -8)
            fprintf(out, "Эти значения выше средней ночной температуры ноября");
    }
    if (month == 12) {
        if (average_temperature <= -17)
            fprintf(out, "Эти значения ниже средней ночной температуры декабря");
        else if (average_temperature > -17 && average_temperature < -12)
            fprintf(out, "Это средние значения для ночной температуры декабря в Нижнем Новгороде");
        else if (average_temperature > -12)
            fprintf(out, "Эти значения выше средней ночной температуры декабря");
    }
}