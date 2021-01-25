cmake_minimum_required(VERSION 3.17)
project(Project_Weather_ C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_Weather_ main.c date.h temperature.h weather.h weather.c wind.h array.h test.h base.h base.c weekday.h weekday.c print_date.h print_date.c month_name.h month_name.c average_temperature.c average_temperature.h)