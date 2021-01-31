#include "wind_constants.h"

StringArray CommentsWind0() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Безветренно. ";
    result.array[1] = "Штиль. ";
    result.array[2] = "Ветра не будет. ";
    return result;
}

StringArray CommentsWind1to3() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Ветер может быть заметен по относу дыма. ";
    result.array[1] = "";
    return result;
}

StringArray CommentsWind3to5() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Будут развеваться тонкие ветви деревьев и лёгкие флаги. ";
    result.array[1] = "";
    return result;
}

StringArray CommentsWind5to8() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Может подниматься пыль и мусор. ";
    result.array[1] = "";
    return result;
}

StringArray CommentsWind8to14() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "В общем, ветер довольно ощутимый. ";
    result.array[1] = "";
    return result;
}

StringArray CommentsWind14to17() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Идти против ветра будет трудно.";
    result.array[1] = "";
    return result;
}

StringArray CommentsWind17to20() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Ветер может ломать сучья деревьев, идти против ветра будет очень трудно. ";
    result.array[1] = "Ветер силён, сопротивление бесполезно. ";
    result.array[2] = "Не пользуйтесь зонтом, а то улетите. ";
    return result;
}

StringArray CommentsWind20to25() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Возможны небольшие повреждения, ветер может разрушать крыши зданий. ";
    result.array[1] = "Опасно с такую погоду выходить из дома. ";
    result.array[2] = "Будте уверены - вас сдует. ";
    return result;
}

StringArray CommentsWindMoreThan25() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Возможны значительные разрушения строений, ветер может вырывать деревья с корнем. ";
    result.array[1] = "Вероятны большие разрушения на значительном пространстве. ";
    result.array[2] = "Вероятны огромные разрушения, серьёзное повреждение зданий, строений и домов, деревья могут быть вырваны с корнями, растительность уничтожена. Случай крайне редкий. ";
    result.array[3] = "Лучше не выходите из дома. ";
    return result;
}

StringArray WindSpeedNotChange() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Скорость ветра прежняя. ";
    result.array[1] = "Средняя скорость ветра не изменится. ";
    result.array[2] = "Скорость ветра останется приблизительно на том же уровне. ";
    return result;
}

StringArray WindIncreased() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Ветер усилится до ";
    result.array[1] = "Скорость ветра увеличится до ";
    result.array[2] = "Ветер поднимется до ";
    return result;
}

StringArray WindDecreased() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Ветер ослабнет до ";
    result.array[1] = "Скорость ветра уменьшится до ";
    result.array[2] = "Ветер подуспокоится и будет дуть со скоростью ";
    return result;
}

StringArray WindSpeedGreatlyIncreased() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Ветер значительно усилится - до ";
    result.array[1] = "Скорость ветра увеличится до ";
    result.array[2] = "Ветер усилится и будет дуть со скоростью ";
    result.array[3] = "Ветер заметно усилится, скорость его составит ";
    return result;
}

StringArray WindSpeedGreatlyDecreased() {
    StringArray result = CreateStringArray(4);
    result.array[0] = "Ветер стихнет до ";
    result.array[1] = "Скорость ветра уменьшится до ";
    result.array[2] = "Ветер значительно ослабнет, его скорость составит ";
    result.array[3] = "Ветер успокоится до ";
    return result;
}

StringArray WindGustsWithoutPrevDay() {
    StringArray result = CreateStringArray(4);
    result.array[0] = " с порывами до ";
    result.array[1] = ", порывы могут достигать ";
    result.array[2] = ", порывы достигнут ";
    result.array[3] = ", могут быть порывы до ";
    return result;
}

StringArray WindGustsWithPrevDay() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Порывы могут достигать ";
    result.array[1] = "Порывы достигнут ";
    result.array[2] = "Могут быть порывы до ";
    return result;
}

StringArray WindDirectionChange() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Ветер сменит направление на ";
    result.array[1] = "Направление ветра сменится на ";
    return result;
}
