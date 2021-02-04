#include "earth_phenom_constants.h"

StringArray CommentsThunder() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Возможна гроза. ";
    result.array[1] = "Ожидаются грозы. ";
    result.array[2] = "Пройдут грозы. ";
    return result;
}

StringArray CommentsFog() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Из-за тумана видимость на дорогах будет снижена. ";
    result.array[1] = "Туман. Будьте внимательны на дорогах. ";
    result.array[2] = "Сильный туман. ";
    return result;
}

StringArray CommentsIceCovering() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "На дорогах гололедица, будьте осторожны. ";
    result.array[1] = "Гололедица. Будьте аккуратны на дорогах. ";
    result.array[2] = "Скользко. ";
    return result;
}