#include "precipitation_constants.h"

StringArray CommentsNoPrecipitation() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Осадки маловероятны. ";
    result.array[1] = "Без осадков. ";
    result.array[2] = "Осадков не ожидается. ";
    return result;
}

StringArray CommentsNoPrecipitationAgain() {
    StringArray result = CreateStringArray(5);
    result.array[0] = "";
    result.array[1] = "Снова без осадков. ";
    result.array[2] = "По прежнему без осадков. ";
    result.array[3] = "Осадков по прежнему не ожидается. ";
    result.array[4] = "Осадков всё ещё не ожидается. ";
    return result;
}

StringArray CommentsRain() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Пройдут дожди. ";
    result.array[1] = "Кратковременные дожди. ";
    result.array[2] = "Ожидается дождь. ";
    return result;
}

StringArray CommentsRainAgain() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Снова прольются дожди. ";
    result.array[1] = "Дожди не прекратятся. ";
    result.array[2] = "Осадки не прекратятся. ";
    result.array[3] = "Дождливая погода сохранится. ";
    return result;
}

StringArray CommentsSnow() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Пройдёт снег. ";
    result.array[1] = "Ожидается снегопад. ";
    result.array[2] = "Снег. ";
    return result;
}

StringArray CommentsSnowAgain() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Снегопад продолжится. ";
    result.array[1] = "Опять снегу наметёт. ";
    result.array[2] = "Снег не закончится. ";
    result.array[3] = "Снежная погода сохранится. ";
    return result;
}

StringArray CommentsSnowWithRain() {
    StringArray result = CreateStringArray(5);
    result.array[0] = "Ожидается снег с дождём. ";
    result.array[1] = "Ожидается ненастная погода с дождем и снегом. ";
    result.array[2] = "Местами пройдёт снег с дождём. ";
    result.array[3] = "Отвратительная погода со снегом и дождём. ";
    result.array[4] = "Дождь, снег, слякоть. ";

    return result;
}

StringArray CommentsSnowWithRainAgain() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Снег с дождём не закончится. ";
    result.array[1] = "Осадки не прекратятся. ";
    result.array[2] = "Снова снег с дождём. ";
    return result;
}

StringArray CommentsHail() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Град. ";
    result.array[1] = "Вероятен град. Будьте осторожны. ";
    result.array[2] = "Местами возможен град. ";
    result.array[3] = "Прогнозируется град. ";
    return result;
}

StringArray CommentsHailAgain() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "И снова град. ";
    result.array[1] = "Град не прекратится. ";
    result.array[2] = "Град не закончится. ";
    return result;
}
