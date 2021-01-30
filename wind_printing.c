#include <math.h>
#include "wind_printing.h"

StringArray ConvertWindDirection(StringArray directions, int word_ending_type) {
    StringArray directions_str = CreateStringArray(directions.size);
    char word_ending_m[] = "ый";
    char word_ending_n[] = "ое";
    for (int i = 0; i < directions.size; ++i) {
        if (strcmp(directions.array[i], "С") == 0) {
            directions_str.array[i] = "северн";
        } else if (strcmp(directions.array[i], "Ю") == 0) {
            directions_str.array[i] = "южн";
        } else if (strcmp(directions.array[i], "З") == 0) {
            directions_str.array[i] = "западн";
        } else if (strcmp(directions.array[i], "В") == 0) {
            directions_str.array[i] = "восточн";
        } else if (strcmp(directions.array[i], "С-З") == 0) {
            directions_str.array[i] = "северо-западн";
        } else if (strcmp(directions.array[i], "С-В") == 0) {
            directions_str.array[i] = "северо-восточн";
        } else if (strcmp(directions.array[i], "Ю-З") == 0) {
            directions_str.array[i] = "юго-западн";
        } else if (strcmp(directions.array[i], "Ю-В") == 0) {
            directions_str.array[i] = "юго-восточн";
        }

        char* word_ending;
        if (word_ending_type == WORD_ENDING_MASCULINE) {
            word_ending = word_ending_m;
        } else if (word_ending_type == WORD_ENDING_NEUTER) {
            word_ending = word_ending_n;
        }
        int new_size = (strlen(directions_str.array[i]) + strlen(word_ending_m) + 1) * sizeof(char);
        char* concated = (char*) malloc(new_size); // +1 символ под \0
        memcpy(concated, directions_str.array[i], (strlen(directions_str.array[i])));
        strcat(concated, word_ending);
        directions_str.array[i] = concated;
    }
    return directions_str;
}

/* wind_dir_text должен содержать строки типа "восточный", а не сокращения */
void PrintWindDirection(FILE* output_file, StringArray wind_direction_text) {
    // если направление ветра задаётся одной буквой
    if (wind_direction_text.size == 1) {
        fprintf(output_file, "%s", wind_direction_text.array[0]); // "восточный "
    } else {
        for (int i = 0; i < wind_direction_text.size; ++i) { // "юго-восточный, юго-западный "
            fprintf(output_file, "%s", wind_direction_text.array[i]);
            if (i != wind_direction_text.size - 1) {
                fprintf(output_file, ", ");
            }
        }
    }
}

void PrintWindSpeedValue(FILE* output_file, int speed_min, int speed_max, int if_previous_day_exists) {
    // если есть предыдущий день, фраза "от 3 до 5 м/с" не подойдёт
    if (if_previous_day_exists == PREVIOUS_DAY_EXISTS) {
        fprintf(output_file, "%d", speed_min);
        if (speed_max != -1) {
            fprintf(output_file, "-%d", speed_max);
        }
    } else {
        switch (rand() % 2) {
            case 0: // "3-5 м/с"
                fprintf(output_file, "%d", speed_min);
                if (speed_max != -1) {
                    fprintf(output_file, "-%d", speed_max);
                }

                break;
            case 1: // "от 3 до 5 м/с"
                if (speed_max != -1) {
                    fprintf(output_file, "от %d до %d", speed_min, speed_max);
                } else {
                    fprintf(output_file, "до %d", speed_min);
                }
                break;
        }
    }
    fprintf(output_file, " м/с");
}

void PrintGustsValue(FILE* output_file, int min_val, int max_val, int if_previous_day_exists) {
    StringArray gusts_text;
    if (if_previous_day_exists == PREVIOUS_DAY_EXISTS) {
        gusts_text = WindGustsWithPrevDay();
    } else {
        gusts_text = WindGustsWithoutPrevDay();
    }
    int index = rand() % gusts_text.size;
    fprintf(output_file, "%s", gusts_text.array[index]);

    fprintf(output_file, "%d", min_val);
    if (max_val != -1) {
        fprintf(output_file, "-%d", max_val);
    }
    fprintf(output_file, " м/с. ");
}

