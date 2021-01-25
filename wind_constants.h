#pragma once

#include "base.h"

StringArray CommentsWind0() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Безветрие.";
    result.array[1] = "Штиль.";
    result.array[2] = "Ветра не будет.";
    return result;
}

StringArray CommentsWind1to3() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Направление ветра может быть заметно по относу дыма.";
    result.array[1] = "Движение ветра ощущается лицом, шелестят листья, приводится в движение флюгер."; // todo не подходит для зимы, перефразировать
    return result;
}

StringArray CommentsWind3to5() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Листья и тонкие ветви деревьев всё время колышутся, ветер развевает лёгкие флаги."; // todo перефразировать
    return result;
}

StringArray CommentsWind5to8() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Ветер поднимает пыль и мусор, приводит в движение тонкие ветви деревьев."; // todo перефразировать
    return result;
}

StringArray CommentsWind8to14() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Качаются тонкие стволы деревьев, движение ветра ощущается рукой.";
    result.array[1] = "Качаются толстые сучья деревьев, гудят телеграфные провода.";
    return result;
}

StringArray CommentsWind14to17() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Идти против ветра будет трудно.";
    return result;
}

StringArray CommentsWind17to20() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Ветер может ломать сучья деревьев, идти против ветра будет очень трудно.";
    return result;
}

StringArray CommentsWind20to25() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Возможны небольшие повреждения, ветер может разрушать крыши зданий.";
    return result;
}

StringArray CommentsWindMoreThan25() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Возможны значительные разрушения строений, ветер может вырывать деревья с корнем.";
    result.array[1] = "Вероятны большие разрушения на значительном пространстве.";
    result.array[2] = "Вероятны огромные разрушения, серьёзное повреждение зданий, строений и домов, деревья могут быть вырваны с корнями, растительность уничтожена. Случай крайне редкий.";
    return result;
}
