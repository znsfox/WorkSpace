cmake_minimum_required(VERSION 3.17)
project(C C)

set(CMAKE_C_STANDARD 11)

add_executable(C main.c ListTest.c fatal.h list.h chapter3_exercise/3.2.c)
add_executable(ListTest ListTest.c)
add_executable(3.2 chapter3_exercise/3.2.c chapter3_exercise/list.h)
add_executable(stack stack/stack.c)
add_executable(tree tree/tree.c)