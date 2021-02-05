#ifndef PROJECT_WEATHER__PRINT_RECOMENDATION_H
#define PROJECT_WEATHER__PRINT_RECOMENDATION_H
#include <stdio.h>
#include <string.h>
#include "weather.h"

#define SIZE 150

void PrintRecomendation(WEATHER * weather, FILE * out);

char introductory[SIZE]       = {"Вследствии того, что "},
     introductory1[SIZE]      = {"Так как прогноз погоды показывает "},
     introductory2[SIZE]      = {"Поэтому "},
     introductory3[SIZE]      = {"Вероятнее всего "},
     introductory4[SIZE]      = {"Оказывается"},
     introductory5[SIZE]      = {"В общем"};

char recom[SIZE]              = {"хотим вам порекомендовать эти вещи:"},
     recom1[SIZE]             = {"мы рекомендуем вам надеть это:"},
     recom2[SIZE]             = {"рекомендуем вам одется потеплее"},
     recom3[SIZE]             = {"можете надеть:"},
     recom4[SIZE]             = {"предоставим вам эти вещи на выход:"};



char very_cold [SIZE]         = {"Подумайте, а стоит ли завтра выходить на улицу?"},
     very_cold1[SIZE]         = {"Советуем вам остаться дома"},
     very_cold2[SIZE]         = {"Мы крайне не рекомендуем выходить на улицу в такую погоду"},
     very_cold3[SIZE]         = {"в такую погоду свои дома сидят"};

char very_coldwinterhat [SIZE]= {" на голову возьмите шапку с мехом"},
     very_coldwinterhat1[SIZE]= {" на голову наденьте шапку-ушанку"},
     very_coldwinterhat2[SIZE]= {"без теплой шапки вам делать нечего"};

char very_coldgloves [SIZE]   = {"вязанные перчатки"},
     very_coldgloves1[SIZE]   = {"варежке"},
     very_coldgloves2[SIZE]   = {"утепленные перчатки"};

char very_coldboots [SIZE]    = {", валенки"},
     very_coldboots1[SIZE]    = {", теплые ботинки"};

char very_coldclothes [SIZE]  = {"и пуховик"},
     very_coldclothes1[SIZE]  = {"зимнюю куртку"};



char coolwinterhat [SIZE]     = " накинте капюшон и кепку",
     coolwinterhat1 [SIZE]    = " используйте капюшон куртки и легкий шарф",
     coolwinterhat2 [SIZE]    = " беретку";

char coolclothes [SIZE]       = ", куртку с джинсами",
     coolclothes1 [SIZE]       = ", жилетку",
     coolclothes2 [SIZE]       = ", кожаная куртка";

char coolboots [SIZE]         = ", ботинки",
     coolboots1 [SIZE]        = ", ботинки.",
     coolboots2 [SIZE]        = ", кроссовки.";

/* char coolspecial [SIZE]       = ", вместо капюшона возмите зонт или дождевик.",
     coolspecial1 [SIZE]      = ", дождевик.",
     coolspecial2 [SIZE]      = ", зонт.";
*/


char cloudywinterhat [SIZE]   = {"шапку, а также"},
     cloudywinterhat1 [SIZE]  = {"теплый головной убор"},
     cloudywinterhat2 [SIZE]  = {" на голову возьмите беретку с шарфом"};

char cloudyclothes [SIZE]     = {"пальто."},
     cloudyclothes1 [SIZE]    = {"теплую куртку."};

char cloudyboots [SIZE]       = {", ботинки"},
     cloudyboots1 [SIZE]      = {", осенне-весенние ботинки"};

char cloudygloves1 [SIZE]     = {", кожаные перчатки"},
     cloudygloves2 [SIZE]     = {"теплые перчатки"};



char warmcap [SIZE]           = {" можете взять шарфик"},
     warmcap1 [SIZE]          = {" кепку"},
     warmcap2 [SIZE]          = {" повязку"};


char warmclothes [SIZE]       = {" футболку с джинсами"},
     warmclothes1 [SIZE]      = {" и ветровку."},
     warmclothes2 [SIZE]      = {" и шорты."};


char warmboots [SIZE]         = {", кеды."},
     warmboots1 [SIZE]        = {", кроссовки"},
     warmboots2 [SIZE]        = {", сандалии"};



#endif //PROJECT_WEATHER__PRINT_RECOMENDATION_H
