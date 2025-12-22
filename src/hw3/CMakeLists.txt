cmake_minimum_required(VERSION 3.25)

project(sortingAppC)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(mainProgram mainProgram.c) 

add_library(sorting sorting.s)
target_link_libraries(mainProgram PUBLIC sorting)

