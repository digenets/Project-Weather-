#ifndef PROJECT_WEATHER__ARRAY_H
#define PROJECT_WEATHER__ARRAY_H

#include <stdlib.h>

#define DECLARE_ARRAY(ARRAY_TYPE_NAME, ITEM_TYPE)                \
                                                                 \
typedef struct Array##ITEM_TYPE {                                \
    ITEM_TYPE* array;                                            \
    size_t size;                                                 \
}ARRAY_TYPE_NAME;                                                \
                                                                 \
ARRAY_TYPE_NAME Create##ARRAY_TYPE_NAME(size_t size);            \


#define DEFINE_ARRAY(ARRAY_TYPE_NAME, ITEM_TYPE)                 \
                                                                 \
ARRAY_TYPE_NAME Create##ARRAY_TYPE_NAME(size_t size) {           \
    ITEM_TYPE* new_array = (ITEM_TYPE*) malloc(                  \
        sizeof (ITEM_TYPE) * size);                              \
    ARRAY_TYPE_NAME result = {new_array, size};                  \
    return result;                                               \
}

#endif //PROJECT_WEATHER__ARRAY_H
