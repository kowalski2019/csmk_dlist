cmake_minimum_required(VERSION 3.16)
project(csmk_dlist C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-g -pedantic -Wall -Wextra)

add_executable(csmk_list main.c
        dlist_v1/DataList_v1.c
        dlist_v1/dlist_types.h dlist_v1/dlist_types.c)
