cmake_minimum_required(VERSION 3.17)
project(whc C)

set(CMAKE_C_STANDARD 99)

add_executable(whc limits.c limits.h fraction.h)