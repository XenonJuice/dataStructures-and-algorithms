cmake_minimum_required(VERSION 3.28)
project(Search_algorithm C)

set(CMAKE_C_STANDARD 99)

add_library(Search_algorithm STATIC library.c
        STACK.h
        STACK.c
        Depth-First-Search.h
        Depth-First-Search.c
)

add_executable(Search_algorithm_exec main.c
        STACK.h
        STACK.c
        Depth-First-Search.h
        Depth-First-Search.c
)

target_link_libraries(Search_algorithm_exec Search_algorithm)
