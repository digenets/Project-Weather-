#include "base.h"

DEFINE_ARRAY(StringArray, STRING)

StringArray Split(char* str, char delim) {
    // посчитать, сколько разделителей, чтоб выделить потом память под строки (кол-во разделителей + 1)
    int delim_counter = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == delim) {
            ++delim_counter;
        }
    }

    // создать массив строк
    int substr_number = delim_counter + 1;
    char** split = (char**) malloc(substr_number * sizeof (char*));

    int left_i = 0;
    int right_i = 0;
    int str_index = 0;
    while (true) {
        if (str[right_i] == delim || str[right_i] == '\0') {
            // создаём строку, копируем туда подстроку
            split[str_index] = (char*) malloc((right_i - left_i + 1) * sizeof (char)); // +1 символ под \0
            memcpy(split[str_index], str + left_i, right_i - left_i + 1);
            split[str_index][right_i - left_i] = '\0';

            ++str_index;
            left_i = right_i + 1;
        }
        if (str[right_i] == '\0') {
            break;
        }
        ++right_i;
    }
    StringArray result = {split, substr_number};
    return result;
}