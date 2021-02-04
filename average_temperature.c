#include "average_temperature.h"

void PrintAverageDayTemperature(int average_temperature, int month, FILE* out) {
    if (month == 1) { // январь
        if (average_temperature <= -13)
            fprintf(out, "Эти значения ниже средней ночной температуры января");
        else if (average_temperature > -13 && average_temperature < -7)
            fprintf(out,"Это средние значения для ночной температуры января в Нижнем Новгороде");
        else if (average_temperature > -7)
            fprintf(out, "Эти значения выше средней ночной температуры января");
    }
    else if (month == 2) { // февраль
        if (average_temperature <= -12)
            fprintf(out, "Эти значения ниже средней ночной температуры февраля");
        else if (average_temperature > -12 && average_temperature < -6)
            fprintf(out,"Это средние значения для ночной температуры февраля в Нижнем Новгороде");
        else if (average_temperature > -6)
            fprintf(out, "Эти значения выше средней ночной температуры февраля");
    }
    else if (month == 3) { // март
        if (average_temperature <= -7)
            fprintf(out, "Эти значения ниже средней ночной температуры марта");
        else if (average_temperature > -7 && average_temperature < 0)
            fprintf(out,"Это средние значения для ночной температуры марта в Нижнем Новгороде");
        else if (average_temperature > 0)
            fprintf(out, "Эти значения выше средней ночной температуры марта");
    }
    else if (month == 4) { // апрель
        if (average_temperature <= 1)
            fprintf(out, "Эти значения ниже средней ночной температуры апреля");
        else if (average_temperature > 1 && average_temperature < 10)
            fprintf(out,"Это средние значения для ночной температуры апреля в Нижнем Новгороде");
        else if (average_temperature > 10)
            fprintf(out, "Эти значения выше средней ночной температуры апреля");
    }
    else if (month == 5) { // май
        if (average_temperature <= 8)
            fprintf(out, "Эти значения ниже средней ночной температуры мая");
        else if (average_temperature > 8 && average_temperature < 18)
            fprintf(out,"Это средние значения для ночной температуры мая в Нижнем Новгороде");
        else if (average_temperature > 18)
            fprintf(out, "Эти значения выше средней ночной температуры мая");
    }
    else if (month == 6) { // июнь
        if (average_temperature <= 12)
            fprintf(out, "Эти значения ниже средней ночной температуры июня");
        else if (average_temperature > 12 && average_temperature < 22)
            fprintf(out,"Это средние значения для ночной температуры июля в Нижнем Новгороде");
        else if (average_temperature > 22)
            fprintf(out, "Эти значения выше средней ночной температуры июля");
    }
    else if (month == 7) { // июль
        if (average_temperature <= 14)
            fprintf(out, "Эти значения ниже средней ночной температуры июля");
        else if (average_temperature > 14 && average_temperature < 24)
            fprintf(out,"Это средние значения для ночной температуры июля в Нижнем Новгороде");
        else if (average_temperature > 24)
            fprintf(out, "Эти значения выше средней ночной температуры июля");
    }
    else if (month == 8) { // август
        if (average_temperature <= 12)
            fprintf(out, "Эти значения ниже средней ночной температуры августа");
        else if (average_temperature > 12 && average_temperature < 22)
            fprintf(out,"Это средние значения для ночной температуры августа в Нижнем Новгороде");
        else if (average_temperature > 22)
            fprintf(out, "Эти значения выше средней ночной температуры августа");
    }
    else if (month == 9) { // сентябрь
        if (average_temperature <= 7)
            fprintf(out, "Эти значения ниже средней ночной температуры сентября");
        else if (average_temperature > 7 && average_temperature < 15)
            fprintf(out,"Это средние значения для ночной температуры сентября в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней ночной температуры сентября");
    }
    else if (month == 10) { // октябрь
        if (average_temperature < 1)
            fprintf(out, "Эти значения ниже средней ночной температуры октября");
        else if (average_temperature >= 1 && average_temperature <= 7) {
            fprintf(out,"Это средние значения для ночной температуры октября в Нижнем Новгороде");
        }
        else if (average_temperature > 7) {
            fprintf(out, "Эти значения выше средней ночной температуры в октябре");
        }
    }
    else if (month == 11) { // ноябрь
        if (average_temperature < -5)
            fprintf(out, "Эти значения ниже средней ночной температуры в ноябре");
        else if (average_temperature >= -5 && average_temperature <= -1) {
            fprintf(out, "Это средние значения для ночной температуры ноября в Нижнем Новгороде");
        }
        else if (average_temperature > -1) {
            fprintf(out, "Эти значения выше средней ночной температуры в ноябре");
        }
    }
    else if (month == 12) { // декабрь
        if (average_temperature < -10)
            fprintf(out, "Эти значения ниже средней ночной температуры в декабре");
        else if (average_temperature >= -10 && average_temperature <= -5) {
            fprintf(out, "Это средние значения для ночной температуры декабря в Нижнем Новгороде");
        }
        else if (average_temperature > -5) {
            fprintf(out, "Эти значения выше средней ночной температуры в декабре");
        }
    }
}
void PrintAverageNightTemperature(int average_temperature, int month, FILE * out){
    if (month == 1) { // январь
        if (average_temperature <= -20)
            fprintf(out, "Эти значения ниже средней ночной температуры января");
        else if (average_temperature > -20 && average_temperature < -14)
            fprintf(out,"Это средние значения для ночной температуры января в Нижнем Новгороде");
        else if (average_temperature > -14)
            fprintf(out, "Эти значения выше средней ночной температуры января");
    }
    else if (month == 2) { // февраль
        if (average_temperature <= -19)
            fprintf(out, "Эти значения ниже средней ночной температуры февраля");
        else if (average_temperature > -19 && average_temperature < -13)
            fprintf(out,"Это средние значения для ночной температуры февраля в Нижнем Новгороде");
        else if (average_temperature > -13)
            fprintf(out, "Эти значения выше средней ночной температуры февраля");
    }
    else if (month == 3) { // март
        if (average_temperature <= -14)
            fprintf(out, "Эти значения ниже средней ночной температуры марта");
        else if (average_temperature > -14 && average_temperature < -7)
            fprintf(out,"Это средние значения для ночной температуры марта в Нижнем Новгороде");
        else if (average_temperature > -7)
            fprintf(out, "Эти значения выше средней ночной температуры марта");
    }
    else if (month == 4) { // апрель
        if (average_temperature <= -6)
            fprintf(out, "Эти значения ниже средней ночной температуры апреля");
        else if (average_temperature > -6 && average_temperature < 3)
            fprintf(out,"Это средние значения для ночной температуры апреля в Нижнем Новгороде");
        else if (average_temperature > 3)
            fprintf(out, "Эти значения выше средней ночной температуры апреля");
    }
    else if (month == 5) { // май
        if (average_temperature <= 1)
            fprintf(out, "Эти значения ниже средней ночной температуры мая");
        else if (average_temperature > 1 && average_temperature < 11)
            fprintf(out,"Это средние значения для ночной температуры мая в Нижнем Новгороде");
        else if (average_temperature > 11)
            fprintf(out, "Эти значения выше средней ночной температуры мая");
    }
    else if (month == 6) { // июнь
        if (average_temperature <= 5)
            fprintf(out, "Эти значения ниже средней ночной температуры июня");
        else if (average_temperature > 5 && average_temperature < 15)
            fprintf(out,"Это средние значения для ночной температуры июля в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней ночной температуры июля");
    }
    else if (month == 7) { // июль
        if (average_temperature <= 7)
            fprintf(out, "Эти значения ниже средней ночной температуры июля");
        else if (average_temperature > 7 && average_temperature < 17)
            fprintf(out,"Это средние значения для ночной температуры июля в Нижнем Новгороде");
        else if (average_temperature > 17)
            fprintf(out, "Эти значения выше средней ночной температуры июля");
    }
    else if (month == 8) { // август
        if (average_temperature <= 5)
            fprintf(out, "Эти значения ниже средней ночной температуры августа");
        else if (average_temperature > 5 && average_temperature < 15)
            fprintf(out,"Это средние значения для ночной температуры августа в Нижнем Новгороде");
        else if (average_temperature > 15)
            fprintf(out, "Эти значения выше средней ночной температуры августа");
    }
    else if (month == 9) { // сентябрь
        if (average_temperature <= 0)
            fprintf(out, "Эти значения ниже средней ночной температуры сентября");
        else if (average_temperature > 0 && average_temperature < 8)
            fprintf(out,"Это средние значения для ночной температуры сентября в Нижнем Новгороде");
        else if (average_temperature > 8)
            fprintf(out, "Эти значения выше средней ночной температуры сентября");
    }
    else if (month == 10) { // октябрь
        if (average_temperature < -6)
            fprintf(out, "Эти значения ниже средней ночной температуры октября");
        else if (average_temperature >= -6 && average_temperature <= 1) {
            fprintf(out,"Это средние значения для ночной температуры октября в Нижнем Новгороде");
        }
        else if (average_temperature > 1) {
            fprintf(out, "Эти значения выше средней ночной температуры в октябре");
        }
    }
    else if (month == 11) { // ноябрь
        if (average_temperature < -12)
            fprintf(out, "Эти значения ниже средней ночной температуры в ноябре");
        else if (average_temperature >= -12 && average_temperature <= -6) {
            fprintf(out, "Это средние значения для ночной температуры ноября в Нижнем Новгороде");
        }
        else if (average_temperature > -6) {
            fprintf(out, "Эти значения выше средней ночной температуры в ноябре");
        }
    }
    else if (month == 12) { // декабрь
        if (average_temperature < -17)
            fprintf(out, "Эти значения ниже средней ночной температуры в декабре");
        else if (average_temperature >= -17 && average_temperature <= -12) {
            fprintf(out, "Это средние значения для ночной температуры декабря в Нижнем Новгороде");
        }
        else if (average_temperature > -12) {
            fprintf(out, "Эти значения выше средней ночной температуры в декабре");
        }
    }
}