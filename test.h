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
}

#endif //PROJECT_WEATHER__TEST_H