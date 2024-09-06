cmake_minimum_required(VERSION 3.28)
project(Search_algorithm C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 23)
message("C Compiler flags: ${CMAKE_C_FLAGS}")
add_library(Search_algorithm STATIC
        STACK.h
        STACK.c
        Depth-First-Search.h
        Depth-First-Search.c
        AVL_TREE.c
        AVL_TREE.h
        Queue.h
        Queue.c
        ArrayList.c
        ArrayList.h
)

add_executable(Search_algorithm_exec main.c
        STACK.h
        STACK.c
        Depth-First-Search.h
        Depth-First-Search.c
        AVL_TREE.c
        AVL_TREE.h
        Queue.h
        Queue.c
        ArrayList.c
        ArrayList.h
        Heap.c
        Heap.h
)

target_link_libraries(Search_algorithm_exec Search_algorithm)
