#ifndef PROJECT_WEATHER__TEST_H
#define PROJECT_WEATHER__TEST_H

#include "base.h"

void Test() {
    // test 1
    char str[STR_SIZE] = ":::";
    char delim = ':';
    StringArray split = Split(str, delim);
    char** split_arr = split.array;
    if (split.size != 4) {
        printf("split array size is wrong: %zu\n", split.size);
        abort();
    }
    if (strcmp(split_arr[0], "") != 0
            || strcmp(split_arr[1], "") != 0
            || strcmp(split_arr[2], "") != 0
            || strcmp(split_arr[3], "") != 0) {
        printf("split result is wrong: %s %s %s %s\n", split_arr[0], split_arr[1], split_arr[2], split_arr[3]);
        abort();
    }

    // test 2
    char str2[STR_SIZE] = "-24..-20\0";
    int min_val = 0, max_val = 0;
    sscanf(str2, "%d..%d", &min_val, &max_val);
    if (min_val != -24 || max_val != -20) {
        printf("wrong parsing numbers < 0: %d %d, expected: -24 -20\n", min_val, max_val);
        abort();
    }

    // test 3
    DATE cur_date1 = {13, 1, 2021};
    DATE cmp_date1 = {12, 1, 2021};
    if (!AreConsecutiveDates(&cur_date1, &cmp_date1)) {
        printf("test 3, expected true, but false: cur %d.%d.%d, compare with %d.%d.%d",
               cur_date1.day, cur_date1.month, cur_date1.year,
               cmp_date1.day, cmp_date1.month, cmp_date1.year);
        abort();
    }

    DATE cur_date2 = {1, 1, 2021};
    DATE cmp_date2 = {31, 12, 2020};
    if (!AreConsecutiveDates(&cur_date2, &cmp_date2)) {
        printf("test 3, expected true, but false: cur %d.%d.%d, compare with %d.%d.%d",
               cur_date2.day, cur_date2.month, cur_date2.year,
               cmp_date2.day, cmp_date2.month, cmp_date2.year);
        abort();
    }
}

#endif //PROJECT_WEATHER__TEST_H