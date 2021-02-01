#include "month_name.h"

void PrintMonth(int number_of_month, FILE * out){
    switch (number_of_month) {
        case 1:
            fprintf(out, "января");
            break;
        case 2:
            fprintf(out, "февраля");
            break;
        case 3:
            fprintf(out, "марта");
            break;
        case 4:
            fprintf(out, "апреля");
            break;
        case 5:
            fprintf(out, "мая");
            break;
        case 6:
            fprintf(out, "июня");
            break;
        case 7:
            fprintf(out, "июля");
            break;
        case 8:
            fprintf(out, "августа");
            break;
        case 9:
            fprintf(out, "сентября");
            break;
        case 10:
            fprintf(out, "ноября");
            break;
        case 11:
            fprintf(out, "октября");
            break;
        case 12:
            fprintf(out, "декабря");
            break;


    }
}