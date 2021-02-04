#include "print_felling_temperature.h"

void PrintFeelingTemperature(int min_feeling, int max_feeling, int day_min, int day_max, FILE * out){
    int feelling_temperature = (min_feeling + max_feeling) / 2;
    int average_day_temperature = (day_min + day_max) / 2;
    switch(rand()%6){
        case 0:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее: от %d до %d С. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее: от %d до %d C. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 1:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее: %dС. ", feelling_temperature);
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее: %dC. Учтите это, когда будете выбирать одежду. ", feelling_temperature);
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее: %dС. ", feelling_temperature);
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее: %dC. Учтите это, когда будете выбирать одежду. ", feelling_temperature);
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 2:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее. ");
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее. ");
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее. ");
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее. ");
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 3:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "По ощущениям немного теплее. ");
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "По ощущениям значительно теплее. Учтите это, когда будете выбирать одежду. ");
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "По ощущениям немного холоднее. ");
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "По ощущениям значительно холоднее. Учтите это, когда будете выбирать одежду. ");
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 4:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно теплее: от %d до %d С. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "Из-за прочих прогодных условий, по ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно холоднее: от %d до %d C. Учтите это, когда будете выбирать одежду. ", min_feeling, max_feeling);
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
        case 5:
            if (feelling_temperature > (average_day_temperature + 1) && feelling_temperature <= (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям немного теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature > (average_day_temperature + 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно теплее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 1) && feelling_temperature >= (average_day_temperature - 4))
                fprintf(out, "Из-за прочих прогодных условий, по ощущениям немного холоднее: от %d до %d С. ", min_feeling, max_feeling);
            else if (feelling_temperature < (average_day_temperature - 4))
                fprintf(out, "Из-за прочих погодных условий, по ощущениям значительно холоднее: от %d до %d C. ", min_feeling, max_feeling);
            else if (feelling_temperature <= (average_day_temperature + 1) && feelling_temperature >= (average_day_temperature - 1))
                fprintf(out, "Ощущается также. ");
            break;
    }
}
