//
// Created by igor on 24.01.2021.
//

#include "average_temperature.h"

void print_average_day_temperature(int average_temperature, int month) {
    if (month >= 1 && month <= 2 || month == 12) { // зима
        if (average_temperature <= -10)
            printf("Eti znacheniya nizhe sredney temperatury zimi"); // Эти значения ниже средней температуры зимы
        if (average_temperature > -10 && average_temperature < -6)
            printf("Eto sredniye znacheniya dlya zimi v Nizhnem Novgorode"); // Это средние значения для зимы в Нижнем Новгороде
        if (average_temperature > -6)
            printf("Eti znacheniya vishe sredney temperatury zimi"); // Эти значения выше средней температуры зимы
    }
    if (month >= 3 && month <= 5) { // весна
        if (average_temperature < 6)
            printf("Eti znacheniya nizhe sredney temperatury vesny"); // Эти значения ниже средней температуры весны
        if (average_temperature >= 6 && average_temperature <= 10) {
            printf("Eto sredniye znacheniya dlya zimi v Nizhnem Novgorode"); // Это средние значения для зимы в Нижнем Новгороде
        }
        if (average_temperature > 10) {
            printf("Eti znacheniya vishe sredney temperatury vesnoy"); // Эти значения выше средней температуры весной
        }
    }
    if (month >= 6 && month <= 8) { // лето
        if (average_temperature < 20)
            printf("Eti znacheniya nizhe sredney temperatury letom"); // Эти значения ниже средней температуры летом
        if (average_temperature >= 20 && average_temperature <= 24) {
            printf("Eto sredniye znacheniya dlya leta v Nizhnem Novgorode"); // Это средние значения для лета в Нижнем Новгороде
        }
        if (average_temperature > 24) {
            printf("Eti znacheniya vishe sredney temperatury letom"); // Эти значения выше средней температуры летом
        }
    }
    if (month >= 9 && month <= 11) { // осень
        if (average_temperature < 20)
            printf("Eti znacheniya nizhe sredney temperatury letom"); // Эти значения ниже средней температуры летом
        if (average_temperature >= 20 && average_temperature <= 24) {
            printf("Eto sredniye znacheniya dlya leta v Nizhnem Novgorode"); // Это средние значения для лета в Нижнем Новгороде
        }
        if (average_temperature > 24) {
            printf("Eti znacheniya vishe sredney temperatury letom"); // Эти значения выше средней температуры летом
        }
    }
}
void print_average_night_temperature(int average_temperature, int month){
    if (month >= 1 && month <= 2 || month == 12) { // зима
        if (average_temperature <= -13)
            printf("Eti znacheniya nizhe sredney nochnoy temperatury zimi"); // Эти значения ниже средней температуры зимы
        if (average_temperature > -13 && average_temperature < -9)
            printf("Eto sredniye znacheniya dlya nochnoy temperatury zimi v Nizhnem Novgorode"); // Это средние значения для зимы в Нижнем Новгороде
        if (average_temperature > -9)
            printf("Eti znacheniya vishe sredney nochnoy temperatury zimi"); // Эти значения выше средней температуры зимы
    }
    if (month >= 3 && month <= 5) { // весна
        if (average_temperature < 3)
            printf("Eti znacheniya nizhe sredney nochnoy temperatury vesny"); // Эти значения ниже средней температуры весны
        if (average_temperature >= 3 && average_temperature <= 7) {
            printf("Eto sredniye znacheniya dlya nochnoy temperatury zimi v Nizhnem Novgorode"); // Это средние значения для зимы в Нижнем Новгороде
        }
        if (average_temperature > 7) {
            printf("Eti znacheniya vishe sredney nochnoy temperatury vesnoy"); // Эти значения выше средней температуры весной
        }
    }
    if (month >= 6 && month <= 8) { // лето
        if (average_temperature < 17)
            printf("Eti znacheniya nizhe sredney nochnoy temperatury letom"); // Эти значения ниже средней температуры летом
        if (average_temperature >= 17 && average_temperature <= 21) {
            printf("Eto sredniye znacheniya dlya nochnoy temperatury leta v Nizhnem Novgorode"); // Это средние значения для лета в Нижнем Новгороде
        }
        if (average_temperature > 21) {
            printf("Eti znacheniya vishe sredney nochnoy temperatury letom"); // Эти значения выше средней температуры летом
        }
    }
    if (month >= 9 && month <= 11) { // осень
        if (average_temperature < 17)
            printf("Eti znacheniya nizhe sredney nochnoy temperatury letom"); // Эти значения ниже средней температуры летом
        if (average_temperature >= 17 && average_temperature <= 21) {
            printf("Eto sredniye znacheniya dlya nochnoy temperatury leta v Nizhnem Novgorode"); // Это средние значения для лета в Нижнем Новгороде
        }
        if (average_temperature > 21) {
            printf("Eti znacheniya vishe sredney nochnoy temperatury letom"); // Эти значения выше средней температуры летом
        }
    }
}