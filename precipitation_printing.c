#include "precipitation_printing.h"
#include "precipitation_constants.h"

void PrintPrecipitation(FILE* output_file, char* precipitation, char* prev_day_precipitation) {
    // если есть данные за предыдущий день - можно сказать о повторяющихся осадках
    if (prev_day_precipitation != NULL && strcmp(precipitation, prev_day_precipitation) == 0) {
        // осадки такие же, как в предыдущий день
        StringArray comments;
        if (strcmp(precipitation, NO_PRECIPITATION) == 0) {
            comments = CommentsNoPrecipitationAgain();
        } else if (strcmp(precipitation, SNOW) == 0) {
            comments = CommentsSnowAgain();
        } else if (strcmp(precipitation, RAIN) == 0) {
            comments = CommentsRainAgain();
        } else if (strcmp(precipitation, SNOW_WITH_RAIN) == 0) {
            comments = CommentsSnowWithRainAgain();
        } else if (strcmp(precipitation, HAIL) == 0) {
            comments = CommentsHailAgain();
        } else {
            fprintf(output_file, "Осадки сохранятся. ");
            return;
        }
        int index = rand() % comments.size;
        fprintf(output_file, "%s", comments.array[index]);
    } else {
        if (strcmp(precipitation, "-") == 0) {
            int index = rand() % CommentsNoPrecipitation().size;
            fprintf(output_file, "%s", CommentsNoPrecipitation().array[index]);
        } else if (strcmp(precipitation, SNOW) == 0) {
                int index = rand() % CommentsSnow().size;
                fprintf(output_file, "%s", CommentsSnow().array[index]);
        } else if (strcmp(precipitation, RAIN) == 0) {
                int index = rand() % CommentsRain().size;
                fprintf(output_file, "%s", CommentsRain().array[index]);
        } else if (strcmp(precipitation, SNOW_WITH_RAIN) == 0) {
                int index = rand() % CommentsSnowWithRain().size;
                fprintf(output_file, "%s", CommentsSnowWithRain().array[index]);
        } else if (strcmp(precipitation, HAIL) == 0) {
                int index = rand() % CommentsHail().size;
                fprintf(output_file, "%s", CommentsHail().array[index]);
        } else {
            fprintf(output_file, "Ожидается %s. ", precipitation);
        }
    }
}