#include "print_recomendation.h"

#define SIZE 1000

void PrintRecomendation(WEATHER * weather, FILE * out) {
    int koef_t = 0;
    int koef_s = 0;
    int koef_g = 0;

    int average_temperature = (weather->day_temp.min_val + weather->day_temp.max_val)/2;
    int average_speed = (weather->wind.speed_min_val + weather->wind.speed_max_val)/2;


    switch (rand() % 5) {
        case 0:
            fprintf(out, "%s", introductory);
            break;
        case 1:
            fprintf(out, "%s", introductory1);
            break;
        case 2:
            fprintf(out, "%s", introductory2);
            break;
        case 3:
            fprintf(out, "%s", introductory3);
            break;
        case 4:
            fprintf(out, "%s", introductory4);
            break;
        case 5:
            fprintf(out, "%s", introductory5);
            break;
    }
    switch (rand()%5){
        case 0:
            fprintf(out, "%s", recom);
            break;
        case 1:
            fprintf(out, "%s", recom1);
            break;
        case 2:
            fprintf(out, "%s", recom2);
            break;
        case 3:
            fprintf(out, "%s", recom3);
            break;
        case 4:
            fprintf(out, "%s", recom4);
            break;
    }

    if (average_temperature < -30)
        koef_t = 0;
    else if (average_temperature >= -30 && average_temperature < -15)
        koef_t = 1;
    else if (average_temperature >= -15 && average_temperature < 0)
        koef_t = 2;
    else if (average_temperature >=0 && average_temperature <15)
        koef_t = 3;
    else if (average_temperature >= 15 && average_temperature < 25)
        koef_t = 4;
    else if (average_temperature >= 25)
        koef_t =5;
    if (average_speed >= 25)
        koef_s = 0;
    else if (average_speed < 25 && average_speed >= 20)
        koef_s = 1;
    else if (average_speed < 20 && average_speed >= 15)
        koef_s = 2;
    else if (average_speed < 15 && average_speed >= 10)
        koef_s = 3;
    else if (average_speed < 10 && average_speed >= 5)
        koef_s = 4;
    else if (average_speed < 5)
        koef_s =5;
    koef_g = koef_s + koef_t;
    if (koef_t == 0 || koef_s == 0 || koef_t == 5 || koef_g <=2){
        switch(rand()%4){ // stay home
            case 0:
                fprintf(out, "%s", very_cold);
                break;
            case 1:
                fprintf(out, "%s", very_cold1);
                break;
            case 2:
                fprintf(out, "%s", very_cold2);
                break;
            case 3:
                fprintf(out, "%s", very_cold3);
                break;
        }
    }// верхняя одежда и ботинки clothes - boots
    else{
        if (koef_g == 3){
            switch(rand()%4) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldwinterhat);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldwinterhat1);
                    break;
                case 2:
                    fprintf(out, "%s", very_coldwinterhat2);
                    break;
                case 3:
                    break;
            }
            switch(rand()%4) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldgloves);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldgloves1);
                    break;
                case 2:
                    fprintf(out, "%s", very_coldgloves2);
                    break;
                case 3:
                    break;
            }
            switch(rand()%2) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldboots);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldboots1);
                    break;
            }
            switch(rand()%2) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldclothes);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldclothes1);
                    break;
            }
        }
        if (koef_g == 4 || koef_g == 5 || koef_g == 6){
            switch(rand()%3) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudywinterhat);
                    break;
                case 1:
                    fprintf(out, "%s", cloudywinterhat1);
                    break;
                case 2:
                    fprintf(out, "%s", cloudywinterhat2);
                    break;
            }
            switch(rand()%2) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudygloves1);
                    break;
                case 1:
                    fprintf(out, "%s", cloudygloves2);
                    break;
            }
            switch(rand()%2) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudyboots);
                    break;
                case 1:
                    fprintf(out, "%s", cloudyboots1);
                    break;
            }
            switch(rand()%2){ //  просто холодно
                case 0:
                    fprintf(out, "%s",  cloudyclothes);
                    break;
                case 1:
                    fprintf(out, "%s",  cloudyclothes1);
                    break;
            }
        if (koef_g == 7){
            switch(rand()%3){ //  просто холодно
                case 0:
                    fprintf(out, "%s", coolwinterhat);
                    break;
                case 1:
                    fprintf(out, "%s", coolwinterhat1);
                    break;
                case 2:
                    fprintf(out, "%s", coolwinterhat2);
                    break;
            }
            switch(rand()%3) { //  просто холодно
                case 0:
                    fprintf(out, "%s", coolboots);
                    break;
                case 1:
                    fprintf(out, "%s", coolboots1);
                    break;
                case 2:
                    fprintf(out, "%s", coolboots2);
                    break;
            }
            switch(rand()%3) { //  просто холодно
                case 0:
                    fprintf(out, "%s", coolclothes);
                    break;
                case 1:
                    fprintf(out, "%s", coolclothes1);
                    break;
                case 2:
                    fprintf(out, "%s", coolclothes2);
                    break;
            }

            }
        if (koef_g >= 8){
        }
        }
    }
}