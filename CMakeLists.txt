cmake_minimum_required(VERSION 3.17)
project(Project_Weather_ C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_Weather_ main.c date.h temperature.h weather.h weather.c wind.h array.h test.h base.h base.c wind_constants.h precipitation_constants.h wind_printing.c wind_printing.h wind_constants.c precipitation_printing.c precipitation_printing.h precipitation_constants.c temperature_pinting.c temperature_pinting.h print_date.c print_date.h month_name.c month_name.h weekday.c weekday.h average_temperature.c average_temperature.h print_pressure.c print_pressure.h date.c print_feelling_temperature.c print_feelling_temperature.h)
