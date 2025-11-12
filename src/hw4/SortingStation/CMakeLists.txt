add_executable(sortingStation sortingStation.c)

add_library(stack stack.c)

target_link_libraries(sortingStation PUBLIC stack)