#pragma once

#include "base.h"

/* если скорость задана только одним числом - оно хранится в min_val, тогда max_val == -1 */
typedef struct Wind {
    int speed_min_val;
    int speed_max_val;

    StringArray direction;

    int gusts_min_val; // порывы
    int gusts_max_val;
}WIND;