#include "precipitation_constants.h"

StringArray CommentsNoPrecipitation() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Осадки маловероятны.";
    result.array[1] = "Без осадков.";
    result.array[2] = "Осадков не ожидается.";
    return result;
}

StringArray CommentsRain() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Пройдут дожди.";
    result.array[1] = "Кратковременные дожди.";
    return result;
}

StringArray CommentsSnow() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Пройдёт снег.";
    result.array[1] = "Ожидается снегопад.";
    result.array[2] = "Снег.";
    return result;
}

StringArray CommentsThunder() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Пройдут грозы.";
    result.array[1] = "Возможна гроза.";
    return result;
}

StringArray CommentsHail() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Град.";
    return result;
}

