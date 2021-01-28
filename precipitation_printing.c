#include "precipitation_printing.h"
#include "precipitation_constants.h"

void PrintPrecipitation(FILE *output_file, WEATHER* weather) {
    if (strcmp(weather->precipitation, "-") == 0) {
        int index = rand() % CommentsNoPrecipitation().size;
        fprintf(output_file, "%s ", CommentsNoPrecipitation().array[index]);
    } else {
        if (strcmp(weather->precipitation, SNOW) == 0) {
            int index = rand() % CommentsSnow().size;
            fprintf(output_file, "%s ", CommentsSnow().array[index]);
        } else if (strcmp(weather->precipitation, RAIN) == 0) {
            int index = rand() % CommentsRain().size;
            fprintf(output_file, "%s ", CommentsRain().array[index]);
        } else if (strcmp(weather->precipitation, HAIL) == 0) {
            int index = rand() % CommentsHail().size;
            fprintf(output_file, "%s ", CommentsHail().array[index]);
        } else if (strcmp(weather->precipitation, THUNDER) == 0) {
            int index = rand() % CommentsThunder().size;
            fprintf(output_file, "%s ", CommentsThunder().array[index]);
        } else {
            fprintf(output_file, "Ожидается %s. ", weather->precipitation);
        }
    }
    fprintf(output_file, "\n");
}