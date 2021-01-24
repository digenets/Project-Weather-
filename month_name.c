#pragma once
#include <stdio.h>

void print_month(int number_of_month){
    switch (number_of_month) {
        case 1:
            printf("yanvarya");
            break;
        case 2:
            printf("fevralya");
            break;
        case 3:
            printf("marta");
            break;
        case 4:
            printf("aprelya");
            break;
        case 5:
            printf("maya");
            break;
        case 6:
            printf("iyunya");
            break;
        case 7:
            printf("ijulya");
            break;
        case 8:
            printf("avgusta");
            break;
        case 9:
            printf("sentyabrya");
            break;
        case 10:
            printf("noyabrya");
            break;
        case 11:
            printf("oktyabrya");
            break;
        case 12:
            printf("dekabrya");
            break;


    }
}