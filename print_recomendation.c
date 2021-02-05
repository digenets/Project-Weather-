#include "print_recomendation.h"
#include "wind_printing.h"

#define SIZE 1000

void PrintRecommendation(WEATHER * weather, FILE * out) {
    char introductory[SIZE] = {"Вследствии этого, "},
            introductory1[SIZE] = {"Так как прогноз погоды показывает "},
            introductory2[SIZE] = {"Поэтому, "},
            introductory3[SIZE] = {"Вероятнее всего, "},
            introductory4[SIZE] = {"В общем, "};

    char recom[SIZE] = {"хотим вам порекомендовать эти вещи:"},
            recom1[SIZE] = {"мы рекомендуем вам надеть это:"},
            recom2[SIZE] = {"можете надеть:"},
            recom3[SIZE] = {"предоставим вам эти вещи на выход:"};


    char very_cold[SIZE] = {"подумайте, а стоит ли завтра выходить на улицу?"},
            very_cold1[SIZE] = {"советуем вам остаться дома"},
            very_cold2[SIZE] = {"мы крайне не рекомендуем выходить на улицу в такую погоду"},
            very_cold3[SIZE] = {"в такую погоду свои дома сидят"};

    char very_coldwinterhat[SIZE] = {"на голову возьмите шапку с мехом"},
            very_coldwinterhat1[SIZE] = {"на голову наденьте шапку-ушанку"},
            very_coldwinterhat2[SIZE] = {"без теплой шапки вам делать нечего"};

    char very_coldgloves[SIZE] = {"вязанные перчатки"},
            very_coldgloves1[SIZE] = {"варежки"},
            very_coldgloves2[SIZE] = {"утепленные перчатки"};

    char very_coldboots[SIZE] = {"валенки"},
            very_coldboots1[SIZE] = {"теплые ботинки"};

    char very_coldclothes[SIZE] = {"и пуховик"},
            very_coldclothes1[SIZE] = {"зимнюю куртку"};


    char coolwinterhat[SIZE] = "накиньте капюшон и кепку",
            coolwinterhat1[SIZE] = "используйте капюшон куртки и легкий шарф",
            coolwinterhat2[SIZE] = "беретку";

    char coolclothes[SIZE] = "куртку с джинсами",
            coolclothes1[SIZE] = "жилетку",
            coolclothes2[SIZE] = "кожаная куртка";

    char coolboots[SIZE] = "ботинки",
            coolboots1[SIZE] = "ботинки",
            coolboots2[SIZE] = "кроссовки";

/* char coolspecial [SIZE]       = ", вместо капюшона возмите зонт или дождевик.",
     coolspecial1 [SIZE]      = ", дождевик.",
     coolspecial2 [SIZE]      = ", зонт.";
*/


    char cloudywinterhat[SIZE] = {"шапку"},
            cloudywinterhat1[SIZE] = {"теплый головной убор"},
            cloudywinterhat2[SIZE] = {"на голову возьмите беретку с шарфом"};

    char cloudyclothes[SIZE] = {"пальто"},
            cloudyclothes1[SIZE] = {"теплую куртку"};

    char cloudyboots[SIZE] = {"ботинки"},
            cloudyboots1[SIZE] = {"осенне-весенние ботинки"};

    char cloudygloves1[SIZE] = {"кожаные перчатки"},
            cloudygloves2[SIZE] = {"теплые перчатки"};


    char warmcap[SIZE] = {"можете взять шарфик"},
            warmcap1[SIZE] = {"кепку"},
            warmcap2[SIZE] = {"повязку"};


    char warmclothes[SIZE] = {"футболку с джинсами"},
            warmclothes1[SIZE] = {"и ветровку"},
            warmclothes2[SIZE] = {"и шорты"};


    char warmboots[SIZE] = {"кеды"},
            warmboots1[SIZE] = {"кроссовки"},
            warmboots2[SIZE] = {"сандалии"};


    int koef_t = 0;
    int koef_s = 0;
    int koef_g = 0;

    int average_temperature = (weather->day_temp.min_val + weather->day_temp.max_val) / 2;
    int average_speed = GetAverageSpeed(weather->wind.speed_min_val, weather->wind.speed_max_val);

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
    }

    if (average_temperature < -30)
        koef_t = 0;
    else if ((average_temperature >= -30) && (average_temperature < -15))
        koef_t = 2;
    else if ((average_temperature >= -15) && (average_temperature < 0))
        koef_t = 4;
    else if ((average_temperature >= 0) && (average_temperature < 15))
        koef_t = 6;
    else if ((average_temperature >= 15) && (average_temperature < 25))
        koef_t = 8;
    else if (average_temperature >= 25)
        koef_t = 10;

    if (average_speed >= 25)
        koef_s = 0;
    else if ((average_speed < 25) && (average_speed >= 20))
        koef_s = 1;
    else if ((average_speed < 20) && (average_speed >= 15))
        koef_s = 2;
    else if ((average_speed < 15) && (average_speed >= 10))
        koef_s = 3;
    else if ((average_speed < 10) && (average_speed >= 5))
        koef_s = 4;
    else if (average_speed < 5)
        koef_s = 5;

    koef_g = koef_s + koef_t;

    // сли совсем плохая погода - советуем остаться дома
    // верхняя одежда и ботинки clothes - boots
    if ((koef_t == 0) || (koef_s == 0) || (koef_t == 10) || (koef_g <= 4)) {
        switch (rand() % 4) { // stay home
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
    else {
        switch (rand() % 4) {
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
        }
        fprintf(out, " ");

        if (koef_g == 5) {
            switch (rand() % 4) { //  оч холодно но жить можно
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
            fprintf(out, ", ");

            switch (rand() % 4) { //  оч холодно но жить можно
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
            fprintf(out, ", ");

            switch (rand() % 2) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldboots);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldboots1);
                    break;
            }
            fprintf(out, ", ");

            switch (rand() % 2) { //  оч холодно но жить можно
                case 0:
                    fprintf(out, "%s", very_coldclothes);
                    break;
                case 1:
                    fprintf(out, "%s", very_coldclothes1);
                    break;
            }
            fprintf(out, ". ");


        } else if (koef_g == 6 || koef_g == 7 || koef_g == 8) {
            switch (rand() % 3) { //  просто холодно
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
            fprintf(out, ", ");

            switch (rand() % 2) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudygloves1);
                    break;
                case 1:
                    fprintf(out, "%s", cloudygloves2);
                    break;
            }
            fprintf(out, ", ");

            switch (rand() % 2) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudyboots);
                    break;
                case 1:
                    fprintf(out, "%s", cloudyboots1);
                    break;
            }
            fprintf(out, ", ");

            switch (rand() % 2) { //  просто холодно
                case 0:
                    fprintf(out, "%s", cloudyclothes);
                    break;
                case 1:
                    fprintf(out, "%s", cloudyclothes1);
                    break;
            }
            fprintf(out, ". ");

        } else if ((koef_g == 9) || (koef_g == 10) || (koef_g == 11)) {
            switch (rand() % 3) { //  просто холодно
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
            fprintf(out, ", ");

            switch (rand() % 3) { //  просто холодно
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
            fprintf(out, ", ");

            switch (rand() % 3) { //  просто холодно
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
            fprintf(out, ". ");


        } else if (koef_g >= 12) {
            switch (rand() % 3) { //  warm yeah
                case 0:
                    fprintf(out, "%s", warmcap);
                    break;
                case 1:
                    fprintf(out, "%s", warmcap1);
                    break;
                case 2:
                    fprintf(out, "%s", warmcap2);
                    break;
            }
            fprintf(out, ", ");

            switch (rand() % 3) {
                case 0:
                    fprintf(out, "%s", warmclothes);
                    break;
                case 1:
                    fprintf(out, "%s", warmclothes1);
                    break;
                case 2:
                    fprintf(out, "%s", warmclothes2);
                    break;
            }
            fprintf(out, ", ");

            switch (rand() % 3) {
                case 0:
                    fprintf(out, "%s", warmboots);
                    break;
                case 1:
                    fprintf(out, "%s", warmboots1);
                    break;
                case 2:
                    fprintf(out, "%s", warmboots2);
                    break;
            }
            fprintf(out, ". ");
        }
    }
}