#include "print_feeling_temperature.h"

void PrintFeelingTemperature(int min_feeling, int max_feeling, int day_min, int day_max, FILE * out) {
    int feeling_temperature = (min_feeling + max_feeling) / 2;
    int average_day_temperature = (day_min + day_max) / 2;
    switch(rand()%6){
        case 0:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее: от %d до %d С. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее: от %d до %d C. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 1:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее: %dС. ", feeling_temperature);
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее: %dC. Учтите это, когда будете выбирать одежду. ", feeling_temperature);
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее: %dС. ", feeling_temperature);
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее: %dC. Учтите это, когда будете выбирать одежду. ", feeling_temperature);
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 2:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее. ");
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее. ");
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее. ");
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее. ");
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 3:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее. ");
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее. Учтите это, когда будете выбирать одежду. ");
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее. ");
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее. Учтите это, когда будете выбирать одежду. ");
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 4:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно теплее: от %d до %d С. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "Из-за прочих прогодных условий, по ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно холоднее: от %d до %d C. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 5:
            if (feeling_temperature > (average_day_temperature + 1) && feeling_temperature <= (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature > (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 1) && feeling_temperature >= (average_day_temperature - 4))
                fprintf(out, "Из-за прочих прогодных условий, по ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feeling_temperature < (average_day_temperature - 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно холоднее: от %d до %d C. ", min_feeling, max_feeling);
            else if (feeling_temperature <= (average_day_temperature + 1) && feeling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
    }
}