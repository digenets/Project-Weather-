#ifndef PROJECT_WEATHER__WIND_CONSTANTS_H
#define PROJECT_WEATHER__WIND_CONSTANTS_H

#include "base.h"

#define WORD_ENDING_MASCULINE 0
#define WORD_ENDING_NEUTER 1

#define PREVIOUS_DAY_EXISTS 2
#define PREVIOUS_DAY_NOT_EXISTS 3

StringArray CommentsWind0();
StringArray CommentsWind1to3();
StringArray CommentsWind3to5();
StringArray CommentsWind5to8();
StringArray CommentsWind8to14();
StringArray CommentsWind14to17();
StringArray CommentsWind17to20();
StringArray CommentsWind20to25();
StringArray CommentsWindMoreThan25();

StringArray WindSpeedNotChange();
StringArray WindIncreased();
StringArray WindDecreased();
StringArray WindSpeedGreatlyIncreased();
StringArray WindSpeedGreatlyDecreased();

StringArray WindGustsWithoutPrevDay();
StringArray WindGustsWithPrevDay();

StringArray WindDirectionChange();

#endif //PROJECT_WEATHER__WIND_CONSTANTS_H
