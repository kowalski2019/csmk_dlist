cmake_minimum_required(VERSION 3.16)
project(csmk_list C)

set(CMAKE_C_STANDARD 99)

add_executable(csmk_list main.c DataList.c linkedList.c doubleLinkedList.c lists_test.c)
