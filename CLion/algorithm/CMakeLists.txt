cmake_minimum_required(VERSION 3.17)
project(algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(algorithm main.c )
add_executable(baseball-game baseball-game.c)
add_executable(backspace-string-compare backspace-string-compare.c)
add_executable(test test.c)