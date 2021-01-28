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

void PrintWindDirection(FILE* output_file, StringArray wind_dir_text) {
    // если направление ветра задаётся одной буквой
    if (wind_dir_text.size == 1) {
        fprintf(output_file, "%s ", wind_dir_text.array[0]); // "восточный "
    } else {
        for (int i = 0; i < wind_dir_text.size; ++i) { // "юго-восточный, юго-западный "
            fprintf(output_file, "%s", wind_dir_text.array[i]);
            if (i == wind_dir_text.size - 1) {
                fprintf(output_file, " ");
            } else {
                fprintf(output_file, ", ");
            }
        }
    }
}

void PrintWindSpeed(FILE* output_file, int speed_min, int speed_max) {
    switch (rand() % 2) {
        case 0: // "3-5 м/с"
            fprintf(output_file, "%d", speed_min);
            if (speed_max != -1) {
                fprintf(output_file, "-%d", speed_max);
            }

            break;
        case 1: // "от 3 до 5 м/с"
            fprintf(output_file, "от %d ", speed_min);
            if (speed_max != -1) {
                fprintf(output_file, "до %d", speed_max);
            }
            break;
    }
    fprintf(output_file, " м/с");
}

void PrintGusts(FILE* output_file, int min_val, int max_val) {
    switch (rand() % 2) {
        case 0:
            fprintf(output_file, " с порывами до ");
            break;
        case 1:
            fprintf(output_file, ", порывы могут достигать ");
            break;
    }
    fprintf(output_file, "%d", min_val);
    if (max_val != -1) {
        fprintf(output_file, "-%d", max_val);
    }
    fprintf(output_file, " м/с. ");
}

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
    fprintf(output_file, "\n");
}

int WindAverage(const WIND *wind) {
    int average = 0;
    if (wind->speed_max_val == -1) {
        average = wind->speed_min_val;
    } else {
        average = round((wind->speed_min_val + wind->speed_max_val) / 2);
    }
    return average;
}

void PrintWind(FILE* output_file, WIND* wind, WIND* previous_day_wind) {
    // если ветер есть
    if (wind->speed_min_val != 0) {
        StringArray wind_dir_text;

        if (previous_day_wind != NULL && rand() % 2 == 0) { // в половине случаев
            int diff = WindAverage(wind) - WindAverage(previous_day_wind);
            if (abs(diff) <= 1) {
                // ветер не изменится
            } else if (abs(diff) > 1 && abs(diff) <= 10) {
                // ветер усилится/ослабнет
            } else if (abs(diff) > 10) {
                // ветер значительно изменится
            }

            print_wind_speed();

            // то же с направлением
            if (wind->direction == previous_day_wind->direction) {
                // не писать или сказать, что не изменится
            } else {
                // направление сменится на ...
            }
        } else {
            // варианты фраз про направление ветра
            switch (rand() % 2) {
                case 0: // "Ветер восточный "
                    fprintf(output_file, "Ветер ");
                    wind_dir_text = ConvertWindDirection(wind.direction, WORD_ENDING_MASCULINE);
                    PrintWindDirection(output_file, wind_dir_text);
                    break;
                case 1: // "Направление ветра юго-западное, "
                    fprintf(output_file, "Направление ветра ");
                    wind_dir_text = ConvertWindDirection(wind.direction, WORD_ENDING_NEUTER);
                    PrintWindDirection(output_file, wind_dir_text);
                    break;
            }

            PrintWindSpeed(output_file, wind->speed_min_val, wind->speed_max_val);
            PrintGusts(output_file, wind->gusts_min_val, wind->gusts_max_val);
        }

        // комментарий в зависимости от средней скорости ветра
        int average = WindAverage(wind);
        PrintWindComment(output_file, average);








        if (previous_day_wind != NULL
                && abs(WindAverage(wind) - WindAverage(previous_day_wind)) > 10 // todo: магическое число
                && rand() % 2 == 0) { // чтобы выполнялось в половине случаев
            switch (rand() % 2) {
                case 0: // "Ветер значительно усилится и составит "
                    fprintf(output_file, "Ветер значительно усилится и составит ");
                    wind_dir_text = ConvertWindDirection(wind->direction, WORD_ENDING_MASCULINE);
                    PrintWindDirection(output_file, wind_dir_text);
                    break;
                case 1: // "Направление ветра юго-западное, "
                    fprintf(output_file, "Направление ветра ");
                    break;
            }
            // todo: после написать, что направление ветра сменится на такое-то, или если не сменится - не писать
        } else {
            // варианты фраз про направление ветра
            switch (rand() % 2) {
                case 0: // "Ветер восточный "
                    fprintf(output_file, "Ветер ");
                    wind_dir_text = ConvertWindDirection(wind.direction, WORD_ENDING_MASCULINE);
                    PrintWindDirection(output_file, wind_dir_text);
                    break;
                case 1: // "Направление ветра юго-западное, "
                    fprintf(output_file, "Направление ветра ");
                    wind_dir_text = ConvertWindDirection(wind.direction, WORD_ENDING_NEUTER);
                    PrintWindDirection(output_file, wind_dir_text);
                    break;
            }
        }

        PrintWindSpeed(output_file, wind->speed_min_val, wind->speed_max_val);
        PrintGusts(output_file, wind->gusts_min_val, wind->gusts_max_val);
    }

    // комментарий в зависимости от средней скорости ветра
    int average = WindAverage(wind);
    PrintWindComment(output_file, average);
}