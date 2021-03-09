cmake_minimum_required(VERSION 3.17)
project(integer_stack C)

set(CMAKE_C_STANDARD 11)

add_executable(integer_stack main.c stack.c stack.h)