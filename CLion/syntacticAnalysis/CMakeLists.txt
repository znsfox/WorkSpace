cmake_minimum_required(VERSION 3.17)
project(syntacticAnalysis C)

set(CMAKE_C_STANDARD 11)

add_executable(syntacticAnalysis main.c test.c)
add_executable(test test.c)