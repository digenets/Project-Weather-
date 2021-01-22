#pragma once

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#define STR_SIZE 50

#define STRING char*

DECLARE_ARRAY(StringArray, STRING)

StringArray Split(char* str, char delim);