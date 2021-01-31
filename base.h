#ifndef PROJECT_WEATHER__BASE_H
#define PROJECT_WEATHER__BASE_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#define STR_SIZE 50

#define STRING char*

DECLARE_ARRAY(StringArray, STRING)

bool AreStringArraysEqual(StringArray lhs, StringArray rhs);
StringArray Split(char* str, char delim);

#endif //PROJECT_WEATHER__BASE_H