/* комментарий в зависимости от средней скорости ветра */
void PrintWindComment(FILE* output_file, int average_speed) {
    if (average_speed == 0) {
        int index = rand() % CommentsWind0().size;
        fprintf(output_file, "%s ", CommentsWind0().array[index]);
    } else if (average_speed > 0 && average_speed <= 3) {
        int index = rand() % CommentsWind1to3().size;
        fprintf(output_file, "%s ", CommentsWind1to3().array[index]);
    } else if (average_speed > 3 && average_speed <= 5) {
        int index = rand() % CommentsWind3to5().size;
        fprintf(output_file, "%s ", CommentsWind3to5().array[index]);
    } else if (average_speed > 5 && average_speed <= 8) {
        int index = rand() % CommentsWind5to8().size;
        fprintf(output_file, "%s ", CommentsWind5to8().array[index]);
    } else if (average_speed > 8 && average_speed <= 14) {
        int index = rand() % CommentsWind8to14().size;
        fprintf(output_file, "%s ", CommentsWind8to14().array[index]);
    } else if (average_speed > 14 && average_speed <= 17) {
        int index = rand() % CommentsWind14to17().size;
        fprintf(output_file, "%s ", CommentsWind14to17().array[index]);
    } else if (average_speed > 17 && average_speed <= 20) {
        int index = rand() % CommentsWind17to20().size;
        fprintf(output_file, "%s ", CommentsWind17to20().array[index]);
    } else if (average_speed > 20 && average_speed <= 25) {
        int index = rand() % CommentsWind20to25().size;
        fprintf(output_file, "%s ", CommentsWind20to25().array[index]);
    } else if (average_speed > 25) {
        int index = rand() % CommentsWindMoreThan25().size;
        fprintf(output_file, "%s ", CommentsWindMoreThan25().array[index]);
    }
}

int GetAverageSpeed(const int min_speed, const int max_speed) {
    int average = 0;
    if (max_speed == -1) {
        average = min_speed;
    } else {
        average = round((min_speed + max_speed) / 2);
    }
    return average;
}

int GetSpeedDiff(int min_speed, int max_speed, int min_speed_prev_day, int max_speed_prev_day) {
    int average_speed = GetAverageSpeed(min_speed, max_speed);
    int average_speed_prev_day = GetAverageSpeed(min_speed_prev_day, max_speed_prev_day);
    int speed_diff = average_speed - average_speed_prev_day;
    return speed_diff;
}

void PrintWindSpeedChange(FILE* output_file, const WIND* wind, const WIND* previous_day_wind) {
    int speed_diff = GetSpeedDiff(wind->speed_min_val, wind->speed_max_val,
                                  previous_day_wind->speed_min_val, previous_day_wind->speed_max_val);
    if (abs(speed_diff) <= 1) {
        int index = rand() % WindSpeedNotChange().size;
        fprintf(output_file, "%s", WindSpeedNotChange().array[index]);
    } else if (abs(speed_diff) > 1 && abs(speed_diff) <= 10) {
        if (speed_diff > 0) {
            int index = rand() % WindIncreased().size;
            fprintf(output_file, "%s", WindIncreased().array[index]);
        } else {
            int index = rand() % WindDecreased().size;
            fprintf(output_file, "%s", WindDecreased().array[index]);
        }
        PrintWindSpeedValue(output_file, wind->speed_min_val, wind->speed_max_val, PREVIOUS_DAY_EXISTS);
        fprintf(output_file, ". ");
    } else if (abs(speed_diff) > 10) {
        if (speed_diff > 0) {
            int index = rand() % WindSpeedGreatlyIncreased().size;
            fprintf(output_file, "%s", WindSpeedGreatlyIncreased().array[index]);
        } else {
            int index = rand() % WindSpeedGreatlyDecreased().size;
            fprintf(output_file, "%s", WindSpeedGreatlyDecreased().array[index]);
        }
        PrintWindSpeedValue(output_file, wind->speed_min_val, wind->speed_max_val, PREVIOUS_DAY_EXISTS);
        fprintf(output_file, ". ");
    }
}

