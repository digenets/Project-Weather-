#pragma once

#include "base.h"

StringArray comments_wind_0() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Безветрие, дым поднимается вертикально, листья деревьев неподвижны.";
    result.array[1] = "Штиль.";
    result.array[2] = "Ветра не будет.";
    return result;
}

StringArray comments_wind_1_3() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Направление ветра заметно по относу дыма.";
    result.array[1] = "Движение ветра ощущается лицом, шелестят листья, приводится в движение флюгер.";
    return result;
}

StringArray comments_wind_3_5() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Листья и тонкие ветви деревьев всё время колышутся, ветер развевает лёгкие флаги.";
    return result;
}

StringArray comments_wind_5_8() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Ветер поднимает пыль и мусор, приводит в движение тонкие ветви деревьев.";
    return result;
}

StringArray comments_wind_8_14() {
    StringArray result = CreateStringArray(2);
    result.array[0] = "Качаются тонкие стволы деревьев, движение ветра ощущается рукой.";
    result.array[1] = "Качаются толстые сучья деревьев, гудят телеграфные провода.";
    return result;
}

StringArray comments_wind_14_17() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Гнутся стволы деревьев, трудно идти против ветра.";
    return result;
}

StringArray comments_wind_17_20() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Ветер ломает сучья деревьев, идти против ветра очень трудно.";
    return result;
}

StringArray comments_wind_20_25() {
    StringArray result = CreateStringArray(1);
    result.array[0] = "Небольшие повреждения, ветер начинает разрушать крыши зданий.";
    return result;
}

StringArray comments_wind_more_than_25() {
    StringArray result = CreateStringArray(3);
    result.array[0] = "Значительные разрушения строений, ветер вырывает деревья с корнем.";
    result.array[1] = "Большие разрушения на значительном пространстве.";
    result.array[2] = "Огромные разрушения, серьёзно повреждены здания, строения и дома, деревья вырваны с корнями, растительность уничтожена. Случай крайне редкий.";
    return result;
}
