#include "print_pressure.h"

void PrintPressure(WEATHER* weather, FILE * out){
    int pressure = weather->pressure;
    if (pressure >= 755)
        fprintf(out, "Атмосферное давление высокое: %d мм ртутного столба.", pressure);
    else if (pressure < 755 && pressure > 745)
        fprintf(out, "Атмосферное давление в норме: %d мм ртутного столба.", pressure);
    else if (pressure <= 745)
        fprintf(out, "Атмосферное давление низкое: %d мм ртутного столба.", pressure);
    fprintf(out, " ");

}