void PrintWindComparedWithPreviousDay(FILE* output_file, const WIND* wind, const WIND* previous_day_wind) {
    int speed_diff = GetSpeedDiff(wind->speed_min_val, wind->speed_max_val,
                                  previous_day_wind->speed_min_val, previous_day_wind->speed_max_val);
    // в половине случаев, если скорость ветра не изменилась, не будем писать про ветер совсем
    if (abs(speed_diff) <= 1 && rand() % 2 == 0) {
        return;
    }
    PrintWindSpeedChange(output_file, wind, previous_day_wind);

    if (wind->speed_min_val == 0 && wind->speed_max_val <= 0) {
        // порывов и направления нет
        return;
    }

    // о порывах, если они изменились в среднем
    int gusts_diff = GetSpeedDiff(wind->gusts_min_val, wind->gusts_max_val,
                                  previous_day_wind->gusts_min_val, previous_day_wind->gusts_max_val);
    if (abs(gusts_diff) > 1) {
        PrintGustsValue(output_file, wind->gusts_min_val, wind->gusts_max_val, PREVIOUS_DAY_EXISTS);
    }

    // если направление ветра не изменилось - не писать про него
    if (!AreStringArraysEqual(wind->direction, previous_day_wind->direction)) {
        int index = rand() % WindDirectionChange().size;
        fprintf(output_file, "%s", WindDirectionChange().array[index]);

        StringArray direction_with_ending = ConvertWindDirection(wind->direction, WORD_ENDING_NEUTER);
        PrintWindDirection(output_file, direction_with_ending);
        fprintf(output_file, ". ");
    }

    if (GetSpeedDiff(wind->speed_min_val, wind->speed_max_val,
                     previous_day_wind->speed_min_val, previous_day_wind->speed_max_val) != 0) {
        int average = GetAverageSpeed(wind->speed_min_val, wind->speed_max_val);
        PrintWindComment(output_file, average);
    }
}

void PrintWindWithoutComparing(FILE* output_file, const WIND* wind) {
    // если скорость = 0, то нет смысла писать про направление
    if (!(wind->speed_min_val == 0 && wind->speed_max_val <= 0)) {
        StringArray wind_direction_text;
        switch (rand() % 2) {
            case 0: // "Ветер восточный "
                fprintf(output_file, "Ветер ");
                wind_direction_text = ConvertWindDirection(wind->direction, WORD_ENDING_MASCULINE);
                PrintWindDirection(output_file, wind_direction_text);
                break;
            case 1: // "Направление ветра юго-западное, "
                fprintf(output_file, "Направление ветра ");
                wind_direction_text = ConvertWindDirection(wind->direction, WORD_ENDING_NEUTER);
                PrintWindDirection(output_file, wind_direction_text);
                break;
        }
        fprintf(output_file, " ");
        PrintWindSpeedValue(output_file, wind->speed_min_val, wind->speed_max_val, PREVIOUS_DAY_NOT_EXISTS);
        PrintGustsValue(output_file, wind->gusts_min_val, wind->gusts_max_val, PREVIOUS_DAY_NOT_EXISTS);
    }
    int average = GetAverageSpeed(wind->speed_min_val, wind->speed_max_val);
    PrintWindComment(output_file, average);
}

void PrintWind(FILE* output_file, WIND* wind, WIND* previous_day_wind) {
    if (previous_day_wind != NULL && rand() % 2 == 0) {
        PrintWindComparedWithPreviousDay(output_file, wind, previous_day_wind);
    } else {
        PrintWindWithoutComparing(output_file, wind);
    }
}