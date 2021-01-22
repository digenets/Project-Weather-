#pragma once

#include <stdlib.h>

#define DECLARE_ARRAY(ARRAY_TYPE_NAME, ITEM_TYPE)                \
                                                                 \
typedef struct Array##ITEM_TYPE {                                \
    ITEM_TYPE* array;                                            \
    size_t size;                                                 \
}ARRAY_TYPE_NAME;                                                \
