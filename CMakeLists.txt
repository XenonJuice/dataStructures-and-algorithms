cmake_minimum_required(VERSION 3.27)
project(Search_algorithm C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 23)
message("C Compiler flags: ${CMAKE_C_FLAGS}")
add_library(myWork STATIC
        STACK.c
        Depth-First-Search.c
        AVL_TREE.c
        Queue.c
        ArrayList.c
        LinkedList.c
)


add_executable(hello.exe main.c)
target_link_libraries(hello.exe myWork m)



