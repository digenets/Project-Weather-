#include "earth_phenom_printing.h"
#include "earth_phenom_constants.h"

void PrintEarthPhenomena(FILE* output_file, StringArray earth_phenomena) {
    for (int i = 0; i < earth_phenomena.size; ++i) {
        StringArray comments;
        if (strcmp(earth_phenomena.array[i], NO_EARTH_PHENOMENA) == 0) {
            continue;
        } else if (strcmp(earth_phenomena.array[i], THUNDER) == 0) {
            comments = CommentsThunder();
        } else if (strcmp(earth_phenomena.array[i], FOG) == 0) {
            comments = CommentsFog();
        } else if (strcmp(earth_phenomena.array[i], ICE_COVERING) == 0) {
            comments = CommentsIceCovering();
        } else {
            fprintf(output_file, "Также, будет %s. ", earth_phenomena.array[i]);
            continue;
        }

        int index = rand() % comments.size;
        fprintf(output_file, "%s", comments.array[index]);
    }
}
